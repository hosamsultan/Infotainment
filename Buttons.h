/*
 * Buttons.h
 *
 *  Created on: Aug 30, 2019
 *      Author: Hossam-PC
 */

#ifndef BUTTONS_H_
#define BUTTONS_H_
#include "LIB/Standard_Types.h"

#define INPUT  0
#define OUTPUT 1

#define HIGH   1
#define LOW    0

#define btn0    20
#define btn1    10

uint8 scan_btn0(void);
uint8 scan_btn1(void);

#endif /* BUTTONS_H_ */
