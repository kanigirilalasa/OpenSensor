#ifndef OPENMQ135_h
#define OPENMQ135_h

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
		
class OpenMQ135: public OpenSensor{
	private:
		int _pin;	
		float _Vcc;
		int _resolution;
		
		float CO2Curve[2] = {116.2737926, -2.737813368};                      // for MQ135
		float COCurve[2] = {782.8492416, -4.268032155};                       // for MQ135  
		float NH4Curve[2] = {109.1992962, -2.461721687};                      // for MQ135
		float SulfideCurve[2] = {80.95013972, -3.05514173};                        // for MQ135
		float MethaneCurve[2] = {47.98892735, -3.275556469};                        // for MQ135
		float BenzeneCurve[2] = {36.78019998, -3.291545675};                        // for MQ135
		
		float co2 = 0.0;                                                      // ppm of co2 for MQ135
		float co = 0.0;                                                       // ppm of co for MQ135
		float nh4 = 0.0;                                                      // ppm of nh4 for MQ135
		float sulfide = 0.0;                                                      // ppm of nh4 for MQ135
		float methane = 0.0;                                                      // ppm of nh4 for MQ135
		float benzene = 0.0;                                                      // ppm of nh4 for MQ135
		
		float Ro = 0;
		
		float MQResistanceCalculation(int raw_adc);
	
	public:
		OpenMQ135(int pin);
		
		void begin(float Vcc, int resolution);
		float GetRo();
		float GetRs();
		
		float readCO2();
		float readCO();
		float readNH4();
		float readSulfide();
		float readMethane();
		float readBenzene();
};

#endif
