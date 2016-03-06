#ifndef OPENSENSOR_H
#define OPENSENSOR_H

#if ARDUINO >= 100
	#include <arduino.h>
#else 
	#include <WProgram.h>
#endif

#define READ_N_TIMES         (5)                                           //define how many times that you read analog from sensor.

class OpenSensor {
	private:
		int _pin;                                                          
		int _digital;
	public:
		OpenSensor();
		OpenSensor(int pin);
		OpenSensor(int analogpin, int digitalpin);
		
		float readnTimes();
		float VoltageCalculation(int raw_adc, float Vcc, int resolution);
};

#endif
