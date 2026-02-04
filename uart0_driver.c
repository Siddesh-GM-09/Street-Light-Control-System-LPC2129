#include<lpc21xx.h>
//UART0 Initialization
void uart0_init(unsigned int baud){
	int pclk=0,result=0;
	int arr[]={15,60,30,15,60};
	pclk=arr[VPBDIV]*1000000;
	result=pclk/(16*baud);
	PINSEL0|=0X5;//Important
	U0LCR=0X83;
	U0DLL=result&0XFF;
	U0DLM=(result>>8)&0XFF;
	U0LCR=0X03;
}
//UART0 Transmitter Section
#define THRE (U0LSR>>5&1)
void uart0_tx(unsigned char data){
	U0THR=data;
	while(THRE==0);
}
//UART0 Reciver Section
#define RDR (U0LSR&1)
unsigned char uart0_rx(){
	while(RDR==0);
	return U0RBR;
}
//UART0 Transmitter Section String
void uart0_tx_string(char *ptr){
	while(*ptr!='\0'){
		uart0_tx(*ptr);
		ptr++;
	}
}
//UART0 Reciver Section String
void uart0_rx_string(char *ptr,int len){
	int i;
	for(i=0;i<len;i++){
		while(RDR==0);
		ptr[i]=U0RBR;
		if(*ptr=='\r'){
			break;
		}
	}
	ptr[i]='\0';
}

void uart0_tx_integer(int num){
	char a[10];
	int i;
	if(num<0){
		uart0_tx('-');
		num=-num;
	}
	if(num==0){
		uart0_tx('0');
		return;
	}
	for(i=0;num;num=num/10,i++){
		a[i]=num%10+48;
	}
	for(--i;i>=0;i--){
		uart0_tx(a[i]);
	}
}
void uart0_tx_float(float f)
{
	int num;
	if(f<0){
		uart0_tx('-');
		f=-f;
	}
	if(f==0){
		uart0_tx_string("0.0");
		return;
	}
	num=f;
	uart0_tx_integer(num);
	uart0_tx('.');
	num=(f-num)*1000000;
	uart0_tx_integer(num);
}


