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
  lm35.begin(5, 10);   //begin(Vcc, resolution): declare Vcc and resolution value of sensor.
  //lm35.begin();      //or this function if you want to use default value: default Vcc=5V, default resolution=10bit.
}

void loop() {
  Serial.println("*********************< LM35 >************************");
  Serial.print("Temperature:    ");
  Serial.print("Celsius: ");
  Serial.print(lm35.readCelsius());  //call function readCelsius().
  Serial.print(" *C                ");
  Serial.print("Fahrenheit: ");
  Serial.print(lm35.readFahrenheit());  //call function readCelsius().
  Serial.println(" *F");
  delay(1000);

}
