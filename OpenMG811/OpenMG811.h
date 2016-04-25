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
 * This is library for CO2 sensor MG811. It measures ppm of CO2 in the air.
 *
******************************************************************************************************/

#ifndef OPENMG811_H
#define OPENMG811_H

#if ARDUINO >= 100
	#include <arduino.h>
#else 
	#include <WProgram.h>
#endif

#include <OpenSensor.h>

#define OPENMG811_VERSION 1

#define         DC_GAIN                      (8.5)   //define the DC gain of amplifier

#define         ZERO_POINT_VOLTAGE           (0.220) //define the output of the sensor in volts when the concentration of CO2 is 400PPM
#define         REACTION_VOLTGAE             (0.020) //define the voltage drop of the sensor when move the sensor from air into 1000ppm CO2

class OpenMG811: public OpenSensor{
	
	private:
		int _analogpin;                                                                                         // analog pin for sensor.  
		int _digitalpin;                                                                                        
	 
		float CO2Curve[3]  =  {2.602,ZERO_POINT_VOLTAGE,(REACTION_VOLTGAE/(2.602-3))};                          // for MG811.
//		float Curve[2] = {0.000002420649289, -16.70473006};
//		float Curve[2] = {3.148633123*pow(10,44), -16.70473006};
		
	public:
		OpenMG811(int analogpin);
		
		SensorInfo getSensor();
		
		float readCO2();
};

	OpenMG811::OpenMG811(int analogpin): OpenSensor(analogpin){
		_analogpin = analogpin;
	}

	/************************************ getSensor *******************************
	Input: None
	Output: basic information about sensor such as name, version, type, min/max value, etc.
	************************************************************************************/
	SensorInfo OpenMG811::getSensor(){
		SensorInfo sensor;
		
		strncpy(sensor.name, "MG811", sizeof(sensor.name) - 1);
		sensor.version = OPENMG811_VERSION;
		sensor.type = SENSOR_TYPE_GAS;
		sensor.min_value = 350;
		sensor.max_value = 10000;
		sensor.analogpin = getAnalogpin();
		sensor.Vcc = getVcc();
		sensor.resolution = getResolution();
		
		return sensor;
	}
	
	/********************************** readCO2 ****************************************
	Input:   none
	Output:  ppm of CO2.
	Remarks: This function use CO2Curve to calculate ppm of CO2.
	************************************************************************************/
	float OpenMG811::readCO2(){
		return pow(10, ((readVout()/DC_GAIN)-CO2Curve[1])/CO2Curve[2]+CO2Curve[0]);
	//		return Curve[0] * pow(readVout(), Curve[1]);
	}

#endif
