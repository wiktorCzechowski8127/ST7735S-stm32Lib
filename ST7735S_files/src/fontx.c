/*

MIT License

Copyright (c) 2012 ChaN
Copyright (c) 2020 Mika Tuupola

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

-cut-

This file is part of the HAGL graphics library:
https://github.com/tuupola/hagl


Adapted from the blog post by ChaN:
http://elm-chan.org/docs/dosv/fontx_e.html

SPDX-License-Identifier: MIT

*/

#include "../../ST7735S_files/include/fontx.h"

#include <stdint.h>
#include <stddef.h>
#include <string.h>


uint16_t get_font_dimensions(font_demensions_t *fontDemensions, const uint16_t *font)
{
	fontDemensions->width = font[FONTX_WIDTH];
	fontDemensions->height = font[FONTX_HEIGHT];

    return (fontDemensions->width * fontDemensions->height);
}



uint16_t get_font_data(font_data_t *fontData, uint8_t code, const uint16_t* font)
{
	fontData->width = font[0];
	fontData->height = font[1];

	uint16_t firstCharNumber = font[2];
	uint16_t numberOfChars = font[3];
	uint16_t charDataAddr = BASIC_FONT_DATA_FIELDS + (code - firstCharNumber) * BASIC_CHAR_DATA_FIELDS;
	uint16_t charBitfieldAddr = (((uint16_t)font[charDataAddr] << 8) | font[charDataAddr + 1]) +
								(numberOfChars * BASIC_CHAR_DATA_FIELDS) + BASIC_FONT_DATA_FIELDS;

	fontData->buffer = &font[charBitfieldAddr];

	fontData->wordsPerChar = font[charDataAddr + CHAR_BITMAP_FIELDS_OFFSET];
	fontData->charWidth = font[charDataAddr + CHAR_WIDTH_OFFSET];

	fontData->pitch = (fontData->width + 7) / 8;
	fontData->size = fontData->pitch * fontData->height;

	return (fontData->width * fontData->height);
}
