# Instalación

## Ensamblado de periféricos

### Generales

Como primer paso debemos extraer las lineas de 5VDC y GND ya que estaremos ocupando constantemente estas dos líneas

### FPM10A

Este sensor lo primero que se debe de hacer es configurarlo, como primer paso, se conecta al arduino y se debe de utilizar
según la documentación el programa de registro de huellas [Enroll](https://github.com/adafruit/Adafruit-Fingerprint-Sensor-Library/blob/master/examples/enroll/enroll.ino)
y registrar dentro del sensor las huellas a utilizar. Solo se modifican los puertos indicados en en los diagramas de conexión.

### ELECHOUSE Voice Recognition V3

Al igual que el sensor de FPM10A este se debe configurar previamente, se debe de conectar según los diagramas a nuestro
Arduino, y además para registrar las voces de los usuarios, es necesario ejecutar el programa[VR sample train](https://github.com/elechouse/VoiceRecognitionV3/blob/master/examples/vr_sample_train/vr_sample_train.ino)
Luego de esto, estará listo para usarse al igual que el elemento anterior.

### HC06

Como podemos ver, en el apartado de conexiones, también se encuentra cómo conectarse, este no se debe de configurar previamente
como los dispositivos anteriores, pero para el uso de este es necesario la programación de una app movil la cual envíe como parámetro
una variable del tipo String con la palabra "OK", para esto podemos hacer uso de un solo botón en la app y se puede hacer en
Anroid Studio con código Java/kotlin o ya sea con Flutter o React Native.

## Etapa de poder

Además se debe de ensamblar la etapa de potencia, esto se hace conectando ya sea la MT1 o la MT2 a GND junto con una de las
terminales del devanado secundario del transformador mientras que la otra se conecta a un extremo de la cerradura eléctrica
y el otro extremo de la cerradura al MT sobrante del TRIAC y el pin 8 del Arduino, debe ir conectado al GATE del TRIAC.

12VAC---Cerradura---MT1--GATE/pin8---MT2---12VAC

:open_hands:

## Montado de la cerradura

Para esto es necesario hacer las perforaciones pertinentes en nuestra caja de metal, para podes insertar la cerradura y poder soldarla,
también es necesario, abrir otros espacios para podes dejar motados el sensor de huella digita y un pequeño agujero para el micrófono.

## Montando el sistema

El sistema debe de ir en un caja y este se debe de encontrar dentro de la caja fuerte, ya que estando fuera es tan fácil como inyectar
5VDC al pin que conectal el arduino con el TRIAC para poder abrir la caja, por esa razón debe de ir todo por dentro sin exponer ningun cable.
