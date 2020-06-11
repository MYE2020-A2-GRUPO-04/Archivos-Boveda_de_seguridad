# Lector de huella digital FPM10A

El dispositivo integra un sensor óptico, un procesador de alta velocidad (DSP), algoritmos de alto desempeño para la identificación,
verificación de huellas y memoria flash para almacenamiento de usuarios. Es necesario conectarlo a un microcontrolador mediante el 
puerto serial TTL, luego se solicita la captura de huellas, búsqueda, detección, etc.

Todo el procesamiento de captura/verificación/búsqueda es realizado por el DSP y responde con comandos sencillos de interpretar. 

Se pueden almacenar hasta 300 huellas en la memoria flash del dispositivo. El sensor óptico incluye un led verde, de manera que 
se pueda saber cuándo el sensor está trabajando. Este sensor incluye además un software para PC-WINDOWS y así poder hacer uso 
completo de sus capacidades. Utilizado en aplicaciones como: control de acceso, cerraduras electrónicas, control de asistencia,
autenticación en finanzas, maquinaria industrial, equipos POS, entre otros.


## Especificaciones tecnicas

- Voltaje de operación: 3.3 VDC
- Consumo corriente: <120mA
- Consumo de corriente pico: 140mA
- Tiempo de muestreo: <1 segundo
- Dimensiones de ventana: 14*18mm
- Peso de archivo de huella: 256 bytes
- Peso de archivo de plantilla: 512 bytes
- Cantidad de huellas almacenadas: 300 
- Taza de falso positivo (FAR): <0.001% (Nivel de Seguridad:3)
- Taza de rechazo erroneo (FRR): <1.0% (Nivel de seguridad:3)
- Tiempo de busqueda: <1.0 segundos
- Interface: UART TTL
- Baudrate: 9600, 19200, 28800, 38400, 57600 (por defecto 57600)
- Temperatura de funcionamiento> -20° hasta 50°C
- Humedad Relativa: 40% hasta 85% RH
