# Triac

Un TRIAC o Triodo para Corriente Alterna es un dispositivo semiconductor, de la familia de los tiristores. 
La diferencia con un tiristor convencional es que éste es unidireccional y el TRIAC es bidireccional. 
De forma coloquial podría decirse que el TRIAC es un interruptor capaz de conmutar la corriente alterna.
Su estructura interna se asemeja en cierto modo a la disposición que formarían dos SCR en direcciones opuestas. 
Posee tres electrodos: MT1, MT2 (en este caso pierden la denominación de ánodo y cátodo) y puerta (G). 
El disparo del TRIAC se realiza aplicando una corriente al electrodo de puerta.

## Funcionamiento

Para explicar el funcionamiento de un TRIAC se suele dividir su régimen en cuadrantes según la polaridad de la puerta (G)
y el terminal secundario (MT2), ambas con respecto al terminal primario (MT1).
En los cuadrantes 1 y 2, MT2 es positivo, y la corriente fluye de MT2 a MT1 a través de capas P, N, P y N. 
La región N unida a MT2 no participa significativamente. 
En los cuadrantes 3 y 4, MT2 es negativo, y la corriente fluye de MT1 a MT2, también a través de capas P, N, P y N. 
La región N unida a MT2 está activa, pero la región N unida a MT1 sólo participa en el disparo inicial, 
no contribuye al flujo inicial de corriente.

###### Cuadrante 1

La operación del Cuadrante 1 ocurre cuando la puerta y MT2 son positivas con respecto a MT1.
La corriente de puerta activa un interruptor de transistor NPN equivalente, 
que a su vez atrae corriente desde la base de un transistor PNP equivalente, activándose también. 
Parte de la corriente de puerta (línea de puntos) se pierde a través del camino óhmico a través del silicio con dopaje p, 
fluyendo directamente en MT1 sin pasar a través de la base del transistor NPN. 

###### Cuadrante 2

La operación del Cuadrante 2 ocurre cuando la puerta es negativa y MT2 es positiva con respecto a MT1.
El encendido del dispositivo es triple y comienza cuando la corriente de MT1 fluye hacia la puerta a través de la unión p-n bajo la puerta. 
Esto conmuta una estructura compuesta por un transistor NPN y un transistor PNP, que tiene la puerta como cátodo.

###### Cuadrante 3

La operación del Cuadrante 3 ocurre cuando la puerta y MT2 son negativas con respecto a MT1.
El proceso también ocurre en diferentes etapas. En la primera fase, la unión pn entre el terminal MT1 y la puerta se polariza hacia delante. 
Como la polarización directa implica la inyección de portadores minoritarios en las dos capas que se unen a la unión, 
se inyectan electrones en la capa p bajo la puerta.

###### Cuadrante 4

La operación del Cuadrante 4 ocurre cuando la puerta es positiva y MT2 es negativa con respecto a MT1.
La activación en este cuadrante es similar a la activación en el cuadrante 3. 
El proceso utiliza un control de puerta remoto. A medida que la corriente fluye desde la capa p bajo la puerta en la capa n bajo MT1, 
se inyectan portadores minoritarios en forma de electrones libres en la región p,
algunos de ellos se recogen por la unión np subyacente y pasan a la unión contigua n-región sin recombinar.




