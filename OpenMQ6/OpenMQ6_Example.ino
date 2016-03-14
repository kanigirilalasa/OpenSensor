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
 * This is example for gas sensor MQ6. It is suitable for detecting of LPG, LNG(it is composed mainly of methane-CH4).
 * 
 * See it as the sample and know how to use OpenSensor. Then you can modify it to your code.
******************************************************************************************************/

#include <OpenMQ6.h>

#define analogpin   A0

OpenMQ6 mq6(analogpin);  //OpenMQ6(analogpin): declare analog pin of sensor.

void setup() {
  Serial.begin(9600);        //set up UART, baudrate = 9600bps.
  mq6.begin(5, 10);   //begin(Vcc, resolution): declare Vcc and resolution value of sensor.
  //mq6.begin();      //or this function if you want to use default value: default Vcc=5V, default resolution=10bit.
}

void loop() {
  Serial.println("*********************< MQ6 >************************");
  Serial.println("Gas Sensor: ");

  Serial.print("Benzene: ");
  Serial.print(mq6.readLPG());  //call function readLPG().
  Serial.print("ppm");
  Serial.print("    ");
  
  Serial.print("Methane: ");
  Serial.print(mq6.readCH4());  //call function readCH4().
  Serial.print("ppm");
  Serial.print("    ");
  
  Serial.println();
  
  delay(1000);

}
