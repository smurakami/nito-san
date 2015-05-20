#pragma once

#include "ofMain.h"
#include "ofxCvHaarFinder.h"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    ofImage hair;
    ofImage image;
    ofxCvHaarFinder finder;
    ofVideoGrabber camera;
    
    float scale = 1.34785;
    float xpos = 1;
    float ypos = -63;
    
    void printStatus() {
        std::cout << "scale: " << scale << ", xpos: " << xpos << ", ypos: " << ypos << std::endl;
    }

};
