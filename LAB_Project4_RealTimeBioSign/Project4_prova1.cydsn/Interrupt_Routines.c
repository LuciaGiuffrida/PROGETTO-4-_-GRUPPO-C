/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/

#include "Interrupt_Routines.h"
#include "project.h"

int32 value_digit;
int32 value_mv;
//char ch_received;
//uint8 SendBytesFlag =0;


CY_ISR (Custom_ISR_ADC)
{
    //if (SendBytesFlag==1){
        Timer_ADC_ReadStatusRegister();
        value_digit= ADC_DelSig_Read32();
        
        if(value_digit>65535) value_digit=65535;
        if(value_digit<0) value_digit=0;
        
        //value_mv = ADC_DelSig_CountsTo_mVolts(value_digit);
        //sprintf(DataBuffer, "Sample: %ld mV\r\n", value_mv);
        //Dobbiamo definire i bytes da mandare senza header e tail
        
        DataBuffer[1]=value_digit>>8; //prendo il più significativo 
        DataBuffer[2]= value_digit & 0xFF; //prendo il meno significativo 
        
        PacketReadyFlag =1;
    //}
}

/*CY_ISR (Custom_ISR_RX)
{
    ch_received= UART_GetChar();
    
    switch(ch_received){
        case 'a':
        case 'A':
            SendBytesFlag=1;
            Pin_LED_Write(1);
            Timer_ADC_Start();
            break;
        
        case 'b':
        case 'B':
            SendBytesFlag=0;
            Pin_LED_Write(0);
            Timer_ADC_Stop();
            break;
            
        default:
            break;
           
    
    } 
}*/

/* [] END OF FILE */
