/*
 * EXTI_program.c
 *
 *  Created on: Sep 2, 2021
 *      Author: hp
 */
#include"../lib/STD.h"
#include "../lib/bitmath.h"

#include"../DIO/DIO_interface.h"

#include"EXTI_config.h"
#include"EXTI_private.h"

void EXTI_EnableIntrubts(u8 Int_no)
{
	switch(Int_no)
	{
	case 1 :SET_BIT(GICR,5);break;
	case 0 :SET_BIT(GICR,6);break;
	case 2 :SET_BIT(GICR,7);break;
	}
}

void EXTI_Init(void)
{
#if EXTI_INT1 == ENABLED
	     DIO_SetPinDirection(DIO_PORTD , DIO_PIN3 , DIO_directionIN) ;
	     SET_BIT(GICR , 5) ;
     #endif

    #if EXTI_INT0 == ENABLED
	     DIO_SetPinDirection(DIO_PORTD , DIO_PIN2 , DIO_directionIN) ;
	     SET_BIT(GICR , 6) ;
    #endif

    #if EXTI_INT2 == ENABLED
	     DIO_SetPinDirection(DIO_PORTB , DIO_PIN2 , DIO_directionIN) ;
	     SET_BIT(GICR , 7) ;
    #endif


    #if EXTI_INT1 == ENABLED

	    DIO_SetPinDirection(DIO_PORTD , DIO_PIN3 , DIO_directionIN) ;

        #if EXTI_INT1_SENSEMODE == EXTI_FALLING_EDGE
	        SET_BIT(MCUCR , 3) ;
	        CLR_BIT(MCUCR , 2) ;
        #endif

        #if EXTI_INT1_SENSEMODE == EXTI_RISING_EDGE
	        SET_BIT(MCUCR , 3) ;
	        SET_BIT(MCUCR , 2) ;
        #endif

        #if EXTI_INT1_SENSEMODE == EXTI_ONCHANGE
	        CLR_BIT(MCUCR , 3) ;
	        SET_BIT(MCUCR , 2) ;
        #endif

        #if EXTI_INT1_SENSEMODE == EXTI_LOWLEVEL
	        CLR_BIT(MCUCR , 3) ;
	        CLR_BIT(MCUCR , 2) ;
        #endif

    #endif

    #if EXTI_INT0 == ENABLED

	    DIO_SetPinDirection(DIO_PORTD , DIO_PIN2 , DIO_directionIN) ;

        #if EXTI_INT1_SENSEMODE == EXTI_FALLING_EDGE
	        SET_BIT(MCUCR , 1) ;
	        CLR_BIT(MCUCR , 0) ;
        #endif

        #if EXTI_INT1_SENSEMODE == EXTI_RISING_EDGE
	        SET_BIT(MCUCR , 1) ;
	        SET_BIT(MCUCR , 0) ;
        #endif

        #if EXTI_INT1_SENSEMODE == EXTI_ONCHANGE
	        CLR_BIT(MCUCR , 1) ;
	        SET_BIT(MCUCR , 0) ;
        #endif

        #if EXTI_INT1_SENSEMODE == EXTI_LOWLEVEL
	        CLR_BIT(MCUCR , 1) ;
	        CLR_BIT(MCUCR , 0) ;
        #endif

    #endif


    #if EXTI_INT2 == ENABLED

	    DIO_SetPinDirection(DIO_PORTB , DIO_PIN2 , DIO_directionIN) ;

        #if EXTI_INT1_SENSEMODE == EXTI_FALLING_EDGE
	        CLR_BIT(MCUCSR , 6) ;
        #endif

        #if EXTI_INT1_SENSEMODE == EXTI_RISING_EDGE
	        SET_BIT(MCUCSR , 6) ;
        #endif

    #endif


    #if EXTI_INT1 == DISABLED
	     DIO_SetPinDirection(DIO_PORTD , DIO_PIN3 , DIO_directionIN) ;
	     CLR_BIT(GIFR , 5) ;
    #endif

    #if EXTI_INT0 == DISABLED
	     DIO_SetPinDirection(DIO_PORTD , DIO_PIN2 , DIO_directionIN) ;
	     CLR_BIT(GIFR , 6) ;
    #endif

    #if EXTI_INT2 == DISABLED
	     DIO_SetPinDirection(DIO_PORTB , DIO_PIN2 , DIO_directionIN) ;
	     CLR_BIT(GIFR , 7) ;
    #endif

}

