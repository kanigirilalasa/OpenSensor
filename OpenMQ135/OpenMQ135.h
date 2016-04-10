/****************************************************************************************************
 * The OpenSensor Arduino Library is an open sources for every body who work with sensor and arduino.
 *
 * @Created by Tran Tri Tan <tantt2810@gmail.com>.
 * @Copyright (C) 2016.
 *
 * Full sources: https://github.com/tantt2810/Opensensor
 *
 ***********************************************
 * DESCRIPTION
 *
 * This is library for air quality sensor MQ135. It is suitable for detecting of NH3, CO, CO2, Benzene, Sunfide, Methane.
 *
 *****************************************************************************************************/

#ifndef OPENMQ135_h
#define OPENMQ135_h

#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

#include <OpenSensor.h>

#define OPENMQ135_VERSION              1

#define RSRO_CLEAN_AIR_FACTOR        3.7                                  //The value of Rs/Ro in clean air. According chart in datasheet.
#define RL_VALUE                     20                                     //The value of the load resistance on the board, in kilo ohms.
#define GET_RO_SAMPLE_TIMES          10                                    //The times of calibrating 
#define GET_RS_SAMPLE_TIMES          10
		
class OpenMQ135: public OpenSensor{
	private:
		int _pin;	
		
		float CO2Curve[2] = {116.2737926, -2.737813368};                      // for MQ135
		float COCurve[2] = {782.8492416, -4.268032155};                       // for MQ135  
		float NH4Curve[2] = {109.1992962, -2.461721687};                      // for MQ135
		float SulfideCurve[2] = {80.95013972, -3.05514173};                   // for MQ135
		float MethaneCurve[2] = {47.98892735, -3.275556469};                  // for MQ135
		float BenzeneCurve[2] = {36.78019998, -3.291545675};                  // for MQ135
		
		float co2 = 0.0;                                                      // ppm of co2 for MQ135
		float co = 0.0;                                                       // ppm of co for MQ135
		float nh4 = 0.0;                                                      // ppm of nh4 for MQ135
		float sulfide = 0.0;                                                  // ppm of nh4 for MQ135
		float methane = 0.0;                                                  // ppm of nh4 for MQ135
		float benzene = 0.0;                                                  // ppm of nh4 for MQ135
		
		float Ro = 0;
		
		float MQResistanceCalculation(int raw_adc);
	
	public:
		OpenMQ135(int pin);
		
		/************************************ setup ****************************************
		Input: None. It use DEFAULT_VCC and DEFAULT_RESOLUTION value. Both are defined on OpenSensor class.
		Output: void
		Remarks: You must only call it one times in setup() function. It use to declare Vcc, resolution value and calculate the Ro value. 
		************************************************************************************/
		void setup(){
			setVcc(DEFAULT_VCC);
			setResolution(DEFAULT_RESOLUTION);
			
			Ro = GetRo();
			
			Serial.print("Calibrating...\n");                       //Calibrating the sensor. Please make sure the sensor is in clean air 
			                                                        //when you perform the calibration                    
			Serial.print("Calibration is done...\n"); 
			Serial.print("Ro=");
		    Serial.print(Ro);
			Serial.print("kohm");
			Serial.print("\n");
		}
		
		/************************************ setup ****************************************
		Input: Vcc - the value of supplying voltage for sensor. Ex: 5V, 3.3V, etc.
		        resolution - determines the resolution (in bits) of the value returned by analogRead() function.Ex: 10bit, 11bit, etc.
		Output: void
		Remarks: You must only call it one times in setup() function. It use to declare Vcc, resolution value and calculate the Ro value. 
		************************************************************************************/
		void setup(float Vcc, int resolution){
			setVcc(Vcc);
			setResolution(resolution);
			
			Ro = GetRo();
			
			Serial.print("Calibrating...\n");                       //Calibrating the sensor. Please make sure the sensor is in clean air 
			                                                        //when you perform the calibration                    
			Serial.print("Calibration is done...\n"); 
			Serial.print("Ro=");
		    Serial.print(Ro);
			Serial.print("kohm");
			Serial.print("\n");
		}
		
		float GetRo();
		float GetRs();
	
		float readCO2();
		float readCO();
		float readNH4();
		float readSulfide();
		float readMethane();
		float readBenzene();
		
		SensorInfo getSensor();
};

#endif
