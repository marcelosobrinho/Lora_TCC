1/*
 
 lora_serial.cpp
 Biblioteca para controle de comunicação entre radios lora via serial 
 Autor: Tec. Marcelo F Sobrinho
 Outubro de 2019


 
 */
 #include <Arduino.h>
 #include "Lora_serial.h"
 //#include <SoftwareSerial.h>

 


 Conecta::Conecta(int tx, int rx)
 {
	//SoftwareSerial loraSerial(tx, rx);
	//Serial.begin(bit_seg);
	//loraSerial.begin(bit_seg);

    _tx = tx;
	_rx = rx;

 }

void Conecta::bit_seg(int seg)
{
}

void Conecta::pacote(String pacote)
{
}

