/*
 * SystemMonitor.h
 *
 *  Created on: Jun 21, 2025
 *      Author: marcv
 */

#ifndef SRC_USER_APP_SYSTEMMONITOR_SYSTEMMONITOR_H_
#define SRC_USER_APP_SYSTEMMONITOR_SYSTEMMONITOR_H_






typedef struct
{
    osThreadId_t                  taskHandle;
    osThreadAttr_t                taskAttr;                   /*!< Task attributes    */
} system_monitor_task_t;



#endif /* SRC_USER_APP_SYSTEMMONITOR_SYSTEMMONITOR_H_ */
