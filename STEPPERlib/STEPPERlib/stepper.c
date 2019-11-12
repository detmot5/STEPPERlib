/*
 * stepper.c
 *
 *  Created on: 8 lis 2019
 *      Author: norbe
 */

#include <avr/io.h>
#include <avr/interrupt.h>

#include "stepper.h"

volatile uint8_t timerFlag;
volatile uint8_t msCounter;
volatile uint8_t stepperSpeed;

//--------------------------------------------------------------------------
//						CONVERSION OF DEGREES TO STEPS
//--------------------------------------------------------------------------
static inline uint16_t angleCalc(uint16_t angle){
	angle = (angle*FULL_REV)/360;
	return angle;
}

//--------------------------------------------------------------------------
//						 STEPPER INITIALIZATION
//--------------------------------------------------------------------------

void stepperInit(void){
#if F_CPU == 8000000
	// CTC mode, prescaler /256, time base 1ms, ATmega 88/168/328
	TCCR0A |= (1<<WGM01);
	TCCR0A |= (1<<CS02);
	TIMSK0 |= (1<<OCIE0A);
 	OCR0A = 30;
#endif

	// Dir out
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

	// Putting stepper pins low
#if STEPPER_QUANTITY >= 1
	PORT(STEPPER1_PORT1) &= ~(1<<STEPPER1_PIN1);
	PORT(STEPPER1_PORT2) &= ~(1<<STEPPER1_PIN2);
	PORT(STEPPER1_PORT3) &= ~(1<<STEPPER1_PIN3);
	PORT(STEPPER1_PORT4) &= ~(1<<STEPPER1_PIN4);
#endif


#if STEPPER_QUANTITY >= 2
	PORT(STEPPER2_PORT1) &= ~(1<<STEPPER2_PIN1);
	PORT(STEPPER2_PORT2) &= ~(1<<STEPPER2_PIN2);
	PORT(STEPPER2_PORT3) &= ~(1<<STEPPER2_PIN3);
	PORT(STEPPER2_PORT4) &= ~(1<<STEPPER2_PIN4);
#endif


#if STEPPER_QUANTITY >= 3
	PORT(STEPPER3_PORT1) &= ~(1<<STEPPER3_PIN1);
	PORT(STEPPER3_PORT2) &= ~(1<<STEPPER3_PIN2);
	PORT(STEPPER3_PORT3) &= ~(1<<STEPPER3_PIN3);
	PORT(STEPPER3_PORT4) &= ~(1<<STEPPER3_PIN4);
#endif


#if STEPPER_QUANTITY >= 4
	PORT(STEPPER4_PORT1) &= ~(1<<STEPPER4_PIN1);
	PORT(STEPPER4_PORT2) &= ~(1<<STEPPER4_PIN2);
	PORT(STEPPER4_PORT3) &= ~(1<<STEPPER4_PIN3);
	PORT(STEPPER4_PORT4) &= ~(1<<STEPPER4_PIN4);
#endif
}

void stepperWriteLeft(uint8_t Stepper_number, uint8_t Angle, uint8_t Speed){
	stepperSpeed = Speed;
	static uint8_t st;
	static uint8_t stepCnt = angleCalc(Angle);
	if(timerFlag || stepCnt){

#if STEPPER_QUANTITY >= 1
	switch(Stepper_number){
	case 1:
		if(st == 0) STEPPER1_STEP1;
		if(st == 1) STEPPER1_STEP2;
		if(st == 2) STEPPER1_STEP3;
		if(st == 3) STEPPER1_STEP4;
		if(++st > 3) st = 0;
		break;
#endif

#if	STEPPER_QUANTITY >= 2
	case 2:
		if(st == 0) STEPPER2_STEP1;
		if(st == 1) STEPPER2_STEP2;
		if(st == 2) STEPPER2_STEP3;
		if(st == 3) STEPPER2_STEP4;
		if(++st > 3) st = 0;
		break;
#endif

#if STEPPER_QUANTITY >= 3
	case 3:
		if(st == 0) STEPPER3_STEP1;
		if(st == 1) STEPPER3_STEP2;
		if(st == 2) STEPPER3_STEP3;
		if(st == 3) STEPPER3_STEP4;
		if(++st > 3) st = 0;
		break;
#endif

#if STEPPER_QUANTITY >= 4
	case 4:
		if(st == 0) STEPPER4_STEP1;
		if(st == 1) STEPPER4_STEP2;
		if(st == 2) STEPPER4_STEP3;
		if(st == 3) STEPPER4_STEP4;
		if(++st > 3) st = 0;
		break;
#endif
	}
	timerFlag = 0;
  }
}
ISR(TIMER0_COMPA_vect){
	if(++msCounter > (1/stepperSpeed)){
		timerFlag = 1;
		msCounter = 0;
	}
}
