#include <stdint.h>
#include <stdio.h>
void delay(void){
	for(volatile int i=0; i<300000;i++);
}
//p0 p1 p2 p3 == output(row)
//p8 p9 p10 p11 == input(coloumn)
int main(void)
{
    uint32_t volatile *const pclkctrlreg =(uint32_t*)0x40023830;
	uint32_t volatile *const pPortDModereg =(uint32_t*)0x40020C00;
	uint32_t volatile *const pPortDOutReg =(uint32_t*)0x40020C14;
	uint32_t volatile *const pPortDInpReg =(uint32_t*)0x40020C10;
	uint32_t volatile *const pPortDpullresister =(uint32_t*)0x40020C0C;

	*pclkctrlreg |= (1<<3);
	*pPortDModereg &= ~(0xff);
	*pPortDModereg |= 0x55;
	*pPortDModereg &= ~(0xff << 16);
	*pPortDpullresister &= ~(0xff << 16);
	*pPortDpullresister |= (0x55 << 16);
	*pPortDOutReg |= 0xf;
	while(1)
	{
		*pPortDOutReg |= 0xf;
	    *pPortDOutReg &= ~(1<<0);
				if(!(*pPortDInpReg & (1<<8))){
					delay();
					printf("1\n");
				}
				if(!(*pPortDInpReg & (1<<9))){
					delay();
					printf("2\n");
				}
				if(!(*pPortDInpReg & (1<<10))){
					delay();
					printf("3\n");
				}
				if(!(*pPortDInpReg & (1<<11))){
					delay();
					printf("A\n");
				}
		*pPortDOutReg |= 0xf;
		*pPortDOutReg &= ~(1<<1);
			    if(!(*pPortDInpReg & (1<<8))){
			    	delay();
			    	printf("4\n");
			    }
				if(!(*pPortDInpReg & (1<<9))){
					delay();
					printf("5\n");
				}
				if(!(*pPortDInpReg & (1<<10))){
					delay();
					printf("6\n");
				}
				if(!(*pPortDInpReg & (1<<11))){
					delay();
					printf("B\n");
				}
		*pPortDOutReg |= 0xf;
		*pPortDOutReg &= ~(1<<2);
				if(!(*pPortDInpReg & (1<<8))){
					delay();
					printf("7\n");
				}
				if(!(*pPortDInpReg & (1<<9))){
					delay();
					printf("8\n");
				}
				if(!(*pPortDInpReg & (1<<10))){
					delay();
					printf("9\n");
				}
				if(!(*pPortDInpReg & (1<<11))){
					delay();
					printf("C\n");
				}
		*pPortDOutReg |= 0xf;
		*pPortDOutReg &= ~(1<<3);
				if(!(*pPortDInpReg & (1<<8))){
					delay();
					printf("*\n");
				}
				if(!(*pPortDInpReg & (1<<9))){
					delay();
					printf("0\n");
				}
				if(!(*pPortDInpReg & (1<<10))){
					delay();
					printf("#\n");
				}
				if(!(*pPortDInpReg & (1<<11))){
					delay();
					printf("D\n");
				}


	}



}

