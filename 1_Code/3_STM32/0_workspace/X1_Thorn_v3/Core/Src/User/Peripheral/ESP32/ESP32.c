/**
  ******************************************************************************
  * @file           : ESP32.c
  * @brief          : Communicates with the ESP32 board to receive the PS4 controller inputs
  *
  * activate = 0 if UART communication failed, if the esp32 did not receive new controller data for 4 seconds or if the
  * triangle button was pressed on the ps4 controller
  *
  ******************************************************************************
*/


#include "ESP32.h"
#include <string.h>
#include "usart.h"
#include <stdbool.h>

typedef enum {
    SYNC_WAIT_1,
    SYNC_WAIT_2,
    SYNC_COLLECT
} FrameState;


static bool uart_data_ready = false;
static float received_floats[5];
static uint32_t inactivity;

static uint8_t    rx_byte;
static uint8_t    collect_count = 0;
static FrameState frame_state = SYNC_WAIT_1;
static uint8_t collect_buf[20];



void esp32_Init(void)
{
	HAL_UART_Receive_IT(&huart5, &rx_byte, 1);
}



uint8_t get_esp32_commands(esp32_commands_t *esp32_commands)
{
	if (uart_data_ready)
	{
		uart_data_ready = false;
		inactivity = 0;
		esp32_commands->ax_command = received_floats[0];
		esp32_commands->p_command = received_floats[1];
		esp32_commands->pitch_command = received_floats[2];
		esp32_commands->roll_command = received_floats[3];
		return  received_floats[4];									// Return status activate
	}
	else
	{
		if (inactivity < 100)
		{
			inactivity++;
			return received_floats[4];
		}
		else
		{
			inactivity++;
			return 0;
		}
	}
}


void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    if (huart == &huart5)
    {
        // 1) Clear Overrun just in case
        __HAL_UART_CLEAR_OREFLAG(&huart5);

        // 2) State machine
        switch (frame_state)
        {
            case SYNC_WAIT_1:
                if (rx_byte == 0x55)
                    frame_state = SYNC_WAIT_2;
                break;

            case SYNC_WAIT_2:
                if (rx_byte == 0xAA)
                {
                    frame_state = SYNC_COLLECT;
                    collect_count = 0;
                }
                else
                    frame_state = SYNC_WAIT_1; // false alarm, restart
                break;

            case SYNC_COLLECT:
                collect_buf[collect_count++] = rx_byte;
                if (collect_count >= sizeof(collect_buf))
                {
                    // got full payload: copy to floats
                    memcpy(received_floats, collect_buf, sizeof(collect_buf));
                    uart_data_ready = true;
                    // restart framing
                    frame_state = SYNC_WAIT_1;
                }
                break;
        }

        // 3) re-arm for next byte
        HAL_UART_Receive_IT(&huart5, &rx_byte, 1);
    }
}


void HAL_UART_ErrorCallback(UART_HandleTypeDef *huart)
{
    if (huart == &huart5)
    {
        // Clear the error flags
        __HAL_UART_CLEAR_OREFLAG(&huart5);
        // Optionally log huart5.ErrorCode
        // Re-arm reception so you don’t lock up
        HAL_UART_Receive_IT(&huart5, &rx_byte, 1);
    }
}
