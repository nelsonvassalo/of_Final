#include "ofApp.h"

#define WORDS_SIZE 2
#define LABOR_X 869
#define LEISURE_X 1051

float widen = 0.0;
float laborWidth = 0.0;
float leisureWidth = 0.0;

int wh, ww, whMiddle, wwMiddle, textAlpha, _time;

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowShape(1920, 1080);
    ofBackground(0);
    ofEnableAlphaBlending();
    wh = ofGetWindowHeight();
    ww = ofGetWindowWidth();
    whMiddle = wh / 2;
    wwMiddle = ww / 2;
    textAlpha = 255;
    
    
    leisureFbo.allocate(LEISURE_X, wh);
    laborFbo.allocate(LABOR_X, wh);
    
    track.load("11.mp3");
    
    for (int i= 0; i < WORDS_SIZE; i++) {
        fonts[i].load("drukxcond.ttf", 200);
    }
    track.play();
    go4.load("g4.jpg");
    labor.load("labor.png");
    leisure.load("leisure.png");
//    track.setSpeed(0.1f);
//    mask.clear();
//    mask.begin();
//        fonts[0].drawString("LABOR", 20, ofGetWindowHeight() - 40);
//    mask.end();
    
    track.play();
    setSoundPos = 0;
    
//    labor.draw(0,0);
//    leisure.draw(0, 851);
    
    laborMask = new ofxAlphaMaskTexture(go4.getTexture(),
                                    laborFbo.getTexture(),
                                    labor.getTexture());
    
    leisureMask = new ofxAlphaMaskTexture(go4.getTexture(),leisureFbo.getTexture(),                                          leisureFbo.getTexture());
    
    
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    widen+= 0.01;
    
//    setSoundPos = 0.001;
    track.setSpeed(ofClamp(laborWidth, 1.0, 0.1));
    
    leisureWidth = LEISURE_X - laborWidth;
    
    
    _time = ofGetElapsedTimef();

}


//--------------------------------------------------------------
void ofApp::draw(){
    
//    mask.allocate(ofGetWindowWidth(), ofGetWindowHeight(), GL_LUMINANCE);
//    mask.clear();
//    mask.begin();
    
//    ofSetColor(0, 0, 0);
    
//    ofPushMatrix();
//    leisureFbo.clear();
//
//    leisureFbo.begin();
//    
//    ofDrawCircle(100, 500, 200);

//    go4.draw(0,0, ofGetWindowWidth(), ofGetWindowHeight());


//            ofScale(1.5 * laborWidth,1.0);
//    labor.draw(0,0, 869, ofGetWindowHeight());
//    leisure.draw(870, 0, 1051, ofGetWindowHeight());
//            fonts[0].drawString("LABOR", 20, ofGetWindowHeight() - 40);
    
//    leisureFbo.end();

//    ofPopMatrix();
    
//    leisureMask->draw(0,0);

//        mask.end();
//    ofPushMatrix();
//     fonts[1].drawString("LEISURE", ofGetWindowWidth()/2 + 20, ofGetWindowHeight() - 40);
//    ofPopMatrix();
//    go4.getTexture().setAlphaMask(mask.getTexture());
    if (_time < 10) {
        ofSetBackgroundColor(0,0,0,textAlpha);
        ofSetColor(255,255,255, textAlpha);
        fonts[0].drawString("HIT SPACEBAR TO GAIN TIME", 320, whMiddle + 50 );
        if (_time >= 3) {
            textAlpha -= 2;
            if (textAlpha <= 0) {
                ofClear(0);
            }
        }
    }
    
//    ofLogNotice(ofToString(_time));
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == ' ') {
        laborWidth -= 10.0;
    }

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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
