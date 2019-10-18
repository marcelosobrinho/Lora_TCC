/*
 
 lora_serial Exemplo
 
 Biblioteca para controle de comunicação entre radios lora via serial 
 Autor: Tec. Marcelo F Sobrinho
 Outubro de 2019


 
 */


#ifndef Lora_s
#define Lora_s 

#include "Arduino.h"

class lr_s
{
  public::
    lr_s(int tx int rx int bit_seg);
    

  private:
    int _tx;
    int _rx;
    int _bit_seg;
   
    
    
};






#endif
