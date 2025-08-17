#include <stdint.h>
int main(void)
{
	uint32_t volatile *pclkctrlreg =(uint32_t*)0x40023830;
	uint32_t volatile *pPortDModereg =(uint32_t*)0x40020C00;
	uint32_t volatile *pPortDOutReg =(uint32_t*)0x40020C14;
	uint32_t volatile *pPortAModeReg =(uint32_t*)0x40020000;
	uint32_t volatile *pPortAInReg =(uint32_t*)0x40020010;

	//1. enable the clock for GPIOD & GPIOA peripherl in the AHB1ENR
	*pclkctrlreg |= (1<<3);
	*pclkctrlreg |= (1<<0);
	//2. configure the mode of the IO pin as output
	//for D port
	*pPortDModereg &=~(3<<24);
	*pPortDModereg |=(1<<24);
	//for A port
	*pPortAModeReg &=~(3<<0);

    //3. SET 12th bit of the output data register to make /O pin-12 as HIGH
	*pPortDOutReg |=(1<<12);




	while(1)
	{
		uint8_t pinstatus = (uint8_t)(*pPortAInReg & 0x1);
		if(pinstatus)
			*pPortDOutReg |=(1<<12);
		else
			*pPortDOutReg &= ~(1<<12);
	}

}
