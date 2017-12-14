/**
 ******************************************************************************
 * @file    ili9481.c
 * @author  MCD Application Team
 * @version V1.0.2
 * @date    02-December-2014
 * @brief   This file includes the LCD driver for ILI9481 LCD.
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

/* Includes ------------------------------------------------------------------*/
#include "ili9481.h"

/** @addtogroup BSP
 * @{
 */

/** @addtogroup Components
 * @{
 */

/** @addtogroup ILI9481
 * @brief This file provides a set of functions needed to drive the
 *        ILI9481 LCD.
 * @{
 */

/** @defgroup ILI9481_Private_TypesDefinitions
 * @{
 */
/**
 * @}
 */

/** @defgroup ILI9481_Private_Defines
 * @{
 */
/**
 * @}
 */

/** @defgroup ILI9481_Private_Macros
 * @{
 */
/**
 * @}
 */

/** @defgroup ILI9481_Private_Variables
 * @{
 */

LCD_DrvTypeDef   ili9481_drv =
{
		ili9481_Init,
		ili9481_ReadID,
		ili9481_DisplayOn,
		ili9481_DisplayOff,
		0,
		0,
		0,
		0,
		0,
		0,
		ili9481_GetLcdPixelWidth,
		ili9481_GetLcdPixelHeight,
		0,
		0,
};

/**
 * @}
 */

/** @defgroup ILI9481_Private_FunctionPrototypes
 * @{
 */

/**
 * @}
 */

/** @defgroup ILI9481_Private_Functions
 * @{
 */

/**
 * @brief  Power on the LCD.
 * @param  None
 * @retval None
 */
void ili9481_Init(void)
{
	/* Initialize ILI9481 low level bus layer ----------------------------------*/
	LCD_IO_Init();

	LCD_Delay(120);
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_1, GPIO_PIN_SET);
	LCD_Delay(20);
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_1, GPIO_PIN_RESET);
	LCD_Delay(20);
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_1, GPIO_PIN_SET);
	LCD_Delay(20);

	/* Configure LCD */

	//************* Start Initial Sequence **********//
	ili9481_WriteReg(LCD_SLEEP_OUT);
	LCD_Delay(120);

	ili9481_WriteReg(LCD_NORMAL_MODE_ON);

	ili9481_WriteReg(LCD_POWER);
	ili9481_WriteData(0x07);
	ili9481_WriteData(0x43);
	ili9481_WriteData(0x15);

	ili9481_WriteReg(LCD_VCOM);
	ili9481_WriteData(0x00);
	ili9481_WriteData(0x07);//07
	ili9481_WriteData(0x10);

	ili9481_WriteReg(LCD_NORMAL_PWR_WR);
	ili9481_WriteData(0x01);
	ili9481_WriteData(0x02);

	ili9481_WriteReg(LCD_PANEL_DRV_CTL);
	ili9481_WriteData(0x10);
	ili9481_WriteData(0x3B);
	ili9481_WriteData(0x00);
	ili9481_WriteData(0x02);
	ili9481_WriteData(0x11);

	ili9481_WriteReg(LCD_FR_INV_CTL);
	ili9481_WriteData(0x03);

	ili9481_WriteReg(LCD_GAMMAWR);
	ili9481_WriteData(0x00);
	ili9481_WriteData(0x32);
	ili9481_WriteData(0x36);
	ili9481_WriteData(0x45);
	ili9481_WriteData(0x06);
	ili9481_WriteData(0x16);
	ili9481_WriteData(0x37);
	ili9481_WriteData(0x75);
	ili9481_WriteData(0x77);
	ili9481_WriteData(0x54);
	ili9481_WriteData(0x0C);
	ili9481_WriteData(0x00);

	ili9481_WriteReg(LCD_PIXEL_FORMAT);
	ili9481_WriteData(0x55);

	ili9481_WriteReg(LCD_COLUMN_ADDR);
	ili9481_WriteData(0x00);
	ili9481_WriteData(0x00);
	ili9481_WriteData(0x01);
	ili9481_WriteData(0x3F);

	ili9481_WriteReg(LCD_PAGE_ADDR);
	ili9481_WriteData(0x00);
	ili9481_WriteData(0x00);
	ili9481_WriteData(0x01);
	ili9481_WriteData(0xE0);
	LCD_Delay(100);
	ili9481_WriteReg(LCD_DISPLAY_ON);

	ili9481_WriteReg(LCD_MAC);
	ili9481_WriteData(1<<3);

	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_SET);
}

/**
 * @brief  Enables the Display.
 * @param  None
 * @retval None
 */
void ili9481_DisplayOn(void)
{
	/* Display On */
	ili9481_WriteReg(LCD_DISPLAY_ON);
}

/**
 * @brief  Disables the Display.
 * @param  None
 * @retval None
 */
void ili9481_DisplayOff(void)
{
	/* Display Off */
	ili9481_WriteReg(LCD_DISPLAY_OFF);
}

/**
 * @brief  Writes  to the selected LCD register.
 * @param  LCD_Reg: address of the selected register.
 * @retval None
 */
void ili9481_WriteReg(uint16_t LCD_Reg)
{
	LCD_IO_WriteReg(LCD_Reg);
}

/**
 * @brief  Writes data to the selected LCD register.
 * @param  LCD_Reg: address of the selected register.
 * @retval None
 */
void ili9481_WriteData(uint16_t RegValue)
{
	LCD_IO_WriteData(RegValue);
}

/**
 * @brief  Reads the selected LCD Register.
 * @param  RegValue: Address of the register to read
 * @param  ReadSize: Number of bytes to read
 * @retval LCD Register Value.
 */
uint32_t ili9481_ReadData(uint16_t RegValue, uint8_t ReadSize)
{
	/* Read a max of 4 bytes */
	return (LCD_IO_ReadData(RegValue, ReadSize));
}

/**
 * @brief  Get LCD PIXEL WIDTH.
 * @param  None
 * @retval LCD PIXEL WIDTH.
 */
uint16_t ili9481_GetLcdPixelWidth(void)
{
	/* Return LCD PIXEL WIDTH */
	return ILI9481_LCD_PIXEL_WIDTH;
}

/**
 * @brief  Get LCD PIXEL HEIGHT.
 * @param  None
 * @retval LCD PIXEL HEIGHT.
 */
uint16_t ili9481_GetLcdPixelHeight(void)
{
	/* Return LCD PIXEL HEIGHT */
	return ILI9481_LCD_PIXEL_HEIGHT;
}

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
