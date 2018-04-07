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

#include <avr/io.h>
#include <util/delay.h>

#include "nokia5110.h"

int main(void)
{
    nokia_lcd_init();
	nokia_lcd_backlight_off();
    nokia_lcd_clear();
    nokia_lcd_write_string("IT'S WORKING!",1);
    nokia_lcd_set_cursor(0, 10);
    nokia_lcd_write_string("Nice!", 3);
    nokia_lcd_render();

	for(uint8_t dc = 0xFF;dc>0x00;dc--) {
		nokia_lcd_backlight_level(dc);
        _delay_ms(50);
	}

	nokia_lcd_backlight_on();

    for (;;) {
    }
}
