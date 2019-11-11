/*
 * stepper.c
 *
 *  Created on: 8 lis 2019
 *      Author: norbe
 */

#include <avr/io.h>
#include <avr/interrupt.h>

#include "stepper.h"

//--------------------------------------------------------------------------
//							 STEPPER PIN DIR
//--------------------------------------------------------------------------
static inline void stepper_dir_out(void){
#if STEPPER_QUANTITY >= 1
DDR(STEPPER1_PORT1) |= (1<<STEPPER1_PIN1);
DDR(STEPPER1_PORT2) |= (1<<STEPPER1_PIN2);
DDR(STEPPER1_PORT3) |= (1<<STEPPER1_PIN3);
DDR(STEPPER1_PORT4) |= (1<<STEPPER1_PIN4);
#endif


#if STEPPER_QUANTITY >= 2
DDR(STEPPER2_PORT1) |= (1<<STEPPER2_PIN1);
DDR(STEPPER2_PORT2) |= (1<<STEPPER2_PIN2);
DDR(STEPPER2_PORT3) |= (1<<STEPPER2_PIN3);
DDR(STEPPER2_PORT4) |= (1<<STEPPER2_PIN4);
#endif


#if STEPPER_QUANTITY >= 3
DDR(STEPPER3_PORT1) |= (1<<STEPPER3_PIN1);
DDR(STEPPER3_PORT2) |= (1<<STEPPER3_PIN2);
DDR(STEPPER3_PORT3) |= (1<<STEPPER3_PIN3);
DDR(STEPPER3_PORT4) |= (1<<STEPPER3_PIN4);
#endif


#if STEPPER_QUANTITY >= 4
DDR(STEPPER4_PORT1) |= (1<<STEPPER4_PIN1);
DDR(STEPPER4_PORT2) |= (1<<STEPPER4_PIN2);
DDR(STEPPER4_PORT3) |= (1<<STEPPER4_PIN3);
DDR(STEPPER4_PORT4) |= (1<<STEPPER4_PIN4);
#endif
}

//--------------------------------------------------------------------------
//						CONVERSION OF DEGREES TO STEPS
//--------------------------------------------------------------------------
static inline uint16_t angleCalc(uint16_t angle){
	angle = (angle*FULL_REV)/360;
	return angle;
}

void stepperInit(void){
	stepper_dir_out();
}
