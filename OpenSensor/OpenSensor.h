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
 *****************************************************************************************************/
#ifndef OPENSENSOR_H
#define OPENSENSOR_H

#if ARDUINO >= 100
	#include <arduino.h>
#else 
	#include <WProgram.h>
#endif

#define READ_N_TIMES         (5)                                           //define how many times that you read analog from sensor.
#define DEFAULT_VCC          (5)										   // define default Vcc value = 5V.
#define DEFAULT_RESOLUTION   (10)										   // define default Resolution = 10bit.

/************************ Sensor Info **********************************
** This is used to describe basic information about a specific sensor.** 
***********************************************************************/
typedef struct
	{
	    char     name[12];                        // name of the sensor.
	    int8_t  version;                         // version of library for specific sensor.
	//    int32_t  type;                            // type of the sensor, choose one of SensorType above.
		char*  type;                            // type of the sensor, choose one of SensorType above.
	    float    min_value;                       // minumum value of this sensor's value.
	    float    max_value;                       // maximum value of this sensor's value.
		int analogpin;
		int digitalpin;
		float Vcc;
		int resolution;
	} SensorInfo;

class OpenSensor {
	private:
		int _analogpin = -1;                                                          
		int _digitalpin = -1;
		
		float _Vcc;                                                     //the value of supplying voltage for sensor. Ex: 5V, 3.3V, etc.
		int _resolution;                                               //determines the resolution (in bits) of the value returned by analogRead().Ex: 10bit, 11bit, etc. 
		
	public:
		
		/************************ Sensor Type *********************************
		**********************************************************************/
		typedef enum
			{
			  SENSOR_TYPE_TEMPERATURE           = (1),
			  SENSOR_TYPE_LIGHT                 = (2),
			  SENSOR_TYPE_GAS                   = (3),
			  SENSOR_TYPE_DUST                  = (4),
			  SENSOR_TYPE_GYROSCOPE             = (5),
			  SENSOR_TYPE_PRESSURE              = (6),
			  SENSOR_TYPE_PROXIMITY             = (7),
			  SENSOR_TYPE_GRAVITY               = (8),
			  SENSOR_TYPE_ROTATION_VECTOR       = (9),
			  SENSOR_TYPE_HUMIDITY              = (10),
			  SENSOR_TYPE_COLOR                 = (11)
			} SensorType;
		
		OpenSensor();
		
		OpenSensor(int analogpin);
		
		OpenSensor(int analogpin, int digitalpin);
		
		/************************************ setup ****************************************
		Input: None. It use DEFAULT_VCC and DEFAULT_RESOLUTION value.
		Output: void
		Remarks: You must only call it one times in setup() function. It declare Vcc and resolution. 
				This is a virtual function. You can redefine it in derived class. 
		************************************************************************************/
		virtual void setup(){
			_Vcc = DEFAULT_VCC;
			_resolution = DEFAULT_RESOLUTION;
		}
		
		/************************************ setup ****************************************
		Input: Vcc - the value of supplying voltage for sensor. Ex: 5V, 3.3V, etc.
		        resolution - determines the resolution (in bits) of the value returned by analogRead() function.Ex: 10bit, 11bit, etc.
		Output: void
		Remarks: You must only call it one times in setup() function. It declare Vcc and resolution. 
				This is a virtual function. You can redefine it in derived class. 
		************************************************************************************/
		virtual void setup(float Vcc, int resolution){
			_Vcc = Vcc;
			_resolution = resolution;
		}
		
		void setAnalogpin(int analogpin);
		
		void setDigitalpin(int digitalpin);
		
		void setVcc(float Vcc);
		
		void setResolution(int resolution);
		
		int getAnalogpin();
		
		int getDigitalpin();
		
		float getVcc();
		
		int getResolution();
		
		int readAnalog();                                               // read adc 1 times.
		
		float readAnalogTimes();                                        // read adc n times with n = READ_N_TIMES, is defined in header.
		
		float readAnalogTimes(int num_times);                           // read adc n times. n is a parameter.
		
		float VoltageCalculation(int raw_adc);                          // map the raw adc into voltage.
		
		float readVout();                                               // read out put voltage of sensor.
		
		int readDigital();                                              // read value of digital pin.
		
		virtual SensorInfo getSensor() = 0;
		
		char* getTypeName(SensorType type);
};

#endif
