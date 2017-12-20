#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(60);
	ofSetBackgroundColor(cs.getColor("W"));
	ofEnableAlphaBlending();
	ofEnableDepthTest();
	for (int i = 0; i < 10; i++) {
		this->mycircles.push_back(shared_ptr<CircleIn3D>(new CircleIn3D(ofVec3f(0, 0, 0), cs.getColor("dp2"), ofGetWidth() * 0.4, ofRandom(180))));
		this->mycircles.push_back(shared_ptr<CircleIn3D>(new CircleIn3D(ofVec3f(0, 0, 0), cs.getColor("dp18"), ofGetWidth() * 0.35, ofRandom(180))));
		this->mycircles.push_back(shared_ptr<CircleIn3D>(new CircleIn3D(ofVec3f(0, 0, 0), cs.getColor("dp12"), ofGetWidth() * 0.30, ofRandom(180))));
		this->mycircles.push_back(shared_ptr<CircleIn3D>(new CircleIn3D(ofVec3f(0, 0, 0), cs.getColor("dp8"), ofGetWidth() * 0.25, ofRandom(180))));
		this->mycircles.push_back(shared_ptr<CircleIn3D>(new CircleIn3D(ofVec3f(0, 0, 0), cs.getColor("dp22"), ofGetWidth() * 0.20, ofRandom(180))));
	}
}

//--------------------------------------------------------------
void ofApp::update(){
	for (int i = 0; i < this->mycircles.size(); i++) {
		this->mycircles[i]->update(ofRandom(0.01, 0.1));
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	this->cam.begin();
	ofRotateY(ofGetFrameNum());
	for (int i = 0; i < this->mycircles.size(); i++) {
		this->mycircles[i]->draw();
	}

	this->cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == 'x') {
		string now = ofGetTimestampString("%Y%m%d%H%M%S");
		this->img.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
		this->img.saveImage("of" + now + ".jpg");
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
