
/* 
 * File:   ecu_layer_init.c
 * Author: Abdallah Saad
 * Created on February 7, 2021, 10:39 PM
 */

#include "ecu_layer_init.h"


void ecu_layer_intialize(void){
    Std_ReturnType ret = E_NOT_OK;
    ret = lcd_8bit_intialize(&lcd_1) ; 
    ret = dc_motor_initialize(&dcMotor_1) ; 
    ret = dc_motor_initialize(&dcMotor_2) ; 

}