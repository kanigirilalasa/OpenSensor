#ifndef OPENSENSOR_H
#define OPENSENSOR_H

#if ARDUINO >= 100
	#include <arduino.h>
#else 
	#include <WProgram.h>
#endif

#define READ_N_TIMES         (5)                                           //define how many times that you read analog from sensor.
#define DEFAULT_VCC          (5)
#define DEFAULT_RESOLUTION   (10)

class OpenSensor {
	private:
		int _pin;                                                          
		int _digital;
		
	protected:
		float _Vcc = 5;                                                     //default supplying voltage for sensor. 
		int _resolution = 10;                                               //default resolution.
		
	public:
		
		OpenSensor();
		OpenSensor(int pin);
		OpenSensor(int analogpin, int digitalpin);
		
		/************************************ begin ****************************************
		Input: None. It use DEFAULT_VCC and DEFAULT_RESOLUTION value.
		Output: void
		Remarks: You must only call it one times in setup() function. It declare Vcc and resolution. 
				This is a virtual function. You can redefine it in derived class. 
		************************************************************************************/
		virtual void begin(){
			_Vcc = DEFAULT_VCC;
			_resolution = DEFAULT_RESOLUTION;
		}
		
		/************************************ begin ****************************************
		Input: Vcc - the value of supplying voltage for sensor. Ex: 5V, 3.3V, etc.
		        resolution - determines the resolution (in bits) of the value returned by analogRead() function.Ex: 10bit, 11bit, etc.
		Output: void
		Remarks: You must only call it one times in setup() function. It declare Vcc and resolution. 
				This is a virtual function. You can redefine it in derived class. 
		************************************************************************************/
		virtual void begin(float Vcc, int resolution){
			_Vcc = Vcc;
			_resolution = resolution;
		}
		
		float readnTimes();
		
		float VoltageCalculation(int raw_adc, float Vcc, int resolution);
};

#endif
