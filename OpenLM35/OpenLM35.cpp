#include <OpenLM35.h>

OpenLM35::OpenLM35(int pin):OpenSensor(pin){
	_pin = pin;
}

/************************************ readCelsius **********************************
Input: voltage - value of voltage that you provide for sensor. Ex: 5V, 3.3V, etc.
       resolution - resolution(in bits) of analog pin. Ex: 10 bit, 12 bit, etc.
Output: Tempurature in Celsius value of the sensor
************************************************************************************/
float OpenLM35::readCelsius(){
//	return (voltage * readnTimes() * 1000/10)/ pow(2, resolution);
	return (VoltageCalculation(readnTimes(), _Vcc, _resolution) * 100);
}

/************************************ readFahrenheit ********************************
Input: voltage - value of voltage that you provide for sensor. Ex: 5V, 3.3V, etc.
       resolution - resolution(in bits) of analog pin. Ex: 10 bit, 12 bit, etc.
Output: Tempurature in Fahrenheit value of the sensor
************************************************************************************/
float OpenLM35::readFahrenheit(){
//  	return ((voltage * readnTimes() * 100)/ pow(2, resolution)) * 9/5 + 32;
  	return ((VoltageCalculation(readnTimes(), _Vcc, _resolution) * 100) * 9/5 +32);
}


