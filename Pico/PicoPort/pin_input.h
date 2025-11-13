#pragma once  // FOR PI PICO ONLY
#include "pin.h"
struct PinInput : Pin{
private:
  static void _noop(uint gpio, uint32_t events){}
public:
  PinInput(uint8_t p,bool irq=true):Pin(p){
    gpio_set_dir(_p,GPIO_IN);
    gpio_pull_up(_p);
    if(irq){
       irq_set_enabled(IO_IRQ_BANK0,true);
       gpio_set_irq_enabled_with_callback(_p,GPIO_IRQ_EDGE_RISE|GPIO_IRQ_EDGE_FALL,true,&_noop);
    }
  }
  bool Get(){
    return !gpio_get(_p);
  }
  void WaitForState(bool s=true){
    while(Get()!=s) __wfi();
  }
  void WaitForPress(bool s=true){
    WaitForState(!s);
    WaitForState(s);
  }
};
