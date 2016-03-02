#ifndef OPENMQ2_h
#define OPENMQ2_h

#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

class OpenMQ2{
	private:
		int _pin;
		
		#define RSRO_CLEAN_AIR_FACTOR        9.83                                  //The value of Rs/Ro in clean air. According chart in datasheet.
		#define RL_VALUE                     20                                     //The value of the load resistance on the board, in kilo ohms.
		#define GET_RO_SAMPLE_TIMES          10                                    //The times of calibrating 
		#define GET_RS_SAMPLE_TIMES          10
		
		float LPGCurve[2] = {612.4440432 , -2.085289323};                          // for MQ2
//		float LPGCurve[2] = {21.68519267 , -0.4794319535};                          // for MQ2
		float PropaneCurve[2] = {677.6031938, -2.104428615};                       // for MQ2
		float H2Curve[2] = {1006.236728, -2.079504157};                            // for MQ2
		float AlcoholCurve[2] = {3678.043993, -2.670473053};                       // for MQ2
		float CH4Curve[2] = {4434.153811, -2.623022788};                           // for MQ2
		float SmokeCurve[2] = {4052.338977, -2.273451061};                         // for MQ2
		float COCurve[2] = {32545.19524, -3.050192053};                            // for MQ2
		
		float MQ135CO2Curve[2] = {116.2737926, -2.737813368};                      // for MQ135
		float MQ135COCurve[2] = {782.8492416, -4.268032155};                       // for MQ135  
		float MQ135NH4Curve[2] = {109.1992962, -2.461721687};                      // for MQ135
		float SulfideCurve[2] = {80.95013972, -3.05514173};                        // for MQ135
		float MethaneCurve[2] = {47.98892735, -3.275556469};                        // for MQ135
		float BenzeneCurve[2] = {36.78019998, -3.291545675};                        // for MQ135
		
		float lpg = 0.0;                                                           // ppm of lpg for MQ2
		float co = 0.0;                                                            // ppm of co for MQ2
		float smoke = 0.0;														   // ppm of smoke for MQ2
		float propane = 0.0;                                                       // ppm of propane for MQ2
		float h2 = 0.0;                                                            // ppm of h2 for MQ2
		float alcohol = 0.0;                                                       // ppm of alcohol for MQ2
		float ch4 = 0.0;                                                           // ppm of ch4 for MQ2
		
		float mq135co2 = 0.0;                                                      // ppm of co2 for MQ135
		float mq135co = 0.0;                                                       // ppm of co for MQ135
		float mq135nh4 = 0.0;                                                      // ppm of nh4 for MQ135
		float sulfide = 0.0;                                                      // ppm of nh4 for MQ135
		float methane = 0.0;                                                      // ppm of nh4 for MQ135
		float benzene = 0.0;                                                      // ppm of nh4 for MQ135
		
		float Ro = 0;
		
		float MQResistanceCalculation(int raw_adc);
	public:	
		OpenMQ2(int pin);
		void begin();
		float GetRo();
		float GetRs();
		float ReadLPG();
		float ReadCO();
		float ReadSmoke();
		float ReadPropane();
		float ReadH2();
		float ReadAlcohol();
		float ReadCH4();
		
		float MQ135ReadCO2();
		float MQ135ReadCO();
		float MQ135ReadNH4();
		float readSulfide();
		float readMethane();
		float readBenzene();
};



#endif
