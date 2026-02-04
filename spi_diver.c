#include<lpc21xx.h>
#include "header.h"
#define CS0 (1<<7) //P0.7

void spi0_init(void){
	PINSEL0|=0x1500;//P0.4 :SCK0 P0.5 : MISO0 P0.6 : MOSI0
	IODIR0|=CS0;//P0.7 : Output Direction
	IOSET0=CS0;//Disselect slave
	S0SPCR=0X20;//CPOL=CPHA,MAster Mode,MSSB first
	S0SPCCR=15;//SPI Frequency is 1MBPS(1MHz)
}

//SPI Data Transfer Function
#define SPIF ((S0SPSR>>7)&1)
unsigned char spi0(unsigned char data){
	S0SPDR=data;//Data M->S
	while(SPIF==0);//Waiting For SPI Transfer
	return S0SPDR;//Data From S->M
}
