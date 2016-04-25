#include "OpenMQ2.h"

/****************** OpenMQ2 ****************************************
Contruction function: you must declare your analog pin that you use for sensor.
************************************************************************************/
OpenMQ2::OpenMQ2(int analogpin): OpenSensor(analogpin){
//	_analogpin = analogpin;
}

//OpenMQ2::OpenMQ2(int analogpin, int digitalpin): OpenSensor(analogpin, digitalpin){}

/****************** MQResistanceCalculation ****************************************
Input:   raw_adc - raw value read from adc, which represents the voltage
Output:  the calculated sensor resistance
Remarks: The sensor and the load resistor forms a voltage divider. Given the voltage
         across the load resistor and its resistance, the resistance of the sensor
         could be derived.
         The RL_VALUE value you can configure in header file.
************************************************************************************/

float OpenMQ2::MQResistanceCalculation(int raw_adc){
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
float OpenMQ2::GetRo(){
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
float OpenMQ2::GetRs(){
	float val = 0;
	
	for(int i=1; i<=GET_RS_SAMPLE_TIMES; i++){
		val += MQResistanceCalculation(readAnalog());
	}
	
	val /= GET_RS_SAMPLE_TIMES;
	
	return val;
}

/***************************** readLPG *********************************************
Input:   None
Output:  ppm of LPG of the sensor
Remarks: This function return ppm of LPG of the sensor. It use LPGCurve[2], GetRs(), Ro
to calculate ppm of LPG.
************************************************************************************/ 
float OpenMQ2::readLPG(){
	return lpg = LPGCurve[0] * pow( (GetRs()/Ro), LPGCurve[1]);
}

/***************************** readCO *********************************************
Input:   None
Output:  ppm of CO of the sensor
Remarks: This function return ppm of CO of the sensor. It use COCurve[2], GetRs(), Ro
to calculate ppm of CO.
************************************************************************************/ 
float OpenMQ2::readCO(){
	return co = COCurve[0] * pow( (GetRs()/Ro), COCurve[1]);
}

/***************************** readSmoke *********************************************
Input:   None
Output:  ppm of Smoke of the sensor
Remarks: This function return ppm of Smoke of the sensor. It use SmokeCurve[2], GetRs(), Ro
to calculate ppm of Smoke.
************************************************************************************/ 
float OpenMQ2::readSmoke(){
	return smoke = SmokeCurve[0] * pow( (GetRs()/Ro), SmokeCurve[1]); 
}

/***************************** readPropane *********************************************
Input:   None
Output:  ppm of Propane of the sensor
Remarks: This function return ppm of Smoke of the sensor. It use PropaneCurve[2], GetRs(), Ro
to calculate ppm of Propane.
************************************************************************************/ 
float OpenMQ2::readPropane(){
	return propane = PropaneCurve[0] * pow( (GetRs()/Ro), PropaneCurve[1]); 
}

/***************************** readH2 *********************************************
Input:   None
Output:  ppm of H2(Hydrogen) of the sensor
Remarks: This function return ppm of Smoke of the sensor. It use H2Curve[2], GetRs(), Ro
to calculate ppm of H2.
************************************************************************************/ 
float OpenMQ2::readH2(){
	return h2 = H2Curve[0] * pow( (GetRs()/Ro), H2Curve[1]); 
}

/***************************** readAlcohol *********************************************
Input:   None
Output:  ppm of Alcohol of the sensor
Remarks: This function return ppm of Smoke of the sensor. It use AlcoholCurve[2], GetRs(), Ro
to calculate ppm of Alcohol.
************************************************************************************/ 
float OpenMQ2::readAlcohol(){
	return alcohol = AlcoholCurve[0] * pow( (GetRs()/Ro), AlcoholCurve[1]); 
}

/***************************** readCH4 *********************************************
Input:   None
Output:  ppm of CH4(Methane) of the sensor
Remarks: This function return ppm of Smoke of the sensor. It use CH4Curve[2], GetRs(), Ro
to calculate ppm of CH4.
************************************************************************************/ 
float OpenMQ2::readCH4(){
	return ch4 = CH4Curve[0] * pow( (GetRs()/Ro), CH4Curve[1]); 
}

/************************************ getSensor *******************************
Input: None
Output: basic information about sensor such as name, version, type, min/max value, etc.
************************************************************************************/
SensorInfo OpenMQ2::getSensor(){
	SensorInfo sensor;
	
	strncpy(sensor.name, "MQ2", sizeof(sensor.name) - 1);
	sensor.version = OPENMQ2_VERSION;
	sensor.type = SENSOR_TYPE_GAS;
	sensor.min_value = 0;
	sensor.max_value = 10000;
	sensor.analogpin = getAnalogpin();
	sensor.Vcc = getVcc();
	sensor.resolution = getResolution();
	
	return sensor;
}




