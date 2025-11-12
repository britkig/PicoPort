#pragma once  // FOR PI PICO ONLY
#include <hardware/gpio.h>
struct Pin{
protected:
	uint8_t _p;
	Pin(uint8_t p){
		gpio_init(_p=p);
	}
};
