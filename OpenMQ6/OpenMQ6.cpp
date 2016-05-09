#include <OpenMQ6.h>

OpenMQ6::OpenMQ6(int analogpin): OpenSensor(analogpin){}

OpenMQ6::OpenMQ6(int analogpin, int digitalpin): OpenSensor(analogpin, digitalpin){}

/****************** MQResistanceCalculation ****************************************
Input:   raw_adc - raw value read from adc, which represents the voltage
Output:  the calculated sensor resistance
Remarks: The sensor and the load resistor forms a voltage divider. Given the voltage
         across the load resistor and its resistance, the resistance of the sensor
         could be derived.
         The RL_VALUE value you can configure in header file.
************************************************************************************/

float OpenMQ6::MQResistanceCalculation(int raw_adc){
	return (RL_VALUE * (getVcc() - VoltageCalculation(raw_adc))/VoltageCalculation(raw_adc));
//return (RL_VALUE * (1023 - raw_adc)/raw_adc);
}

/************************************ GetRo *****************************************
Input: None
Output: Ro value of the sensor
Remarks: This function assumes that the sensor is in clean air. It use  
         MQResistanceCalculation to calculates the sensor resistance in clean air 
         and then divides it with RO_CLEAN_AIR_FACTOR. RSRO_CLEAN_AIR_FACTOR is about 
         10, which differs slightly between different sensors.
************************************************************************************/
float OpenMQ6::GetRo(){
	float val = 0;
	
	for(int i=1; i<=GET_RO_SAMPLE_TIMES; i++){
		val += MQResistanceCalculation(readAnalog());
	}
	
	val /= GET_RO_SAMPLE_TIMES;                                     //calculate the average value 
		
	val /= RSRO_CLEAN_AIR_FACTOR;                                  //divide for RSRO_CLEAN_AIR_FACTOR to calculate Ro
	
	return val;
}

/*****************************  GetRs *********************************************
Input:   None
Output:  Rs of the sensor
Remarks: This function use MQResistanceCalculation to caculate the sensor resistance (Rs).
         The Rs changes as the sensor is in the different consentration of the target
         gas. The sample times could be configured by changing the definition in header file.
************************************************************************************/ 
float OpenMQ6::GetRs(){
	float val = 0;
	
	for(int i=1; i<=GET_RS_SAMPLE_TIMES; i++){
		val += MQResistanceCalculation(readAnalog());
	}
	
	val /= GET_RS_SAMPLE_TIMES;
	
	return val;
}


float OpenMQ6::readLPG(){
	return LPGCurve[0] * pow((GetRs()/Ro), LPGCurve[1]);
}

float OpenMQ6::readCH4(){
	return CH4Curve[0] * pow((GetRs()/Ro), CH4Curve[1]);
}

/************************************ getSensor *******************************
Input: None
Output: basic information about sensor such as name, version, type, min/max value, etc.
************************************************************************************/
SensorInfo OpenMQ6::getSensor(){
	SensorInfo sensor;
	
	strncpy(sensor.name, "MQ6", sizeof(sensor.name) - 1);
	sensor.version = OPENMQ6_VERSION;
	sensor.type = getTypeName(SENSOR_TYPE_GAS);
	sensor.min_value = 0;
	sensor.max_value = 10000;
	sensor.analogpin = getAnalogpin();
	sensor.digitalpin = getDigitalpin();
	sensor.Vcc = getVcc();
	sensor.resolution = getResolution();
	
	return sensor;
}
