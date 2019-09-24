#ifndef  Bit_Math_H_
#define  Bit_Math_H_


//////////
#define Set_Bit(Reg,Bit_no)  ( (Reg) |=  (1<<Bit_no))

#define Clr_Bit(Reg,Bit_no)  ( (Reg) &= ~(1<<Bit_no))

#define Tog_Bit(Reg,Bit_no)  ( (Reg) ^=  (1<<Bit_no))

#define Get_Bit(Reg,Bit_no)  ( (Reg)&(1<<Bit_no))


#endif
