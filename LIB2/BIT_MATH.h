/*
 * BIT_MATH.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: ALI SHAWKY
 */

#ifndef LIB2_BIT_MATH_H_
#define LIB2_BIT_MATH_H_

#define Set_Bit(Reg,Bit)      ( (Reg) |= (1 << Bit))
#define Clr_Bit(Reg,Bit)      ( (Reg) &=~ (1 << Bit))
#define Toggle_Bit(Reg,Bit)   ( (Reg) ^= (1 << Bit))
#define Get_Bit(Reg,Bit)      ( (Reg >> Bit) & (0x01))

#endif /* LIB2_BIT_MATH_H_ */
