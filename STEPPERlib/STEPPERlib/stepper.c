/*
 * stepper.c
 *
 *  Created on: 8 lis 2019
 *      Author: norbe
 */

#include <avr/io.h>
#include <avr/interrupt.h>

#include "stepper.h"

#if _STEPPER_ENABLE == 1

volatile static uint8_t stepperTimerFlag;
volatile static uint8_t stepperMsCounter;
volatile static uint8_t stepperSpeed;

uint8_t stepperEmergencyFlag = 0;			// 1 - emergency stop (for example: too small distance from an obstacle


//--------------------------------------------------------------------------
//						CONVERSION OF DEGREES TO STEPS
//--------------------------------------------------------------------------
/*static inline uint16_t angleCalc(uint16_t angle){
	angle = (angle*FULL_REV)/360;
	return angle;
}*/
//--------------------------------------------------------------------------
//					CONVERSION OF STEPS PER SECOND TO mS
//--------------------------------------------------------------------------
/*
static inline float speedCalc(float speed){
	speed = (1/speed)*1000;
	return speed;
}
*/

//--------------------------------------------------------------------------
//						 STEPPER INITIALIZATION
//--------------------------------------------------------------------------

void stepperInit(void){
#if F_CPU == 8000000UL
	// CTC mode, prescaler /256, time base 1ms, ATmega 88/168/328
	TCCR0A |= (1<<WGM01);
	TCCR0B |= (1<<CS02);
 	OCR0A = 30;
	TIMSK0 |= (1<<OCIE0A);
#endif

#if F_CPU == 16000000UL
 	// CTC mode, prescaler /256, time base 1ms, ATmega 88/168/328
	TCCR0A |= (1<<WGM01);
	TCCR0A |= (1<<CS02);
	TIMSK0 |= (1<<OCIE0A);
 	OCR0A = 61;
#endif
 	sei();


	// Dir out
#if _STEPPER_QUANTITY >= 1
	DDR(_STEPPER1_PORT1) |= (1<<_STEPPER1_PIN1);
	DDR(_STEPPER1_PORT2) |= (1<<_STEPPER1_PIN2);
	DDR(_STEPPER1_PORT3) |= (1<<_STEPPER1_PIN3);
	DDR(_STEPPER1_PORT4) |= (1<<_STEPPER1_PIN4);
#endif


#if _STEPPER_QUANTITY >= 2
	DDR(_STEPPER2_PORT1) |= (1<<_STEPPER2_PIN1);
	DDR(_STEPPER2_PORT2) |= (1<<_STEPPER2_PIN2);
	DDR(_STEPPER2_PORT3) |= (1<<_STEPPER2_PIN3);
	DDR(_STEPPER2_PORT4) |= (1<<_STEPPER2_PIN4);
#endif


#if _STEPPER_QUANTITY >= 3
	DDR(_STEPPER3_PORT1) |= (1<<_STEPPER3_PIN1);
	DDR(_STEPPER3_PORT2) |= (1<<_STEPPER3_PIN2);
	DDR(_STEPPER3_PORT3) |= (1<<_STEPPER3_PIN3);
	DDR(_STEPPER3_PORT4) |= (1<<_STEPPER3_PIN4);
#endif


#if _STEPPER_QUANTITY >= 4
	DDR(_STEPPER4_PORT1) |= (1<<_STEPPER4_PIN1);
	DDR(_STEPPER4_PORT2) |= (1<<_STEPPER4_PIN2);
	DDR(_STEPPER4_PORT3) |= (1<<_STEPPER4_PIN3);
	DDR(_STEPPER4_PORT4) |= (1<<_STEPPER4_PIN4);
#endif

	// Putting stepper pins low
#if _STEPPER_QUANTITY >= 1
	PORT(_STEPPER1_PORT1) &= ~(1<<_STEPPER1_PIN1);
	PORT(_STEPPER1_PORT2) &= ~(1<<_STEPPER1_PIN2);
	PORT(_STEPPER1_PORT3) &= ~(1<<_STEPPER1_PIN3);
	PORT(_STEPPER1_PORT4) &= ~(1<<_STEPPER1_PIN4);
#endif


#if _STEPPER_QUANTITY >= 2
	PORT(_STEPPER2_PORT1) &= ~(1<<_STEPPER2_PIN1);
	PORT(_STEPPER2_PORT2) &= ~(1<<_STEPPER2_PIN2);
	PORT(_STEPPER2_PORT3) &= ~(1<<_STEPPER2_PIN3);
	PORT(_STEPPER2_PORT4) &= ~(1<<_STEPPER2_PIN4);
#endif


#if _STEPPER_QUANTITY >= 3
	PORT(_STEPPER3_PORT1) &= ~(1<<_STEPPER3_PIN1);
	PORT(_STEPPER3_PORT2) &= ~(1<<_STEPPER3_PIN2);
	PORT(_STEPPER3_PORT3) &= ~(1<<_STEPPER3_PIN3);
	PORT(_STEPPER3_PORT4) &= ~(1<<_STEPPER3_PIN4);
#endif


#if _STEPPER_QUANTITY >= 4
	PORT(_STEPPER4_PORT1) &= ~(1<<_STEPPER4_PIN1);
	PORT(_STEPPER4_PORT2) &= ~(1<<_STEPPER4_PIN2);
	PORT(_STEPPER4_PORT3) &= ~(1<<_STEPPER4_PIN3);
	PORT(_STEPPER4_PORT4) &= ~(1<<_STEPPER4_PIN4);
#endif
}

//--------------------------------------------------------------------------
//						 STEPPER MOVING FUNCTIONS
//--------------------------------------------------------------------------

void stepperGoLeft(uint8_t stepperNumber, uint16_t stepsQuantity, uint8_t stepDelay){

	stepperSpeed = stepDelay;
	static uint8_t st;
	uint16_t stepCnt = 0;

	while(stepCnt <= stepsQuantity && !stepperEmergencyFlag){
			if(stepperTimerFlag){
#if _STEPPER_QUANTITY >= 1

			switch(stepperNumber){
			case 1:
				if(st == 0) {_STEPPER1_STEP4;}
				if(st == 1) {_STEPPER1_STEP3;}
				if(st == 2) {_STEPPER1_STEP2;}
				if(st == 3) {_STEPPER1_STEP1;}
				if(++st > 3) st = 0;
				break;
#endif
#if	_STEPPER_QUANTITY >= 2
			case 2:
				if(st == 0) {_STEPPER2_STEP4;}
				if(st == 1) {_STEPPER2_STEP3;}
				if(st == 2) {_STEPPER2_STEP2;}
				if(st == 3) {_STEPPER2_STEP1;}
				if(++st > 3) st = 0;
				break;
#endif

#if _STEPPER_QUANTITY >= 3
			case 3:
				if(st == 0) {_STEPPER3_STEP4;}
				if(st == 1) {_STEPPER3_STEP3;}
				if(st == 2) {_STEPPER3_STEP2;}
				if(st == 3) {_STEPPER3_STEP1;}
				if(++st > 3) st = 0;
				break;
#endif

#if _STEPPER_QUANTITY >= 4
			case 4:
				if(st == 0) {_STEPPER4_STEP4;}
				if(st == 1) {_STEPPER4_STEP3;}
				if(st == 2) {_STEPPER4_STEP2;}
				if(st == 3) {_STEPPER4_STEP1;}
				if(++st > 3) st = 0;
				break;
#endif


			}
			stepCnt++;
			stepperTimerFlag = 0;
    }
  }
}

void stepperGoRight(uint8_t stepperNumber, uint16_t stepsQuantity, uint8_t stepDelay){


	stepperSpeed = stepDelay;
	static uint8_t st;
	uint16_t stepCnt = 0;

	while(stepCnt <= stepsQuantity && !stepperEmergencyFlag){
			if(stepperTimerFlag ){
#if _STEPPER_QUANTITY >= 1

			switch(stepperNumber){
			case 1:
				if(st == 0) {_STEPPER1_STEP1;}
				if(st == 1) {_STEPPER1_STEP2;}
				if(st == 2) {_STEPPER1_STEP3;}
				if(st == 3) {_STEPPER1_STEP4;}
				if(++st > 3) st = 0;
				break;
#endif
#if	_STEPPER_QUANTITY >= 2
			case 2:
				if(st == 0) {_STEPPER2_STEP1;}
				if(st == 1) {_STEPPER2_STEP2;}
				if(st == 2) {_STEPPER2_STEP3;}
				if(st == 3) {_STEPPER2_STEP4;}
				if(++st > 3) st = 0;
				break;
#endif

#if _STEPPER_QUANTITY >= 3
			case 3:
				if(st == 0) {_STEPPER3_STEP1;}
				if(st == 1) {_STEPPER3_STEP2;}
				if(st == 2) {_STEPPER3_STEP3;}
				if(st == 3) {_STEPPER3_STEP4;}
				if(++st > 3) st = 0;
				break;
#endif

#if _STEPPER_QUANTITY >= 4
			case 4:
				if(st == 0) {_STEPPER4_STEP1;}
				if(st == 1) {_STEPPER4_STEP2;}
				if(st == 2) {_STEPPER4_STEP3;}
				if(st == 3) {_STEPPER4_STEP4;}
				if(++st > 3) st = 0;
				break;
#endif

			}
			stepCnt++;
			stepperTimerFlag = 0;
    }
  }
}

#if _USE_ROBOT_FUNC == 1 && _STEPPER_QUANTITY == 4

void robotStepperGo(_stepperRobotDir dir, uint16_t stepsQuantity, uint8_t stepDelay){

	stepperSpeed = stepDelay;
	static uint8_t st;
	uint16_t stepCnt = 0;

	while(stepCnt <= stepsQuantity){
		if(stepperTimerFlag){

			if(dir == stFW){

				// Stepper1 and Stepper2 - Left motors, Rotate right
				// Stepper3 and Stepper4 - Right motors - Rotate left

				// Stepper1 and Stepper3 - Front motors
				// Stepper2 and Stepper4 - Rear motors

				if(st == 0) {
					_STEPPER1_STEP1;
					_STEPPER2_STEP1;
					_STEPPER3_STEP4;
					_STEPPER4_STEP4;
				}
				if(st == 1) {
					_STEPPER1_STEP2;
					_STEPPER2_STEP2;
					_STEPPER3_STEP3;
					_STEPPER4_STEP3;
				}
				if(st == 2) {
					_STEPPER1_STEP3;
					_STEPPER2_STEP3;
					_STEPPER3_STEP2;
					_STEPPER4_STEP2;
				}
				if(st == 3) {
					_STEPPER1_STEP4;
					_STEPPER2_STEP4;
					_STEPPER3_STEP1;
					_STEPPER4_STEP1;
				}
				if(++st > 3) st = 0;
			}

			if(dir == stRW){

				if(st == 0) {
					_STEPPER3_STEP1;
					_STEPPER4_STEP1;
					_STEPPER1_STEP4;
					_STEPPER2_STEP4;
				}
				if(st == 1) {
					_STEPPER3_STEP2;
					_STEPPER4_STEP2;
					_STEPPER1_STEP3;
					_STEPPER2_STEP3;
				}
				if(st == 2) {
					_STEPPER3_STEP3;
					_STEPPER4_STEP3;
					_STEPPER1_STEP2;
					_STEPPER2_STEP2;
				}
				if(st == 3) {
					_STEPPER3_STEP4;
					_STEPPER4_STEP4;
					_STEPPER1_STEP1;
					_STEPPER2_STEP1;
				}
				if(++st > 3) st = 0;
			}
			stepCnt++;
			stepperTimerFlag = 0;
		}
	}
}



#endif


//--------------------------------------------------------------------------
//						  ISR - time base 1ms
//--------------------------------------------------------------------------
ISR(TIMER0_COMPA_vect){
	if(++stepperMsCounter >= stepperSpeed){
		stepperTimerFlag = 1;
		stepperMsCounter = 0;
	}

}
#endif
