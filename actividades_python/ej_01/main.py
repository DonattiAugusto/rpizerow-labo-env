from gpiozero import LED, Button
from signal import pause
#importo las librerias
led = LED(26)
button = Button(18)
#declaro los pines del led y el botón, y les asigno una variable
button.when_pressed = led.on
button.when_released = led.off
#Declaro que el led se encienda o apague cuando el boton esta
#presionado o suelto respectivamente
pause()
