## Librerías usadas

### Adafruit_Fingerprint

Es la librería encargada del manejo de eventos, configuraciones y control del sensor FPM10A,
la cual es creada por el mismo desarrollador del dispositivo.

Código fuente: [Adafruit_Fingerprint](https://github.com/adafruit/Adafruit-Fingerprint-Sensor-Library)


### SoftwareSerial

Esta librería se encarga de la comunicación serial entre los distintos puertos RX/TX de arduino con los dispositivos que hacen uso de estos,
también se comunica con el monitor serie para pode escribir y leer datos de este mismo. Esta viene por defecto en el IDE de Arduino.

Librería: [SoftwareSerial](https://www.arduino.cc/en/Reference/SoftwareSerial)


### VoiceRecognitionV3

Esta librería se encarga del manejo de todos los eventos, así como la configuración y programación del dispositivo empleado para el 
reconocimiento de vos, el ELECHOUSE Voice Recognition. La cual también ha sido creada por el mismo desarrollador del periférico.

Código fuente: [VoiceRecognitionV3](https://github.com/elechouse/VoiceRecognitionV3)


### Keypad

Esta es la librería que se utiliza para poder hacer uso de los diferentes Keypad, esta sirve para hacer la configuración del pinout del
teclar, ya que se puede configurar que puertos se desean usar, dependiendo de las filas y columnas con las que este cuente, se puede utilizar
tanto para el Keypad 3x4 como para el 4x4.

Librería: [Keypad](https://playground.arduino.cc/Code/Keypad/)


### Wire

Esta es la librería que hace posible la comunicación mediante nuestro el protocolo I2C, nos permite reducir la cantidad de pines usados para
la comunicación con otros dispositivos como el caso de un display 16x2, se emplea un shield I2C y basta con importar la librería y hacer uso de esta
para facilitar el envío de datos a nuestro display.

Librería [Wire](https://www.arduino.cc/en/reference/wire)


### LiquidCrystal_I2C

Esta librería al igual que Wire nos sirve para facilitar la comunicación de Arduino con el display mediante I2C, ambas trabajan en conjunto
para poder hacer posible esta comunicación, reduciendo así la cantidad de código, tiempo y materiales empleados por el usuario.
La podemos encontrar en varias versiones, en la página de Arduino Playground podemos ver la descripción y uso de cada una de estas,
algunas son específicas para ciertos tipos de display y depende del que se utilice, así será la librería.

Librería [LiquidCrystal_I2C/LCDi2c](https://playground.arduino.cc/Code/LCDi2c/)
