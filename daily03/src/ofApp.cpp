#include "ofApp.h"
#include <iostream>

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFullscreen(true);
    ofSetBackgroundColor(21);
    randomSeed=0;
    rectSizeX=ofGetWidth()/tileCount;
    rectSizeY=ofGetHeight()/tileCount;
    noiseX=0;
    noiseY=1000;
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    randomNoise=0;
}

//--------------------------------------------------------------
void ofApp::update(){
    walkX=ofMap(ofNoise(noiseX),0,1,0,ofGetWidth());
    walkY=ofMap(ofNoise(noiseY), 0, 1, 0, ofGetHeight());
    noiseX+=0.1;
    noiseY+=0.1;
    randomNoise+=0.01;
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    cam.begin();
    
    ofSeedRandom(randomSeed);
    
    //gene grid
    for(int gridY=0;gridY<tileCount;gridY++){
        for(int gridX=0;gridX<tileCount;gridX++){
            
            float posX=gridX*rectSizeX;
            float posY=gridY*rectSizeY;
            //std::cout<<posX<<std::endl;
            
            float dNoise1=ofMap(ofNoise(randomNoise), 0, 1, -3, 3);
            float dNoise2=ofMap(ofNoise(randomNoise+10), 0, 1, -3, 3);
            float dNoise3=ofMap(ofNoise(randomNoise+20), 0, 1, -3, 3);
            float dNoise4=ofMap(ofNoise(randomNoise+30), 0, 1, -3, 3);
            float dNoise5=ofMap(ofNoise(randomNoise+40), 0, 1, -3, 3);
            float dNoise6=ofMap(ofNoise(randomNoise+50), 0, 1, -3, 3);
            float dNoise7=ofMap(ofNoise(randomNoise+60), 0, 1, -3, 3);
            float dNoise8=ofMap(ofNoise(randomNoise+70), 0, 1, -3, 3);

            
            float shiftX1=walkX/rectSizeX*dNoise1;
            float shiftY1=walkY/rectSizeY*dNoise2;
            float shiftX2=walkX/rectSizeX*dNoise3;
            float shiftY2=walkY/rectSizeY*dNoise4;
            float shiftX3=walkX/rectSizeX*dNoise5;
            float shiftY3=walkY/rectSizeY*dNoise6;
            float shiftX4=walkX/rectSizeX*dNoise7;
            float shiftY4=walkY/rectSizeY*dNoise8;
            
            //std::cout<<posX+shiftX1<<std::endl;
            
            c.setHsb(ofRandom(140,180),255*0.8,255*0.8,255);

            
            ofPushMatrix();
            ofTranslate(-ofGetWidth()/2, -ofGetHeight()/2);
            ofBeginShape();
            ofSetColor(c);
            ofVertex(posX+shiftX1, posY+shiftY1);
            ofVertex(posX+shiftX2+rectSizeX, posY+shiftY2);
            ofVertex(posX+shiftX3+rectSizeX, posY+shiftY3+rectSizeY);
            ofVertex(posX+shiftX4, posY+shiftY4+rectSizeY);
            ofVertex(posX+shiftX1, posY+shiftY1);
            ofEndShape();
            ofPopMatrix();
            
        }
    }
    
    
    cam.end();
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
