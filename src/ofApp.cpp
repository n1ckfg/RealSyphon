#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    ofSetVerticalSync(true);
    realsense.setupDevice(0);
    realsense.setupColor(848, 480, 30);
    //realsense.setupIR(640, 360, 30);
    realsense.setupDepth(848, 480, 30);
    realsense.startPipeline(true);
    
    syphon.setName("RealSyphon");
    
    gui.setup("appSettings.xml");
    gui.add(realsense.getGui());
}

//--------------------------------------------------------------
void ofApp::update() {
    realsense.update();
}

//--------------------------------------------------------------
void ofApp::draw() {
    ofBackground(0);
    
    //if (realsense.irEnabled()) realsense.getIrTex()->draw(640, 0);
    
    if (realsense.depthEnabled()) {
        //realsense.getRawDepthTex()->draw(0, 360);
        realsense.getDepthTex()->draw(0,480);
    }

    if (realsense.colorEnabled()) realsense.getColorTex()->draw(0, 0);
    
    ofDrawBitmapString(ofToString(ofGetFrameRate()), 10, 10);
    
    syphon.publishScreen();
    
    gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
    //
}

void ofApp::exit() {
    realsense.exit();
}
