/*
 * main.c
 *
 *  Created on: 2021 May 05 13:35:00
 *  Author: wiegelep
 */



#include <xmc_gpio.h>

#define TICKS_PER_SECOND 1000
#define DELAY_MS 1000
unsigned int volatile ticks=0;
/**
 * @brief main() - Simple blinky with systick timer
 *
 * <b>Details of function</b><br>
 * This routine is the application entry point. It is invoked by the device startup code. 
 */

int main(void)
{

	const XMC_GPIO_CONFIG_t p1_0_conf = {
	  .mode = XMC_GPIO_MODE_OUTPUT_PUSH_PULL,
	  .output_level = XMC_GPIO_OUTPUT_LEVEL_LOW
	};
	XMC_GPIO_Init(P1_0,&p1_0_conf);					/* LED */
	XMC_GPIO_ToggleOutput(P1_0);


	SysTick_Config(SystemCoreClock / TICKS_PER_SECOND);

	while(1U)
	{
      if(ticks == DELAY_MS)
      {
    	XMC_GPIO_ToggleOutput(P1_0);
    	ticks = 0;
      }

	}
}

void SysTick_Handler(void)
{
	ticks++;
}
