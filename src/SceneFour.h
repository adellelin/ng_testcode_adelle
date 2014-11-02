//
//  SceneFour.h
//  NightGames
//
//  Created by Adelle on 1/11/14.
//
//

#ifndef __NightGames__SceneFour__
#define __NightGames__SceneFour__

#include <iostream>

#include <stdio.h>
#include "ofmain.h"
#include "Scene.h"


class SceneFour:public Scene{
public:
    void setup();
    void draw();
    void update();
    void drag(int x, int y);
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    IOSC *osc;
    IArduino *device;
    
    int xpos;
    int ypos;
    int myCircleX;
    int myCircleY;
    int myCircleRadius;
    int colorVal;
    
    
    SceneFour();
    ~SceneFour();
};

#endif /* defined(__NightGames__SceneFour__) */
