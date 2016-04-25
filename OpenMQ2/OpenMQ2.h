/****************************************************************************************************
 * The OpenSensor Arduino Library is an open sources for every body who work with sensor and arduino.
 *
 * @Created by Tran Tri Tan <tantt2810@gmail.com>.
 *
 * @Intructor: Truong Minh Thai (tmthai@cit.ctu.edu.vn).
 *
 * @Copyright (C) 2016.
 *
 * Full sources: https://github.com/tantt2810/Opensensor
 *
 ***********************************************
 * DESCRIPTION
 *
 * This is library for gas sensor MQ2. It is suitable for detecting of LPG, CO, propane, methane(CH4) ,alcohol, Hydrogen, smoke.
 *
******************************************************************************************************/

#ifndef OPENMQ2_h
#define OPENMQ2_h

#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

#include <OpenSensor.h>

#define OPENMQ2_VERSION              1

#define RSRO_CLEAN_AIR_FACTOR        9.83                                  //define the value of Rs/Ro in clean air. According chart in datasheet.
#define RL_VALUE                     5                                     //define the value of the load resistance on the board, in kilo ohms.
#define GET_RO_SAMPLE_TIMES          10                                    //define how many times of calibrating to calculate Ro.
#define GET_RS_SAMPLE_TIMES          10                                    //define how many times of calibrating to calculate Rs.  

class OpenMQ2 : public OpenSensor{
	private:
		int _analogpin;
		
		float LPGCurve[2] = {612.4440432 , -2.085289323};                          // for MQ2
		float PropaneCurve[2] = {677.6031938, -2.104428615};                       // for MQ2
		float H2Curve[2] = {1006.236728, -2.079504157};                            // for MQ2
		float AlcoholCurve[2] = {3678.043993, -2.670473053};                       // for MQ2
		float CH4Curve[2] = {4434.153811, -2.623022788};                           // for MQ2
		float SmokeCurve[2] = {4052.338977, -2.273451061};                         // for MQ2
		float COCurve[2] = {32545.19524, -3.050192053};                            // for MQ2
		
		float lpg = 0.0;                                                           // ppm of lpg for MQ2
		float co = 0.0;                                                            // ppm of co for MQ2
		float smoke = 0.0;														   // ppm of smoke for MQ2
		float propane = 0.0;                                                       // ppm of propane for MQ2
		float h2 = 0.0;                                                            // ppm of h2 for MQ2
		float alcohol = 0.0;                                                       // ppm of alcohol for MQ2
		float ch4 = 0.0;                                                           // ppm of ch4 for MQ2
		
		float Ro = 0;
		
		float MQResistanceCalculation(int raw_adc);	
	public:	
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
		
		OpenMQ2(int analogpin);
//		OpenMQ2(int analogpin, int digitalpin);
		
		float GetRo();
		float GetRs();
		float getRsRo(float tempurature, float humidity){
			return (0.0004 *	pow(tempurature, 2) - 0.0273 * tempurature + 1.4179) * humidity / 33;
		}
		
		float readLPG();
		float readCO();
		float readSmoke();
		float readPropane();
		float readH2();                                  //Read Hydrogen
		float readAlcohol();
		float readCH4();                                 //Read Methane
		
		SensorInfo getSensor();
};

#endif
