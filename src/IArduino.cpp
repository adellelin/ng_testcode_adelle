//
//  IArduino.cpp
//  NightGames
//
//  Created by Phoenix Perry on 18/10/14.
//
//

#include "IArduino.h"
#include <iostream>
using namespace std;


// yo Adelle - send in ya port lady! :)
void IArduino::setup(string port){
    serial.enumerateDevices();
    ard.connect("/dev/tty.usbmodem1421", 57600);
    ofAddListener(ard.EInitialized, this, &IArduino::setupArd);
    bSetupArduino	= false; // flag so we setup arduino when its ready, you don't need to touch this
    
    ofEnableSmoothing();
    
    
}



void IArduino::setupArd(const int &version)
{
    // remove listener because we don't need it anymore
    ofRemoveListener(ard.EInitialized, this, &IArduino::setupArd);
    
    // it is now safe to send commands to the Arduino
    bSetupArduino = true;
   
    
    //this is the output on the arduino
    // set pin D9 and D10 as digital output

    ard.sendDigitalPinMode(9, ARD_OUTPUT);
    ard.sendDigitalPinMode(10, ARD_OUTPUT);
    
    //like say you'd want to send in data instead, do this.
    ard.sendDigitalPinMode(3, ARD_INPUT);
    
    // set pin A0 to analog input
    ard.sendAnalogPinReporting(0, ARD_INPUT);
    //ard.sendAnalogPinReporting(4, ARD_OUTPUT);
    
    // if want to set pin D11 as PWM (analog output)
	ard.sendDigitalPinMode(11, ARD_PWM);
    
    // Listen for changes on the digital and analog pins
        //ofAddListener(ard.EDigitalPinChanged, this, &IArduino::digitalPinChanged);
        //ofAddListener(ard.EAnalogPinChanged, this, &IArduino::analogPinChanged);
    
    cout << "up" <<endl;
   
}


void IArduino::update(){
    
    cout << ard.isArduinoReady() << " is the state of things" << endl;
    
    auto sensorValue0 = ard.getAnalog(0);
    auto sensorValNew0 = (unsigned int)sensorValue0 >> 2;
    cout << sensorValNew0 << endl;
    ard.update();
}


void IArduino::testLed(){
    // Sending out power to an led on port 9
    ard.sendDigital(9, ARD_HIGH);


    //and to receive data
    //auto num = ard.getDigital(9);
    //cout << num << endl;
    ard.getAnalog(1);
//    int sensorValue0 = ard.getAnalog(0);
//    int sensorValNew0 = (unsigned int)sensorValue0 >> 3;
//    float sensorValue1 = ard.getAnalog(1);
//    cout << sensorValNew0 << sensorValue1 << endl;
    cout << "analog pin: " + ofToString(0) + " = " + ofToString(ard.getAnalog(0)) << endl;
    cout << "digital pin: " + ofToString(9) + " = " + ofToString(ard.getDigital(9)) << endl;
    
    ard.update();
}

void IArduino::testLedOff(){
    //be sending out power yo to an led on port 9

    ard.sendDigital(9, ARD_LOW);
    //ard.sendDigital(10, ARD_LOW);
    // fade the led connected to pin D11, can't get this to work yet
    ard.sendPwm(11, (int)(128 + 128 * sin(ofGetElapsedTimef())));   // pwm...
	
}


void IArduino::testLed1(){
    //be sending out power yo to an led on port 9
    ard.sendDigital(10, ARD_HIGH);
    
}

void IArduino::testLedOff1(){
    ard.sendDigital(10, ARD_LOW);
 
    
}