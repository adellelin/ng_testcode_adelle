#include "ofApp.h"

float circleX[3];
float circleY[3];
float circRadius[3];

#define NUM_CIRCLES 500 //don't put a ; after this

float circle2X[NUM_CIRCLES];
float circle2Y[NUM_CIRCLES];
float circleRad[NUM_CIRCLES];

int circleR[NUM_CIRCLES];
int circleG[NUM_CIRCLES];
int circleB[NUM_CIRCLES];

//--------------------------------------------------------------
void ofApp::setup(){
    // setting up the values of each circle
    ofSetFrameRate(24);
    
    int i;
    for (i=0; i < 3; i++) {
        circleX[i] = ofRandom(-1, ofGetWidth());
        circleY[i] = ofRandom(-1, ofGetHeight());
        circRadius[i] = ofRandom (10, 40);
    }

    for (i=0; i < NUM_CIRCLES; i++) {
        circle2X[i] = ofRandom(0, ofGetWidth());
        circle2Y[i] = ofRandom(0, ofGetHeight());
        circleRad[i] = ofRandom(0, 50);
        circleR[i] = ofRandom(0, 255);
        circleG[i] = ofRandom(0, 255);
        circleB[i] = ofRandom(0, 255);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
   // constantly changing the position of the circle in each round by adding small increments continuously to the initial value, as the range is always less than 3 it will keep changing.
    for(int i=0; i<3; i++)
    {
        circleX[i] += ofRandom(-1,1);
        circleY[i] += ofRandom(-1,1);
    }
    for(int i = 0; i < NUM_CIRCLES; i++ ) {
        circle2X[i] += ofRandom(-10,10);
        circle2Y[i] += ofRandom(-10,10);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    // drawing each of the 3 circles
    for(int i=0; i<3; i++)
    {
        ofCircle(circleX[i], circleY[i], circRadius[i]);
    }
    for (int i = 0; i < NUM_CIRCLES; i++) {
        ofSetColor(circleR[i], circleG[i], circleB[i]);
        ofCircle(circle2X[i], circle2Y[i], circleRad[i]);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
