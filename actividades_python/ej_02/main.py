from gpiozero import LED, Button
from signal import pause
from time import sleep

#establezco el led y el color
led_verde = LED(13)
led_rojo = LED(19)
led_azul = LED(26)

#establezo un bucle que prende los leds y los apaga despues de un tiempo determinado 
while True:
	led_rojo.on()
	sleep(1)
	led_rojo.off()
	
	led_azul.on()
	sleep(0.5)
	led_azul.off()

	led_verde.on()
	sleep(0.25)
	led_verde.off()
	

pause()
