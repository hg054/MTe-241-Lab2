#include <LPC17xx.h>
#include "stdio.h"
#include "uart.h"

int main(void)
{

	/*	int input = 5;
	int counter = 8;
	for(int i = 0; i< 8; i++)
	{
		int mod = 2;
		int temp = input%mod;
		if(temp == 1)
			
		
	}*/
	
	unsigned int input = 5;
	
	int LEDnum = 8;
	unsigned int shift = input;
	int count;
	
	
	SystemInit();
	
	printf("Hello\n");
	
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
		if(remainder == 1)
		{
			if(count == 0)
			{
				LPC_GPIO2->FIOSET |= 1<<6;
				printf("---0---");
			}
			if(count == 1)
			{
				LPC_GPIO2->FIOSET |= 1<<5;
				printf("1");
			}
			if(count == 2)
			{
				LPC_GPIO2->FIOSET |= 1<<4;
				printf("2");
			}
			if(count == 3)
			{
				LPC_GPIO2->FIOSET |= 1<<3;
				printf("3");
			}
			if(count == 4)
			{
				LPC_GPIO2->FIOSET |= 1<<2;
			printf("4");
			}
		
			if(count == 5)
			{
				LPC_GPIO1->FIOSET |= 1<<31;
				printf("5");
			}

			if(count == 6)
			{
				LPC_GPIO1->FIOSET |= 1<<29;
				printf("6");
			}

			if(count == 7)
			{
				LPC_GPIO1->FIOSET |= 1<<28;
				printf("7");
			}

			
		}
		
		shift = input >> 1;
		printf("\n shift: %d for count: %d", shift, count);
			
	}


	while(1);
	
		
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
