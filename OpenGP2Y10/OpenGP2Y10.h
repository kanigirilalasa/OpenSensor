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
 * This is library for dust sensor GP2Y10. It measures the density of dust.
 *
******************************************************************************************************/

#ifndef OPENGP2Y10_h
#define OPENGP2Y10_h

#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

#include <OpenSensor.h>

#define OPENGP2Y10_VERSION 1

class OpenGP2Y10: public OpenSensor{
	private:
		int _pin;                                                     // analog pin that you use for snesor.
		int _ledpin;                                                  // pin use for led inside GP2Y10, it is digital pin.
		
//		float OpenGP2Y10Curve[2] = {4.685692361, 0.582463384};        // for GP2Y10.
		float OpenGP2Y10Curve[2] = {0.07461348997, 1.659171329};        // for GP2Y10.
		
	public:
		
		/************************************ setup ****************************************
		Input: None. It use DEFAULT_VCC and DEFAULT_RESOLUTION value. Both are defined on OpenSensor class.
		Output: void
		Remarks: You must only call it one times in setup() function. It use to declare Vcc, resolution value and set pinMode OUTPUT for led on sensor. 
		************************************************************************************/
		void setup(){
			setVcc(DEFAULT_VCC);
			setResolution(DEFAULT_RESOLUTION);
			pinMode(_ledpin, OUTPUT);                                          // set OUTPUT for led inside sensor.
		}
		
		/************************************ setup ****************************************
		Input: Vcc - the value of supplying voltage for sensor. Ex: 5V, 3.3V, etc.
		        resolution - determines the resolution (in bits) of the value returned by analogRead() function.Ex: 10bit, 11bit, etc.
		Output: void
		Remarks: You must only call it one times in setup() function. It use to declare Vcc, resolution value and set pinMode OUTPUT for led on sensor. 
		************************************************************************************/
		virtual void setup(float Vcc, int resolution){
			setVcc(Vcc);
			setResolution(resolution);
			pinMode(_ledpin, OUTPUT);                                          // set OUTPUT for led inside sensor.
		}
		
		OpenGP2Y10(int analogpin, int digitalpin);
		
		float dustDensity();
		
		SensorInfo getSensor();
};

#endif
