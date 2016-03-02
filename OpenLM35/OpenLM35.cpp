#include <OpenLM35.h>

OpenLM35::OpenLM35(int pin){
	_pin = pin;
}

/************************************ readCelsius **********************************
Input: voltage - value of voltage that you provide for sensor. Ex: 5V, 3.3V, etc.
       resolution - resolution(in bits) of analog pin. Ex: 10 bit, 12 bit, etc.
Output: Tempurature in Celsius value of the sensor
************************************************************************************/
float OpenLM35::readCelsius(float voltage, int resolution){
	return (voltage * readnTimes() * 100)/ pow(2, resolution);
}

/************************************ readFahrenheit ********************************
Input: voltage - value of voltage that you provide for sensor. Ex: 5V, 3.3V, etc.
       resolution - resolution(in bits) of analog pin. Ex: 10 bit, 12 bit, etc.
Output: Tempurature in Fahrenheit value of the sensor
************************************************************************************/
float OpenLM35::readFahrenheit(float voltage, int resolution){
  	return ((voltage * readnTimes() * 100)/ pow(2, resolution)) * 9/5 + 32;
}

/************************************ readnTimes **********************************
Input: none
Output: average value of sensor after READ_TIMES times reading.
Remarks: This function help to get value exactly because it read more times then average them.
************************************************************************************/
float OpenLM35::readnTimes(){
	  float val;
	  for(int i=1; i<=READ_TIMES; i++){                               
	    val += analogRead(_pin);                                      // Read more time then sum them.
	  }
	  val = val/READ_TIMES;                                           //average values;
	  return val;
}


