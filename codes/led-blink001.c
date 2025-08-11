#include <stdint.h>
int main(void)
{
	uint32_t *pclkctrlreg =(uint32_t*)0x40023830;
	uint32_t *pPortDModereg =(uint32_t*)0x40020C00;
	uint32_t *pPortDOutReg =(uint32_t*)0x40020C14;

	//1. enable the clock for GPIOD peripherl in the AHB1ENR
	*pclkctrlreg |= (1<<3);

	//2. configure the mode of the IO pin as output
	//a. clear the 24th and 25th bit position (CLEAR)
	*pPortDModereg &=~(3<<24);
	//b. make 24th bit position as 1(SET)
	*pPortDModereg |=(1<<24);
	//3. SET 12th bit of the output data register to make /O pin-12 as HIGH
	*pPortDOutReg |=(1<<12);
	while(1)
	{ if(*pPortDOutReg & 0x1000)
		*pPortDOutReg &= ~0x1000;
		else
			*pPortDOutReg |=0x1000;
	for(volatile int i=0; i<300000;i++);


	}


}

