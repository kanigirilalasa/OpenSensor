#ifndef OPENGP2Y10_h
#define OPENGP2Y10_h

#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

#include <OpenSensor.h>

class OpenGP2Y10: public OpenSensor{
	private:
		int _pin;                                                     // analog pin that you use for snesor.
		int _ledpin;                                                  // pin use for led inside GP2Y10, it is digital pin.
		float _Vcc;                                                   // the value of supplying voltage for sensor. Ex: 5V, 3.3V, etc.
		int _resolution;                                              // determines the resolution (in bits) of the value returned by analogRead().Ex: 10bit, 11bit, etc. 
		
		float OpenGP2Y10Curve[2] = {4.685692361, 0.582463384};        // for GP2Y10.
		
	public:
		OpenGP2Y10(int pin);
		void begin(float Vcc, int resolution);
		OpenGP2Y10(int analogpin, int digitalpin);
		float dustDensity();
};

#endif
