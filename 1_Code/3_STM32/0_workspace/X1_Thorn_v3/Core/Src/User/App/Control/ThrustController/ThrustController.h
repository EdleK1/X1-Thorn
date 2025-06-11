/*
 * Control.h
 *
 *  Created on: May 13, 2025
 *      Author: marcv
 */

#ifndef SRC_USER_APP_CONTROL_THRUSTCONTROLLER_THRUSTCONTROLLER_H_
#define SRC_USER_APP_CONTROL_THRUSTCONTROLLER_THRUSTCONTROLLER_H_

void ThrustController_Init(void);
float ThrustController_Update(float curr_error);


#endif /* SRC_USER_APP_HIGHLEVELCONTROL_CONTROL_H_ */
