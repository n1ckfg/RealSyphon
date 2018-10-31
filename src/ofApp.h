#pragma once

#include "ofMain.h"
#include "ofxLibRealSense2.hpp"
#include "ofxSyphon.h"

class ofApp : public ofBaseApp{

    public:
        void setup();
        void update();
        void draw();
        void exit();
        void keyPressed(int key);
    
        ofxLibRealSense2 realsense;
        ofxPanel gui;
    
        ofTexture tex;
        ofxSyphonServer syphon;

};
