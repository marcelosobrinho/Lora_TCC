/*
 
 lora_serial.cpp
 Biblioteca para controle de comunicação entre radios lora via serial 
 Autor: Tec. Marcelo F Sobrinho
 Outubro de 2019


 
 */
 #include <Arduino.h>
 #include "Lora_serial.h"
 #include <SoftwareSerial.h>

 


 Conexao::Conexao(int tx, int rx, int  bit_seg)
 {
    _tx = tx;
	_rx = rx;
	_bit_seg = bit_seg;
 }

void Conexao::iniciar()
{
	SoftwareSerial loraSerial(_tx, _rx);
	loraSerial.begin(_bit_seg);

}

void Conexao::quant_disp(int quant)
{
}
void Conexao::empacotar(String dados)
{

}