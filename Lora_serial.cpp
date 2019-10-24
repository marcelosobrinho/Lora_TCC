/*
 
 lora_serial.cpp
 Biblioteca para controle de comunicação entre radios lora via serial 
 Autor: Tec. Marcelo F Sobrinho
 Outubro de 2019


 
 */
 #include <Arduino.h>
 #include "Lora_serial.h"
 #include <SoftwareSerial.h>

 


Conexao::Conexao(int rx, int tx, int quant_disp, int bit_seg)
 {
	
	_tx = tx;
	_rx = rx;
	_bit_seg = bit_seg;
	_quant_disp = quant_disp;
 }

void Conexao::incializar_setup()
{
	SoftwareSerial loraSerial(_tx, _rx);
	//Serial.begin(_bit_seg);
	loraSerial.begin(_bit_seg);
	loraSerial.println("Sucesso!!");
}

void Conexao::iniciar_trans()
{
	
	//Serial.println("Sucesso!!");
	
	//loraSerial.begin(_bit_seg);
	
	//delay(2000);
}


void Conexao::empacotar(String *Vdados)
{
}

