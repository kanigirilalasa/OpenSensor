#include <OpenSensor.h>

OpenSensor::OpenSensor(){}

OpenSensor::OpenSensor(int pin){
	_pin = pin;
}

OpenSensor::OpenSensor(int analogpin, int digitalpin){
	_pin = analogpin;
	_digital = digitalpin;
}

/************************************ readnTimes **********************************
Input: none
Output: average adc value of sensor after READ_TIMES times reading.
Remarks: This function help to get value exactly because it read more times then average them.
         The READ_N_TIMES value you can configure in header file.
************************************************************************************/
float OpenSensor::readnTimes(){
	  float val;
	  for(int i=1; i<=READ_N_TIMES; i++){                               
	    val += analogRead(_pin);                                      // Read READ_N_TIMES time then sum them.
	  }
	  val = val/READ_N_TIMES;                                         // average values;
	  return val;
}

/************************************ VoltageCalculation **********************************
Input: raw_adc - the value of analog input.
	   Vcc - the value of supplying voltage.Ex: 5V, 3.3V, etc.
	   resolution - determines the resolution (in bits) of the value returned by analogRead() function.Ex: 10bit, 11bit, etc.
Output: voltage value(V) that convert from raw_adc.
Remarks: This function map raw_adc(input analog) into input voltages.
************************************************************************************/
float OpenSensor::VoltageCalculation(int raw_adc, float Vcc, int resolution){
	return (raw_adc * Vcc / pow(2, resolution));
}
