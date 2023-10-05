/*    
*     Created in 6/9/2023
*     By : Ahmed Eldab3
*/


#include "../LIB/Bit_utils.h"
#include "../LIB/Std_types.h"

#define F_CPU 1000000
#include "util/delay.h"
#include "../MCAL/DIO/DIO_Interface.h"
#include "../MCAL/INT/INT_Interface.h"
#include "../HALL/SSD/SSD_Interface.h"
#include "../HALL/LCD/LCD_Interface.h"
#include "../HALL/KPAD/KPAD_Interface.h"


int main (){

	LCD_voidAddPatternsToCGRAM();
	LCD_voidIitialize();
	KPAD_voidInitialize();
	LCD_voidGoToPosition(LINE1,3);
	LCD_voidWriteString("Welcome to");
	LCD_voidGoToPosition(LINE2,0);
	LCD_voidWriteString("My Stop Watch");
	_delay_ms(500);
	LCD_voidWriteCommand(Clear_Display);
	LCD_voidGoToPosition(LINE1,0);
	LCD_voidWriteData('0');
	LCD_voidGoToPosition(LINE1,1);
	LCD_voidWriteData('0');
	LCD_voidGoToPosition(LINE1,2);
	LCD_voidWriteData(':');
	LCD_voidGoToPosition(LINE1,3);
	LCD_voidWriteData('0');
	LCD_voidGoToPosition(LINE1,4);
	LCD_voidWriteData('0');
	LCD_voidGoToPosition(LINE1,5);
	LCD_voidWriteData(':');
	LCD_voidGoToPosition(LINE1,6);
	LCD_voidWriteData('0');
	LCD_voidGoToPosition(LINE1,7);
	LCD_voidWriteData('0');
	LCD_voidGoToPosition(LINE2,1);
	LCD_voidWritePattern(6);

	u8 Local_pressed;
	s8 Minutes_digit_1 , Minutes_digit_2 , Seconds_digit_1, Seconds_digit_2, total_Number_Seconds, total_Number_Minutes, total_Number_Hours;
    while(1){

    u8 m = 0;  // used as a counter
    u8 l = 60; // used as a counter

    while (m!=5){
    	Local_pressed = KPAD_u8GetPressed();

    	if (Local_pressed!=255 && Local_pressed!= 13)
    	{
    		switch (m){

    		case 0 :
    			LCD_voidGoToPosition(LINE1,1);
    			LCD_voidWriteNumber(Local_pressed);
    			total_Number_Hours = Local_pressed;
    			break;
    		case 1 :
    			LCD_voidGoToPosition(LINE1,3);
    			LCD_voidWriteNumber(Local_pressed);
    			Minutes_digit_1 = Local_pressed * 10;
    			break;
    		case 2 :
    			LCD_voidGoToPosition(LINE1,4);
    			LCD_voidWriteNumber(Local_pressed);
    			Minutes_digit_2 = Local_pressed;
    			break;
    		case 3 :
    			LCD_voidGoToPosition(LINE1,6);
    			LCD_voidWriteNumber(Local_pressed);
    			Seconds_digit_1 = Local_pressed * 10;
    			break;
    		case 4:
    			LCD_voidGoToPosition(LINE1,7);
    			LCD_voidWriteNumber(Local_pressed);
    			Seconds_digit_2 = Local_pressed;
    			break;
    		}


    	}else if (Local_pressed!= 255 && Local_pressed== 13 && m==0){
    		LCD_voidGoToPosition(LINE2,1);
    		LCD_voidWriteData(' ');
    		LCD_voidGoToPosition(LINE2,3);
    		LCD_voidWritePattern(6);
    		m++;
    	}else if (Local_pressed!= 255 && Local_pressed== 13 && m==1){
    		LCD_voidGoToPosition(LINE2,3);
    		LCD_voidWriteData(' ');
    		LCD_voidGoToPosition(LINE2,4);
    		LCD_voidWritePattern(6);
    		m++;
    	}else if (Local_pressed!= 255 && Local_pressed== 13 && m==2){
    		LCD_voidGoToPosition(LINE2,4);
    		LCD_voidWriteData(' ');
    		LCD_voidGoToPosition(LINE2,6);
    		LCD_voidWritePattern(6);
    		m++;
    	}else if (Local_pressed!= 255 && Local_pressed== 13 && m==3){
    		LCD_voidGoToPosition(LINE2,6);
    		LCD_voidWriteData(' ');
    		LCD_voidGoToPosition(LINE2,7);
    		LCD_voidWritePattern(6);
    		m++;
    	}else if (Local_pressed!= 255 && Local_pressed== 13 && m==4){
    		LCD_voidGoToPosition(LINE2,7);
    		LCD_voidWriteData(' ');
    		LCD_voidGoToPosition(LINE2,9);
    		LCD_voidWritePattern(6);
    		LCD_voidGoToPosition(LINE1,9);
    		LCD_voidWriteString("start");
    		m++;
    	}
    }
    total_Number_Seconds = Seconds_digit_1+Seconds_digit_2;
    while (total_Number_Seconds != 0){

    	for (s8 i=total_Number_Seconds ; i>0 ; i--){

    		if (i<=9){
    		    LCD_voidGoToPosition(LINE1,6);
    		    LCD_voidWriteData('0');
    		    LCD_voidGoToPosition(LINE1,7);
    		    LCD_voidWriteNumber(i);
    		    _delay_ms(1);
    		    }else{
    		    LCD_voidGoToPosition(LINE1,6);
    		    LCD_voidWriteNumber(i);
    		    _delay_ms(1);
    		    }
    		total_Number_Seconds--;
    	}


    }

    total_Number_Minutes = Minutes_digit_2 + Minutes_digit_1;
    while (total_Number_Minutes!=0){
    	total_Number_Minutes--;
    		if (total_Number_Minutes==0){
    			LCD_voidGoToPosition(LINE1,4);
    			LCD_voidWriteData('0');
    			LCD_voidGoToPosition(LINE1,3);
    			LCD_voidWriteData('0');
    	    }else if (total_Number_Minutes <=9 && total_Number_Minutes >0){
    	    	LCD_voidGoToPosition(LINE1,3);
    	    	LCD_voidWriteData('0');
    	        LCD_voidGoToPosition(LINE1,4);
    	        LCD_voidWriteNumber(total_Number_Minutes);
    	    }else {
    	    	LCD_voidGoToPosition(LINE1,3);
    	    	LCD_voidWriteNumber(total_Number_Minutes);
    	    }
    		for (s8 i=60;i>0;i--){
    			if (i<=9){
    				LCD_voidGoToPosition(LINE1,6);
    				LCD_voidWriteData('0');
    				LCD_voidGoToPosition(LINE1,7);
    				LCD_voidWriteNumber(i);
    				_delay_ms(1);
    			}else{
    				LCD_voidGoToPosition(LINE1,6);
    				LCD_voidWriteNumber(i);
    				_delay_ms(1);
    			}
    		}
    	}

    while (total_Number_Hours!=0){
    		if (total_Number_Hours == 1 || total_Number_Hours == 0){
    			LCD_voidGoToPosition(LINE1,1);
    			LCD_voidWriteData('0');
    		}else{
    			LCD_voidGoToPosition(LINE1,1);
    			LCD_voidWriteNumber(total_Number_Hours - 1);
    		}
    		l--;
    		if (l!=0){
    			LCD_voidGoToPosition(LINE1,3);
    			LCD_voidWriteNumber(l);

    		}else if (l==0){
    			total_Number_Hours==0;
    		}
    		for (s8 i=60;i>0;i--){
    			if (i<=9){
    				LCD_voidGoToPosition(LINE1,6);
    				LCD_voidWriteData('0');
    				LCD_voidGoToPosition(LINE1,7);
    				LCD_voidWriteNumber(i);
    				_delay_ms(1);
    			}else{
    				LCD_voidGoToPosition(LINE1,6);
    				LCD_voidWriteNumber(i);
    				_delay_ms(1);
    			}
    		}
       }
    break;
    }


}
