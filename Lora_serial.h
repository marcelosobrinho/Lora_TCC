/*
 
 lora_serial.h
 
 Biblioteca para controle de comunicação entre radios lora via serial 
 Autor: Tec. Marcelo F Sobrinho
 Outubro de 2019


 
 */


#ifndef Lora_s
#define Lora_s 

#include <Arduino.h>
#include <SoftwareSerial.h>
#include <SPI.h>
#include <SD.h>




class Conexao
{
  public:
	Conexao(int rx, int tx, int bit_seg, int op);
	void iniciar_setup();
	void empacotar(String dados, int op); 
	void transmissor_c_conf();
	void transmissor_s_conf();
	String atualizar_nomeDev(int inicio, int fim);
	String aguardar_conf_recep();
	String iniciar_recep();
	void  iniciar_grav_arq(String dados);
	//

  private:
    int _rx;
	int _tx;
	int _bit_seg;
	String _dadosT;
	String _dadosR;
	int _op;
	SoftwareSerial *loraSerial;
	String _nomeDev;
	//File *arqLog;
	     
};

#endif
