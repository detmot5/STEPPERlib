/*

 * main.c
 *
 *  Created on: 8 lis 2019
 *      Author: norbe

*/

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "STEPPERlib/stepper.h"

#define BUT_TOG (PINB & (1<<PB0))

uint8_t buttonPressed(uint8_t button);

int main(void){

	stepperInit();




	stepperGoRight(3,1024,3);
	stepperGoLeft(3,1024,3);

	while(1){

		//if(buttonPressed(BUT_TOG)){




	//}
  }
}

uint8_t buttonPressed(uint8_t button){
	if(!button){
		_delay_ms(20);
		if(!button) return 1;
	}
	return 0;
}
