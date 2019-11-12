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

void Conexao::iniciar_recep()
{
	SoftwareSerial loraSerial(2, 3);
	loraSerial.begin(9600);
	

	//loraSerial.println("n1|"+_dados);
	if (loraSerial.available() > 0) {
		Serial.print("recebendo...");
		delay(100);
		Serial.print("......");
		delay(100);
		Serial.print("............");
		delay(100);
		Serial.println("....................ok");
		delay(50);
		String input = loraSerial.readString();
		Serial.begin(4800);
		Serial.println(input);
	}
	else {
		Serial.begin(4800);
		Serial.println("FALHA!!");
		delay(50);
	}


}




