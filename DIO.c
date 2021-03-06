#include "stdtypes.h"
#include "MCAL_PIC18F.h"
#include <pic16/pic18f452.h>

volatile GPIOXX* MPIC_getgpio(u8_t PORTxx){
	GPIOXX* GPIOx;
switch (PORTxx){
case PORTa :
	GPIOx->PORTX=(volatile u8_t *)(0x0F80);
	GPIOx->TRISX=(volatile u8_t *)(0x0F92);
	GPIOx->LATX=(volatile u8_t *)(0x0F89);
	break;return GPIOx;
case PORTb :
	GPIOx->PORTX=(volatile u8_t *)(0x0F81);
	GPIOx->TRISX=(volatile u8_t *)(0x0F93);
	GPIOx->LATX=(volatile u8_t *)(0x0F8A);
	break;return GPIOx;
case PORTc :
	GPIOx->PORTX=(volatile u8_t *)(0x0F82);
	GPIOx->TRISX=(volatile u8_t *)(0x0F94);
	GPIOx->LATX=(volatile u8_t *)(0x0F8B);
	break;return GPIOx;
case PORTd :
	GPIOx->PORTX=(volatile u8_t *)(0x0F83);
	GPIOx->TRISX=(volatile u8_t *)(0x0F95);
	GPIOx->LATX=(volatile u8_t *)(0x0F8C);
	break;return GPIOx;
case PORTe :
	GPIOx->PORTX=(volatile u8_t *)(0x0F84);
	GPIOx->TRISX=(volatile u8_t *)(0x0F96);
	GPIOx->LATX=(volatile u8_t *)(0x0F8D);
	break;return GPIOx;
default:
    return NULL;}

return 0;}
void MPIC_Init_Port(u8_t PORTxx){
if ((PORTxx==PORTd) || (PORTxx==PORTe)) {ADCON1=0xff;}
return;}
void MPIC_SetBitDir( u8_t  PORTxx , u8_t bitx , u8_t dir){
	GPIOXX* gpio=MPIC_getgpio(PORTxx);
	if (dir==INPUT){set_bit(*(gpio->TRISX),bitx);}
			else {clr_bit(*(gpio->TRISX),bitx);}
return;}
void MPIC_SetBitsDir( u8_t  PORTxx , u8_t bitx , u8_t bit_counuter , u8_t dir){
int i ; for (i=0 ; i<bit_counuter;i++){MAVR_SetBitDir(PORTxx,bitx,dir); bitx++;}return ;}
void MPIC_SetPORTDir(u8_t  PORTxx ,u8_t dir){
	GPIOXX* gpio=MPIC_getgpio(PORTxx);
	if (dir==INPUT){*(gpio->TRISX)=PORT_IN;}
			else {*(gpio->TRISX)=PORT_OUT;}
}
void MPIC_SetBitVal( u8_t  PORTxx , u8_t bitx , u8_t val){
	GPIOXX* gpio=MPIC_getgpio(PORTxx);
    if (val==0){set_bit(*(gpio->LATX),bitx);}
    else {clr_bit(*(gpio->LATX),bitx);}
return;}
void MPIC_SetBitSVal( u8_t  PORTxx , u8_t bitx , u8_t val,u8_t bit_counuter){
    GPIOXX* gpio=MPIC_getgpio(PORTxx);
	if (val==0){set_bits(*(gpio->LATX),bitx,val);}
	else if(val==1) {clr_bits(*(gpio->LATX),bitx,val);}
}
void MPIC_SetPORTVal( u8_t  PORTxx , u8_t val ){
GPIOXX* gpio=MPIC_getgpio(PORTxx);	*(gpio->LATX)=val; return;}

u8_t MPIC_GetBitVal ( u8_t  PORTxx , u8_t bitx){
GPIOXX* gpio=MPIC_getgpio(PORTxx);
return get_bit(*(gpio->PORTX),bitx);}
u8_t MPIC_GetPINVal( u8_t  PORTxx ){
    GPIOXX* gpio=MPIC_getgpio(PORTxx);return *(gpio->PORTX);
    }

