#include <QTRSensors.h>

#define NUM_SENSORS             6    
#define NUM_SAMPLES_PER_SENSOR  4    
#define EMITTER_PIN             11  

// Configuración de la librería QTR-8A         
QTRSensorsAnalog qtra((unsigned char[]) 
  {A0, A1, A2, A3, A4, A5}
, NUM_SENSORS, NUM_SAMPLES_PER_SENSOR, EMITTER_PIN);

unsigned int sensorValues[NUM_SENSORS];
unsigned int position = 0; 

void setup(){

	/*Calibracion de sensores*/
	for ( int i=0; i<70; i++)
	{
		digitalWrite(LED, HIGH);  delay(50);
    	qtra.calibrate();
    	digitalWrite(LED, LOW);  delay(50);
	}	
}

void loop(){

	/*Medicion de posicion*/
	position = qtra.readLine(sensorValues, true, false);
	
}
