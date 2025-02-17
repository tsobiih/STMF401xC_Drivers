/*
 * MRCC_config.h
 *
 *  Created on: Feb 7, 2025
 *      Author: elwady
 */

#ifndef MRCC_CONFIG_H_
#define MRCC_CONFIG_H_


/*
 * Choose between
 * 1- HSI_CLOCK
 * 2- HSE_CLOCK
 */

#define SYS_CLOCK	HSI_CLOCK

/*
 * Choose Between
 * 1- RC_CLOCK
 * 2- MECHANICAL_CLOCK
 */

#define HSE_OSC MECHANICAL_CLOCK

#endif /* MRCC_CONFIG_H_ */
