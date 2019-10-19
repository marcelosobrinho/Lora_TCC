/*
 
 lora_serial.cpp
 Biblioteca para controle de comunicação entre radios lora via serial 
 Autor: Tec. Marcelo F Sobrinho
 Outubro de 2019


 
 */


 #include "Arduino.h"
 #include "Lora_serial.h"
 #include <SoftwareSerial.h>

 


 Conecta::Conecta(int rx)
 {
	 SoftwareSerial loraSerial(rx);
  _rx=rx;

 }


 void Conecta::cx_bit() {


 }