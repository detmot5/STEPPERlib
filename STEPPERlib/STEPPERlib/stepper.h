/* Library for stepper motor control with AVR uC.
 *
 *
 */

#ifndef STEPPERLIB_STEPPER_H_
#define STEPPERLIB_STEPPER_H_

#define STEPS_PER_REV    		32  // Depends on choosed stepper motor
#define GEAR_RED				64  // if none, type 1
#define STEPS 	STEPS_PER_REV * GEAR_RED

//--------------------------------------------------------------------------
//						  LIBRARY CONFIG
//--------------------------------------------------------------------------
#define STEPPER_ENABLE     		1

#define STEPPER_QUANTITY 		4   // Max 4


//--------------------------------------------------------------------------
//						    PIN/PORT SETTINGS
//--------------------------------------------------------------------------
#define STEPPER_1_PORT 			A
#define STEPPER_1_PIN			0

#define STEPPER_2_PORT 			A
#define STEPPER_2_PIN 			1

#define STEPPER_3_PORT 			A
#define STEPPER_3_PIN 			2

#define STEPPER_4_PORT			A
#define STEPPER_4_PIN			3

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
//						LOGIC STATE CHANGE MACROS
//--------------------------------------------------------------------------

#define  STEP1	PORT(STEPPER_1_PORT) |= (1<<STEPPER_1_PIN); PORT(STEPPER_1_PORT) &= ~(1<<STEPPER_1_PIN)
#define  STEP2	PORT(STEPPER_2_PORT) |= (1<<STEPPER_2_PIN); PORT(STEPPER_2_PORT) &= ~(1<<STEPPER_2_PIN)
#define  STEP3	PORT(STEPPER_3_PORT) |= (1<<STEPPER_3_PIN); PORT(STEPPER_3_PORT) &= ~(1<<STEPPER_3_PIN)
#define  STEP4	PORT(STEPPER_4_PORT) |= (1<<STEPPER_3_PIN); PORT(STEPPER_3_PORT) &= ~(1<<STEPPER_4_PIN)

#endif /* STEPPERLIB_STEPPER_H_ */
