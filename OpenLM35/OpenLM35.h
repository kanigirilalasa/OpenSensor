#ifndef OPENLM35_H
#define OPENLM35_H

#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

#define READ_TIMES  5                                                      // define how many times you read to average value.

class OpenLM35{
	private:
		int _pin;                                                          // analog pin that you use for sensor LM35.
	public:
		OpenLM35(int pin);
		float readCelsius(float voltage, int resolution);	
		float readFahrenheit(float voltage, int resolution);
		float readnTimes();	
};

#endif
