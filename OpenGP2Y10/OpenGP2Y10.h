#ifndef OPENGP2Y10_h
#define OPENGP2Y10_h

#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

class OpenGP2Y10{
	private:
		int _pin; 
		int _ledpin = 12;
		
		float OpenGP2Y10Curve[2] = {4.685692361, 0.582463384};                          
		#define Vcc                                 (3.3)
		#define READ_SAMPLE_TIMES                   (10)
		
	public:
		OpenGP2Y10(int pin);
//		OpenGP2Y10(int analogpin, int digitalpin);
		float VoltageCalculation(int raw_adc);
		float DustDensity();
		float readnTimes();
};

#endif
