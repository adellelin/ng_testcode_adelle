//
//  IArduino.cpp
//  NightGames
//
//  Created by Phoenix Perry on 18/10/14.
//
//

#include "IArduino.h"

// yo Adelle - send in ya port lady! :)
void IArduino::setup(string port){
    //ard.connect(port, 57600);
    ard.connect(port, 9600);
    ofAddListener(ard.EInitialized, this, &IArduino::setupArd);
}

void IArduino::update(){

    cout << ard.isArduinoReady() << " is the state of things";
}

void IArduino::setupArd(const int &version)
{
    ofRemoveListener(ard.EInitialized, this, &IArduino::setupArd);
    //this is the output on the arduino
    
    ard.sendDigitalPinMode(9, ARD_OUTPUT);
    
    //like say you'd want to send in data instead, do this.
    //ard.sendDigitalPinMode(9, ARD_INPUT);
    ard.sendAnalogPinReporting(0, ARD_INPUT);
    cout << "up" <<endl; 
}

void IArduino::testLed(){
    //be sending out power yo to an led on port 9 
    ard.sendDigital(9, ARD_HIGH);
    //and to receive data
    //auto num = ard.getDigital(9);
    auto num = ard.getAnalog(0);
    cout << num *1000 << endl;
}
