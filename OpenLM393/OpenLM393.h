/****************************************************************************************************
 * The OpenSensor Arduino Library is an open sources for every body who work with sensor and arduino.
 *
 * @Created by Tran Tri Tan <tantt2810@gmail.com>.
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

class OpenLM393: public OpenSensor{
	private:
		int _analogpin;
	
	public:
		OpenLM393(int analogpin);
		
		float readLightLevel();
	
};

OpenLM393::OpenLM393(int analogpin): OpenSensor(analogpin){
	_analogpin = analogpin;
}

/************************************ readLightLevel ****************************************
Input: None
Output: level of the light (0-100) percent.
Remarks: This function calculate the level of the light.
************************************************************************************/
float OpenLM393::readLightLevel(){
	
	int max_value = pow(2, _resolution);
	int value = readnTimes();
	
	float level = max_value - value;
	level /= max_value;
	level *= 100;
	
	return level;
}

#endif
