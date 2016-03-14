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
 * This is example for dust sensor GP2Y10. It measures the density of dust.
 * 
 * See it as the sample and know how to use OpenSensor. Then you can modify it to your code.
******************************************************************************************************/
#include <OpenGP2Y10.h>

#define analogpin   A4
#define ledpin      12

OpenGP2Y10 dust(analogpin, ledpin);  //OpenGP2Y10(analogpin, digitalpin): declare analog pin of sensor and digital pin for the led inside sensor.

void setup() {
  Serial.begin(9600);  //set up UART, baudrate = 9600bps.
  dust.begin(5, 10);   //begin(Vcc, resolution): declare Vcc and resolution value of sensor.
  //dust.begin();      //or this function if you want to use default value: default Vcc=5V, default resolution=10bit.
}

void loop() {
  Serial.print("Dust Density: ");
  Serial.print(dust.dustDensity());  //call function dustDensity().
  Serial.println("mg/m3");
  delay(1000);
}
