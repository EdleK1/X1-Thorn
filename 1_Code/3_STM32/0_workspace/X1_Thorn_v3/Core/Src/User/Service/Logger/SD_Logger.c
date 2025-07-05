/*
 * SD_LOGGER.c
 *
 *  Created on: 6 sept. 2024
 *      Author: david
 */
#include "SD_Logger.h"
#include <stdbool.h>

#define SD_LOGGER_MAX_VARIABLES         16                                  /*!< Máximo número de variables a registrar */
#define SD_LOGGER_FREQUENCY_HZ          10                                  /*!< Frecuencia de logging en Hertz */

#define SD_LOGGER_STACK_SIZE			(configMINIMAL_STACK_SIZE * 16)		/*!< Stack size	*/


typedef struct {
    void* ptr;
    SD_Logger_DataType_t type;
    const char* header;
} RegisteredVariable_t;

typedef struct{

	osThreadId_t				taskHandle;				/*!< Task handle		*/
    osThreadAttr_t              taskAttr;               /*!< Task attributes    */

    osMutexId_t 				mutex;

    FATFS                       fs;
    FIL                         fil;
    char                        log_filename[32];
    RegisteredVariable_t        registered_vars[SD_LOGGER_MAX_VARIABLES];
    uint8_t                     num_registered_vars;

    bool 						initalized;

    uint32_t					log_delay_ms;

}SD_Logger_t;


void 		SD_Logger_Task(void * argument);
uint8_t		SD_Logger_Start(void);

char float_buf[32]; // Buffer para formatear los float


static SD_Logger_t sd_logger;


void SD_Logger_Init(void)
{



	sd_logger.taskAttr.name = "SD_Logger_Task";
	sd_logger.taskAttr.priority = osPriorityNormal;
	sd_logger.taskAttr.stack_size = SD_LOGGER_STACK_SIZE;
	sd_logger.taskHandle = osThreadNew(SD_Logger_Task, NULL, &sd_logger.taskAttr);

	osMutexNew(sd_logger.mutex);

}







void SD_Logger_Task(void * argument)
{
	osDelay(500); // Esperar a que se registren las variables

    if (sd_logger.num_registered_vars == 0)
    {
//        SD_Logger_Printf("SD_Logger: No variables registered. Task will not run.");
        for(;;) { osDelay(osWaitForever); } // Dormir la tarea para siempre
    }

	SD_Logger_Start();


	for(;;)
	{
        for (uint8_t i = 0; i < sd_logger.num_registered_vars; i++)
        {
            switch (sd_logger.registered_vars[i].type)
            {
                case LOG_TYPE_INT32:
                    f_printf(&sd_logger.fil, "%ld", *((int32_t*)sd_logger.registered_vars[i].ptr));
                    break;
                case LOG_TYPE_UINT32:
                    f_printf(&sd_logger.fil, "%lu", *((uint32_t*)sd_logger.registered_vars[i].ptr));
                    break;
                case LOG_TYPE_FLOAT:
                    // Usar sprintf porque f_printf no soporta float
                    sprintf(float_buf, "%.3f", *((float*)sd_logger.registered_vars[i].ptr));
                    f_printf(&sd_logger.fil, "%s", float_buf);
                    break;
            }
            if (i < sd_logger.num_registered_vars - 1)
            {
                f_printf(&sd_logger.fil, ",");
            }
        }
        f_printf(&sd_logger.fil, "\n");
        f_sync(&sd_logger.fil);

		osDelay(sd_logger.log_delay_ms > 0 ? sd_logger.log_delay_ms : 1);
	}

}



uint8_t SD_Logger_Start(void)
{
    int result;

    sd_logger.log_delay_ms = 1000 / SD_LOGGER_FREQUENCY_HZ;

//    SD_Logger_Printf("SD_Logger: Initializing SD");
    result = (int)HAL_SD_Init(&hsd1);

    if (result != HAL_OK)
    {
//        SD_Logger_ErrorPrintf("SD_Logger: SD_Init error: %d, probably no SD detected", (uint32_t)result);
        return ERROR;
    }

//    SD_Logger_Printf("SD_Logger: SD Init OK, proceeding to mount");
    result = (int)f_mount(&sd_logger.fs, "0:", 1);

    if (result != FR_OK)
    {
//        SD_Logger_ErrorPrintf("SD_Logger: FATFS Mount failed (FRESULT: %d)", result);
        return ERROR;
    }

//    SD_Logger_Printf("SD_Logger: FATFS Mount OK, scanning for log files");

    DIR dir;
    FILINFO fno;
    uint8_t max_log_num = 0;
    long current_log_num_long;
    char filename_buffer[20];
    char *endptr;

    result = (int)f_opendir(&dir, "0:/");
    if (result != FR_OK)
    {
//        SD_Logger_ErrorPrintf("SD_Logger: Failed to open root directory (FRESULT: %d)", result);
        return ERROR;
    }

    while ((result = (int)f_readdir(&dir, &fno)) == FR_OK && fno.fname[0] != 0)
    {
        if (strncmp(fno.fname, "LOG", 3) == 0)
        {
            // Busca el punto de la extensión
            char *dot_ptr = strchr(fno.fname + 3, '.');
            //
            // --- LA CORRECCIÓN ESTÁ AQUÍ ---
            //
            if (dot_ptr != NULL && strcmp(dot_ptr, ".CSV") == 0)
            {
                // Convierte la parte numerica a long
                current_log_num_long = strtol(fno.fname + 3, &endptr, 10);

                // Verifica que se haya leido un numero y que no haya caracteres adicionales antes de .
                if (endptr == dot_ptr && current_log_num_long > 0 && current_log_num_long <= 255) // maximo para uint8_t
                {
                    if ((uint8_t)current_log_num_long > max_log_num)
                    {
                        max_log_num = (uint8_t)current_log_num_long;
                    }
                }
            }
        }
    }
    f_closedir(&dir);

    if (result != FR_OK && result != FR_NO_FILE)
    {
//        SD_Logger_ErrorPrintf("SD_Logger: Error reading directory (FRESULT: %d)", result);
        return ERROR;
    }

    uint8_t next_log_num = max_log_num + 1;
    if (next_log_num > 64)
    {
//        SD_Logger_ErrorPrintf("SD_Logger: Max log files reached (64). Cannot create new log.");
        return ERROR;
    }

    snprintf(filename_buffer, sizeof(filename_buffer), "0:/LOG%d.CSV", next_log_num);

//    SD_Logger_Printf("SD_Logger: Attempting to create file: %s", filename_buffer);

    result = (int)f_open(&sd_logger.fil, filename_buffer, FA_CREATE_ALWAYS | FA_WRITE | FA_READ);

    if (result == FR_OK)
    {
//        SD_Logger_Printf("SD_Logger: File %s created correctly, writting the header", filename_buffer);

        // Escribir la cabecera del CSV
        for (uint8_t i = 0; i < sd_logger.num_registered_vars; i++)
        {
            f_printf(&sd_logger.fil, "%s", sd_logger.registered_vars[i].header);
            if (i < sd_logger.num_registered_vars - 1)
            {
                f_printf(&sd_logger.fil, ",");
            }
        }
        f_printf(&sd_logger.fil, "\n");
        f_sync(&sd_logger.fil);
    }

//    SD_Logger_Printf("SD_Logger: Initialization complete. Starting periodic logging.");

    sd_logger.initalized = true;

    // Devuelve SUCCESS si f_open tuvo éxito, de lo contrario, devuelve el código de error.
    return (result == FR_OK) ? SUCCESS : ERROR;
}



uint8_t SD_Logger_RegisterVariable(void* var_ptr, SD_Logger_DataType_t type, const char* header_name)
{
	if (sd_logger.initalized == true)
	{
//		SD_Logger_ErrorPrintf("SD_Logger: Trying to register a variable while logging, wrong state", header_name, sd_logger.num_registered_vars);
	}

	osMutexAcquire(sd_logger.mutex, osWaitForever);


    if (sd_logger.num_registered_vars >= SD_LOGGER_MAX_VARIABLES) {
//        SD_Logger_ErrorPrintf("SD_Logger: Max registered variables reached");
        return -1;
    }
    if(var_ptr == NULL || header_name == NULL) {
//		SD_Logger_ErrorPrintf("SD_Logger: Invalid pointer provided for registration");
		return -1;
	}

    sd_logger.registered_vars[sd_logger.num_registered_vars].ptr = var_ptr;
    sd_logger.registered_vars[sd_logger.num_registered_vars].type = type;
    sd_logger.registered_vars[sd_logger.num_registered_vars].header = header_name;
    sd_logger.num_registered_vars++;

//    SD_Logger_Printf("SD_Logger: Variable %s registered, total: %d/%d", header_name, sd_logger.num_registered_vars, SD_LOGGER_MAX_VARIABLES);

    osMutexRelease(sd_logger.mutex);

    return 0;
}


