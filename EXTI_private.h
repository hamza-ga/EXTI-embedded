/*
 * EXTI_private.h
 *
 *  Created on: Sep 2, 2021
 *      Author: hp
 */

#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_

#define ENABLED               1
#define DISABLED              0

#define EXTI_RISING_EDGE  1
#define EXTI_FALLING_EDGE 2
#define EXTI_ONCHANGE     3
#define EXTI_LOWLEVEL     4

#define GICR   *((volatile u8*)(0x5B))
#define GIFR   *((volatile u8*)(0x5A))

#define MCUCR  *((volatile u8*)(0x55))
#define MCUCSR *((volatile u8*)(0x54))



#endif /* EXTI_PRIVATE_H_ */
