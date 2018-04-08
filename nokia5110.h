/* Nokia 5110 LCD AVR Library
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public Licence
 * as published by the Free Software Foundation; either version 3
 * of the Licence, or (at your option) any later version.
 *
 * Original library written by Sergey Denisov aka LittleBuster
 * https://github.com/LittleBuster/avr-nokia5110
 */

#ifndef __NOKIA_5110_H__
#define __NOKIA_5110_H__

#include <avr/pgmspace.h>
#include <stdint.h>

/*
 * LCD's port
 */
#define PORT_LCD PORTB
#define DDR_LCD DDRB

/*
 * LCD's pins
 */
#define LCD_SCE PB0
#define LCD_BGL PB1
#define LCD_RST PB2
#define LCD_DC  PB3
#define LCD_DIN PB4
#define LCD_CLK PB5

/*
 * Must be called once before any other function, initializes display
 */
void nokia_lcd_init(void);

/*
 * Clear screen
 */
void nokia_lcd_clear(void);

/**
 * Power of display
 * @lcd: lcd nokia struct
 * @on: 1 - on; 0 - off;
 */
void nokia_lcd_power(uint8_t on);

/**
 * Set single pixel
 * @x: horizontal pozition
 * @y: vertical position
 * @value: show/hide pixel
 */
void nokia_lcd_set_pixel(uint8_t x, uint8_t y, uint8_t value);

/**
 * Draw single char with 1-6 scale
 * @code: char code
 * @scale: size of char
 */
void nokia_lcd_write_char(char code, uint8_t scale);

/**
 * Draw string. Example: nokia_lcd_write_string("abc",3);
 * @str: sending string
 * @scale: size of text
 */
void nokia_lcd_write_string(const char *str, uint8_t scale);

/**
 * Set cursor position
 * @x: horizontal position
 * @y: vertical position
 */
void nokia_lcd_set_cursor(uint8_t x, uint8_t y);

/**
 * Draw image to screen.
 * image  - 1bpp image data
 * wi, hi   - image width and height
 * xd, yd   - display coordinates
 */
void nokia_lcd_draw_image(const uint8_t image[], uint8_t wi, uint8_t hi, uint8_t xd, uint8_t yd);

/**
 * Render screen to display
 */
void nokia_lcd_render(void);

/**
 * Set backlight on.
 */
void nokia_lcd_backlight_on(void);

/**
 * Set backlight off.
 */
void nokia_lcd_backlight_off(void);

/**
 * Set pwm off. (pin can be used as output again)
 */
void nokia_lcd_turn_off_pwm(void);

/*
 * Set backlight intensity.
 * 0 -> 100%, 0xFF -> 0%
 * Example nokia_lcd_backlight_level(0xE0);
*/
void nokia_lcd_backlight_level(uint8_t dc);

#endif
