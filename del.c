/*
 * del.c
 *
 *  Created on: Aug 17, 2019
 *      Author: Hossam-PC
 */
#include "del.h"

void del_ms(uint32 x)
{
	volatile uint32 i,j;
	for(i=0;i<x;i++)
	{
		for(j=0;j<240;j++);
	}
}
