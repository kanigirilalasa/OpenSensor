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

#include <OpenMQ.h>

#define RL_VALUE                     5                                     //The value of the load resistance on the board, in kilo ohms.

class OpenMQ6: public OpenMQ{
	private:
		int _analogpin;
		
		float LPGCurve[2] = {1137.436966, -2.287352162};
		float CH4Curve[2] = {2289.351676, -2.477686812};
		
	public :
		OpenMQ6(int analogpin);
		
		float readLPG();
		
		float readCH4();

};

OpenMQ6::OpenMQ6(int analogpin): OpenMQ(analogpin){}

float OpenMQ6::readLPG(){
	return LPGCurve[0] * pow((GetRs()/Ro), LPGCurve[1]);
}

float OpenMQ6::readCH4(){
	return CH4Curve[0] * pow((GetRs()/Ro), CH4Curve[1]);
}

#endif
