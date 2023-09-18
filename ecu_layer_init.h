/* 
 * File:   ecu_layer_init.h
 * Author: Abdallah Saad
 * Created on February 7, 2023, 10:39 PM
 */

#ifndef ECU_LAYER_INIT_H
#define	ECU_LAYER_INIT_H

#include "LED/ecu_led.h"
#include "7_Segment/ecu_seven_segment.h"
#include "Rleay/ecu_relay.h"
#include "DC_Motor/ecu_dc_motor.h"
#include "button/ecu_button.h"
#include "KeyPad/ecu_keypad.h"
#include "Chr_LCD/ecu_chr_lcd.h"

dc_motor_t dcMotor_1 = {
    .dc_motor_pin[0].direction = GPIO_DIRECTION_OUTPUT  ,
    .dc_motor_pin[0].logic = GPIO_LOW , 
    .dc_motor_pin[0].port = PORTA_INDEX , 
    .dc_motor_pin[0].pin = GPIO_PIN0  , 
    
    .dc_motor_pin[1].direction = GPIO_DIRECTION_OUTPUT  ,
    .dc_motor_pin[1].logic = GPIO_LOW , 
    .dc_motor_pin[1].port = PORTA_INDEX , 
    .dc_motor_pin[1].pin = GPIO_PIN1  , 
} ; 
dc_motor_t dcMotor_2 = {
    .dc_motor_pin[0].direction = GPIO_DIRECTION_OUTPUT  ,
    .dc_motor_pin[0].logic = GPIO_LOW , 
    .dc_motor_pin[0].port = PORTA_INDEX , 
    .dc_motor_pin[0].pin = GPIO_PIN2  , 
    
    .dc_motor_pin[1].direction = GPIO_DIRECTION_OUTPUT  ,
    .dc_motor_pin[1].logic = GPIO_LOW , 
    .dc_motor_pin[1].port = PORTA_INDEX , 
    .dc_motor_pin[1].pin = GPIO_PIN3  , 
} ; 

chr_lcd_8bit_t lcd_1 = {
    .lcd_rs.port = PORTD_INDEX,
    .lcd_rs.pin = GPIO_PIN0,
    .lcd_rs.direction = GPIO_DIRECTION_OUTPUT,
    .lcd_rs.logic = GPIO_LOW,
    .lcd_en.port = PORTD_INDEX,
    .lcd_en.pin = GPIO_PIN1,
    .lcd_en.direction = GPIO_DIRECTION_OUTPUT,
    .lcd_en.logic = GPIO_LOW,
    .lcd_data[0].port = PORTC_INDEX,
    .lcd_data[0].pin = GPIO_PIN0,
    .lcd_data[0].direction = GPIO_DIRECTION_OUTPUT,
    .lcd_data[0].logic = GPIO_LOW,
    .lcd_data[1].port = PORTC_INDEX,
    .lcd_data[1].pin = GPIO_PIN1,
    .lcd_data[1].direction = GPIO_DIRECTION_OUTPUT,
    .lcd_data[1].logic = GPIO_LOW,
    .lcd_data[2].port = PORTC_INDEX,
    .lcd_data[2].pin = GPIO_PIN2,
    .lcd_data[2].direction = GPIO_DIRECTION_OUTPUT,
    .lcd_data[2].logic = GPIO_LOW,
    .lcd_data[3].port = PORTC_INDEX,
    .lcd_data[3].pin = GPIO_PIN3,
    .lcd_data[3].direction = GPIO_DIRECTION_OUTPUT,
    .lcd_data[3].logic = GPIO_LOW,
    .lcd_data[4].port = PORTC_INDEX,
    .lcd_data[4].pin = GPIO_PIN4,
    .lcd_data[4].direction = GPIO_DIRECTION_OUTPUT,
    .lcd_data[4].logic = GPIO_LOW,
    .lcd_data[5].port = PORTC_INDEX,
    .lcd_data[5].pin = GPIO_PIN5,
    .lcd_data[5].direction = GPIO_DIRECTION_OUTPUT,
    .lcd_data[5].logic = GPIO_LOW,
    .lcd_data[6].port = PORTC_INDEX,
    .lcd_data[6].pin = GPIO_PIN6,
    .lcd_data[6].direction = GPIO_DIRECTION_OUTPUT,
    .lcd_data[6].logic = GPIO_LOW,
    .lcd_data[7].port = PORTC_INDEX,
    .lcd_data[7].pin = GPIO_PIN7,
    .lcd_data[7].direction = GPIO_DIRECTION_OUTPUT,
    .lcd_data[7].logic = GPIO_LOW,
};




void ecu_layer_intialize(void);

#endif	/* ECU_LAYER_INIT_H */

