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
 *	Lib has also function for drive robot's wheels (can be switched off below):
 *
 *	robotStepperGo - drive a robot for a given distance quantity of steps and delay  between them
 *
 *	Stepper1 and Stepper3 are front motors
 *	Stepper2 and Stepper3 are rear motors
 *	Stepper1 and Stepper2 are left motors
 *	Stepper3 and Stepper4 are right motors
 *
 * Library takes from ~500 to 1500~ bytes of flash (depends on the settings)
 *
 * Using in own projects and modyfiying is fully allowed.
 *
 * Author: Norbert Bielak
 * Created: 23 Nov 2019
 *
 * stepper.h
*/

#ifndef STEPPERLIB_STEPPER_H_
#define STEPPERLIB_STEPPER_H_


//--------------------------------------------------------------------------
//						  	LIBRARY CONFIG
//--------------------------------------------------------------------------
#define _STEPPER_ENABLE     	1

#define _STEPPER_QUANTITY 		1			// Max 4

#define _BIPOLAR_MODE			0			// 1 - Bipolar motor, 0 - Unipolar motor (coming soon)

#define _USE_ROBOT_FUNC         0			// Using robot functions (go forward or backward)

#define _STEPS_PER_REV    		32  		// Depends on choosed stepper motor
#define _GEAR_RED				64 			// if none, type 1
#define FULL_REV   _STEPS_PER_REV * _GEAR_RED
//^^Can be used in user's function, for example: stepperGoLeft(1,FULL_REV/2,3);

//--------------------------------------------------------------------------
//						    PIN/PORT SETTINGS
//--------------------------------------------------------------------------


#if _STEPPER_QUANTITY >= 1
#define _STEPPER1_PORT1 		C
#define _STEPPER1_PIN1			5

#define _STEPPER1_PORT2 		C
#define _STEPPER1_PIN2 			4

#define _STEPPER1_PORT3 		C
#define _STEPPER1_PIN3 			3

#define _STEPPER1_PORT4			C
#define _STEPPER1_PIN4			2
#endif


#if _STEPPER_QUANTITY >= 2
#define _STEPPER2_PORT1 		C
#define _STEPPER2_PIN1			1

#define _STEPPER2_PORT2 		C
#define _STEPPER2_PIN2			0

#define _STEPPER2_PORT3 		B
#define _STEPPER2_PIN3 			1

#define _STEPPER2_PORT4			B
#define _STEPPER2_PIN4			0
#endif


#if _STEPPER_QUANTITY >= 3
#define _STEPPER3_PORT1 		D
#define _STEPPER3_PIN1			7

#define _STEPPER3_PORT2 		D
#define _STEPPER3_PIN2			6

#define _STEPPER3_PORT3 		D
#define _STEPPER3_PIN3 			5

#define _STEPPER3_PORT4			B
#define _STEPPER3_PIN4			7
#endif


#if _STEPPER_QUANTITY >= 4
#define _STEPPER4_PORT1 		D
#define _STEPPER4_PIN1			4

#define _STEPPER4_PORT2 		D
#define _STEPPER4_PIN2			3

#define _STEPPER4_PORT3 		D
#define _STEPPER4_PIN3 			2

#define _STEPPER4_PORT4			D
#define _STEPPER4_PIN4			1
#endif

//--------------------------------------------------------------------------
// 					 SIMPLYFYING PORT ACCESS MACROS
//--------------------------------------------------------------------------

// PORT - output
#define PORT(x) SPORT(x)
#define SPORT(x) (PORT##x)
// PIN - input
#define PIN(x) SPIN(x)
#define SPIN(x) (PIN##x)
// DDR - direction
#define DDR(x) SDDR(x)
#define SDDR(x) (DDR##x)

//--------------------------------------------------------------------------
//						 LOGIC STATE DEFINES
//--------------------------------------------------------------------------

#if _STEPPER_QUANTITY >= 1
#define _SET_STEPPER1_1 PORT(_STEPPER1_PORT1) |= (1<<_STEPPER1_PIN1)
#define _CLR_STEPPER1_1 PORT(_STEPPER1_PORT1) &= ~(1<<_STEPPER1_PIN1)

#define _SET_STEPPER1_2 PORT(_STEPPER1_PORT2) |= (1<<_STEPPER1_PIN2)
#define _CLR_STEPPER1_2 PORT(_STEPPER1_PORT2) &= ~(1<<_STEPPER1_PIN2)

#define _SET_STEPPER1_3 PORT(_STEPPER1_PORT3) |= (1<<_STEPPER1_PIN3)
#define _CLR_STEPPER1_3 PORT(_STEPPER1_PORT3) &= ~(1<<_STEPPER1_PIN3)

#define _SET_STEPPER1_4 PORT(_STEPPER1_PORT4) |= (1<<_STEPPER1_PIN4)
#define _CLR_STEPPER1_4 PORT(_STEPPER1_PORT1) &= ~(1<<_STEPPER1_PIN4)
#endif



#if _STEPPER_QUANTITY >= 2
#define _SET_STEPPER2_1 PORT(_STEPPER2_PORT1) |= (1<<_STEPPER2_PIN1)
#define _CLR_STEPPER2_1 PORT(_STEPPER2_PORT1) &= ~(1<<_STEPPER2_PIN1)

#define _SET_STEPPER2_2 PORT(_STEPPER2_PORT2) |= (1<<_STEPPER2_PIN2)
#define _CLR_STEPPER2_2 PORT(_STEPPER2_PORT2) &= ~(1<<_STEPPER2_PIN2)

#define _SET_STEPPER2_3 PORT(_STEPPER2_PORT3) |= (1<<_STEPPER2_PIN3)
#define _CLR_STEPPER2_3 PORT(_STEPPER2_PORT3) &= ~(1<<_STEPPER2_PIN3)

#define _SET_STEPPER2_4 PORT(_STEPPER2_PORT4) |= (1<<_STEPPER2_PIN4)
#define _CLR_STEPPER2_4 PORT(_STEPPER2_PORT4) &= ~(1<<_STEPPER2_PIN4)
#endif



#if _STEPPER_QUANTITY >= 3
#define _SET_STEPPER3_1 PORT(_STEPPER3_PORT1) |= (1<<_STEPPER3_PIN1)
#define _CLR_STEPPER3_1 PORT(_STEPPER3_PORT1) &= ~(1<<_STEPPER3_PIN1)

#define _SET_STEPPER3_2 PORT(_STEPPER3_PORT2) |= (1<<_STEPPER3_PIN2)
#define _CLR_STEPPER3_2 PORT(_STEPPER3_PORT2) &= ~(1<<_STEPPER3_PIN2)

#define _SET_STEPPER3_3 PORT(_STEPPER3_PORT3) |= (1<<_STEPPER3_PIN3)
#define _CLR_STEPPER3_3 PORT(_STEPPER3_PORT3) &= ~(1<<_STEPPER3_PIN3)

#define _SET_STEPPER3_4 PORT(_STEPPER3_PORT4) |= (1<<_STEPPER3_PIN4)
#define _CLR_STEPPER3_4 PORT(_STEPPER3_PORT4) &= ~(1<<_STEPPER3_PIN4)
#endif



#if _STEPPER_QUANTITY >= 4
#define _SET_STEPPER4_1 PORT(_STEPPER4_PORT1) |= (1<<_STEPPER4_PIN1)
#define _CLR_STEPPER4_1 PORT(_STEPPER4_PORT1) &= ~(1<<_STEPPER4_PIN1)

#define _SET_STEPPER4_2 PORT(_STEPPER4_PORT2) |= (1<<_STEPPER4_PIN2)
#define _CLR_STEPPER4_2 PORT(_STEPPER4_PORT2) &= ~(1<<_STEPPER4_PIN2)

#define _SET_STEPPER4_3 PORT(_STEPPER4_PORT3) |= (1<<_STEPPER4_PIN3)
#define _CLR_STEPPER4_3 PORT(_STEPPER4_PORT3) &= ~(1<<_STEPPER4_PIN3)

#define _SET_STEPPER4_4 PORT(_STEPPER4_PORT4) |= (1<<_STEPPER4_PIN4)
#define _CLR_STEPPER4_4 PORT(_STEPPER4_PORT4) &= ~(1<<_STEPPER4_PIN4)
#endif




//--------------------------------------------------------------------------
//						 	STEPS DEFINES
//--------------------------------------------------------------------------

#if _STEPPER_QUANTITY >= 1
#define  _STEPPER1_STEP1 	_SET_STEPPER1_1; _CLR_STEPPER1_2; _CLR_STEPPER1_3; _CLR_STEPPER1_4
#define  _STEPPER1_STEP2	_SET_STEPPER1_2; _CLR_STEPPER1_1; _CLR_STEPPER1_3; _CLR_STEPPER1_4
#define  _STEPPER1_STEP3 	_SET_STEPPER1_3; _CLR_STEPPER1_1; _CLR_STEPPER1_2; _CLR_STEPPER1_4
#define  _STEPPER1_STEP4	_SET_STEPPER1_4; _CLR_STEPPER1_1; _CLR_STEPPER1_2; _CLR_STEPPER1_3
#endif


#if _STEPPER_QUANTITY >= 2
#define  _STEPPER2_STEP1	_SET_STEPPER2_1; _CLR_STEPPER2_2; _CLR_STEPPER2_3; _CLR_STEPPER2_4
#define  _STEPPER2_STEP2	_SET_STEPPER2_2; _CLR_STEPPER2_1; _CLR_STEPPER2_3; _CLR_STEPPER2_4
#define  _STEPPER2_STEP3	_SET_STEPPER2_3; _CLR_STEPPER2_1; _CLR_STEPPER2_2; _CLR_STEPPER2_4
#define  _STEPPER2_STEP4	_SET_STEPPER2_4; _CLR_STEPPER2_1; _CLR_STEPPER2_2; _CLR_STEPPER2_3
#endif


#if _STEPPER_QUANTITY >= 3
#define  _STEPPER3_STEP1	_SET_STEPPER3_1; _CLR_STEPPER3_2; _CLR_STEPPER3_3; _CLR_STEPPER3_4
#define  _STEPPER3_STEP2	_SET_STEPPER3_2; _CLR_STEPPER3_1; _CLR_STEPPER3_3; _CLR_STEPPER3_4
#define  _STEPPER3_STEP3	_SET_STEPPER3_3; _CLR_STEPPER3_1; _CLR_STEPPER3_2; _CLR_STEPPER3_4
#define  _STEPPER3_STEP4	_SET_STEPPER3_4; _CLR_STEPPER3_1; _CLR_STEPPER3_2; _CLR_STEPPER3_3
#endif


#if _STEPPER_QUANTITY >= 4
#define  _STEPPER4_STEP1	_SET_STEPPER4_1; _CLR_STEPPER4_2; _CLR_STEPPER4_3; _CLR_STEPPER4_4
#define  _STEPPER4_STEP2	_SET_STEPPER4_2; _CLR_STEPPER4_1; _CLR_STEPPER4_3; _CLR_STEPPER4_4
#define  _STEPPER4_STEP3	_SET_STEPPER4_3; _CLR_STEPPER4_1; _CLR_STEPPER4_2; _CLR_STEPPER4_4
#define  _STEPPER4_STEP4	_SET_STEPPER4_4; _CLR_STEPPER4_1; _CLR_STEPPER4_2; _CLR_STEPPER4_3
#endif

//--------------------------------------------------------------------------
//						DECLARATIONS OF FUNCTIONS AND VARIABLES
//--------------------------------------------------------------------------

extern uint8_t stepperEmergencyFlag;												// 1 - emergency stop (for example: too small distance from an obstacle

void stepperInit(void);
void stepperGoLeft(uint8_t stepperNumber, uint16_t stepsQuantity, uint8_t stepDelay);
void stepperGoRight(uint8_t stepperNumber,uint16_t stepsQuantity, uint8_t stepDelay);


// 						    ROBOT CONTROL TYPES AND FUNCTIONS
#if _USE_ROBOT_FUNC == 1 && _STEPPER_QUANTITY == 4


typedef enum _stepperDir {stRW, stFW}_stepperRobotDir;				// FW - Forward RW - Reverse

void robotStepperGo(_stepperRobotDir dir, uint16_t stepsQuantity, uint8_t stepDelay);


#endif

#endif /* STEPPERLIB_STEPPER_H_ */
