#include <OpenLM35.h>

OpenLM35::OpenLM35(int analogpin):OpenSensor(analogpin){
	_analogpin = analogpin;
}

/************************************ readCelsius **********************************
Input: voltage - value of voltage that you provide for sensor. Ex: 5V, 3.3V, etc.
       resolution - resolution(in bits) of analog pin. Ex: 10 bit, 12 bit, etc.
Output: Tempurature in Celsius value of the sensor
************************************************************************************/
float OpenLM35::readCelsius(){
//	return (voltage * readnTimes() * 1000/10)/ pow(2, resolution);
	return (VoltageCalculation(readAnalogTimes()) * 100);
}

/************************************ readFahrenheit ********************************
Input: voltage - value of voltage that you provide for sensor. Ex: 5V, 3.3V, etc.
       resolution - resolution(in bits) of analog pin. Ex: 10 bit, 12 bit, etc.
Output: Tempurature in Fahrenheit value of the sensor
************************************************************************************/
float OpenLM35::readFahrenheit(){
//  	return ((voltage * readnTimes() * 100)/ pow(2, resolution)) * 9/5 + 32;
  	return ((VoltageCalculation(readAnalogTimes()) * 100) * 9/5 +32);
}

/************************************ convertCtoF ********************************
Input: temperature value in Celsius.
Output: Tempurature value in Fahrenheit.
************************************************************************************/
float OpenLM35::convertCtoF(float C){
	return (C * 9/5 + 32);
}

/************************************ convertFtoC ********************************
Input: temperature value in Fahrenheit.
Output: Tempurature value in Celsius.
************************************************************************************/
float OpenLM35::convertFtoC(float F){
	return ((F - 32) * 5/9);
}

/************************************ getSensor *******************************
Input: None
Output: basic information about sensor such as name, version, type, min/max value, etc.
************************************************************************************/
SensorInfo OpenLM35::getSensor(){
	SensorInfo sensor;
	
	strncpy(sensor.name, "LM35", sizeof(sensor.name) - 1);
	sensor.version = OPENLM35_VERSION;
	sensor.type = SENSOR_TYPE_TEMPERATURE;
	sensor.min_value = -55;
	sensor.max_value = 150;
	sensor.analogpin = getAnalogpin();
	sensor.Vcc = getVcc();
	sensor.resolution = getResolution();
	
	return sensor;
}
