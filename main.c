#include<lpc21xx.h>
#include "header.h"
#define Light (1<<9)
int main(){
	IODIR0=Light;
	IOSET0=Light;
	spi0_init();
	lcd_init();
	uart0_init(9600);
	uart0_tx_string("ADC Test\r\n");
	//LDR
	while(1){
		LDR();
		lcd_cmd(0X80);
		if(Intensity>50.0f){
			IOCLR0=Light;
			lcd_string("LIGHT ON ");
		}
		else{
			IOSET0=Light;
			lcd_string("LIGHT OFF");
		}
	}
}
