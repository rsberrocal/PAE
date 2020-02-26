#include "msp.h"
#include <msp432p401r.h>
#include <stdio.h>
#include <stdint.h>
#include "lib_PAE2.h" //Libreria grafica + configuracion reloj MSP432

//Variables que controlan los estados
uint8_t status = 0;
uint8_t last_status = 8;
/**
 * Estados
 * Boton S1 -> 1
 * Boton S2 -> 2
 * Joy Izq  -> 3
 * Joy Der  -> 4
 * Joy Up   -> 5
 * Joy Down -> 6
 * Joy Cent -> 7
 **/


void setPins(void){
    //DIR I = 0 O = 1. OUT I = 1 O = 0
    //Leds
    P2DIR |= 0x50; //OR para no modificar valores anteriores, y dejar a 1 los pins 6 y 4
    P2OUT &= ~0x50;

    P5DIR |= 0x40; //Led_B Puerto 5 Pin 6
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
    P4DIR &= ~0xA2; //Joy derecha, Joy izquierda, Joy center
    P4SEL0 = P4SEL1 = 0x00;  //Se definen los puertos con: bit1-> Center, bit5-> Derecha, bit7->Izquierda,
    P4OUT |= 0xA2;
    P4REN |= 0xA2;

    P5DIR &= ~0x30; //Joy up, Joy down
    P5SEL0 = P5SEL1 = 0x00;
    P5OUT |= 0x30;
    P5REN |= 0x30;

}

//delay de tiempo, de 0 hasta lo indicado
void delay_t(uint32_t temps){
    volatile uint32_t i = 0;
    do{
        i = i + 1;
        //quizas hacer un print de la i y ver su funcionamiento
        //quizas hay que llamar a una funcion delay() y hacer un delay de un segundo
        //de hecho, esto seria tonteria
    }while(i<temps);
}

//funcion que gestiona el led rgb, para cada parametro acepta solo 0 y 1, 0 apagado, 1 encendido
void handleLedRGB(uint32_t red, uint32_t green, uint32_t blue){
    //ver como inciar el led rgb
}

/**
 * main.c
 */
void main(void)
{
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;		// stop watchdog timer

	init_ucs_24MHz();       //Ajustes del clock (Unified Clock System)

	setPins(); //Se llama para iniciar los botones

	//mirar si hay que pillar interrupciones, en la P1 se hacia
	//Config de pantalla, debug

	//Se inicia un bucle infinito hasta que se detiene la ejecucion
	do{
	    if(last_status != status){ //Solo salta cuando el ha habido un cambio de estados, se podria usar un flag
	        last_status = status;
	        //Mirar funciones de interrepcion, como funcionan, no se llaman en algun lado o se llaman automatico question
	        switch(status){ //estados del 1 al 8; definidos arriba
	            case 1:
	                //Boton1
	                //Encender las 3 luces
	                break;
	            case 2:
	                //Boton2
	                //Apagar todas las luces
	                break;
	            case 3:
	                //Joy Izquierda
	                //Encender las 3 luces
	                break;
	            case 4:
	                //Joy Derecha
	                //Encender rojo y verde
	                break;
	            case 5:
	                //Joy Up
	                //Encender rojo y azul
	                break;
	            case 6:
	                //Joy Down
	                //Encender verde y azul
	                break;
	            case 7:
	                //Joy Center
	                //Se invierten las señales
	                break;

	        }
	    }
	}while(1)


}
