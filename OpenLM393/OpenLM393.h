/****************************************************************************************************
 * The OpenSensor Arduino Library is an open sources for every body who work with sensor and arduino.
 *
 * @Created by Tran Tri Tan <tantt2810@gmail.com>.
 *
 * @Intructor: Truong Minh Thai (tmthai@cit.ctu.edu.vn).
 * 
 * @Copyright (C) 2016.
 *
 * Full sources: https://github.com/tantt2810/Opensensor
 *
 ***********************************************
 * DESCRIPTION
 *
 * This is library for light sensor LM393. It measures the level of light.
 * 
 *****************************************************************************************************/

#ifndef OPENLM393_H
#define OPENLM393_H

#if ARDUINO >= 100
	#include <arduino.h>
#else 
	#include <WProgram.h>
#endif

#include <OpenSensor.h>

#define OPENLM393_VERSION 1

class OpenLM393: public OpenSensor{
	private:
		int _analogpin;
		int _digitalpin;
	
	public:
		OpenLM393(int analogpin);
		
		OpenLM393(int analogpin, int digitalpin);
		
		SensorInfo getSensor();
		
		float readLightLevel();	
		
		bool isLight();

};

OpenLM393::OpenLM393(int analogpin): OpenSensor(analogpin){
	_analogpin = analogpin;
}

OpenLM393::OpenLM393(int analogpin, int digitalpin): OpenSensor(analogpin, digitalpin){
	_analogpin = analogpin;
	_digitalpin	= digitalpin;
}

/************************************ getSensor *******************************
Input: None
Output: basic information about sensor such as name, version, type, min/max value, etc.
************************************************************************************/
SensorInfo OpenLM393::getSensor(){
	SensorInfo sensor;
	
	strncpy(sensor.name, "LM393", sizeof(sensor.name) - 1);
	sensor.version = OPENLM393_VERSION;
	sensor.type = SENSOR_TYPE_LIGHT;
	sensor.min_value = 0;
	sensor.max_value = 100;
	sensor.analogpin = getAnalogpin();
	sensor.Vcc = getVcc();
	sensor.resolution = getResolution();
	
	return sensor;
}

/************************************ readLightLevel *******************************
Input: None
Output: level of the light (0-100) percent.
Remarks: This function calculate the level of the light.
************************************************************************************/
float OpenLM393::readLightLevel(){
	
	int max_value = pow(2, getResolution());
	int value = readAnalogTimes();
	
	float level = max_value - value;
	level /= max_value;
	level *= 100;
	
	return level;
}

/************************************ isLight **************************************
Input: None
Output: true if Light, false if Dark.
************************************************************************************/
bool OpenLM393::isLight(){
	if(readDigital() == HIGH)             // Dark
		return false;
	else                                  // Light
		return true;
}
#endif
