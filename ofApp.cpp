#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("Insta");

	ofBackground(39);
	ofNoFill();
	ofEnableDepthTest();
	ofSetLineWidth(2);
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();
	ofRotateX(ofGetFrameNum() * 0.1);
	ofRotateY(ofGetFrameNum() * 0.25);

	float radius = 400;
	ofIcoSpherePrimitive ico_sphere = ofIcoSpherePrimitive(radius, 3);
	vector<ofMeshFace> triangles = ico_sphere.getMesh().getUniqueFaces();

	for (int c = 0; c < 5; c++) {

		ofColor color;
		color.setHsb(c * 50, 200, 255);
		ofSetColor(color);

		int i_start = (ofGetFrameNum() + 192 * c) % triangles.size();
		for (int i = 0; i < 64; i++) {

			int index = (i_start + i) % triangles.size();

			vector<ofPoint> vertices;
			for (int j = 0; j < 3; j++) {

				ofPoint point(triangles[index].getVertex(j).x, triangles[index].getVertex(j).y, triangles[index].getVertex(j).z);
				vertices.push_back(point);
			}

			ofBeginShape();
			ofVertices(vertices);
			ofEndShape(true);
		}
	}

	this->cam.end();
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}