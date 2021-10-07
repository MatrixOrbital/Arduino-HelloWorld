//A simple "HELLO WORLD" I2C example with an Arduino Uno with the ASCII Table printed
//
//By Matrix Orbital
//
//WEB
//https://www.matrixorbital.com
//SUPPORT
//https://www.lcdforums.com/forums/viewforum.php?f=1
//
//-------------------------------------------------------------
//Connect an Arduino UNO to a Matrix Orbital I2C Display:
//Connect PIN 5V to PIN 1 VIN
//Connect PIN 4 to PIN 2 SCL
//Connect PIN 5 to PIN 3 SDA 
//Connect PIN GND to PIN 4 GND
//
//On power up, you should see "Matrix Orbital" on the display
//--------------------------------------------------------------

#include <Wire.h> //This library allows you to communicate with I2C devices

//global variables
byte ASCII_value = 0x30; //Going to start with a value number 0
byte I2C_Display = 0x28; //Display default I2C address in 7 bits

//run once
void setup(){ 
  
  //Arduino Configuration
  Wire.begin(); //Setup I2C in the Arduino

  //Begin Program, clear the screen and say Hello!

  //Clear the screen on the display
  Wire.beginTransmission(I2C_Display); // I2C transmit to device to address 0x28
  Wire.write(254); //Display command prefix
  Wire.write("X"); //Clear screen command    
  Wire.endTransmission();    //Stop transmitting  

  //Write "Hello World" to the screen
  Wire.beginTransmission(I2C_Display); // I2C transmit to device to address 0x28
  Wire.write("Hello World!"); //Text to send to display
  Wire.endTransmission();    //Stop transmitting  

}

//Main loop
void loop(){  

  //Here we will display the ASCII Table in Column 1 and Row 2, from 0x30 to 0xFC

  //Set Cursor Position to Column 1, Row 2
  Wire.beginTransmission(I2C_Display); // I2C transmit to device to address 0x28
  Wire.write(254); //Display command prefix
  Wire.write("G"); //Set cursor position command  
  Wire.write(1); //Column 1
  Wire.write(2); //Row 2
  Wire.endTransmission();    //Stop transmitting 

  //Write to screen
  Wire.beginTransmission(I2C_Display); // I2C transmit to device to address 0x28
  Wire.write(ASCII_value); //Write value to display
  Wire.endTransmission();    //Stop transmitting 

  delay (400); //delay 400ms
  
  ASCII_value++;
  
  if (ASCII_value == 0xFE) ASCII_value = 0x30;  //We CANNOT send ASCII HEX FE or DEC 254 to the display because it is the Command Prefix,
                                                //putting the display into Command Mode, so we set the Variable back to 0x30
}
