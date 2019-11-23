/*
 
 lora_serial.cpp
 Biblioteca para controle de comunicação entre radios lora via serial 
 Autor: Tec. Marcelo F Sobrinho
 Outubro de 2019


 
 */
 #include <Arduino.h>
 #include "Lora_serial.h"


 


Conexao::Conexao(int rx, int tx, int bit_seg,int op )
 {
	
	_tx = tx;
	_rx = rx;
	_bit_seg = bit_seg;
	_op = op;
	SoftwareSerial loraSerial(_rx, _tx);
	loraSerial.begin(_bit_seg);
	
 }
void Conexao::empacotar(float dados)
{
	if (_op==2) {
		_dados += String(dados);
	}
	else if (_op==2) {
		_dados += "|" + String(dados);
	}
	

}


void Conexao::iniciar_trans()
{
	SoftwareSerial loraSerial(_rx, _tx);
	loraSerial.begin(_bit_seg);
	loraSerial.println("n1|"+_dados);
	_dados = "";
	delay(2000);
}

void Conexao::iniciar_setup()
{
	loraSerial = new SoftwareSerial(_rx,_tx);
	loraSerial->begin(_bit_seg);
}

void Conexao::iniciar_recep()
{
	
	
	
	
	Serial.begin(19200);
	if (loraSerial->available() > 0) {
	

		Serial.print("recebendo...");
		delay(100);
		Serial.print("......");
		delay(100);
		Serial.print("............");
		delay(100);
		Serial.println("....................ok");
		delay(50);
		String input = String(loraSerial->readString());

		Serial.println(input);

	}
	else {
		Serial.println("FALHA!!");
		delay(50);
	}




	}
	



