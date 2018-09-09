//Mapeo de pines                                                                                                                                                                                                                                                                     
#define AIN1 7   
#define AIN2 8 
#define PWMA 6

#define BIN1 9 
#define BIN2 4  
#define PWMB 5 

#define VELNOM 110   
#define DIFMAX 110

// Función accionamiento motor izquierdo
void Motoriz(int value)
{
  if ( value >= 0 )
  {
    digitalWrite(BIN1,HIGH);
    digitalWrite(BIN2,LOW);
  }
  else
  {
    digitalWrite(BIN1,LOW);
    digitalWrite(BIN2,HIGH);
    value *= -1;
  }
  analogWrite(PWMB,value);
}


// Función accionamiento motor derecho
void Motorde(int value)
{  
  if ( value >= 0 )
  {
    digitalWrite(AIN1,HIGH);
    digitalWrite(AIN2,LOW);
  }
  else
  {
    digitalWrite(AIN1,LOW);
    digitalWrite(AIN2,HIGH);
    value *= -1;
  }    
  analogWrite(PWMA,value);
}


//Accionamiento de motores
void Motor(int left, int right)
{
  Motoriz(left);
  Motorde(right);
}