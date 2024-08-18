/*
 * hagl_hal.h
 *
 *  Created on: Aug 6, 2024
 *      Author: czeko
 */

#ifndef INC_HAGL_HAL_H_
#define INC_HAGL_HAL_H_

#include "../../ST7735S_files/include/bitmap.h"
#include "../../ST7735S_files/include/lcd.h"

#define DISPLAY_WIDTH 	(LCD_WIDTH)
#define DISPLAY_HEIGHT 	(LCD_HEIGHT)
#define DISPLAY_DEPTH 	16

typedef uint16_t color_t;

#define hagl_hal_put_pixel lcd_put_pixel

#endif /* INC_HAGL_HAL_H_ */
