#include <OpenGP2Y10.h>

OpenGP2Y10::OpenGP2Y10(int pin){
	_pin = pin;
//	_ledpin = ledpin;
}

//OpenGP2Y10::OpenGP2Y10(int analogpin, int digitalpin){
//	_pin = analogpin;
//	_ledpin = digitalpin;
//}

float OpenGP2Y10::VoltageCalculation(int raw_adc){
	return (raw_adc * Vcc / 1024);
}

float OpenGP2Y10::DustDensity(){
	float dust = 0; 
	
	digitalWrite(_ledpin, HIGH);
	
	dust = OpenGP2Y10Curve[0] * pow(VoltageCalculation(readnTimes()), OpenGP2Y10Curve[1]);
	
	digitalWrite(_ledpin, LOW);
	
	return dust;
}

float OpenGP2Y10::readnTimes(){
	float val;
	
	for(int i=1; i<=READ_SAMPLE_TIMES; i++){
		val += analogRead(_pin);
	}
	
	val /= READ_SAMPLE_TIMES;
	
	return val;
}
