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
//		float _Vcc;                                                   // the value of supplying voltage for sensor. Ex: 5V, 3.3V, etc.
//		int _resolution;                                              // determines the resolution (in bits) of the value returned by analogRead().Ex: 10bit, 11bit, etc. 
		
		float OpenGP2Y10Curve[2] = {4.685692361, 0.582463384};        // for GP2Y10.
		
	public:
		
		/************************************ begin ****************************************
		Input: None. It use DEFAULT_VCC and DEFAULT_RESOLUTION value. Both are defined on OpenSensor class.
		Output: void
		Remarks: You must only call it one times in setup() function. It use to declare Vcc, resolution value and set pinMode OUTPUT for led on sensor. 
		************************************************************************************/
		virtual void begin(){
			_Vcc = DEFAULT_VCC;
			_resolution = DEFAULT_RESOLUTION;
			pinMode(_ledpin, OUTPUT);
		}
		
		/************************************ begin ****************************************
		Input: Vcc - the value of supplying voltage for sensor. Ex: 5V, 3.3V, etc.
		        resolution - determines the resolution (in bits) of the value returned by analogRead() function.Ex: 10bit, 11bit, etc.
		Output: void
		Remarks: You must only call it one times in setup() function. It use to declare Vcc, resolution value and set pinMode OUTPUT for led on sensor. 
		************************************************************************************/
		virtual void begin(float Vcc, int resolution){
			_Vcc = Vcc;
			_resolution = resolution;
			pinMode(_ledpin, OUTPUT);                                          // set OUTPUT for led inside sensor.
		}
		
		OpenGP2Y10(int analogpin, int digitalpin);
		
		float dustDensity();
};

#endif
