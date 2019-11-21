/* Library for stepper motor control with AVR uC.
 *
 *
 */

#ifndef STEPPERLIB_STEPPER_H_
#define STEPPERLIB_STEPPER_H_


//--------------------------------------------------------------------------
//						  	LIBRARY CONFIG
//--------------------------------------------------------------------------
#define STEPPER_ENABLE     		1

#define STEPPER_QUANTITY 		4			// Max 4

#define BIPOLAR_MODE			0			// 1 - Bipolar motor, 0 - Unipolar motor

#define USE_ROBOT_FUNC          0			// Using robot functions (go forward or backward)

#define STEPS_PER_REV    		32  		// Depends on choosed stepper motor
#define GEAR_RED				64 			// if none, type 1
#define FULL_REV	STEPS_PER_REV * GEAR_RED

//--------------------------------------------------------------------------
//						    PIN/PORT SETTINGS
//--------------------------------------------------------------------------


#if STEPPER_QUANTITY >= 1
#define STEPPER1_PORT1 			C
#define STEPPER1_PIN1			2

#define STEPPER1_PORT2 			C
#define STEPPER1_PIN2 			3

#define STEPPER1_PORT3 			C
#define STEPPER1_PIN3 			4

#define STEPPER1_PORT4			C
#define STEPPER1_PIN4			5
#endif


#if STEPPER_QUANTITY >= 2
#define STEPPER2_PORT1 			C
#define STEPPER2_PIN1			1

#define STEPPER2_PORT2 			C
#define STEPPER2_PIN2			0

#define STEPPER2_PORT3 			B
#define STEPPER2_PIN3 			1

#define STEPPER2_PORT4			B
#define STEPPER2_PIN4			0
#endif


#if STEPPER_QUANTITY >= 3
#define STEPPER3_PORT1 			D
#define STEPPER3_PIN1			5

#define STEPPER3_PORT2 			D
#define STEPPER3_PIN2			6

#define STEPPER3_PORT3 			D
#define STEPPER3_PIN3 			7

#define STEPPER3_PORT4			B
#define STEPPER3_PIN4			0
#endif


#if STEPPER_QUANTITY >= 4
#define STEPPER4_PORT1 			D
#define STEPPER4_PIN1			4

#define STEPPER4_PORT2 			D
#define STEPPER4_PIN2			3

#define STEPPER4_PORT3 			D
#define STEPPER4_PIN3 			2

#define STEPPER4_PORT4			D
#define STEPPER4_PIN4			1
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
//								STEPS DEFINES
//--------------------------------------------------------------------------
#define _SET_STEPPER1_1 PORT(STEPPER1_PORT1) |= (1<<STEPPER1_PIN1)
#define _CLR_STEPPER1_1 PORT(STEPPER1_PORT1) &= ~(1<<STEPPER1_PIN1)

#define _SET_STEPPER1_2 PORT(STEPPER1_PORT2) |= (1<<STEPPER1_PIN2)
#define _CLR_STEPPER1_2 PORT(STEPPER1_PORT2) &= ~(1<<STEPPER1_PIN2)

#define _SET_STEPPER1_3 PORT(STEPPER1_PORT3) |= (1<<STEPPER1_PIN3)
#define _CLR_STEPPER1_3 PORT(STEPPER1_PORT3) &= ~(1<<STEPPER1_PIN3)

#define _SET_STEPPER1_4 PORT(STEPPER1_PORT4) |= (1<<STEPPER1_PIN4)
#define _CLR_STEPPER1_4 PORT(STEPPER1_PORT1) &= ~(1<<STEPPER1_PIN4)



#define _SET_STEPPER2_1 PORT(STEPPER2_PORT1) |= (1<<STEPPER2_PIN1)
#define _CLR_STEPPER2_1 PORT(STEPPER2_PORT1) &= ~(1<<STEPPER2_PIN1)

#define _SET_STEPPER2_2 PORT(STEPPER2_PORT2) |= (1<<STEPPER2_PIN2)
#define _CLR_STEPPER2_2 PORT(STEPPER2_PORT2) &= ~(1<<STEPPER2_PIN2)

#define _SET_STEPPER2_3 PORT(STEPPER2_PORT3) |= (1<<STEPPER2_PIN3)
#define _CLR_STEPPER2_3 PORT(STEPPER2_PORT3) &= ~(1<<STEPPER2_PIN3)

#define _SET_STEPPER2_4 PORT(STEPPER2_PORT4) |= (1<<STEPPER2_PIN4)
#define _CLR_STEPPER2_4 PORT(STEPPER2_PORT4) &= ~(1<<STEPPER2_PIN4)



#define _SET_STEPPER3_1 PORT(STEPPER3_PORT1) |= (1<<STEPPER3_PIN1)
#define _CLR_STEPPER3_1 PORT(STEPPER3_PORT1) &= ~(1<<STEPPER3_PIN1)

#define _SET_STEPPER3_2 PORT(STEPPER3_PORT2) |= (1<<STEPPER3_PIN2)
#define _CLR_STEPPER3_2 PORT(STEPPER3_PORT2) &= ~(1<<STEPPER3_PIN2)

#define _SET_STEPPER3_3 PORT(STEPPER3_PORT3) |= (1<<STEPPER3_PIN3)
#define _CLR_STEPPER3_3 PORT(STEPPER3_PORT3) &= ~(1<<STEPPER3_PIN3)

#define _SET_STEPPER3_4 PORT(STEPPER3_PORT4) |= (1<<STEPPER3_PIN4)
#define _CLR_STEPPER3_4 PORT(STEPPER3_PORT4) &= ~(1<<STEPPER3_PIN4)



#define _SET_STEPPER4_1 PORT(STEPPER4_PORT1) |= (1<<STEPPER4_PIN1)
#define _CLR_STEPPER4_1 PORT(STEPPER4_PORT1) &= ~(1<<STEPPER4_PIN1)

#define _SET_STEPPER4_2 PORT(STEPPER4_PORT2) |= (1<<STEPPER4_PIN2)
#define _CLR_STEPPER4_2 PORT(STEPPER4_PORT2) &= ~(1<<STEPPER4_PIN2)

#define _SET_STEPPER4_3 PORT(STEPPER4_PORT3) |= (1<<STEPPER4_PIN3)
#define _CLR_STEPPER4_3 PORT(STEPPER4_PORT3) &= ~(1<<STEPPER4_PIN3)

#define _SET_STEPPER4_4 PORT(STEPPER4_PORT4) |= (1<<STEPPER4_PIN4)
#define _CLR_STEPPER4_4 PORT(STEPPER4_PORT4) &= ~(1<<STEPPER4_PIN4)





#if STEPPER_QUANTITY >= 1
#define  STEPPER1_STEP1 _SET_STEPPER1_1; _CLR_STEPPER1_2; _CLR_STEPPER1_3; _CLR_STEPPER1_4
#define  STEPPER1_STEP2	_SET_STEPPER1_2; _CLR_STEPPER1_1; _CLR_STEPPER1_3; _CLR_STEPPER1_4
#define  STEPPER1_STEP3 _SET_STEPPER1_3; _CLR_STEPPER1_1; _CLR_STEPPER1_2; _CLR_STEPPER1_4
#define  STEPPER1_STEP4	_SET_STEPPER1_4; _CLR_STEPPER1_1; _CLR_STEPPER1_2; _CLR_STEPPER1_3
#endif


#if STEPPER_QUANTITY >= 2
#define  STEPPER2_STEP1	_SET_STEPPER2_1; _CLR_STEPPER2_2; _CLR_STEPPER2_3; _CLR_STEPPER2_4
#define  STEPPER2_STEP2	_SET_STEPPER2_2; _CLR_STEPPER2_1; _CLR_STEPPER2_3; _CLR_STEPPER2_4
#define  STEPPER2_STEP3	_SET_STEPPER2_3; _CLR_STEPPER2_1; _CLR_STEPPER2_2; _CLR_STEPPER2_4
#define  STEPPER2_STEP4	_SET_STEPPER2_4; _CLR_STEPPER2_1; _CLR_STEPPER2_2; _CLR_STEPPER2_3
#endif


#if STEPPER_QUANTITY >= 3
#define  STEPPER3_STEP1	_SET_STEPPER3_1; _CLR_STEPPER3_2; _CLR_STEPPER3_3; _CLR_STEPPER3_4
#define  STEPPER3_STEP2	_SET_STEPPER3_2; _CLR_STEPPER3_1; _CLR_STEPPER3_3; _CLR_STEPPER3_4
#define  STEPPER3_STEP3	_SET_STEPPER3_3; _CLR_STEPPER3_1; _CLR_STEPPER3_2; _CLR_STEPPER3_4
#define  STEPPER3_STEP4	_SET_STEPPER3_4; _CLR_STEPPER3_1; _CLR_STEPPER3_2; _CLR_STEPPER3_3
#endif


#if STEPPER_QUANTITY >= 4
#define  STEPPER4_STEP1	_SET_STEPPER4_1; _CLR_STEPPER4_2; _CLR_STEPPER4_3; _CLR_STEPPER4_4
#define  STEPPER4_STEP2	_SET_STEPPER4_2; _CLR_STEPPER4_1; _CLR_STEPPER4_3; _CLR_STEPPER4_4
#define  STEPPER4_STEP3	_SET_STEPPER4_3; _CLR_STEPPER4_1; _CLR_STEPPER4_2; _CLR_STEPPER4_4
#define  STEPPER4_STEP4	_SET_STEPPER4_4; _CLR_STEPPER4_1; _CLR_STEPPER4_2; _CLR_STEPPER4_3
#endif

//--------------------------------------------------------------------------
//						DECLARATIONS OF FUNCTIONS AND VARIABLES
//--------------------------------------------------------------------------



void stepperInit(void);
void stepperGoLeft(uint8_t stepperNumber, uint16_t stepsQuantity, uint8_t stepDelay);
void stepperGoRight(uint8_t stepperNumber,uint16_t stepsQuantity, uint8_t stepDelay);


// 						    ROBOT CONTROL TYPES AND FUNCTIONS
#if USE_ROBOT_FUNC == 1 && STEPPER_QUANTITY == 4

extern uint8_t stepperStopFlag;													// 1 - emergency stop (for example: too small distance from an obstacle

typedef enum _stepperDir {stepperRW, stepperFW}_stepperRobotDir;				// FW - Forward RW - Reverse

void robotStepperGo(_stepperRobotDir dir, uint8_t stepsQuantity, uint8_t stepDelay);

#endif

#endif /* STEPPERLIB_STEPPER_H_ */
