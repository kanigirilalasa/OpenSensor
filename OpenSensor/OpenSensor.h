#ifndef OPENSENSOR_H
#define OPENSENSOR_H

#if ARDUINO >= 100
	#include <arduino.h>
#else 
	#include <WProgram.h>
#endif
#include <OpenLM35.h>
#include <OpenMQ2.h>
#include <OpenGP2Y10.h>

class OpenSensor : public OpenLM35, public OpenMQ2, public OpenGP2Y10{
	private:
		int _pin;
	public:
		OpenSensor(int pin);
		OpenSensor(int analogpin, int digitalpin);
};

#endif
