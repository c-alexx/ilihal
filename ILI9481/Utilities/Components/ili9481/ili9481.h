/**
  ******************************************************************************
  * @file    ili9481.h
  * @author  MCD Application Team
  * @version V1.0.2
  * @date    02-December-2014
  * @brief   This file contains all the functions prototypes for the ili9481.c
  *          driver.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT(c) 2014 STMicroelectronics</center></h2>
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */ 

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __ILI9481_H
#define __ILI9481_H

#ifdef __cplusplus
 extern "C" {
#endif 

/* Includes ------------------------------------------------------------------*/
#include "../Common/lcd.h"
#include "stm32f4xx_hal.h"

/** @addtogroup BSP
  * @{
  */ 

/** @addtogroup Components
  * @{
  */ 
  
/** @addtogroup ILI9481
  * @{
  */

/** @defgroup ILI9481_Exported_Types
  * @{
  */
/**
  * @}
  */ 

/** @defgroup ILI9481_Exported_Constants
  * @{
  */

/** 
  * @brief ILI9481 chip IDs
  */ 
#define ILI9481_ID                  0x9481

/** 
  * @brief  ILI9481 Size
  */  
#define  ILI9481_LCD_PIXEL_WIDTH    ((uint16_t)320)
#define  ILI9481_LCD_PIXEL_HEIGHT   ((uint16_t)480)

/** 
  * @brief  ILI9481 Timing
  */     
/* Timing configuration  (Typical configuration from ILI9481 datasheet)
  HSYNC=10 (9+1)
  HBP=20 (29-10+1)
  ActiveW=240 (269-20-10+1)
  HFP=10 (279-240-20-10+1)

  VSYNC=2 (1+1)
  VBP=2 (3-2+1)
  ActiveH=320 (323-2-2+1)
  VFP=4 (327-320-2-2+1)
*/
#define  ILI9481_HSYNC            ((uint32_t)9)   /* Horizontal synchronization */
#define  ILI9481_HBP              ((uint32_t)29)    /* Horizontal back porch      */
#define  ILI9481_HFP              ((uint32_t)2)    /* Horizontal front porch     */
#define  ILI9481_VSYNC            ((uint32_t)1)   /* Vertical synchronization   */
#define  ILI9481_VBP              ((uint32_t)3)    /* Vertical back porch        */
#define  ILI9481_VFP              ((uint32_t)2)    /* Vertical front porch       */

/** 
  * @brief  ILI9481 Registers
  */

/* Level 1 Commands */
#define LCD_NOOP				0x00   /* No Operation*/
#define LCD_SWRESET             0x01   /* Software Reset */
#define LCD_RDDPM               0x0A   /* Read Display Power Mode */
#define LCD_RDDMADCTL           0x0B   /* Read Display MADCTL */
#define LCD_RDDCOLMOD           0x0C   /* Read Display Pixel Format */
#define LCD_RDDIM               0x0D   /* Read Display Image Format */
#define LCD_RDDSM               0x0E   /* Read Display Signal Mode */
#define LCD_RDDSDR              0x0F   /* Read Display Self-Diagnostic Result */
#define LCD_SPLIN               0x10   /* Enter Sleep Mode */
#define LCD_SLEEP_OUT           0x11   /* Sleep out register */
#define LCD_PTLON               0x12   /* Partial Mode ON */
#define LCD_NORMAL_MODE_ON      0x13   /* Normal Display Mode ON */
#define LCD_DINVOFF             0x20   /* Display Inversion OFF */
#define LCD_DINVON              0x21   /* Display Inversion ON */
#define LCD_GAMMA               0x26   /* Gamma register */
#define LCD_DISPLAY_OFF         0x28   /* Display off register */
#define LCD_DISPLAY_ON          0x29   /* Display on register */
#define LCD_COLUMN_ADDR         0x2A   /* Column address register */
#define LCD_PAGE_ADDR           0x2B   /* Page address register */
#define LCD_GRAM                0x2C   /* GRAM register */
#define LCD_RGBSET              0x2D   /* Color SET */
#define LCD_RAMRD               0x2E   /* Memory Read */
#define LCD_PLTAR               0x30   /* Partial Area */
#define LCD_VSCRDEF             0x33   /* Vertical Scrolling Definition */
#define LCD_TEOFF               0x34   /* Tearing Effect Line OFF */
#define LCD_TEON                0x35   /* Tearing Effect Line ON */
#define LCD_MAC                 0x36   /* Memory Access Control register*/
#define LCD_VSCRSADD            0x37   /* Vertical Scrolling Start Address */
#define LCD_IDMOFF              0x38   /* Idle Mode OFF */
#define LCD_IDMON               0x39   /* Idle Mode ON */
#define LCD_PIXEL_FORMAT        0x3A   /* Pixel Format register */
#define LCD_WRITE_MEM_CONTINUE  0x3C   /* Write Memory Continue */
#define LCD_READ_MEM_CONTINUE   0x3E   /* Read Memory Continue */
#define LCD_SET_TEAR_SCANLINE   0x44   /* Set Tear Scanline */
#define LCD_GET_SCANLINE        0x45   /* Get Scanline */
#define LCD_READ_DDB_START		0xA1   /* Read DDB start */

/* Level 2 Commands */
#define LCD_CMDACCPRTC		    0xB0   /* Command Access Protect  */
#define LCD_FRMCTR              0xB3   /* Frame Memory Access and Interface setting  */
#define LCD_DMFMCTR             0xB4   /* Display Mode and Frame Memory Write Mode
setting */
#define LCD_DEVCODERD	        0xBF   /* Device code read */
#define LCD_PANEL_DRV_CTL       0xC0   /* Panel Driving Setting */
#define LCD_NORMAL_TIMING_WR    0xC1   /* Display Timing Setting for Normal Mode  */
#define LCD_PARTIAL_TIMING_WR   0xC2   /* Display Timing Setting for Partial Mode  */
#define LCD_IDLE_TIMING_WR      0xC3   /* Display Timing Setting for Idle Mode  */
#define LCD_FR_INV_CTL          0xC5   /* Frame rate and Inversion Control  */
#define LCD_INTERFACE           0xC6   /* Interface Control */
#define LCD_GAMMAWR				0xC8   /* Gamma Setting */
#define LCD_POWER               0xD0   /* POWER CONTROL */
#define LCD_VCOM	            0xD1   /* VCOM Control */
#define LCD_NORMAL_PWR_WR	    0xD2   /* Power Setting for Normal Mode  */
#define LCD_PARTIAL_PWR_WR      0xD3   /* Power Setting for Partial Mode  */
#define LCD_IDLE_PWR_WR         0xD4   /* Power Setting for Idle Mode  */
#define LCD_NVMEMWR             0xE0   /* NV Memory Write  */
#define LCD_NVMEMCTRL           0xE1   /* NV Memory Control */
#define LCD_NVMEMRD  	        0xE2   /* NV Memory Status */
#define LCD_NVMEMPRT            0xE3   /* NV Memory Protection  */
#define LCD_EEPROMWR_ENABLE		0xE8   /* EEPROM Write Enable  */
#define LCD_EEPROMWR_DISABLE    0xE9   /* EEPROM Write Disable  */
#define LCD_EEPROMWR			0xEA   /* EEPROM Word Write */
#define LCD_EEPROMRD            0xEB   /* EEPROM Word Read   */
#define LCD_EEPROM_ADR_SET    	0xEC   /* EEPROM Address Set */
#define LCD_EEPROM_ERASE     	0xED   /* EEPROM Erase */
#define LCD_EEPROM_ERASE_ALL    0xEE   /* EEPROM Erase All  */

/* Extend register commands */

/* Size of read registers */

/**
  * @}
  */
  
/** @defgroup ILI9481_Exported_Functions
  * @{
  */ 
void     ili9481_Init(void);
uint16_t ili9481_ReadID(void);
void     ili9481_WriteReg(uint16_t LCD_Reg);
void     ili9481_WriteData(uint16_t RegValue);
uint32_t ili9481_ReadData(uint16_t RegValue, uint8_t ReadSize);
void     ili9481_DisplayOn(void);
void     ili9481_DisplayOff(void);
uint16_t ili9481_GetLcdPixelWidth(void);
uint16_t ili9481_GetLcdPixelHeight(void);

/* LCD driver structure */
extern LCD_DrvTypeDef   ili9481_drv;

/* LCD IO functions */
void     LCD_IO_Init(void);
void     LCD_IO_WriteData(uint16_t RegValue);
void     LCD_IO_WriteReg(uint8_t Reg);
uint32_t LCD_IO_ReadData(uint16_t RegValue, uint8_t ReadSize);
void     LCD_Delay (uint32_t delay);
      
#ifdef __cplusplus
}
#endif

#endif /* __ILI9481_H */

/**
  * @}
  */ 

/**
  * @}
  */ 

/**
  * @}
  */ 

/**
  * @}
  */
  
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
