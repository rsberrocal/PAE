#include "msp.h"
#include <msp432p401r.h>
#include <stdio.h>
#include <stdint.h>
#include "lib_PAE2.h" //Libreria grafica + configuracion reloj MSP432


void setPins(void){
    //DIR I = 0 O = 1. OUT I = 1 O = 0
    //Leds
    P2DIR |= 0x50; //OR para no modificar valores anteriores, y dejar a 1 los pins 6 y 4
    P2OUT &= ~0x50;

    P5DIR |= 0x40;
    P5OUT &= ~0x40;

    //Botones
    //Boton S1
    P5SEL0 = P5SEL1 = 0x00;
    P5DIR &= ~0x02;
    P5OUT |= 0x02;
    P5REN |= 0x02;

    //Boton S2
    P3SEL0 = P3SEL1 = 0x00;
    P3DIR &= ~0x20;
    P3OUT |= 0x20;
    P3REN |= 0x20;

    //Joystick
    P4DIR &= ~0xA2;
    P4SEL0 = P4SEL1 = 0x00;  //Se definen los puertos con: bit1-> Center, bit5-> Derecha, bit7->Izquierda,
    P4OUT |= 0xA2;
    P4REN |= 0xA2;

    P5DIR &= ~0x30;
    P5SEL0 = P5SEL1 = 0x00;
    //P5OUT |= 0x30;
    //P5REN |= 0x30;

}

/**
 * main.c
 */
void main(void)
{
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;		// stop watchdog timer

	init_ucs_24MHz();       //Ajustes del clock (Unified Clock System)


}
