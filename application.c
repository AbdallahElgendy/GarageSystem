/* 
 * File:   application.c
 * Author: Abdallah Saad
* Created on August 7, 2022, 10:39 PM
 */

#include "application.h"

pin_config_t pin_1 = {
    .direction = GPIO_DIRECTION_INPUT  , 
    .logic =  GPIO_LOW  , 
    .pin = GPIO_PIN0 ,  
    .port = PORTB_INDEX , 
} ; 

pin_config_t pin_2 = {
    .direction = GPIO_DIRECTION_INPUT  , 
    .logic =  GPIO_LOW  , 
    .pin = GPIO_PIN1 ,  
    .port = PORTB_INDEX , 
} ; 


logic_t logic_1 = GPIO_LOW ; 
logic_t logic_2 = GPIO_LOW ;
uint8 counter = 0 , flag_1 = 0 , flag_2 = 0 ; 
int main() { 
    Std_ReturnType ret = E_NOT_OK;
    application_intialize();

    while(1){
        gpio_pin_read_logic(&pin_1 ,&logic_1) ; 
        gpio_pin_read_logic(&pin_2 ,&logic_2) ; 
        if(counter <3){
            lcd_8bit_send_string_pos(&lcd_1 ,1 ,1 ,"Available : ") ;
            lcd_8bit_send_char_data_pos(&lcd_1 , 1 , 13 , (3-counter)+'0') ; 
        }
        else if(counter == 3){
            lcd_8bit_send_string_pos(&lcd_1 ,1 ,1 , "No places    ") ;
        } 
        

        if((counter < 3)&&(logic_1 == GPIO_HIGH)&&(flag_1 == 0)){
            counter++ ; 
            if(counter <3){
                lcd_8bit_send_string_pos(&lcd_1 ,1 ,1 ,"Available : ") ;
                lcd_8bit_send_char_data_pos(&lcd_1 , 1 , 13 , (3-counter)+'0') ; 
            }
            else if(counter == 3){
                lcd_8bit_send_string_pos(&lcd_1 ,1 ,1 , "No places    ") ;
            }
            
            flag_1 = 1 ; 
            ret = dc_motor_move_left(&dcMotor_1) ; 
            __delay_ms(300) ; 
             ret = dc_motor_stop(&dcMotor_1) ;
             __delay_ms(200) ; 
            ret = dc_motor_move_right(&dcMotor_1) ;
            __delay_ms(300) ; 
            ret = dc_motor_stop(&dcMotor_1) ; 
        }
        else if(logic_1 == GPIO_LOW)
        {
            flag_1 = 0 ; 
        }
        if((counter > 0)&&(logic_2 == GPIO_HIGH)&&(flag_2 == 0)){
            counter-- ;
            if(counter <3){
                lcd_8bit_send_string_pos(&lcd_1 ,1 ,1 ,"Available : ") ;
                lcd_8bit_send_char_data_pos(&lcd_1 , 1 , 13 , (3-counter)+'0') ; 
            }
            else if(counter == 3){
                lcd_8bit_send_string_pos(&lcd_1 ,1 ,1 , "No places    ") ;
            }   
            
            flag_2 = 1 ; 
            ret = dc_motor_move_left(&dcMotor_2) ; 
            __delay_ms(300) ; 
             ret = dc_motor_stop(&dcMotor_2) ;
             __delay_ms(200) ; 
            ret = dc_motor_move_right(&dcMotor_2) ;
            __delay_ms(300) ; 
            ret = dc_motor_stop(&dcMotor_2) ;  
        }
        else if(logic_2 == GPIO_LOW)
        {
            flag_2 = 0 ; 
        }

        
    }
    return (EXIT_SUCCESS);
}

void application_intialize(void){
    Std_ReturnType ret = E_NOT_OK;
    
    ret = gpio_pin_intialize(&pin_1) ; 
    ret |= gpio_pin_intialize(&pin_2) ; 
    ecu_layer_intialize() ; 
    
}




