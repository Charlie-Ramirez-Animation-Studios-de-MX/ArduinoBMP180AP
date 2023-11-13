/*Copyright (C) 2023 Boyzo Ramirez Carlos|©-Archivo Historico Digitalizado Charlie Ramirez Animation Studios de Mexico -LidiaElectric
UNIVERSIDAD NACIONAL AUTONOMA DE MEXICO-FACULTAD DE ESTUDIOS SUPERIORES ARAGON-INGENIERIA ELECTRICA ELECTRONICA.
Lector de Presion Barometrica y Temperatura con registro y Salida Serial-hoja de calculo, Version A- PRO: 2023-11-13 06:13:36
CODIGO BAJO "LICENCIA MIT". PARA CODIGO ABIERTO (OPEN SOURCE  https://opensource.org/licenses/MIT).
PresBaroBMP180.asm
Created: 2022-12-02 23:19:36
Author : CharlieUSTCN1*/

#include <SFE_BMP180.h>
#include <Wire.h>

SFE_BMP180 bmp180;
// ********* VARIABLES  ************* 
// ADVERTENCIA!!! - SIEMPRE DESCONECTE EL SERIAL/EXCEL ANTES DE CUALQUIER CAMBIO
// NO UTILICE EXCEL Y EL SERIAL DE ARDUINO AL MISMO TIEMPO.

// Definir el tiempo de delay EN MILISEGUNDOS
int tiempoDeEspera = 1000;  // Puedes ajustar este valor segun tus necesidades

int modo = 1;  // Variable para almacenar el modo elegido por el usuario
/*Los modos son: 
1 - Modo PLX-DAQ solo Presion,  
  2 - Modo Transmisor de Datos, COM Excel Solo Presion
3 - Modo Modo PLX-DAQ Presion + Temperatura,
  4 - Modo Transmisor de Datos, COM Excel Presion + Temperatura
// El usuario elige el modo (1 para PLX, 2 para Log, por ejemplo)*/
  
// -********************************

void setup() {
  if (bmp180.begin())
    Serial.println("BMP180 iniciado correctamente");
  else {
    Serial.println("Error al iniciar el BMP180");
    while (1); // bucle infinito
  }
  // Ejecutar el setup correspondiente según el modo elegido
  if (modo == 1 || modo == 3) {
    setupPLX();
  } else if (modo == 2 || modo == 4) {
    setupLog();
  }
}

void loop() {
  // Ejecutar el loop correspondiente según el modo elegido
  if (modo == 1 || modo == 3) {
    loopPLX();
  } else if (modo == 2 || modo == 4) {
    loopLog();
  }
}


void setupPLX() {
  Serial.begin(9600);
  Serial.println("CLEARSHEET"); // Limpia el CSV desde la Fila 1 "En el PLX DAQ v2"
  if (modo == 1) {
    Serial.println("CLEARSHEET");
   Serial.println("LABEL,Fecha,Hora,Presion en mBar");
  } else if (modo == 3) {
    Serial.println("CLEARSHEET");
    Serial.println("LABEL,Fecha,Hora,Presion en mBar,Temperatura en C");
  }
  
  
  
}

void loopPLX() {
  char status;
  double T, P;

  status = bmp180.startTemperature(); // Inicio de lectura de temperatura
  if (status != 0) {   
    delay(status); // Pausa para que finalice la lectura
    status = bmp180.getTemperature(T); // Obtener la temperatura
    if (status != 0) {
      status = bmp180.startPressure(3); // Inicio lectura de presión
      if (status != 0) {        
        delay(status); // Pausa para que finalice la lectura        
        status = bmp180.getPressure(P, T); // Obtenemos la presión
        if (status != 0) {
          //Write_PlxDaq();
          // Función para escribir en PLX DAQ
void Write_PlxDaq(); {
              Serial.print("DATA"); // siempre escribe "DATA" para indicar que lo siguiente es un dato
              Serial.print(",");
              Serial.print("DATE");
              Serial.print(",");
              Serial.print("TIME");
              Serial.print(",");
              Serial.print(P, 2);
              Serial.print(",");
              if (modo == 3) {
              Serial.print(T, 2);
              Serial.print(",");
              Serial.println();
              } else if (modo == 1) {
                Serial.println();
              }
  
          }
        }
      }
    }
  } 
  delay(tiempoDeEspera);  // Usar la variable en lugar de un valor fijo


}

void setupLog() {
  // Configuración específica para el modo "Log"

}

void loopLog() {
  // Bucle específico para el modo "Log"
  char status;
  double T, P;

  status = bmp180.startTemperature(); // Inicio de lectura de temperatura
  if (status != 0) {   
    delay(status); // Pausa para que finalice la lectura
    status = bmp180.getTemperature(T); // Obtener la temperatura
    if (status != 0) {
      status = bmp180.startPressure(3); // Inicio lectura de presión
      if (status != 0) {        
        delay(status); // Pausa para que finalice la lectura        
        status = bmp180.getPressure(P, T); // Obtenemos la presión
        if (status != 0) {
          Serial.print(P, 2);
          if (modo == 4) {
            Serial.print(",");
            Serial.print(T, 2);
            Serial.println();
  }       else if (modo == 2) {
            Serial.println();
  }
        }
      }
    }
  } 
  delay(tiempoDeEspera);  // Usar la variable en lugar de un valor fijo

}


