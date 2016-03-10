#include <OpenGP2Y10.h>

OpenGP2Y10::OpenGP2Y10(int analogpin, int digitalpin): OpenSensor(analogpin, digitalpin){
	_pin = analogpin;
	_ledpin = digitalpin;
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
