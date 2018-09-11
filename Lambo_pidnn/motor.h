//Mapeo de pines                                                                                                                                                                                                                                                                     
#define AIN1 7   
#define AIN2 8 
#define PWMA 6

#define BIN1 9 
#define BIN2 4  
#define PWMB 5 
#define LED  13

/*Funcion para configurar los pines del motor*/
void MotorInit()
{
  // Declara como salida los pines a utilizar
  pinMode(LED   ,OUTPUT);
  pinMode(BIN2  ,OUTPUT);
  pinMode(BIN1  ,OUTPUT);
  pinMode(PWMB  ,OUTPUT);
  pinMode(AIN1  ,OUTPUT);
  pinMode(AIN2  ,OUTPUT);
  pinMode(PWMA  ,OUTPUT);
}

/*Accionamiento motor izquierdo*/
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


/*Accionamiento motor derecho*/
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


/*Accionamiento de ambos motores*/
void Motor(int left, int right)
{
  Motoriz(left);
  Motorde(right);
}
