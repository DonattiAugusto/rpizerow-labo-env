from gpiozero import LED, Button
from signal import pause
#importación de las librerias para usar
led = LED(26)
button = Button(18)
#establezco que pines voy a usar del botón y del led, y les pongo el igual para que sean una variable
button.when_pressed = led.on
button.when_released = led.off
#establezco que cuando el botón esté apretado o suelto, el led esté prendido o apagado
pause()
