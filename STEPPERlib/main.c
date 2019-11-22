/* Library for control the ULN2003 stepper motor driver using AVR uC
 *
 * Up to 4 motors can be used
 *
 * Supported F_CPU - 16MHz and 8Mhz
 *
 * Microcontroler used in project - ATmega328p (old AVR's needs change timer settings)
 *
 *	Function list:
 *
 *	stepperInit - Initialization of timers, output pins etc.	Must be called before use any other function.
 *	stepperGoLeft - Choosen motor is moving left for a given quantity of steps and delay between them
 *	stepperGoRight - Choosen motor is moving right for a given quantity of steps and delay between them
 *
 *	Lib has also function for drive robot's wheels (can be switched off below)
 *	Stepper1 and Stepper3 are front motors
 *	Stepper2 and Stepper3 are rear motors
 *	Stepper1 and Stepper2 are left motors
 *	Stepper3 and Stepper4 are right motors
 *
 *
 *
 * Using in own projects and modyfiying is fully allowed.
 *
 * Author: Norbert Bielak
 * Created: 8 Nov 2019
 *
 * main.c
*/

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "STEPPERlib/stepper.h"

#define BUT_TOG (PINB & (1<<PB0))

uint8_t buttonPressed(uint8_t button);
int i = 40;

int main(void){

	stepperInit();
	DDRD |= (1<<PD0);

	while(1){
		robotStepperGo(stFW,10,i--);
		if(i==2) i = 10;
  }
}

uint8_t buttonPressed(uint8_t button){
	if(!button){
		_delay_ms(20);
		if(!button) return 1;
	}
	return 0;
}
