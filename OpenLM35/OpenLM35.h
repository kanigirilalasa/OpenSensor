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
 * This is library for temperature sensor LM35. It measures temperature(in Celsius or Fahrenheit).
 *
******************************************************************************************************/

#ifndef OPENLM35_H
#define OPENLM35_H

#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

#include <OpenSensor.h>

#define OPENLM35_VERSION 1

class OpenLM35: public OpenSensor{
	private:
		int _analogpin;                                                          // analog pin that you use for sensor LM35.

	public:
		OpenLM35(int analogpin);
		
		float readCelsius();	                                           // tempurature value in Celsius.
		
		float readFahrenheit();                                            // // tempurature value in Fahrenheit.
		
		float convertCtoF(float C);
		
		float convertFtoC(float F);
		
		SensorInfo getSensor();
};

#endif
