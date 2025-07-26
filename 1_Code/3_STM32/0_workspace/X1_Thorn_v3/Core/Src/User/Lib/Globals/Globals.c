/**
  ******************************************************************************
  * @file           : Globals.c
  * @brief          : Defines global variables that are used by all functions.
  *
  *
  * Odometry, GroundCommands -> actuators_t
  ******************************************************************************
*/


#include "globals.h"

/* Initialize to status 0 & ESC 0 (inactive) */

volatile uint8_t g_Status = 0;
volatile uint8_t g_ESC_Active = 0;
