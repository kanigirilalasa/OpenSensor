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
 * This is library for gas sensor.
 *
******************************************************************************************************/

#ifndef OPENMQ_H
#define OPENMQ_H

#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

#include <OpenSensor.h>

#define RSRO_CLEAN_AIR_FACTOR        9.83                                  //The value of Rs/Ro in clean air. According chart in datasheet.
#define RL_VALUE                     5                                     //The value of the load resistance on the board, in kilo ohms.
#define GET_RO_SAMPLE_TIMES          10                                    //The times of calibrating 
#define GET_RS_SAMPLE_TIMES          10

class OpenMQ: public OpenSensor{
	private:
		int _analogpin;			
		
	protected:	
		float Ro = 0;
		
		float MQResistanceCalculation(int raw_adc);
		
	public:
		OpenMQ(int analogpin);
		
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
		virtual void setup(float Vcc, int resolution){
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
};

#endif
