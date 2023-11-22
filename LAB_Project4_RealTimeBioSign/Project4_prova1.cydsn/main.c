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
#include "project.h"
#include "Interrupt_Routines.h"
#include "stdio.h"

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    
    UART_Start();
    ADC_DelSig_Start(); //Inizializza
    Timer_ADC_Start();
    isr_ADC_StartEx(Custom_ISR_ADC); //StartEx
   
    PacketReadyFlag =0;
    
    ADC_DelSig_StartConvert(); //Inizia conversione
    WaveDAC8_1_Start();
    DataBuffer[0]= 0xA0;
    DataBuffer[TRANSMIT_BUFFER_SIZE-1]=0xC0;
    
    
    for(;;)
    {
        if (PacketReadyFlag==1){
            UART_PutArray(DataBuffer,TRANSMIT_BUFFER_SIZE);
            PacketReadyFlag=0;
        }
    }
}
/* [] END OF FILE */
