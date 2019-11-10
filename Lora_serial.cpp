/*
 
 lora_serial.cpp
 Biblioteca para controle de comunicação entre radios lora via serial 
 Autor: Tec. Marcelo F Sobrinho
 Outubro de 2019


 
 */
 #include <Arduino.h>
 #include "Lora_serial.h"
 #include <SoftwareSerial.h>

 


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


void Conexao::iniciar_trans()
{
	SoftwareSerial loraSerial(_rx, _tx);
	loraSerial.begin(_bit_seg);
	loraSerial.println("n1|"+_dados);
	_dados = "";
	delay(2000);
}




