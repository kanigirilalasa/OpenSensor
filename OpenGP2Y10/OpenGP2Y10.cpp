#include <OpenGP2Y10.h>

OpenGP2Y10::OpenGP2Y10(int pin): OpenSensor(pin){
	_pin = pin;
//	_ledpin = ledpin;
}

OpenGP2Y10::OpenGP2Y10(int analogpin, int digitalpin): OpenSensor(analogpin, digitalpin){
	_pin = analogpin;
	_ledpin = digitalpin;
}

/************************************ begin ****************************************
Input: None
Output: Vcc - the value of supplying voltage for sensor. Ex: 5V, 3.3V, etc.
        resolution - determines the resolution (in bits) of the value returned by analogRead() function.Ex: 10bit, 11bit, etc.
Remarks: You must only call it one times int setup() function. It use to calculate the Ro value.
************************************************************************************/
void OpenGP2Y10::begin(float Vcc, int resolution){
	_Vcc = Vcc;
	_resolution = resolution;
	pinMode(_ledpin, OUTPUT);                                          // set OUTPUT for led inside sensor.
}

/************************************ dustDensity ****************************************
Input: None
Output: dust density in the air (mg/m3).
Remarks: This function calculate the dust density in the air base on using OpenGP2Y10Curve.
************************************************************************************/
float OpenGP2Y10::dustDensity(){
	float dust = 0; 
	
	digitalWrite(_ledpin, HIGH);
	
	dust = OpenGP2Y10Curve[0] * pow(VoltageCalculation(readnTimes(), _Vcc, _resolution), OpenGP2Y10Curve[1]);
	
	digitalWrite(_ledpin, LOW);
	
	return dust;
}
