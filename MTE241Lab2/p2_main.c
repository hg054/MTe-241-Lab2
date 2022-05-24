#include <LPC17xx.h>
#include "stdio.h"
#include "uart.h"

int main(void)
{
	
	unsigned int input = 123;
	
	int LEDnum = 8;
	unsigned int shift = input;
	int count;
	
	SystemInit();
	
	LPC_GPIO2->FIODIR |= 1<<6;
	LPC_GPIO2->FIODIR |= 1<<5;
	LPC_GPIO2->FIODIR |= 1<<4;
	LPC_GPIO2->FIODIR |= 1<<3;
	LPC_GPIO2->FIODIR |= 1<<2;
	LPC_GPIO1->FIODIR |= 1<<31;
	LPC_GPIO1->FIODIR |= 1<<29;
	LPC_GPIO1->FIODIR |= 1<<28;
	
	for(count = 0; count < LEDnum; count++){
		int remainder = shift%2;
		printf("\n Remainder: %d", remainder);
		if(remainder == 1)
		{
			if(count == 0)		
				LPC_GPIO2->FIOSET |= 1<<6;
			if(count == 1)
				LPC_GPIO2->FIOSET |= 1<<5;
			if(count == 2)
				LPC_GPIO2->FIOSET |= 1<<4;
			if(count == 3)
				LPC_GPIO2->FIOSET |= 1<<3;
			if(count == 4)
				LPC_GPIO2->FIOSET |= 1<<2;
			if(count == 5)
				LPC_GPIO1->FIOSET |= 1<<31;
			if(count == 6)
				LPC_GPIO1->FIOSET |= 1<<29;
			if(count == 7)
				LPC_GPIO1->FIOSET |= 1<<28;
			
		}
		shift = shift >> 1;
		
		printf("\n shift: %d for count: %d", shift, count);
			
	}


	while(1){

		unsigned int pin = LPC_GPIO1->FIOPIN & 1<<20;
		if(!pin)
			printf("Pin 20: Pressed");
	};
	
		
}

/*
	int input = 5;
	
	int remainder = input % 2;		
	
	int mult2 = (input-remainder);
	int num2 = 0;
	while(mult2 != 1){
		mult2 = mult2/2;
		num2++;
	}
	
	
	int counter = 0; 
	LPC_GPIO2->FIODIR |= 1<<6;
	LPC_GPIO2->FIODIR |= 1<<5;
	LPC_GPIO2->FIODIR |= 1<<4;
	LPC_GPIO2->FIODIR |= 1<<3;
	LPC_GPIO2->FIODIR |= 1<<2;
	LPC_GPIO1->FIODIR |= 1<<31;
	LPC_GPIO1->FIODIR |= 1<<29;
	LPC_GPIO1->FIODIR |= 1<<28;
	while(mult2 != 1){
		mult2 = mult2/2;
		counter++;
		
		if(counter == 1)
			LPC_GPIO2->FIODIR |= 0<<5;
		if(counter == 2)
			LPC_GPIO2->FIODIR |= 0<<4;
		if(counter == 3)
			LPC_GPIO2->FIODIR |= 0<<3;
		if(counter == 4)
			LPC_GPIO2->FIODIR |= 0<<2;
		if(counter == 5)
			LPC_GPIO1->FIODIR |= 0<<31;
		if(counter == 6)
			LPC_GPIO1->FIODIR |= 0<<29;
		if(counter == 7)
			LPC_GPIO1->FIODIR |= 0<<28;
	
	}	
	
	if(remainder == 0)
		LPC_GPIO2->FIODIR |= 1<<6;
*/
