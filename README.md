Hi guys! Welcome to the coding section of OttoBots!

This repo covers the code behind the ottobot, some possible errors that may occur when uploading code to the ottobot and how to modify the code to personalise your Otto!

The main files we will be using are calibration.ino and allmoves.ino. Calibration.ino contains the main setup and loop functions which we upload to the otto. allmoves.ino contains a plethora of otto functions that I demonstrate later.

# 1. Setting up the IDE 
Once you have downloaded the [Arduino IDE](https://www.arduino.cc/en/software), open the calibration.ino file.

Now go to library manager (Sketch > Include Library > Manage Libraries) and download **OttoDIYLib** by Otto DIY. Or you can click the library icon on the left of the window. To confirm that you have downloaded it, compile the sketch using the 'tick' icon on the top left of the IDE: [tick icon](initialise/Compile.png) The code should compile without any errors.

# 2. Uploading to the nano
Once you have completed step 1, connect the otto's Arduino nano to your computer and select the board. 

