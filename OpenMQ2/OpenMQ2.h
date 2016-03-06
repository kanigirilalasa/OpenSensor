#ifndef OPENMQ2_h
#define OPENMQ2_h

#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

#include <OpenSensor.h>

#define RSRO_CLEAN_AIR_FACTOR        9.83                                  //define the value of Rs/Ro in clean air. According chart in datasheet.
#define RL_VALUE                     5                                     //define the value of the load resistance on the board, in kilo ohms.
#define GET_RO_SAMPLE_TIMES          10                                    //define how many times of calibrating to calculate Ro.
#define GET_RS_SAMPLE_TIMES          10                                    //define how many times of calibrating to calculate Rs.  

class OpenMQ2 : public OpenSensor{
	private:
		int _pin;
		float _Vcc;
		int _resolution;
		
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
	
		OpenMQ2(int pin);
		void begin(float Vcc, int resolution);
		float GetRo();
		float GetRs();
		
		float readLPG();
		float readCO();
		float readSmoke();
		float readPropane();
		float readH2();
		float readAlcohol();
		float readCH4();
};

#endif
