/*
 
 lora_serial.cpp
 Biblioteca para controle de comunicação entre radios lora via serial 
 Autor: Tec. Marcelo F Sobrinho
 Outubro de 2019


 
 */
 #include <Arduino.h>
 #include "Lora_serial.h"

#include <SPI.h>
#include <SD.h>


 


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
	File myFile;

	// Open serial communications and wait for port to open:
	Serial.begin(9600);
	while (!Serial) {
		; // wait for serial port to connect. Needed for native USB port only
	}


	Serial.print("Initializing SD card...");

	if (!SD.begin(4)) {
		Serial.println("initialization failed!");
		while (1);
	}
	Serial.println("initialization done.");

	// open the file. note that only one file can be open at a time,
	// so you have to close this one before opening another.
	myFile = SD.open("test.txt", FILE_WRITE);

	// if the file opened okay, write to it:
	if (myFile) {
		Serial.print("Writing to test.txt...");
		myFile.println("testing 1, 2, 3.");
		// close the file:
		myFile.close();
		Serial.println("done.");
	}
	else {
		// if the file didn't open, print an error:
		Serial.println("error opening test.txt");
	}

	// re-open the file for reading:
	myFile = SD.open("test.txt");
	if (myFile) {
		Serial.println("test.txt:");

		// read from the file until there's nothing else in it:
		while (myFile.available()) {
			Serial.write(myFile.read());
		}
		// close the file:
		myFile.close();
	}
	else {
		// if the file didn't open, print an error:
		Serial.println("error opening test.txt");
	}


	//




}
	



