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
 * This is example for temperature sensor LM35. It measures the temperature(in Celsius or Fahrenheit).
 * 
 * See it as the sample and know how to use OpenSensor. Then you can modify it to your code.
******************************************************************************************************/

#include <OpenLM35.h>

#define analogpin A0

OpenLM35 lm35(analogpin);  //OpenLM35(analogpin): declare analog pin of sensor.

void setup() {
  Serial.begin(9600);        //set up UART, baudrate = 9600bps.
  lm35.setup(5, 10);   //begin(Vcc, resolution): declare Vcc and resolution value of sensor.
  //lm35.setup();      //or this function if you want to use default value: default Vcc=5V, default resolution=10bit.

  // Getting info about sensor.
  Serial.println("*********************< LM35 >************************");
  Serial.print("Name: ");
  Serial.println(lm35.getSensor().name);
  Serial.print("Version: ");
  Serial.println(lm35.getSensor().version);
  Serial.print("Type: ");
  Serial.println(lm35.getSensor().type);
  Serial.print("Min value: ");
  Serial.println(lm35.getSensor().min_value);
  Serial.print("Max value: ");
  Serial.println(lm35.getSensor().max_value);
  Serial.print("Vcc: ");
  Serial.print(lm35.getSensor().Vcc);
  Serial.println("V");
  Serial.print("Resolution: ");
  Serial.print(lm35.getSensor().resolution);
  Serial.println("bit");
  Serial.println("******************************************************");
}

void loop() {
  Serial.print("Temperature:    ");
  Serial.print("Celsius: ");
  Serial.print(lm35.readCelsius());  //call function readCelsius().
  Serial.print(" *C                ");
  Serial.print("Fahrenheit: ");
  Serial.print(lm35.readFahrenheit());  //call function readCelsius().
  Serial.println(" *F");
  delay(1000);

}
