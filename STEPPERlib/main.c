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

int main(void){
	stepperInit();

	while(1){
		stepperGoLeft(1,30,400);
		_delay_ms(300);
		stepperGoRight(1,30,400);
		_delay_ms(300);
	}

}
