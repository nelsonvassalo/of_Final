#include "ofApp.h"

#define WORDS_SIZE 2
#define LABOR_X 869
#define LEISURE_X 1051

float widen = 0.0;
float laborWidth = 0.0;
float leisureWidth = LEISURE_X;
float leisureScale;
float laborScale;

int wh, ww, whMiddle, wwMiddle, textAlpha, _time;

//--------------------------------------------------------------
void ofApp::setup(){
//    ofSetWindowShape(1920, 1080);
    ofSetWindowShape(1920, 1080);
    ofBackground(0);
    ofEnableAlphaBlending();
    wh = ofGetWindowHeight();
    ww = ofGetWindowWidth();
    whMiddle = wh / 2;
    wwMiddle = ww / 2;
    textAlpha = 255;
    
    leisureFbo.allocate(ww, wh);
    laborFbo.allocate(ww, wh);
    
    
    track.load("11.mp3");
    
    for (int i= 0; i < WORDS_SIZE; i++) {
        fonts[i].load("drukxcond.ttf", 200);
    }
    track.play();
    go4.load("g4.jpg");
    office.load("office.jpg");
    labor.load("labor.png");
    leisure.load("leisure.png");
    white.load("white.png");
    
    
    
    
    
//    track.setSpeed(0.1f);
//    mask.clear();
//    mask.begin();
//        fonts[0].drawString("LABOR", 20, ofGetWindowHeight() - 40);
//    mask.end();
    
    

    
    track.play();
    setSoundPos = 0;
    
//    leisure.draw(0, 851);
    
    laborMask = new ofxAlphaMaskTexture(office.getTexture(),
                                    laborFbo.getTexture(),
                                    labor.getTexture());
    
    leisureMask = new ofxAlphaMaskTexture(go4.getTexture(),leisureFbo.getTexture(),                                          leisure.getTexture());
    
    
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    widen+= 0.01;
    
    laborWidth += 1.0;
    laborScale = ofMap(laborWidth, 1, LABOR_X, 0.01, 1.0);
    
//    setSoundPos = 0.001;
    
    leisureWidth = LEISURE_X - laborWidth;
    
    
    leisureScale = ofMap(leisureWidth, 1, LEISURE_X, 0.01, 1.0);
//    leisureScale = ofMap(
    track.setSpeed(ofClamp(ofMap(leisureWidth, 1.0, LEISURE_X, 0.1, 1.0), 0.1, 1.0));

    
    _time = ofGetElapsedTimef();
//    ofLogNotice(ofToString(leisureWidth,laborWidth));
}


//--------------------------------------------------------------
void ofApp::draw(){
    
    
    
    
//    mask.allocate(ofGetWindowWidth(), ofGetWindowHeight(), GL_LUMINANCE);
   
    
    
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
    ofClear(0);
    
    laborFbo.clear();
    laborFbo.begin();
    ofBackground(0);
    labor.draw(0, 0, ww, wh);
    laborFbo.end();
    ofClear(0);
    
        leisureFbo.clear();
        leisureFbo.begin();
            ofBackground(0);
            leisure.draw(LABOR_X,0, ww, wh);
        leisureFbo.end();
     ofClear(0);
    
    ofPushMatrix();
//        ofTranslate(500, 0);
        ofScale(ofClamp(leisureScale, 0.1, 2.44), 1.0);
//        ofTranslate(1920, 0);

        leisureMask->draw(500, 0);
    ofPopMatrix();
    
    
    ofPushMatrix();
        ofScale(ofClamp(laborScale, 0.1, 2.44), 1.0);
        laborMask->draw(0,0);
    ofPopMatrix();
    
    

   
   

    if (_time < 6) {
        ofClear(0);
        ofSetBackgroundColor(0,0,0,textAlpha);
        ofSetColor(255,255,255, textAlpha);
        fonts[0].drawString("HIT SPACEBAR TO GAIN FREE TIME", 220, whMiddle + 50 );
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
    

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if (key == ' ') {
        laborWidth -= 13.0;
    }

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
