<h1>Display library ver 1.0 </h1>
<h2>Overview </h2>
Stm32 library for TFT display with ST7735S chip. Project beasd on Hardware Agnostic Graphics Library (https://github.com/tuupola/hagl/tree/master) and Forbot stm32 course (https://forbot.pl/blog/kurs-stm32l4-kolorowy-wyswietlacz-tft-spi-id48620). Library have few additional options and functions.

<h2>Aditional functions</h2>

<h4>current version:</h4>

- text rotation
- text size scaling
- transparent background of characters
- init function with pointer to SPI structure
- background color
- one dir to attatch

<h4>plans fo feature:</h4>

- add aditional fonts

<h2>Example</h2>


<img src="https://github.com/wiktorCzechowski8127/ST7735S-stm32Lib/blob/main/img/rotation.png" width="400" align="left">

<img src="https://github.com/wiktorCzechowski8127/ST7735S-stm32Lib/blob/main/img/scaling.png" width="400">


<h2>Manual</h2>

<h3>- Initialization</h3>

Display initialization function

__Syntax:__

```
void lcd_init(SPI_HandleTypeDef* spiHandler);
```
__Parameters:__

| Arg                | Desc                           |
|--------------------|--------------------------------|
| SPI_HandleTypeDef* | Pointer to used SPI structure. |

__Example:__
```
lcd_init(&hspi1);
```

---

<h3>- Printing buffer on display</h3>

Drawing the finished frame

__Syntax/Example:__

```
lcd_print();
```

---

<h3>- Backgoround color</h3>

Fill all display with choosen color

__Syntax:__

```
hagl_set_bg_color(color_t color);
```

__Parameters:__

| Arg                | Desc                           |
|--------------------|--------------------------------|
| color_t            | Color in RGB565 format         |

__Example:__
```
hagl_set_bg_color(0xffc0);
```

---

<h3>- Printing text</h3>

Printing text to buffer.

__Syntax:__

```
uint16_t hagl_put_text(const wchar_t *str, int16_t x0, int16_t y0, color_t color, const unsigned char *font, uint8_t rotation, uint8_t scale);
```

__Parameters:__

| Arg      |   Desc                                                                        |
|----------|-------------------------------------------------------------------------------|
| *str     | Text to print. Couse wchar type need to add L before string                   |
| x0       | X pos on display.                                                             |
| y0       | Y pos on display                                                              |
| color    | Color of text in RGB565 type.                                                  |
| font     | Pointer to font. Avaible fonts: 5x7, 5x8, 6x9. Font header file should be included before use. |
| rotation | Avaible rotation: ROTATION_NONE, ROTATION_RIGHT, ROTATION_LEFT, ROTATION_FLIP.  |
| scale    | Text scalar. Unsigned 8 bit values only. 1 = default size                                      |

__Example:__

```
hagl_put_text(L"default text", 0, 0, YELLOW, font6x9, ROTATION_NONE, 2);
```

---

Functiopns to draw geometric shapes are described in the hagl documentation: https://github.com/tuupola/hagl/tree/master




