
//	Automatically boots device into flashing mode as when BOOTSEL is held down during power-up or when at factory settings.
//	First parameter sets which GPIOs to use to indicate USB data activity (use 1<<LED_BUILTIN for built-in LED);

int main(){
	reset_usb_boot(0,0);
	return 0;
}
