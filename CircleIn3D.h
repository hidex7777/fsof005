#pragma once
#include "ofMain.h"

class CircleIn3D {
public:
	CircleIn3D(ofVec3f center, ofColor color, float r, float theta);
	~CircleIn3D() {};
	void update(float add);
	void draw();
	vector<ofVec3f> getDots();
private:
	ofVec3f mycenter;
	float myradius;
	vector<ofVec3f> mydots;
	ofColor mycolor;
	float theta;
	int dotalp;
	int linealp;
};