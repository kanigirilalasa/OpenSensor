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
 * This is library for gas sensor. It is suitable for detecting of LPG, Methane(CH4).
 *
******************************************************************************************************/

#ifndef OPENMQ6_H
#define OPENMQ6_H

#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

#include "OpenSensor.h"

#define OPENMQ6_VERSION              1

#define RSRO_CLEAN_AIR_FACTOR        9.9                                  //The value of Rs/Ro in clean air. According chart in datasheet.
#define RL_VALUE                     20                                     //The value of the load resistance on the board, in kilo ohms.
#define GET_RO_SAMPLE_TIMES          10                                    //The times of calibrating 
#define GET_RS_SAMPLE_TIMES          10

class OpenMQ6: public OpenSensor{
	private:
		
		float LPGCurve[2] = {1137.436966, -2.287352162};
		float CH4Curve[2] = {2289.351676, -2.477686812};
		
		float Ro = 0;
		
		float MQResistanceCalculation(int raw_adc);
		
	public :
		OpenMQ6(int analogpin);
		OpenMQ6(int analogpin, int digitalpin);
		
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
		
		float readLPG();
		
		float readCH4();
		
		SensorInfo getSensor();
};

#endif
