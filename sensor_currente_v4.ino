//Carrega as bibliotecas
#include <EmonLib.h>

  
EnergyMonitor emon1;

  
//Tensao da rede eletrica
int rede = 240.0;
  
//Pino do sensor SCT
int pino_sct = 1;
  
void setup()
{
  
  Serial.begin(9600);  
  //Pino, calibracao - Cur Const= Ratio/BurdenR. 2000/220 = 9.0909
  emon1.current(pino_sct,20); //aferido contador EDP
  Serial.println("Tensao:   ;Corrente:    ;Potencia");
 
}
  
void loop()
{
  //Calcula a corrente 
  double Irms = emon1.calcIrms(1480);
  //Mostra o valor da corrente
  
  Serial.print(rede); Serial.print(" ; ");
  
  Serial.print(Irms); Serial.print(" ; ");// Irms
  
   
  //Calcula e mostra o valor da potencia
 
  Serial.print(Irms*rede);Serial.println(" ; ");
  
   
  delay(15000); //15 segundos
}
