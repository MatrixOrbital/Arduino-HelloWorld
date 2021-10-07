# Arduino-HelloWorld
A very quick Hello World demo with an ASCII counter on an Arduino

This is a very fast simple example getting an Arduino Uno displaying on a Matrix Orbital I2C Display. 

<img src=WireDiagram.png></img>

Connect an Arduino UNO to a Matrix Orbital I2C Display:
1. Connect PIN 5V to PIN 1 VIN
2. Connect PIN 4 to PIN 2 SCL
3. Connect PIN 5 to PIN 3 SDA 
4. Connect PIN GND to PIN 4 GND

On power up, you should see "Matrix Orbital" on the display


The blocks for this program are:
1.	Arduino Configuration
2.	Display Configuration
3.	Start of the program
4.	Main Loop of the program

What you fill see on the screen on start

Line 1: Hello World!

Line 2: The ASCII/FONT table of the display starting at 0x30 which is ASCII “0” to 0xFC

<img src=Arduino-HelloWorld-800.jpg></img>

WEB https://www.matrixorbital.com

SUPPORT https://www.lcdforums.com/forums/viewforum.php?f=1
