/*
 
 lora_serial.cpp
 Biblioteca para controle de comunicação entre radios lora via serial 
 Autor: Tec. Marcelo F Sobrinho
 Outubro de 2019


 
 */


 #include "Arduino.h"
 #include "Lora_serial.h"
 #include <SoftwareSerial.h>

 


 Conecta::Conecta(int rx int tx int bit_seg)
 {
	 SoftwareSerial loraSerial(rx, tx);
	 loraSerial.begin(bit_seg);

  _rx=rx;
  _tc=tx;
  _bit_seg=bit_seg;


 }
