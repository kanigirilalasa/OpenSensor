#include <OpenMQ.h>

OpenMQ::OpenMQ(int analogpin): OpenSensor(analogpin){
	_analogpin = analogpin;
}

/****************** MQResistanceCalculation ****************************************
Input:   raw_adc - raw value read from adc, which represents the voltage
Output:  the calculated sensor resistance
Remarks: The sensor and the load resistor forms a voltage divider. Given the voltage
         across the load resistor and its resistance, the resistance of the sensor
         could be derived.
         The RL_VALUE value you can configure in header file.
************************************************************************************/
float OpenMQ::MQResistanceCalculation(int raw_adc){
	return (RL_VALUE * (getVcc() - VoltageCalculation(raw_adc))/VoltageCalculation(raw_adc));
}

/************************************ GetRo *****************************************
Input: None
Output: Ro value of the sensor
Remarks: This function assumes that the sensor is in clean air. It use  
         MQResistanceCalculation to calculates the sensor resistance in clean air 
         and then divides it with RO_CLEAN_AIR_FACTOR. RSRO_CLEAN_AIR_FACTOR is about 
         10, which differs slightly between different sensors.
************************************************************************************/
float OpenMQ::GetRo(){
	float val = 0;
	
	for(int i=1; i<=GET_RO_SAMPLE_TIMES; i++){
		val += MQResistanceCalculation(readAnalogTimes());
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
float OpenMQ::GetRs(){
	float val = 0;
	
	for(int i=1; i<=GET_RS_SAMPLE_TIMES; i++){
		val += MQResistanceCalculation(readAnalogTimes());
	}
	
	val /= GET_RS_SAMPLE_TIMES;
	
	return val;
}
