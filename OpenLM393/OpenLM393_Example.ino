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
 * This is example for light sensor LM393. It measures the level of the light.
 * 
 * See it as the sample and know how to use OpenSensor. Then you can modify it to your code.
******************************************************************************************************/

#include <OpenLM393.h>

#define analogpin   A0
#define digitalpin  2

OpenLM393 lm393(analogpin, digitalpin);  //OpenLM393(analogpin): declare analog pin of sensor.

void setup() {
  Serial.begin(9600);        //set up UART, baudrate = 9600bps.
  lm393.setup(5, 10);   //begin(Vcc, resolution): declare Vcc and resolution value of sensor.
  //lm393.setup();      //or this function if you want to use default value: default Vcc=5V, default resolution=10bit.
  
  // Getting info about sensor.
  Serial.println("*********************< LM393 >************************");
  Serial.print("Name: ");
  Serial.println(lm393.getSensor().name);
  Serial.print("Version: ");
  Serial.println(lm393.getSensor().version);
  Serial.print("Type: ");
  Serial.println(lm393.getSensor().type);
  Serial.print("Min value: ");
  Serial.println(lm393.getSensor().min_value);
  Serial.print("Max value: ");
  Serial.println(lm393.getSensor().max_value);
  Serial.print("Vcc: ");
  Serial.print(lm393.getSensor().Vcc);
  Serial.println("V");
  Serial.print("Resolution: ");
  Serial.print(lm393.getSensor().resolution);
  Serial.println("bit");
  Serial.println("******************************************************");
}

void loop() {
  Serial.print("Light Level: ");
  Serial.println(lm393.readLightLevel());  //call function dustDensity().
  
  delay(1000);

}
