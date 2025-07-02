#include "customcode_HKPmF5QXLgcGJK5m6IhD3D.h"
#ifdef __cplusplus
extern "C" {
#endif


/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
DLL_EXPORT_CC extern const char_T *get_dll_checksum_HKPmF5QXLgcGJK5m6IhD3D(void);
DLL_EXPORT_CC extern void PID_Init_HKPmF5QXLgcGJK5m6IhD3D(pid_handle_t *pid, real32_T Kp, real32_T Ki, real32_T Kd, real32_T dt, uint16_T outputMin, uint16_T outputMax, real32_T integratorMin, real32_T integratorMax, real32_T tau);
DLL_EXPORT_CC extern uint16_T PID_Update_HKPmF5QXLgcGJK5m6IhD3D(pid_handle_t *pid, real32_T measurement, real32_T setpoint);

/* Function Definitions */
DLL_EXPORT_CC const uint8_T *get_checksum_source_info(int32_T *size);
#ifdef __cplusplus
}
#endif

