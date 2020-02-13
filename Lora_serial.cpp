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
void Conexao::empacotar(String dados, int op )
{
	if (op==1) {
		_dadosT += String(dados);
	}
	else if (op==2) {
		_dadosT += "|" + String(dados);
	}
}
void Conexao::iniciar_setup()
{
	loraSerial = new SoftwareSerial(_rx, _tx);
	loraSerial->begin(_bit_seg);
	Serial.begin(9600);
}

void Conexao::transmissor_c_conf()
{
	loraSerial->println("n1|" + _dadosT);
	_dadosT = "";
	delay(2000);
	this->aguardar_conf_recep();
}

void Conexao::transmissor_s_conf()
{
	loraSerial->println("n1|" + _dadosT);
	_dadosT = "";
	delay(2000);

}

void Conexao::detectar_erro(char op)
{
	String nome ="mar";
	String  codif = "";
	String bin = "";
	byte  aux=0;
	for (int i=0; i < nome.length();i++) {
		bin = String(nome.charAt(i), BIN);
		if ('0'==bin.charAt(i)) {
			codif += '0' +bin;
		}
		else {
			codif +=bin;
		}
		
		Serial.println(bin.charAt(i));
		Serial.println();
		Serial.println();
		Serial.println();
		Serial.println(codif);
	}
	
	//for (int i = 0; i < 1; i++) {
	//	for (int j = 0; j < 1; j++) {
	//		codif 
	//	}
	//}
	Serial.println(codif.length());
	
	while (true);
	{

	}
	//Serial.println(String(01001101));
	nome = "";

}

String Conexao::atualizar_nomeDev(int inicio, int fim)
{
	String input = "";
	input = loraSerial->readString();
//	Serial.println(input);
	_nomeDev = "";
	for (inicio; inicio < fim; inicio++) {
		_nomeDev += String(input.charAt(inicio));
	}
	//Serial.println(_nomeDev);
	//delay(50);
	return _nomeDev;

}

String Conexao::aguardar_conf_recep()
{

	if (loraSerial->available() > 0) {
		this->atualizar_nomeDev(0,5);
		Serial.println(_nomeDev);
		delay(50);
		if (_nomeDev == "n1|ok") {
			Serial.println("CONFIRMADO, AGUARDANDO PROXIMO ENVIO EM 5 MINUTOS");
			delay(5000);

		}
		else {
			Serial.println("RETRANSTINDO");
			delay(50);
			
		}

		delay(50);


	}
	return "";
}

String Conexao::iniciar_recep()
{
	String input = "";
	
	if (loraSerial->available() > 0) {
		this->atualizar_nomeDev(0, 2);
		Serial.println(_nomeDev);
		input = loraSerial->readString();
		delay(50);
		if (_nomeDev == "n1") {
			this->iniciar_grav_arq(input);
			this->empacotar("ok", 1);
			this->transmissor_s_conf();
		}
		else {
			Serial.println("Conexão Negada para - > "+_nomeDev);
			delay(50);
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
	while (!SD.begin(4)) {
		Serial.println("Cartão desconectado!");
		//Serial.println("Reiniciar Arduino!");
		//while (1);
	}
	arq = SD.open("datalog.txt", FILE_WRITE);
	if (arq) {

			Serial.println("Gravado OK");
			Serial.println(dados);
			arq.println(String(dados));
			arq.close();
			delay(50);
		
	}
	else {
		Serial.println("FALHA - Abertura datalog.txt");
	}

	
	
}



	



