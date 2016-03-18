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
 * This is example for air quality sensor MQ135. It is suitable for detecting of NH3, CO, CO2, Benzene, Sunfide, Methane.
 * 
 * See it as the sample and know how to use OpenSensor. Then you can modify it to your code.
******************************************************************************************************/

#include <OpenMQ135.h>

#define analogpin   A0

OpenMQ135 mq135(analogpin);  //OpenMQ135(analogpin): declare analog pin of sensor.

void setup() {
  Serial.begin(9600);        //set up UART, baudrate = 9600bps.
  mq135.setup(5, 10);   //begin(Vcc, resolution): declare Vcc and resolution value of sensor.
  //mq135.setup();      //or this function if you want to use default value: default Vcc=5V, default resolution=10bit.

  // Getting info about sensor.
  Serial.println("*********************< Openmq135 >************************");
  Serial.print("Name: ");
  Serial.println(mq135.getSensor().name);
  Serial.print("Version: ");
  Serial.println(mq135.getSensor().version);
  Serial.print("Type: ");
  Serial.println(mq135.getSensor().type);
  Serial.print("Min value: ");
  Serial.println(mq135.getSensor().min_value);
  Serial.print("Max value: ");
  Serial.println(mq135.getSensor().max_value);
  Serial.print("Vcc: ");
  Serial.print(mq135.getSensor().Vcc);
  Serial.println("V");
  Serial.print("Resolution: ");
  Serial.print(mq135.getSensor().resolution);
  Serial.println("bit");
  Serial.println("******************************************************");
}

void loop() {
  Serial.println("*********************< OpenMQ135 >************************");
  Serial.println("Air quality Sensor: ");
  
  Serial.print("CO2: ");
  Serial.print(mq135.readCO2());  //call function readCO2().
  Serial.print("ppm");
  Serial.print("    ");

  Serial.print("CO: ");
  Serial.print(mq135.readCO());  //call function readCO().
  Serial.print("ppm");
  Serial.print("    ");

  Serial.print("NH4: ");
  Serial.print(mq135.readNH4());  //call function readNH4().
  Serial.print("ppm");
  Serial.print("    ");

  Serial.print("Sulfide: ");
  Serial.print(mq135.readSulfide());  //call function readSulfide().
  Serial.print("ppm");
  Serial.print("    ");

  Serial.print("Methane: ");
  Serial.print(mq135.readMethane());  //call function readMethane().
  Serial.print("ppm");
  Serial.print("    ");

  Serial.print("Benzene: ");
  Serial.print(mq135.readBenzene());  //call function readBenzene().
  Serial.print("ppm");
  Serial.print("    ");

  Serial.println();
  
  delay(1000);

}
