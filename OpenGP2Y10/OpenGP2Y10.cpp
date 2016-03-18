#include <OpenGP2Y10.h>

OpenGP2Y10::OpenGP2Y10(int analogpin, int digitalpin): OpenSensor(analogpin, digitalpin){
	_pin = analogpin;
	_ledpin = digitalpin;
}

/************************************ dustDensity ****************************************
Input: None
Output: dust density in the air (mg/m3).
Remarks: This function calculate the dust density in the air base on using OpenGP2Y10Curve.
************************************************************************************/
float OpenGP2Y10::dustDensity(){
	float dust = 0; 
	
	digitalWrite(_ledpin, HIGH);
	
	dust = OpenGP2Y10Curve[0] * pow(VoltageCalculation(readAnalogTimes()), OpenGP2Y10Curve[1]);
	
	digitalWrite(_ledpin, LOW);
	
	return dust;
}

/************************************ getSensor ************************************
Input: None
Output: basic information about sensor such as name, version, type, min/max value, etc.
************************************************************************************/
SensorInfo OpenGP2Y10::getSensor(){
	SensorInfo sensor;
	
	strncpy(sensor.name, "GP2Y10", sizeof(sensor.name) - 1);
	sensor.version = OPENGP2Y10_VERSION;
	sensor.type = SENSOR_TYPE_DUST;
	sensor.min_value = 0;
	sensor.analogpin = getAnalogpin();
	sensor.Vcc = getVcc();
	sensor.resolution = getResolution();
	
	return sensor;
}
