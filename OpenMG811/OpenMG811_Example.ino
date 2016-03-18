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
 * This is example for CO2 sensor MG811. It measures the ppm of CO2 in the air.
 * 
 * See it as the sample and know how to use OpenSensor. Then you can modify it to your code.
******************************************************************************************************/

#include <OpenMG811.h>

#define analogpin   A0

OpenMG811 mg811(analogpin);  //OpenMG811(analogpin): declare analog pin of sensor.

void setup() {
  Serial.begin(9600);        //set up UART, baudrate = 9600bps.
  mg811.setup(5, 10);   //begin(Vcc, resolution): declare Vcc and resolution value of sensor.
  //mg811.setup();      //or this function if you want to use default value: default Vcc=5V, default resolution=10bit.

  // Getting info about sensor.
  Serial.println("*********************< MG811 >************************");
  Serial.print("Name: ");
  Serial.println(mg811.getSensor().name);
  Serial.print("Version: ");
  Serial.println(mg811.getSensor().version);
  Serial.print("Type: ");
  Serial.println(mg811.getSensor().type);
  Serial.print("Min value: ");
  Serial.println(mg811.getSensor().min_value);
  Serial.print("Max value: ");
  Serial.println(mg811.getSensor().max_value);
  Serial.print("Vcc: ");
  Serial.print(mg811.getSensor().Vcc);
  Serial.println("V");
  Serial.print("Resolution: ");
  Serial.print(mg811.getSensor().resolution);
  Serial.println("bit");
  Serial.println("******************************************************");
}

void loop() {
  Serial.println("*********************< MG811 >************************");
  Serial.print("CO2: ");
  Serial.print(mg811.readCO2());  //call function readCO2().
  Serial.println(" ppm");
  delay(1000);
}
