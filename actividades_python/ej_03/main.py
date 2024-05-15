from gpiozero import LED, Buzzer
from time import sleep

# Inicialización de componentes
led_verde = LED(13)
led_rojo = LED(19)
led_azul = LED(26)
bzz = Buzzer(22)

while True:
    # Solicitar comando al usuario
    comando = input("Introduce el comando (Formato: comando.opcion):")

    # Opciones de comando, con manejo de errores
    if comando == "buzz.on":
        bzz.on()
    elif comando == "buzz.off":
        bzz.off()
    elif comando == "rgb.red":
        led_rojo.on()
        led_azul.off()
        led_verde.off()
    elif comando == "rgb.blue":
        led_azul.on()
        led_verde.off()
        led_rojo.off()
    elif comando == "rgb.green":
        led_verde.on()
        led_azul.off()
        led_rojo.off()
    else:
        # Manejo de errores para comandos incorrectos
        print("Error: comando no reconocido")
