#include<lpc21xx.h>
#include "header.h"
#define CS0 (1<<7)
unsigned int mcp3204_adc_read(unsigned char ch_num){
	unsigned int result=0;
	unsigned char byteL=0,byteH=0;
  ch_num=ch_num<<6;//Set Channel Number
	IOCLR0=CS0;//Select Slave
	
	spi0(0X06);//M->S 
	byteH=spi0(ch_num);//M->S
	byteL=spi0(0X00);
	IOSET0=CS0;
	
	byteH=byteH&0X0F;//Mask Higher Nibble
	result=(byteH<<8)|byteL;//Merge ADC result
	return result;
}
