#ifndef OPENGAS_H
#define OPENGAS_H

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

class OpenGas: public OpenSensor{
	private:
		int _analogpin;			
		
	protected:	
		float Ro = 0;
		
		float MQResistanceCalculation(int raw_adc);
		
	public:
		OpenGas(int analogpin);
		
		/************************************ begin ****************************************
		Input: None. It use DEFAULT_VCC and DEFAULT_RESOLUTION value. Both are defined on OpenSensor class.
		Output: void
		Remarks: You must only call it one times in setup() function. It use to declare Vcc, resolution value and calculate the Ro value. 
		************************************************************************************/
		virtual void begin(){
			_Vcc = DEFAULT_VCC;
			_resolution = DEFAULT_RESOLUTION;
			
			Ro = GetRo();
			
			Serial.print("Calibrating...\n");                       //Calibrating the sensor. Please make sure the sensor is in clean air 
			                                                        //when you perform the calibration                    
			Serial.print("Calibration is done...\n"); 
			Serial.print("Ro=");
		    Serial.print(Ro);
			Serial.print("kohm");
			Serial.print("\n");
		}
		
		/************************************ begin ****************************************
		Input: Vcc - the value of supplying voltage for sensor. Ex: 5V, 3.3V, etc.
		        resolution - determines the resolution (in bits) of the value returned by analogRead() function.Ex: 10bit, 11bit, etc.
		Output: void
		Remarks: You must only call it one times in setup() function. It use to declare Vcc, resolution value and calculate the Ro value. 
		************************************************************************************/
		virtual void begin(float Vcc, int resolution){
			_Vcc = Vcc;
			_resolution = resolution;
			
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
