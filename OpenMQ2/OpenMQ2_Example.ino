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
  mq2.setup(5, 10);   //begin(Vcc, resolution): declare Vcc and resolution value of sensor.
  //mq2.setup();      //or this function if you want to use default value: default Vcc=5V, default resolution=10bit.

// Getting info about sensor.
  Serial.println("*********************< OpenMQ2 >************************");
  Serial.print("Name: ");
  Serial.println(mq2.getSensor().name);
  Serial.print("Version: ");
  Serial.println(mq2.getSensor().version);
  Serial.print("Type: ");
  Serial.println(mq2.getSensor().type);
  Serial.print("Min value: ");
  Serial.println(mq2.getSensor().min_value);
  Serial.print("Max value: ");
  Serial.println(mq2.getSensor().max_value);
  Serial.print("Vcc: ");
  Serial.print(mq2.getSensor().Vcc);
  Serial.println("V");
  Serial.print("Resolution: ");
  Serial.print(mq2.getSensor().resolution);
  Serial.println("bit");
  Serial.println("******************************************************");
}

void loop() {
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
