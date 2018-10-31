#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetVerticalSync(false);
    _realsense2.setupDevice(0);
    _realsense2.setupColor(848, 480, 30);
    //_realsense2.setupIR(640, 360, 30);
    _realsense2.setupDepth(848, 480, 30);
    _realsense2.startPipeline(true);
    
    syphon.setName("RealSyphon");
    
    _gui.setup("appSettings.xml");
    _gui.add(_realsense2.getGui());
}

//--------------------------------------------------------------
void ofApp::update(){
    _realsense2.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    
    if(_realsense2.colorEnabled())
        _realsense2.getColorTex()->draw(0, 0);
    
    //if(_realsense2.irEnabled())
        //_realsense2.getIrTex()->draw(640, 0);
    
    if(_realsense2.depthEnabled()) {
        //_realsense2.getRawDepthTex()->draw(0, 360);
        _realsense2.getDepthTex()->draw(0, 480);
    }
    
    ofDrawBitmapString(ofToString(ofGetFrameRate()), 10, 10);
    
    syphon.publishScreen();
    
    _gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

void ofApp::exit()
{
    _realsense2.exit();
}
