# OpenSensor

 * OpenSensor is a open source library for many sensor of arduino.
 * This is a simple library to use with sensor in arduino.
 *
 * @Created by Tran Tri Tan (<tantt2810@gmail.com>).
 * @Intructor: Truong Minh Thai (<tmthai@cit.ctu.edu.vn>).
 * @Copyright (C) 2016.
 *
 * Full sources: https://github.com/tantt2810/Opensensor

<h1>Download and Install</h1>
To intall the library to use it with the Arduino IDE, download it as zip and unzip it into your 'libraries' folder and restart the Arduino IDE.
<h1>Usage</h1>
<p>To use OpenSensor library, you just only simply do some step:</p>
<p>Step 1: Include the library of your sensor. Ex: #include "OpenLM35.h"</p>
Step 2: Declare your sensor'pin that connect to Arduino by initializing an instant. Ex: OpenLM35 lm35(A0)
Step 3: Setup the voltage and resolution that supply for your sensor by one of these function below:
- setup(float voltage, int resolution): setup voltage and resolution suply for sensor.
- setup(): setup voltage with 5V and resolution with 10bit. If you have diffent voltage or resolution, you can use setup(float voltage, int resolution). Ex: lm35.setup(5, 10) or lm35.setup();
Step 4: Use some function in each sensor to reading its value.
