#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
//    ofSetWindowShape(320, 240);
    ofSetFrameRate(60);
    
    // init camera
    camera.setDeviceID(0);
    camera.initGrabber(320, 240);
    image.allocate(camera.getWidth(), camera.getHeight(), OF_IMAGE_COLOR);
    
    ofSetWindowShape(camera.getWidth(), camera.getHeight());
    
    // init face detector
//	image.loadImage("test.jpg");
    hair.loadImage("nito.png");
	finder.setup("haarcascade_frontalface_default.xml");
	finder.findHaarObjects(image);
}

//--------------------------------------------------------------
void ofApp::update(){
    camera.update();
    
    // copy image from camera
    unsigned char * cdata = camera.getPixels();
    unsigned char * idata = image.getPixels();
    for (int i = 0; i < camera.getWidth() * camera.getHeight() * 3; i++) {
        idata[i] = cdata[i];
    }
    
    image.update();
    
    finder.findHaarObjects(image);
}

//--------------------------------------------------------------
void ofApp::draw(){
    image.draw(0, 0, ofGetWidth(), ofGetHeight());
	ofNoFill();
	for(unsigned int i = 0; i < finder.blobs.size(); i++) {
		ofRectangle cur = finder.blobs[i].boundingRect;
//		ofRect(cur.x, cur.y, cur.width, cur.height);
        
        ofPoint center(cur.x + cur.width/2, cur.y + cur.height/2);
        
        float width = cur.width * scale;
        float height = cur.height * scale;
        
        center.x += xpos;
        center.y += ypos;
        
        hair.draw(center.x - width/2, center.y - height/2, width, height);
	}
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    cout << key << endl;
    if (key == 357) { // up
        ypos--;
    } else if (key == 359) { // down
        ypos++;
    } else if (key == 356) { // left
        xpos--;
    } else if (key == 358) { // right
        xpos++;
    } else if (key == 'b') {
        scale *= 1.01;
    } else if (key == 's') {
        scale *= 1/1.01;
    }
    
    printStatus();
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
