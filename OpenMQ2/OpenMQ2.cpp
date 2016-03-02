#include "OpenMQ2.h"

/****************** MQResistanceCalculation ****************************************
Contruction function: you must identify your analog pin that you use in the parameter
************************************************************************************/
OpenMQ2::OpenMQ2(int pin){
	_pin = pin;
}

/************************************ begin ****************************************
Input: None
Output: void
Remarks: You must only call it one times. It use to calculate the Ro value.
************************************************************************************/
void OpenMQ2::begin(){
	Ro = GetRo();
	Serial.print("Calibrating...\n");                       //Calibrating the sensor. Please make sure the sensor is in clean air 
	                                                    //when you perform the calibration                    
	Serial.print("Calibration is done...\n"); 
	Serial.print("Ro=");
    Serial.print(Ro);
	Serial.print("kohm");
	Serial.print("\n");
}

/****************** MQResistanceCalculation ****************************************
Input:   raw_adc - raw value read from adc, which represents the voltage
Output:  the calculated sensor resistance
Remarks: The sensor and the load resistor forms a voltage divider. Given the voltage
         across the load resistor and its resistance, the resistance of the sensor
         could be derived.
************************************************************************************/

float OpenMQ2::MQResistanceCalculation(int raw_adc){
	return (RL_VALUE * (1023 - raw_adc)/raw_adc);
}

/************************************ GetRo *****************************************
Input: None
Output: Ro value of the sensor
Remarks: This function assumes that the sensor is in clean air. It use  
         MQResistanceCalculation to calculates the sensor resistance in clean air 
         and then divides it with RO_CLEAN_AIR_FACTOR. RO_CLEAN_AIR_FACTOR is about 
         10, which differs slightly between different sensors.
************************************************************************************/
float OpenMQ2::GetRo(){
	float val = 0;
	
	for(int i=1; i<=GET_RO_SAMPLE_TIMES; i++){
		val += MQResistanceCalculation(analogRead(_pin));
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
         gas. The sample times and the time interval between samples could be configured
         by changing the definition of the macros.
************************************************************************************/ 
float OpenMQ2::GetRs(){
	float val = 0;
	
	for(int i=1; i<=GET_RS_SAMPLE_TIMES; i++){
		val += MQResistanceCalculation(analogRead(_pin));
	}
	
	val /= GET_RS_SAMPLE_TIMES;
	
	return val;
}

/***************************** ReadLPG *********************************************
Input:   None
Output:  ppm of LPG of the sensor
Remarks: This function return ppm of LPG of the sensor. It use LPGCurve[2], GetRs(), Ro
to calculate ppm of LPG.
************************************************************************************/ 
float OpenMQ2::ReadLPG(){
	return lpg = LPGCurve[0] * pow( (GetRs()/Ro), LPGCurve[1]);
}

/***************************** ReadCO *********************************************
Input:   None
Output:  ppm of CO of the sensor
Remarks: This function return ppm of CO of the sensor. It use COCurve[2], GetRs(), Ro
to calculate ppm of CO.
************************************************************************************/ 
float OpenMQ2::ReadCO(){
	return co = COCurve[0] * pow( (GetRs()/Ro), COCurve[1]);
}

/***************************** ReadSmoke *********************************************
Input:   None
Output:  ppm of Smoke of the sensor
Remarks: This function return ppm of Smoke of the sensor. It use SmokeCurve[2], GetRs(), Ro
to calculate ppm of Smoke.
************************************************************************************/ 
float OpenMQ2::ReadSmoke(){
	return smoke = SmokeCurve[0] * pow( (GetRs()/Ro), SmokeCurve[1]); 
}

/***************************** ReadPropane *********************************************
Input:   None
Output:  ppm of Propane of the sensor
Remarks: This function return ppm of Smoke of the sensor. It use PropaneCurve[2], GetRs(), Ro
to calculate ppm of Propane.
************************************************************************************/ 
float OpenMQ2::ReadPropane(){
	return propane = PropaneCurve[0] * pow( (GetRs()/Ro), PropaneCurve[1]); 
}

/***************************** ReadH2 *********************************************
Input:   None
Output:  ppm of H2 of the sensor
Remarks: This function return ppm of Smoke of the sensor. It use H2Curve[2], GetRs(), Ro
to calculate ppm of H2.
************************************************************************************/ 
float OpenMQ2::ReadH2(){
	return h2 = H2Curve[0] * pow( (GetRs()/Ro), H2Curve[1]); 
}

/***************************** ReadH2 *********************************************
Input:   None
Output:  ppm of H2 of the sensor
Remarks: This function return ppm of Smoke of the sensor. It use H2Curve[2], GetRs(), Ro
to calculate ppm of H2.
************************************************************************************/ 
float OpenMQ2::ReadAlcohol(){
	return alcohol = AlcoholCurve[0] * pow( (GetRs()/Ro), AlcoholCurve[1]); 
}
float OpenMQ2::ReadCH4(){
	return ch4 = CH4Curve[0] * pow( (GetRs()/Ro), CH4Curve[1]); 
}

float OpenMQ2::MQ135ReadCO2(){
	return mq135co2 = MQ135CO2Curve[0] * pow( (GetRs()/Ro), MQ135CO2Curve[1]); 
}
float OpenMQ2::MQ135ReadCO(){
	return mq135co = MQ135COCurve[0] * pow( (GetRs()/Ro), MQ135COCurve[1]); 
}
float OpenMQ2::MQ135ReadNH4(){
	return mq135nh4 = MQ135NH4Curve[0] * pow( (GetRs()/Ro), MQ135NH4Curve[1]); 
}
float OpenMQ2::readSulfide(){
	return sulfide = SulfideCurve[0] * pow( (GetRs()/Ro), SulfideCurve[1]); 
}
float OpenMQ2::readMethane(){
	return methane = MethaneCurve[0] * pow( (GetRs()/Ro), MethaneCurve[1]); 
}
float OpenMQ2::readBenzene(){
	return benzene = BenzeneCurve[0] * pow( (GetRs()/Ro), BenzeneCurve[1]); 
}


