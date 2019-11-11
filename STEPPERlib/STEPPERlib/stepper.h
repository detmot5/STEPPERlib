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

#define STEPPER_QUANTITY 		4   		// Max 4

#define STEPS_PER_REV    		32  		// Depends on choosed stepper motor
#define GEAR_RED				64 			// if none, type 1
#define FULL_REV	STEPS_PER_REV * GEAR_RED
#define PI 					FULL_REV/2
//--------------------------------------------------------------------------
//						    PIN/PORT SETTINGS
//--------------------------------------------------------------------------

// 		1st STEPPER
#if STEPPER_QUANTITY >= 1
#define STEPPER1_PORT1 			A
#define STEPPER1_PIN1			0

#define STEPPER1_PORT2 			A
#define STEPPER1_PIN2 			1

#define STEPPER1_PORT3 			A
#define STEPPER1_PIN3 			2

#define STEPPER1_PORT4			A
#define STEPPER1_PIN4			3
#endif


#if STEPPER_QUANTITY >= 2
#define STEPPER2_PORT1 			A
#define STEPPER2_PIN1			4

#define STEPPER2_PORT2 			A
#define STEPPER2_PIN2			5

#define STEPPER2_PORT3 			A
#define STEPPER2_PIN3 			6

#define STEPPER2_PORT4			A
#define STEPPER2_PIN4			7
#endif


#if STEPPER_QUANTITY >= 3
#define STEPPER3_PORT1 			C
#define STEPPER3_PIN1			0

#define STEPPER3_PORT2 			C
#define STEPPER3_PIN2			1

#define STEPPER3_PORT3 			C
#define STEPPER3_PIN3 			2

#define STEPPER3_PORT4			C
#define STEPPER3_PIN4			3
#endif


#if STEPPER_QUANTITY >= 4
#define STEPPER4_PORT1 			C
#define STEPPER4_PIN1			4

#define STEPPER4_PORT2 			C
#define STEPPER4_PIN2			5

#define STEPPER4_PORT3 			C
#define STEPPER4_PIN3 			6

#define STEPPER4_PORT4			C
#define STEPPER4_PIN4			7
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
//								STEPS MACROS
//--------------------------------------------------------------------------

#if STEPPER_QUANTITY >= 1
#define  STEPPER1_STEP1	PORT(STEPPER1_PORT1) |= (1<<STEPPER1_PIN1); PORT(STEPPER1_PORT1) &= ~(1<<STEPPER1_PIN1)
#define  STEPPER1_STEP2	PORT(STEPPER1_PORT2) |= (1<<STEPPER1_PIN2); PORT(STEPPER1_PORT2) &= ~(1<<STEPPER2_PIN2)
#define  STEPPER1_STEP3	PORT(STEPPER1_PORT3) |= (1<<STEPPER1_PIN3); PORT(STEPPER1_PORT3) &= ~(1<<STEPPER3_PIN3)
#define  STEPPER1_STEP4	PORT(STEPPER1_PORT4) |= (1<<STEPPER1_PIN4); PORT(STEPPER1_PORT4) &= ~(1<<STEPPER4_PIN4)
#endif


#if STEPPER_QUANTITY >= 2
#define  STEPPER2_STEP1	PORT(STEPPER2_PORT1) |= (1<<STEPPER2_PIN1); PORT(STEPPER2_PORT1) &= ~(1<<STEPPER2_PIN1)
#define  STEPPER2_STEP2	PORT(STEPPER2_PORT2) |= (1<<STEPPER2_PIN2); PORT(STEPPER2_PORT2) &= ~(1<<STEPPER2_PIN2)
#define  STEPPER2_STEP3	PORT(STEPPER2_PORT3) |= (1<<STEPPER2_PIN3); PORT(STEPPER2_PORT3) &= ~(1<<STEPPER2_PIN3)
#define  STEPPER2_STEP4	PORT(STEPPER2_PORT4) |= (1<<STEPPER2_PIN4); PORT(STEPPER2_PORT4) &= ~(1<<STEPPER2_PIN4)
#endif


#if STEPPER_QUANTITY >= 3
#define  STEPPER3_STEP1	PORT(STEPPER3_PORT1) |= (1<<STEPPER3_PIN1); PORT(STEPPER3_PORT1) &= ~(1<<STEPPER3_PIN1)
#define  STEPPER3_STEP2	PORT(STEPPER3_PORT2) |= (1<<STEPPER3_PIN2); PORT(STEPPER3_PORT2) &= ~(1<<STEPPER3_PIN2)
#define  STEPPER3_STEP3	PORT(STEPPER3_PORT3) |= (1<<STEPPER3_PIN3); PORT(STEPPER3_PORT3) &= ~(1<<STEPPER3_PIN3)
#define  STEPPER3_STEP4	PORT(STEPPER3_PORT4) |= (1<<STEPPER3_PIN4); PORT(STEPPER3_PORT4) &= ~(1<<STEPPER3_PIN4)
#endif


#if STEPPER_QUANTITY >= 4
#define  STEPPER4_STEP1	PORT(STEPPER4_PORT1) |= (1<<STEPPER4_PIN1); PORT(STEPPER4_PORT1) &= ~(1<<STEPPER4_PIN1)
#define  STEPPER4_STEP2	PORT(STEPPER4_PORT2) |= (1<<STEPPER4_PIN2); PORT(STEPPER4_PORT2) &= ~(1<<STEPPER4_PIN2)
#define  STEPPER4_STEP3	PORT(STEPPER4_PORT3) |= (1<<STEPPER4_PIN3); PORT(STEPPER4_PORT3) &= ~(1<<STEPPER4_PIN3)
#define  STEPPER4_STEP4	PORT(STEPPER4_PORT4) |= (1<<STEPPER4_PIN4); PORT(STEPPER4_PORT4) &= ~(1<<STEPPER4_PIN4)
#endif



#endif /* STEPPERLIB_STEPPER_H_ */
