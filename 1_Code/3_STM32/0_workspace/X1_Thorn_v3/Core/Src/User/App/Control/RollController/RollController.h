/*
 * Control.h
 *
 *  Created on: May 13, 2025
 *      Author: marcv
 */

#ifndef SRC_USER_APP_CONTROL_ROLLCONTROLLER_ROLLCONTROLLER_H_
#define SRC_USER_APP_CONTROL_ROLLCONTROLLER_ROLLCONTROLLER_H_

void Roll_Controller_Init(void);
float Roll_Controller_Update(float p_ref, float p_measured);


#endif /* SRC_USER_APP_HIGHLEVELCONTROL_CONTROL_H_ */
