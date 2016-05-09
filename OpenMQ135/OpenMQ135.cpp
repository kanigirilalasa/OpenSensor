#include <OpenMQ135.h>
/****************** OpenMQ135 ****************************************
Contruction function: you must declare your analog pin that you use in the parameter
************************************************************************************/
OpenMQ135::OpenMQ135(int analogpin): OpenSensor(analogpin){}

/****************** OpenMQ135 ****************************************
Contruction function: you must declare your analog pin and digital pin that you use in the parameter
************************************************************************************/
OpenMQ135::OpenMQ135(int analogpin, int digitalpin): OpenSensor(analogpin, digitalpin){}

/****************** MQResistanceCalculation ****************************************
Input:   raw_adc - raw value read from adc, which represents the voltage
Output:  the calculated sensor resistance
Remarks: The sensor and the load resistor forms a voltage divider. Given the voltage
         across the load resistor and its resistance, the resistance of the sensor
         could be derived.
         The RL_VALUE value you can configure in header file.
************************************************************************************/

float OpenMQ135::MQResistanceCalculation(int raw_adc){
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
float OpenMQ135::GetRo(){
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
float OpenMQ135::GetRs(){
	float val = 0;
	
	for(int i=1; i<=GET_RS_SAMPLE_TIMES; i++){
		val += MQResistanceCalculation(readAnalog());
	}
	
	val /= GET_RS_SAMPLE_TIMES;
	
	return val;
}

/***************************** readCO2 *********************************************
Input:   None
Output:  ppm of CO2 of the sensor
Remarks: This function return ppm of CO2 of the sensor. It use CO2Curve[2], GetRs(), Ro
to calculate ppm of CO2.
************************************************************************************/ 
float OpenMQ135::readCO2(){
	return co2 = CO2Curve[0] * pow( (GetRs()/Ro), CO2Curve[1]); 
}

/***************************** readCO *********************************************
Input:   None
Output:  ppm of CO of the sensor
Remarks: This function return ppm of CO of the sensor. It use COCurve[2], GetRs(), Ro
to calculate ppm of CO.
************************************************************************************/ 
float OpenMQ135::readCO(){
	return co = COCurve[0] * pow( (GetRs()/Ro), COCurve[1]); 
}

/***************************** readNH4 *********************************************
Input:   None
Output:  ppm of NH4 of the sensor
Remarks: This function return ppm of NH4 of the sensor. It use NH4Curve[2], GetRs(), Ro
to calculate ppm of NH4.
************************************************************************************/ 
float OpenMQ135::readNH4(){
	return nh4 = NH4Curve[0] * pow( (GetRs()/Ro), NH4Curve[1]); 
}

/***************************** readSulfide *********************************************
Input:   None
Output:  ppm of Sulfide of the sensor
Remarks: This function return ppm of Sulfide of the sensor. It use SulfideCurve[2], GetRs(), Ro
to calculate ppm of Sulfide.
************************************************************************************/ 
float OpenMQ135::readSulfide(){
	return sulfide = SulfideCurve[0] * pow( (GetRs()/Ro), SulfideCurve[1]); 
}

/***************************** readMethane *********************************************
Input:   None
Output:  ppm of Methane of the sensor
Remarks: This function return ppm of Methane of the sensor. It use MethaneCurve[2], GetRs(), Ro
to calculate ppm of Methane.
************************************************************************************/ 
float OpenMQ135::readMethane(){
	return methane = MethaneCurve[0] * pow( (GetRs()/Ro), MethaneCurve[1]); 
}

/***************************** readBenzene *********************************************
Input:   None
Output:  ppm of Benzene of the sensor
Remarks: This function return ppm of Benzene of the sensor. It use BenzeneCurve[2], GetRs(), Ro
to calculate ppm of Benzene.
************************************************************************************/ 
float OpenMQ135::readBenzene(){
	return benzene = BenzeneCurve[0] * pow( (GetRs()/Ro), BenzeneCurve[1]); 
}

/************************************ getSensor *******************************
Input: None
Output: basic information about sensor such as name, version, type, min/max value, etc.
************************************************************************************/
SensorInfo OpenMQ135::getSensor(){
	SensorInfo sensor;
	
	strncpy(sensor.name, "MQ135", sizeof(sensor.name) - 1);
	sensor.version = OPENMQ135_VERSION;
	sensor.type = getTypeName(SENSOR_TYPE_GAS);
	sensor.min_value = 0;
	sensor.max_value = 10000;
	sensor.analogpin = getAnalogpin();
	sensor.digitalpin = getDigitalpin();
	sensor.Vcc = getVcc();
	sensor.resolution = getResolution();
	
	return sensor;
}
