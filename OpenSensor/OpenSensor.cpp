#include <OpenSensor.h>

OpenSensor::OpenSensor(){}

OpenSensor::OpenSensor(int analogpin){
	_analogpin = analogpin;
}

OpenSensor::OpenSensor(int analogpin, int digitalpin){
	_analogpin = analogpin;
	_digitalpin = digitalpin;
}

void OpenSensor::setAnalogpin(int analogpin){
	_analogpin = analogpin;
}

void OpenSensor::setDigitalpin(int digitalpin){
	_digitalpin = digitalpin;
}

void OpenSensor::setVcc(float Vcc){
	_Vcc = Vcc;
}

void OpenSensor::setResolution(int resolution){
	_resolution = resolution;
}

int OpenSensor::getAnalogpin(){
	return _analogpin;
}

int OpenSensor::getDigitalpin(){
	return _digitalpin;
}

float OpenSensor::getVcc(){
	return _Vcc;
}

int OpenSensor::getResolution(){
	return _resolution;
}

/************************************ readAnalog ************************************
Input: none
Output: adc value of the sensor.
************************************************************************************/
int OpenSensor::readAnalog(){
	return analogRead(_analogpin);
}

/************************************ readAnalogTimes **********************************
Input: none
Output: average adc value of sensor after READ_TIMES times reading.
Remarks: This function help to get value exactly because it read more times then average them.
         The READ_N_TIMES value you can configure in header file.
************************************************************************************/
float OpenSensor::readAnalogTimes(){
	  float val = 0;
	  for(int i=1; i<=READ_N_TIMES; i++){                               
		val += analogRead(_analogpin);                                      // Read READ_N_TIMES time then sum them.
	  }
	  val = val/READ_N_TIMES;                                         // average values;
	  return val;
}

/************************************ readAnalogTimes **********************************
Input: num_times - number of times that you read.
Output: average adc value of sensor after num_times times reading.
Remarks: This function help to get value exactly because it read more times then average them.
************************************************************************************/
float OpenSensor::readAnalogTimes(int num_times){
	  float val = 0;
	  for(int i=1; i<=num_times; i++){                               
	    val += analogRead(_analogpin);                                      // Read num_times time then sum them.
	  }
	  val = val/num_times;                                         // average values;
	  return val;
}

/************************************ VoltageCalculation **********************************
Input: raw_adc - the value of analog input.
	   Vcc - the value of supplying voltage.Ex: 5V, 3.3V, etc.
	   resolution - determines the resolution (in bits) of the value returned by analogRead() function.Ex: 10bit, 11bit, etc.
Output: voltage value(V) that convert from raw_adc.
Remarks: This function map raw_adc(input analog) into input voltages.
************************************************************************************/
float OpenSensor::VoltageCalculation(int raw_adc){
	return (raw_adc * _Vcc / pow(2, _resolution));
}

/************************************ readVout *************************************
Input: None.
Output: the out put voltage value of sensor.\

************************************************************************************/
float OpenSensor::readVout(){
	return VoltageCalculation(readAnalog());
}

/************************************ readVout *************************************
Input: None.
Output: read digital value.
		return 1 if HIGH
		return 0 if LOW
************************************************************************************/
int OpenSensor::readDigital(){
	if(digitalRead(_digitalpin) == HIGH)
		return 1;
	if(digitalRead(_digitalpin) == LOW)
		return 0;
//	return (digitalRead(_digitalpin) == HIGH) ? HIGH : LOW;
}

char* OpenSensor::getTypeName(SensorType type){
	char* str;
			
	switch(type){
		case 1:
			str = "SENSOR_TYPE_TEMPERATURE";
			break;
		case 2:
			str = "SENSOR_TYPE_LIGHT";
			break;
		case 3:
			str = "SENSOR_TYPE_GAS"; 
			break;
		case 4:
			str = "SENSOR_TYPE_DUST";
			break;
		case 5:
			str = "SENSOR_TYPE_GYROSCOPE";
			break;
		case 6:
			str = "SENSOR_TYPE_PRESSURE";
			break;
		case 7:
			str = "SENSOR_TYPE_PROXIMITY";
			break;
		case 8:
			str = "SENSOR_TYPE_GRAVITY";
			break;
		case 9:
			str = "SENSOR_TYPE_ROTATION_VECTOR";
			break;
		case 10:
			str = "SENSOR_TYPE_HUMIDITY";
			break;
		case 11:
			str = "SENSOR_TYPE_COLOR";
			break;
		default:
			str = "UNDETERMINE";
			break;
	}
	return str;
}
