/*
 * KYP_int.h
 *
 *  Created on: May 31, 2019
 *      Author: Hossam-PC
 */

#ifndef KYP_INT_H_
#define KYP_INT_H_

#include "LIB/Standard_Types.h"
#include "util/delay.h"
#include "GPIO.h"

typedef enum {
	NOT_PRESSED,
	PRE_PRESSED,
	PRESSED
}Button_status;



Button_status Kyp_getPressedButton(uint8* Button_Num);
void KYP_vidInit(void);

#endif /* KYP_INT_H_ */
