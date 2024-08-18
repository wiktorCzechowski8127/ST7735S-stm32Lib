/*
 * lcd.h
 *
 *  Created on: Aug 5, 2024
 *      Author: czeko
 */

#ifndef SRC_LCD_H_
#define SRC_LCD_H_

#include <stdint.h>
#include "spi.h"

#define LCD_WIDTH	160
#define LCD_HEIGHT	128

#define BLACK		0x0000
#define RED			0x00f8
#define GREEN		0xe007
#define BLUE		0x1f00
#define YELLOW		0xe0ff
#define MAGENTA		0x1ff8
#define CYAN		0xff07
#define WHITE		0xffff

void set_bg_color(uint16_t color);
void lcd_init(SPI_HandleTypeDef* spiData);
void lcd_put_pixel(int x, int y, uint16_t color);
void lcd_print(void);

#endif /* SRC_LCD_H_ */
