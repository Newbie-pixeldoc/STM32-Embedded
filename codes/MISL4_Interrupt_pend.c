//IRQ = Interrupt request no.
//ISPR = Interrupt set pending register
//ISER = Interrupt set enable register

#include <stdint.h>
#include <stdio.h>

#define USART3_IRQNO 39

int main(void)
{
	 //Manually pend the pending bit for the USART3 IRQ Number in NVIC
	 uint32_t *pISPR = (uint32_t*)0xE000E204;
	 *pISPR |= (1<<(USART3_IRQNO%32));

	 //Enable the USART3 IRQ Number in NVIC
	 uint32_t *pISER = (uint32_t*)0xE000E104;
	 *pISER |= (1<<(USART3_IRQNO%32));

	 for(;;);

}

void USART3_IRQHandler(void)
{

	printf("in USART ISR\n");

}