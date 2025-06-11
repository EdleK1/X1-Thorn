/*
 * Control.h
 *
 *  Created on: May 13, 2025
 *      Author: marcv
 */

#ifndef SRC_USER_APP_CONTROL_PITCHCONTROLLER_PITCHCONTROLLER_H_
#define SRC_USER_APP_CONTROL_PITCHCONTROLLER_PITCHCONTROLLER_H_

void PitchController_Init(void);
float PitchController_Update(float curr_error);


#endif /* SRC_USER_APP_HIGHLEVELCONTROL_CONTROL_H_ */
