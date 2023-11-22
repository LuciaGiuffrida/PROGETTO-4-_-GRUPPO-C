/*******************************************************************************
* File Name: WaveDAC8_1.c
* Version 2.10
*
* Description:
*  This file provides the source code for the 8-bit Waveform DAC 
*  (WaveDAC8) Component.
*
********************************************************************************
* Copyright 2013, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "WaveDAC8_1.h"

uint8  WaveDAC8_1_initVar = 0u;

const uint8 CYCODE WaveDAC8_1_wave1[WaveDAC8_1_WAVE1_LENGTH] = { 128u,135u,143u,150u,158u,165u,172u,179u,186u,193u,199u,205u,211u,216u,222u,226u,231u,234u,238u,241u,244u,246u,247u,249u,249u,250u,249u,249u,247u,246u,244u,241u,238u,234u,231u,226u,222u,216u,211u,205u,199u,193u,186u,179u,172u,165u,158u,150u,143u,135u,128u,120u,112u,105u,97u,90u,83u,76u,69u,62u,56u,50u,44u,39u,33u,29u,24u,21u,17u,14u,11u,9u,8u,6u,6u,6u,6u,6u,8u,9u,11u,14u,17u,21u,24u,29u,33u,39u,44u,50u,56u,62u,69u,76u,83u,90u,97u,105u,112u,120u };
const uint8 CYCODE WaveDAC8_1_wave2[WaveDAC8_1_WAVE2_LENGTH] = { 60u,62u,66u,69u,71u,70u,68u,67u,70u,72u,72u,76u,79u,84u,86u,88u,87u,91u,91u,89u,89u,91u,92u,86u,82u,78u,76u,77u,79u,81u,78u,80u,81u,81u,80u,79u,76u,74u,75u,75u,73u,70u,68u,69u,68u,69u,67u,65u,66u,67u,68u,70u,68u,65u,62u,65u,67u,71u,71u,70u,71u,69u,63u,62u,62u,61u,60u,58u,59u,60u,60u,61u,61u,63u,66u,66u,70u,74u,71u,71u,72u,72u,72u,71u,70u,70u,69u,69u,71u,74u,72u,71u,74u,77u,83u,87u,88u,85u,86u,90u,98u,109u,126u,147u,167u,187u,207u,228u,245u,254u,244u,219u,181u,140u,102u,70u,49u,42u,39u,31u,28u,27u,29u,36u,44u,48u,50u,55u,60u,63u,68u,70u,70u,70u,68u,67u,70u,70u,64u,60u,57u,56u,58u,61u,63u,67u,74u,77u,77u,78u,76u,70u,63u,58u,56u,56u,58u,63u,65u,68u,67u,65u,62u,57u,51u,50u,56u,61u,62u,66u,71u,75u,78u,78u,75u,72u,71u,70u,68u,67u,66u,71u,71u,73u,75u,75u,75u,73u,73u,74u,77u,78u,80u,82u,84u,88u,91u,91u,91u,93u,95u,91u,86u,82u,85u,89u,94u,94u,94u,95u,100u,105u,102u,101u,101u,104u,109u,112u,112u,111u,108u,106u,102u,98u,100u,104u,109u,112u,117u,119u,119u,119u,117u,114u,111u,111u,110u,111u,113u,114u,114u,113u,110u,112u,110u,105u,100u,96u,91u,90u,82u,76u,75u,71u,66u,62u,60u,56u,51u,50u,51u,47u,46u,49u,51u,44u,39u,37u,35u,35u,35u,36u,39u,37u,35u,32u,27u,21u,12u,8u,7u,9u,8u,9u,15u,21u,22u,23u,23u,23u,26u,27u,27u,29u,30u,27u,22u,22u,23u,24u,26u,27u,34u,39u,42u,43u,41u,41u,44u,44u,42u,36u,30u,29u,29u,30u,33u,37u,37u,39u,39u,38u,35u,39u,43u,42u,43u,44u,47u,48u,46u,40u,39u,40u,40u,40u,39u,39u,45u,52u,52u,57u,59u,57u,55u,46u,38u,34u,35u,34u,34u,39u,41u,41u,41u,43u,48u,50u,47u,42u,39u,39u,40u,40u,45u,50u,53u,50u,45u,44u,41u,40u,40u,40u,45u,50u,53u,55u,53u,50u,47u,48u,50u,51u,54u,58u,63u,65u,61u,58u,53u,49u,50u,47u,47u,47u,46u,50u,55u,55u,53u,51u,49u,48u,49u,55u,61u,63u,62u,62u,61u,56u,55u,55u,57u,61u,64u,66u,67u,64u,64u,65u,66u,69u,74u,74u,75u,77u,79u,78u,77u,80u,81u,80u,78u,78u,75u,73u,70u,68u,68u,70u,73u,78u,79u,78u,81u,80u,78u,74u,68u,60u,57u,56u,53u,51u,54u,56u,58u,58u,57u,55u,54u,50u,50u,48u,44u,41u,41u,44u,45u,47u,51u,52u,52u,51u,50u,55u,58u,59u,57u,57u,55u,50u,50u,53u,55u,57u,61u };

static uint8  WaveDAC8_1_Wave1Chan;
static uint8  WaveDAC8_1_Wave2Chan;
static uint8  WaveDAC8_1_Wave1TD;
static uint8  WaveDAC8_1_Wave2TD;


/*******************************************************************************
* Function Name: WaveDAC8_1_Init
********************************************************************************
*
* Summary:
*  Initializes component with parameters set in the customizer.
*
* Parameters:  
*  None
*
* Return: 
*  None
*
*******************************************************************************/
void WaveDAC8_1_Init(void) 
{
	WaveDAC8_1_VDAC8_Init();
	WaveDAC8_1_VDAC8_SetSpeed(WaveDAC8_1_HIGHSPEED);
	WaveDAC8_1_VDAC8_SetRange(WaveDAC8_1_DAC_RANGE);

	#if(WaveDAC8_1_DAC_MODE == WaveDAC8_1_CURRENT_MODE)
		WaveDAC8_1_IDAC8_SetPolarity(WaveDAC8_1_DAC_POL);
	#endif /* WaveDAC8_1_DAC_MODE == WaveDAC8_1_CURRENT_MODE */

	#if(WaveDAC8_1_OUT_MODE == WaveDAC8_1_BUFFER_MODE)
	   WaveDAC8_1_BuffAmp_Init();
	#endif /* WaveDAC8_1_OUT_MODE == WaveDAC8_1_BUFFER_MODE */

	/* Get the TD Number for the DMA channel 1 and 2   */
	WaveDAC8_1_Wave1TD = CyDmaTdAllocate();
	WaveDAC8_1_Wave2TD = CyDmaTdAllocate();
	
	/* Initialize waveform pointers  */
	WaveDAC8_1_Wave1Setup(WaveDAC8_1_wave1, WaveDAC8_1_WAVE1_LENGTH) ;
	WaveDAC8_1_Wave2Setup(WaveDAC8_1_wave2, WaveDAC8_1_WAVE2_LENGTH) ;
	
	/* Initialize the internal clock if one present  */
	#if defined(WaveDAC8_1_DacClk_PHASE)
	   WaveDAC8_1_DacClk_SetPhase(WaveDAC8_1_CLK_PHASE_0nS);
	#endif /* defined(WaveDAC8_1_DacClk_PHASE) */
}


/*******************************************************************************
* Function Name: WaveDAC8_1_Enable
********************************************************************************
*  
* Summary: 
*  Enables the DAC block and DMA operation.
*
* Parameters:  
*  None
*
* Return: 
*  None
*
*******************************************************************************/
void WaveDAC8_1_Enable(void) 
{
	WaveDAC8_1_VDAC8_Enable();

	#if(WaveDAC8_1_OUT_MODE == WaveDAC8_1_BUFFER_MODE)
	   WaveDAC8_1_BuffAmp_Enable();
	#endif /* WaveDAC8_1_OUT_MODE == WaveDAC8_1_BUFFER_MODE */

	/* 
	* Enable the channel. It is configured to remember the TD value so that
	* it can be restored from the place where it has been stopped.
	*/
	(void)CyDmaChEnable(WaveDAC8_1_Wave1Chan, 1u);
	(void)CyDmaChEnable(WaveDAC8_1_Wave2Chan, 1u);
	
	/* set the initial value */
	WaveDAC8_1_SetValue(0u);
	
	#if(WaveDAC8_1_CLOCK_SRC == WaveDAC8_1_CLOCK_INT)  	
	   WaveDAC8_1_DacClk_Start();
	#endif /* WaveDAC8_1_CLOCK_SRC == WaveDAC8_1_CLOCK_INT */
}


/*******************************************************************************
* Function Name: WaveDAC8_1_Start
********************************************************************************
*
* Summary:
*  The start function initializes the voltage DAC with the default values, 
*  and sets the power to the given level.  A power level of 0, is the same as 
*  executing the stop function.
*
* Parameters:  
*  None
*
* Return: 
*  None
*
* Reentrant:
*  No
*
*******************************************************************************/
void WaveDAC8_1_Start(void) 
{
	/* If not Initialized then initialize all required hardware and software */
	if(WaveDAC8_1_initVar == 0u)
	{
		WaveDAC8_1_Init();
		WaveDAC8_1_initVar = 1u;
	}
	
	WaveDAC8_1_Enable();
}


/*******************************************************************************
* Function Name: WaveDAC8_1_StartEx
********************************************************************************
*
* Summary:
*  The StartEx function sets pointers and sizes for both waveforms
*  and then starts the component.
*
* Parameters:  
*   uint8 * wavePtr1:     Pointer to the waveform 1 array.
*   uint16  sampleSize1:  The amount of samples in the waveform 1.
*   uint8 * wavePtr2:     Pointer to the waveform 2 array.
*   uint16  sampleSize2:  The amount of samples in the waveform 2.
*
* Return: 
*  None
*
* Reentrant:
*  No
*
*******************************************************************************/
void WaveDAC8_1_StartEx(const uint8 * wavePtr1, uint16 sampleSize1, const uint8 * wavePtr2, uint16 sampleSize2)

{
	WaveDAC8_1_Wave1Setup(wavePtr1, sampleSize1);
	WaveDAC8_1_Wave2Setup(wavePtr2, sampleSize2);
	WaveDAC8_1_Start();
}


/*******************************************************************************
* Function Name: WaveDAC8_1_Stop
********************************************************************************
*
* Summary:
*  Stops the clock (if internal), disables the DMA channels
*  and powers down the DAC.
*
* Parameters:  
*  None  
*
* Return: 
*  None
*
*******************************************************************************/
void WaveDAC8_1_Stop(void) 
{
	/* Turn off internal clock, if one present */
	#if(WaveDAC8_1_CLOCK_SRC == WaveDAC8_1_CLOCK_INT)  	
	   WaveDAC8_1_DacClk_Stop();
	#endif /* WaveDAC8_1_CLOCK_SRC == WaveDAC8_1_CLOCK_INT */
	
	/* Disble DMA channels */
	(void)CyDmaChDisable(WaveDAC8_1_Wave1Chan);
	(void)CyDmaChDisable(WaveDAC8_1_Wave2Chan);

	/* Disable power to DAC */
	WaveDAC8_1_VDAC8_Stop();
}


/*******************************************************************************
* Function Name: WaveDAC8_1_Wave1Setup
********************************************************************************
*
* Summary:
*  Sets pointer and size for waveform 1.                                    
*
* Parameters:  
*  uint8 * WavePtr:     Pointer to the waveform array.
*  uint16  SampleSize:  The amount of samples in the waveform.
*
* Return: 
*  None 
*
*******************************************************************************/
void WaveDAC8_1_Wave1Setup(const uint8 * wavePtr, uint16 sampleSize)

{
	#if (CY_PSOC3)
		uint16 memoryType; /* determining the source memory type */
		memoryType = (WaveDAC8_1_HI16FLASHPTR == HI16(wavePtr)) ? HI16(CYDEV_FLS_BASE) : HI16(CYDEV_SRAM_BASE);
		
		WaveDAC8_1_Wave1Chan = WaveDAC8_1_Wave1_DMA_DmaInitialize(
		WaveDAC8_1_Wave1_DMA_BYTES_PER_BURST, WaveDAC8_1_Wave1_DMA_REQUEST_PER_BURST,
		memoryType, HI16(CYDEV_PERIPH_BASE));
	#else /* PSoC 5 */
		WaveDAC8_1_Wave1Chan = WaveDAC8_1_Wave1_DMA_DmaInitialize(
		WaveDAC8_1_Wave1_DMA_BYTES_PER_BURST, WaveDAC8_1_Wave1_DMA_REQUEST_PER_BURST,
		HI16(wavePtr), HI16(WaveDAC8_1_DAC8__D));
	#endif /* CY_PSOC3 */
	
	/*
	* TD is looping on itself. 
    * Increment the source address, but not the destination address. 
	*/
	(void)CyDmaTdSetConfiguration(WaveDAC8_1_Wave1TD, sampleSize, WaveDAC8_1_Wave1TD, 
                                    (uint8)CY_DMA_TD_INC_SRC_ADR | (uint8)WaveDAC8_1_Wave1_DMA__TD_TERMOUT_EN); 
	
	/* Set the TD source and destination address */
	(void)CyDmaTdSetAddress(WaveDAC8_1_Wave1TD, LO16((uint32)wavePtr), LO16(WaveDAC8_1_DAC8__D));
	
	/* Associate the TD with the channel */
	(void)CyDmaChSetInitialTd(WaveDAC8_1_Wave1Chan, WaveDAC8_1_Wave1TD);
}


/*******************************************************************************
* Function Name: WaveDAC8_1_Wave2Setup
********************************************************************************
*
* Summary:
*  Sets pointer and size for waveform 2.                                    
*
* Parameters:  
*  uint8 * WavePtr:     Pointer to the waveform array.
*  uint16  SampleSize:  The amount of samples in the waveform.
*
* Return: 
*  None
*
*******************************************************************************/
void WaveDAC8_1_Wave2Setup(const uint8 * wavePtr, uint16 sampleSize)
 
{
	#if (CY_PSOC3)
		uint16 memoryType; /* determining the source memory type */
		memoryType = (WaveDAC8_1_HI16FLASHPTR == HI16(wavePtr)) ? HI16(CYDEV_FLS_BASE) : HI16(CYDEV_SRAM_BASE);
			
		WaveDAC8_1_Wave2Chan = WaveDAC8_1_Wave2_DMA_DmaInitialize(
		WaveDAC8_1_Wave2_DMA_BYTES_PER_BURST, WaveDAC8_1_Wave2_DMA_REQUEST_PER_BURST,
		memoryType, HI16(CYDEV_PERIPH_BASE));
	#else /* PSoC 5 */
		WaveDAC8_1_Wave2Chan = WaveDAC8_1_Wave2_DMA_DmaInitialize(
		WaveDAC8_1_Wave2_DMA_BYTES_PER_BURST, WaveDAC8_1_Wave2_DMA_REQUEST_PER_BURST,
		HI16(wavePtr), HI16(WaveDAC8_1_DAC8__D));
	#endif /* CY_PSOC3 */
	
	/*
	* TD is looping on itself. 
	* Increment the source address, but not the destination address. 
	*/
	(void)CyDmaTdSetConfiguration(WaveDAC8_1_Wave2TD, sampleSize, WaveDAC8_1_Wave2TD, 
                                    (uint8)CY_DMA_TD_INC_SRC_ADR | (uint8)WaveDAC8_1_Wave2_DMA__TD_TERMOUT_EN); 
	
	/* Set the TD source and destination address */
	(void)CyDmaTdSetAddress(WaveDAC8_1_Wave2TD, LO16((uint32)wavePtr), LO16(WaveDAC8_1_DAC8__D));
	
	/* Associate the TD with the channel */
	(void)CyDmaChSetInitialTd(WaveDAC8_1_Wave2Chan, WaveDAC8_1_Wave2TD);
}


/* [] END OF FILE */
