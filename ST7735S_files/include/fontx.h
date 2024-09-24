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

#ifndef _HAGL_FONTX_H
#define _HAGL_FONTX_H

#ifdef __cplusplus
extern "C" {
#endif

#define FONTX_OK                   (0)
#define FONTX_ERR_GLYPH_NOT_FOUND  (1)
#define FONTX_NAME                 (6) //WC: none used
#define FONTX_WIDTH               (0) //0
#define FONTX_HEIGHT              (1) //1
#define FONTX_TYPE                (16) //WC: none used
#define FONTX_TYPE_SBCS            (0)
#define FONTX_TYPE_DBCS            (1)
#define FONTX_GLYPH_DATA_START    (17)
#define FONTX_BLOCK_TABLE_SIZE    (17)
#define FONTX_BLOCK_TABLE_START   (18)

#define BASIC_FONT_DATA_FIELDS 4
#define BASIC_CHAR_DATA_FIELDS 4
#define CHAR_BITMAP_FIELDS_OFFSET 2
#define CHAR_WIDTH_OFFSET 3

#include <stdint.h>
#include <stddef.h>

/* Pitch is bytes per row. Size is size in bytes. */

typedef struct{
    uint8_t size;
    uint8_t pitch;

	uint16_t width;
	uint16_t height;
	uint16_t firstChar;
	uint16_t numbersOfChar;

	uint16_t addr;
	uint16_t wordsPerChar;
	uint16_t charWidth;

    const uint16_t *buffer;
}font_data_t;


typedef struct{
    uint8_t width;
    uint8_t height;
} font_demensions_t;


/**
 * Fill font_demensions_t struct with choosen with width and height of choosen font.
 *
 * @param fontDemensions [in/out] pointer font_demensions_t struct.
 * @param font [in] pointer to file with font.
 * @return Maximum area of ​​the single character.
 */
uint16_t get_font_dimensions(font_demensions_t *fontDemensions, const uint16_t *font);

/**
 * Fill font_demensions_t struct with choosen with width and height of choosen font.
 *
 * @param fontDemensions [in/out] pointer font_demensions_t struct.
 * @param code [in] current character code.
 * @param font [in] pointer to file with font.
 * @return Maximum area of ​​the single character.
 */
uint16_t get_font_data(font_data_t *fontData, uint8_t code, const uint16_t *font);

#ifdef __cplusplus
}
#endif
#endif /* _HAGL_FONTX_H */
