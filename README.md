# Arduino BMP180AP
Repositorio del Dispositivo Medidor de Presion Barometrica Absoluta y Temperatura con capacidad para registro Serial y a Excel Mediante Arduino UNO USB
El codigo PRO Permite elegir entre 4 Modos - Modo PLX-DAC y Transmisor de Datos (Complemento COM de Excel) - Salida Serial sencilla.
-Compatible con Arduino IDE clasico e IDE 2
-En ambos modos puede elegirse si arrojar solo los datos de Presion (en mBar), o Presion + Temperatura en °C, ambos con hasta 2 Decimales de presicion, 
- Tiempo de Espera entre lecturas y modo de Facil ajuste [En Codigo]
- El modo PLX-DAC Permite registrar los datos con la Fecha y Hora de la Maquina Host.
- Para uso con el Sensor de Bosch BMP180 - Mediante Breakout de Sparkfun o generica Equivalente.
- Amplia variedad de aplicaciones: Medida de Presion y temperatura en Aire acondicionado o Ductos, Variacion de Nivel de liquidos, Registro Climatologico "Barometro y termometro", Calculo de Altura en MSMN (Requiere calculo y Codigo adicional) - Lectura de presion Barometrica Absoluta. 

- EL MODO PLX-DAC, funciona con Versiones de MS Office Excel 2000 en Adelante, Requiere Habilitacion o uso de Macros. - No funciona en LibreOffice
- El Modo Transmisor de Datos Requiere del Complemento COM - homonimo "Data Streamer" Disponible en Versiones de MS Office 365 Vease para instrucciones detalladas: https://learn.microsoft.com/es-es/microsoft-365/education/data-streamer/
y
https://learn.microsoft.com/es-es/microsoft-365/education/data-streamer/enable-in-excel
-SIN EMBARGO, Este modo Arroja una Salida Serial Simple, Por lo que puede aplicarse a cualquier otro uso en el que pueda leerse o se necesite una salida serial simple.

-Para Usos en Cualquier otra Placa diferente de Arduino UNO, se debe tomar en cuenta que los Puertos A4 y A5 corresponden a las Conexiones SDA y SCL respectivamente, y pese a estar señalizados como Analogos, estos en realidad se Comunican por protocolo I2C Por lo que deben adecuarse a los correspondientes a su placa.

-El bajo consumo del Arduino, el sensor y la Funcionalidad de Salida Serial por USB, Permiten prescindir de una Fuente de alimentación externa, utilizando la energia entregada por la PC mediante USB.

-Las librerias Incluidas deben instalarse manualmente en su carpeta de Arduino.
