/*
 
 lora_serial.h
 
 Biblioteca para controle de comunicação entre radios lora via serial 
 Autor: Tec. Marcelo F Sobrinho
 Outubro de 2019


 
 */


#ifndef Lora_s
#define Lora_s 

#include <Arduino.h>

class Conecta
{
  public:
	Conecta(int rx, int tx);
	void bit_seg(int seg); 
	void pacote(String pacote); 

  private:
    int _rx;
	int _tx;
	
     
};

#endif
