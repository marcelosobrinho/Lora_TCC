/*
 
 lora_serial.h
 
 Biblioteca para controle de comunicação entre radios lora via serial 
 Autor: Tec. Marcelo F Sobrinho
 Outubro de 2019


 
 */


#ifndef Lora_s
#define Lora_s 

#include <Arduino.h>



class Conexao
{
  public:
	Conexao(int rx, int tx, int bit_seg, int op);
	void empacotar(float dados); 
	void iniciar_trans();

  private:
    int _rx;
	int _tx;
	int _bit_seg;
	String _dados;
	int _op;
	
	
     
};

#endif
