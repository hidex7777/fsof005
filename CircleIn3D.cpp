#include "CircleIn3D.h"

CircleIn3D::CircleIn3D(ofVec3f center, ofColor color, float r, float theta) {
	this->mycenter = center;
	this->mycolor = color;
	this->myradius = r;
	this->theta = theta;
	for (int i = 0; i < 360; i=i+2) {
		float x = this->mycenter.x + this->myradius * cos(ofDegToRad(i));
		float y = this->mycenter.y + this->myradius * sin(ofDegToRad(i));
		float z = this->mycenter.z;
		this->mydots.push_back(ofVec3f(x, y, z));
	}
}
void CircleIn3D::update(float add) {
	this->theta += add;
}
void CircleIn3D::draw() {
	ofRotateY(this->theta);
	for (int i = 0; i < this->mydots.size(); i++) {
		ofSetColor(this->mycolor);
		//ofDrawEllipse(this->mydots[i], 4, 4);
		ofPushMatrix();
		ofTranslate(this->mydots[i]);
		ofDrawSphere(2);
		ofPopMatrix();
		ofSetLineWidth(1);
		if (i == 0) {
			ofDrawLine(this->mydots[i], this->mydots[this->mydots.size() - 1]);
		}
		else if (i > 0) {
			ofDrawLine(this->mydots[i], this->mydots[i - 1]);
		}
	}
	
}
vector<ofVec3f> CircleIn3D::getDots() {
	return this->mydots;
}