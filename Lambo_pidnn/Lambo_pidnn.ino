#include "motor.h"
#include "neuronas.h"
#include "sensor.h"

#define VELNOM 110   //Velocidad de los motores
#define DIFMAX 110   //Delta maximo de velocidad

void setup() {
  /*Inicializa las salidas para controlar los motores y calibra los sensores*/
  MotorInit();
  SensorInit();

  Serial.begin(9600);
}

unsigned int position = 0;
/*Neuronas*/
float xin, xp, xi, xd, xo;

/*Setpoint*/
float xr = 0.5;

/*Pesos iniciales de la red*/
float w1  = 10;
float w2  = 10;
float w3  = 10;
float w11 = 10;
float w12 = 10;
float w13 = 10;
float w21 = 10;
float w22 = 10;
float w23 = 10;

/*Acumulacion backpropagation*/
float djdw1, djdw2, djdw3, djdw11, djdw12, djdw13, djdw21, djdw22, djdw23;

/*Entradas neuronas capa oculta*/
float up, ui, ud;

/*Valores medicion anterior*/
float up_ant, ui_ant, ud_ant, up_ant2, ui_ant2, ud_ant2;
float xin_ant, xp_ant, xi_ant, xd_ant, xo_ant, xp_ant2, xi_ant2, xd_ant2, xo_ant2;

/*Factor de aprendizaje*/
float factor = 0.2;

/*Deltas*/
float delta, delta1, delta2, delta3;

int n = 0;
void loop() {
  /*Lee la posicion e ingresa a la neurona xin*/
  Sensor(position);
  xin = position/5000.0;
  
  /*Evaluacion entradas*/
  up = w11*xr+w21*xin;
  ui = w12*xr+w22*xin;
  ud = w13*xr+w23*xin;
  xp = neuroP(up);
  xi = neuroI(xi, ui);
  xd = neuroD(ud_ant, ud);
  xo = neuroP(w1*xp+w2*xi+w3*xd);

  /*Movimiento*/
  if(xo >= 0)
  {
    Motor(VELNOM - xo*DIFMAX, VELNOM );
  }
  else
  {
    Motor(VELNOM, VELNOM + xo*DIFMAX); 
  }

  /*Gradiente del error*/
  if((xo_ant-xo_ant2 != 0) && (up_ant-up_ant2 != 0) && (ui_ant-ui_ant2 != 0)&& (ud_ant-ud_ant2 != 0)){
  delta = (xr-xo_ant)*(xin-xin_ant)/(xo_ant-xo_ant2);
  djdw1 -= delta*xp_ant;
  djdw2 -= delta*xi_ant;
  djdw3 -= delta*xd_ant;

  delta1 = delta*w1*(xp-xp_ant)/(up_ant-up_ant2);
  delta2 = delta*w2*(xi-xi_ant)/(ui_ant-ui_ant2);
  delta3 = delta*w3*(xd-xd_ant)/(ud_ant-ud_ant2);
  djdw11 -= delta1*xr;
  djdw12 -= delta2*xr;
  djdw13 -= delta3*xr;
  djdw21 -= delta1*xin_ant;
  djdw22 -= delta2*xin_ant;
  djdw23 -= delta3*xin_ant;
  n++;
  }

  /*Se guardan los valores para la siguiente operacion*/
  up_ant2 = up_ant;
  ui_ant2 = ui_ant;
  ud_ant2 = ud_ant;
  xp_ant2 = xp_ant;
  xi_ant2 = xi_ant;
  xd_ant2 = xd_ant;
  xo_ant2 = xo_ant;
  up_ant = up;
  ui_ant = ui;
  ud_ant = ud;
  xp_ant = xp;
  xi_ant = xi;
  xd_ant = xd;
  xo_ant = xo;
  xin_ant = xin;

  
}
