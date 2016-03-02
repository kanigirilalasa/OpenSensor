#include <OpenSensor.h>

OpenSensor::OpenSensor(int pin): OpenLM35(pin), OpenMQ2(pin), OpenGP2Y10(pin){
	_pin = pin;
}

//OpenSensor::OpenSensor(int analogpin, int digitalpin): OpenGP2Y10(analogpin, digitalpin){
//	_pin = analogpin;
//	_digitalpin = digitalpin;
//}
