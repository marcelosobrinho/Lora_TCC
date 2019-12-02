/*
 
 lora_serial.cpp
 Biblioteca para controle de comunicação entre radios lora via serial 
 Autor: Tec. Marcelo F Sobrinho
 Outubro de 2019


 
 */
 #include <Arduino.h>
 #include "Lora_serial.h"

//#include <SPI.h>
//#include <SD.h>


 


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
		_dadosT += String(dados);
	}
	else if (_op==2) {
		_dadosT += "|" + String(dados);
	}
	

}


void Conexao::iniciar_setup()
{
	loraSerial = new SoftwareSerial(_rx, _tx);
	loraSerial->begin(_bit_seg);
}

void Conexao::iniciar_trans()
{
	loraSerial->println("n1|"+_dadosT);
	_dadosT = "";
	delay(2000);
}

String Conexao::iniciar_recep()
{
	String input = "";
	
	if (loraSerial->available() > 0) {
		input = loraSerial->readString();
		String nomedesp ="";
		Serial.println("Sinal recebido OK!");
		nomedesp += input.charAt(0);
		nomedesp += input.charAt(1);
		Serial.println(nomedesp);
		delay(200);
		if (nomedesp == "n1") {
			this->iniciar_grav_arq(input);
		}
		
	}
	else {
		Serial.println("Sem sinal do radio!");
		input ="FALHA-recepcao";
		delay(50);
	}

	return input;
	}

void Conexao::iniciar_grav_arq(String dados)
{
	Serial.begin(9600);
	File arq;
	if (!SD.begin(4)) {
		Serial.println("Cartão desconectado!");
		Serial.println("Reiniciar Arduino!");
		while (1);
	}
	arq = SD.open("datalog.txt", FILE_WRITE);
	if (arq) {

			Serial.println("Gravado OK");
			arq.println(dados);
			arq.close();
			delay(50);
		
	}
	else {
		Serial.println("FALHA - Abertura datalog.txt");
	}

	
	
}



	



