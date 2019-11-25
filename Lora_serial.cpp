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

 }
void Conexao::empacotar(float dados)
{
	if (_op==1) {
		_dados += String(dados);
	}
	else if (_op==2) {
		_dados += "|" + String(dados);
	}
	

}


void Conexao::iniciar_setup()
{
	loraSerial = new SoftwareSerial(_rx, _tx);
	loraSerial->begin(_bit_seg);
}

void Conexao::iniciar_trans()
{
	loraSerial->println("n1|"+_dados);
	_dados = "";
	delay(2000);
}

String Conexao::iniciar_recep()
{
	String input = "";
	if (loraSerial->available() > 0) {
		input = loraSerial->readString();
	}
	else {
		Serial.println("FALHA");
		delay(50);
	}
	return input;
	}

void Conexao::iniciar_grav_arq(String dados)
{
 
}
	



