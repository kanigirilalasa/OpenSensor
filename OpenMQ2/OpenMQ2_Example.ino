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
 * This is example for gas sensor MQ2. It is suitable for detecting of LPG, CO, propane, methane(CH4) ,alcohol, Hydrogen, smoke.
 * 
 * See it as the sample and know how to use OpenSensor. Then you can modify it to your code.
******************************************************************************************************/

#include <OpenMQ2.h>

#define analogpin   A0

OpenMQ2 mq2(analogpin);  //OpenMQ2(analogpin): declare analog pin of sensor.

void setup() {
  Serial.begin(9600);        //set up UART, baudrate = 9600bps.
  mq2.begin(5, 10);   //begin(Vcc, resolution): declare Vcc and resolution value of sensor.
  //mq2.begin();      //or this function if you want to use default value: default Vcc=5V, default resolution=10bit.
}

void loop() {
  Serial.println("*********************< MQ2 >************************");
  Serial.println("Gas Sensor: ");
  
  Serial.print("LPG: ");
  Serial.print(mq2.readLPG());  //call function readLPG().
  Serial.print("ppm");
  Serial.print("    ");

  Serial.print("CO: ");
  Serial.print(mq2.readCO());  //call function readCO().
  Serial.print("ppm");
  Serial.print("    ");

  Serial.print("Smoke: ");
  Serial.print(mq2.readLPG());  //call function readLPG().
  Serial.print("ppm");
  Serial.print("    ");

  Serial.print("Propane: ");
  Serial.print(mq2.readPropane());  //call function readPropane().
  Serial.print("ppm");
  Serial.print("    ");

  Serial.print("H2: ");
  Serial.print(mq2.readH2());  //call function readH2().
  Serial.print("ppm");
  Serial.print("    ");

  Serial.print("Alcohol: ");
  Serial.print(mq2.readAlcohol());  //call function readAlcohol().
  Serial.print("ppm");
  Serial.print("    ");

  Serial.print("CH4: ");
  Serial.print(mq2.readCH4());  //call function readCH4().
  Serial.print("ppm");
  Serial.print("    ");

  Serial.println();
  
  delay(1000);

}
