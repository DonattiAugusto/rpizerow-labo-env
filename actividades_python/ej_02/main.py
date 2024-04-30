from gpiozero import LED, Button
from signal import pause
from time import sleep

#declaro que led usar y su respectivo color
led_verde = LED(13)
led_rojo = LED(19)
led_azul = LED(26)

#declaro un bucle while true que enciende los leds un tiempo determinado
#y los apaga
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
