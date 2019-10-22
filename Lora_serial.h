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
	Conexao(int rx, int tx, int bit_seg);
	void iniciar(); 
	void quant_disp(int quant); 
	void empacotar(String dados); 

  private:
    int _rx;
	int _tx;
	int _bit_seg;
	
     
};

#endif
