# Display 16x2 (I2C)

LCD son las siglas en inglés de Liquid Crystal Dysplay, 
pantalla de cristal líquido en español, 
un tipo de dispositivo que se utiliza para la visualización de diferentes tipos de contenidos o información de manera gráfica, 
mediante el uso de diferentes caracteres, símbolos o dibujos.

La segunda parte de este término, 16x2, 
se refiere a que la pantalla cuenta con dos filas, 
cada una con la capacidad para mostrar hasta dieciséis caracteres, 
símbolos o figuras, 
según su programación.

Entonces, 
el término LCD 16x2 se refiere a un pequeño dispositivo con pantalla de cristal líquido que cuenta con dos filas, 
de dieciséis caracteres cada una, 
que se utiliza para mostrar información, 
por lo general alfanumérica. 
Las capacidades de estos dispositivos son altas, 
pues se puede mostrar todo tipo de información sin importar qué tipo de símbolos o caracteres sean,
el idioma o el lenguaje, 
pues el sistema puede mostrar cualquier carácter alfanumérico,
símbolos y algunas figuras, 
el número de píxeles que tiene cada símbolo o carácter varía dependiendo del modelo del dispositivo,
y cada artefacto está controlado por un microcontrolador que está programado para:
dirigir el funcionamiento y la imagen mostrada en la pantalla.

## Protocolo I2C

I2C es un puerto y protocolo de comunicación serial, 
define la trama de datos y las conexiones físicas para transferir bits entre 2 dispositivos digitales. 
El puerto incluye dos cables de comunicación, SDA y SCL. 
Además el protocolo permite conectar hasta 127 dispositivos esclavos con esas dos líneas, 
con hasta velocidades de 100, 400 y 1000 kbits/s. 
También es conocido como IIC ó TWI – Two Wire Interface.

El protocolo I2C es uno de los más utilizados para comunicarse con sensores digitales, 
ya que a diferencia del puerto Serial,
su arquitectura permite tener una confirmación de los datos recibidos,
dentro de la misma trama, entre otras ventajas.

El Módulo adaptador LCD a I2C que usaremos está basado en el controlador I2C PCF8574, 
el cual es un Expansor de Entradas y Salidas digitales controlado por I2C. 
Por el diseño del PCB este módulo se usa especialmente para controlar un LCD Alfanumérico.

La dirección I2C por defecto del módulo puede ser 0x3F o en otros casos 0x27. 
Es muy importante identificar correctamente la dirección I2C de nuestro modulo, 
pues de otra forma nuestro programa no funcionará correctamente. 
Para identificar la dirección especifica de nuestro módulo podemos utilizar un pequeño sketch de prueba llamado: 
I2C Scanner, el cual nos permite identificar la dirección I2C del dispositivo conectado al Arduino. 
Si en caso existiera la necesidad de trabajar con más de un LCD,
podemos modificar la dirección I2C del modulo adaptador. 
Para esto es necesario soldar los puentes A0, A1 y A2 presentes en el módulo,
estos tres puentes son los bits menos significativos de la dirección I2C del módulo. 
La dirección 0x3F en binario sería: 0|0|1|1|1|A2|A1|A0 y la dirección 0x27: 0|0|1|0|0|A2|A1|A0.
Por defecto A0, A2, A1 valen 1 pero si soldamos los puentes,
estos se conectan a tierra teniendo un valor 0. 
Por ejemplo si soldamos los tres puentes la nueva dirección sería 0|0|1|0|0|0|0|0 (0x20), 
para un chip que anteriormente era 0x27.
