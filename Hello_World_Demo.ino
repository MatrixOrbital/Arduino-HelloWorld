//A simple "HELLO WORLD" I2C example with an Arduino Uno
//For a 20+ character wide display
//
//By Matrix Orbital
//
//WEB
//https://www.matrixorbital.com
//SUPPORT
//https://www.lcdforums.com/forums/viewforum.php?f=1
//
//-------------------------------------------------------------
//For an Arduino UNO to Display:
//Connect PIN 5V to PIN 1 VIN
//Connect PIN 4 to PIN 2 SCL
//Connect PIN 5 to PIN 3 SDA 
//Connect PIN GND to PIN4 GND
//
//On power up, you should see "Matrix Orbital" on the display

//--------------------------------------------------------------

#include <Wire.h> //This library allows you to communicate with I2C devices

//global variables
byte ASCII_value = 0x30; //Going to start with a value of ASCII 0
byte I2C_Display = 0x28; //Display default I2C address in 7 bits

//run once
void setup(){ 
  
  //***Arduino Configuration***
  Wire.begin(); //Setup I2C in the Arduino

  //***Begin Program***

  //Clear the screen on the display
  Wire.beginTransmission(I2C_Display); // I2C transmit to device to address 0x28
  Wire.write(254); //Display command prefix
  Wire.write("X"); //Clear screen Command    
  Wire.endTransmission();    // stop transmitting  

  //Write Hello Word to the screen
  Wire.beginTransmission(I2C_Display); // I2C transmit to device to address 0x28
  Wire.write("Hello World! ASCII:"); //Text to send to display
  Wire.endTransmission();    // stop transmitting  

}

//Main loop
void loop(){  

  //Set Cursor Position to Column 20, Row 1
  Wire.beginTransmission(I2C_Display); // I2C transmit to device to address 0x28
  Wire.write(254); //Display command prefix
  Wire.write("G"); //Clear Set Cursor Position Command  
  Wire.write(20); //Column 20
  Wire.write(1); //Row 1
  Wire.endTransmission();    // stop transmitting 

  //Write to screen
  Wire.beginTransmission(I2C_Display); // I2C transmit to device to address 0x28
  Wire.write(ASCII_value); //Write value to display
  Wire.endTransmission();    // stop transmitting 

  delay (750); //delay 750ms
  
  ASCII_value++;
}
