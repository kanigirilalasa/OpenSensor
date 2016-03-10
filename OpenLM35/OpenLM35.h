#ifndef OPENLM35_H
#define OPENLM35_H

#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

#include <OpenSensor.h>

class OpenLM35: public OpenSensor{
	private:
		int _pin;                                                          // analog pin that you use for sensor LM35.

	public:
		OpenLM35(int pin);
		
		float readCelsius();	                                           // tempurature value in Celsius.
		
		float readFahrenheit();                                            // // tempurature value in Fahrenheit.
};

#endif
