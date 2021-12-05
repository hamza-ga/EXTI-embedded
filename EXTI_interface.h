/*
 * EXTI_interface.h
 *
 *  Created on: Sep 2, 2021
 *      Author: hp
 */

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

#define EXTI_INT1 5
#define EXTI_INT0 6
#define EXTI_INT2 7

void EXTI_EnableIntrubts(u8 Int_no);
void EXTI_Init(void);

#endif /* EXTI_INTERFACE_H_ */
