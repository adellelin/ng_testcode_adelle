//
//  SceneFour.cpp
//  NightGames
//
//  Created by Adelle on 1/11/14.
//
//

#include "SceneFour.h"
using namespace std;


ofVec2f v2(200,400);
// v2.normalize;



    
SceneFour::SceneFour():Scene(){
        //Constructor
        osc = new IOSC();
        device = new IArduino();
     
    }

void SceneFour::setup(){
        osc->setup("192.168.178.15", 8000);
        device->setup("/dev/tty.usbmodem1421");
    }

void SceneFour::update(){
        device->update();
        osc->update();
    
    
}


void SceneFour::keyPressed(int key){
    
    }


void SceneFour::keyReleased(int key){
    
}


void SceneFour::draw(){
    ofCircle(xpos, ypos, 20);
    ofLine(0, 0, 200, 400);
  
    
}
void SceneFour::drag(int x, int y){
    xpos = x;
    ypos = y;
    ofVec2f v1(x,y);
   // v1.normalize;
   
    cout << v1.dot(v2)<< endl;
}


    // check
    
    SceneFour::~SceneFour(){}
        
