#include "ofApp.h"
#include "PaintTool.h"
#include <GLFW/glfw3.h>

bool mouseSwitch = false;
ofColor color;
int lineAlpha;
int lineSize;

//--------------------------------------------------------------
void ofApp1::setup() {
	ofBackground(255, 255, 255);
	ofSetCircleResolution(32);
	ofEnableAlphaBlending();
	//glBlendFuncSeparate(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA, GL_SRC_ALPHA, GL_ONE);
	color = (0, 0, 0);
	lineAlpha = 255;
	lineSize = 100;
	pt.fbo.begin();
	ofClear(255, 255, 255, 255);
	pt.fbo.end();
}

//--------------------------------------------------------------
void ofApp1::update() {
}

//--------------------------------------------------------------
void ofApp1::draw() {
	int r = color.r;
	int g = color.g;
	int b = color.b;
	lineAlpha = 100 * app2->alpha;

	ofSetColor(r, g, b, lineAlpha);
	if (pt.preLine.size() > 0) {
		pt.drawLine();
	}

	pt.drawCanvas();


	cout << "pre is " << pt.preLine.size() << ". spline is " << pt.spline.controlPoints.size() << ". line is " << pt.line.size() << ".\n";
}

//--------------------------------------------------------------
void ofApp1::keyPressed(int key) {
	auto glfwWindow2 = (GLFWwindow *)window2->getWindowContext();
	switch (key) {
	case 'w':
		glfwShowWindow(glfwWindow2);
		break;
	case 'h':
		glfwHideWindow(glfwWindow2);
		break;
	}
}

//--------------------------------------------------------------
void ofApp1::keyReleased(int key) {
}

//--------------------------------------------------------------
void ofApp1::mouseMoved(int x, int y) {
}

//--------------------------------------------------------------
void ofApp1::mouseDragged(int x, int y, int button) {
	if (mouseSwitch == true) {
		pt.saveLine(x, y);
	}
}

//--------------------------------------------------------------
void ofApp1::mousePressed(int x, int y, int button) {
	mouseSwitch = true;
}

//--------------------------------------------------------------
void ofApp1::mouseReleased(int x, int y, int button) {
	mouseSwitch = false;

	pt.saveCanvas();
}

//--------------------------------------------------------------
void ofApp1::mouseEntered(int x, int y) {
}

//--------------------------------------------------------------
void ofApp1::mouseExited(int x, int y) {
}

//--------------------------------------------------------------
void ofApp1::windowResized(int w, int h) {
}

//--------------------------------------------------------------
void ofApp1::gotMessage(ofMessage msg) {
}

//--------------------------------------------------------------
void ofApp1::dragEvent(ofDragInfo dragInfo) {
}

//--------------------------------------------------------------
void ofApp2::setup() {
	ofBackground(255);
	ofSetCircleResolution(32);
	ofEnableAlphaBlending();
	ofSetColor(255, 0, 0, 255);

	shader.load("shader");

	ofxGuiSetDefaultWidth(255);
	ofxGuiSetDefaultHeight(10);
	gui.setup();
	gui.setPosition(0, 255);
	gui.add(hue.setup("Hue", 0.0, 0.0, 1.0));
	hue.setSize(255, 30);
	gui.add(size.setup("Size", 0.1, 0.1, 1.0));
	size.setSize(255, 30);
	gui.add(alpha.setup("Alpha", 1.0, 0.0, 1.0));
	alpha.setSize(255, 30);
}

//--------------------------------------------------------------
void ofApp2::update() {
}

//--------------------------------------------------------------
void ofApp2::draw() {
	ofBackground(255);
	ofSetColor(0);

	shader.begin();
	shader.setUniform1f("hue", hue);
	ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
	shader.end();

	ofSetColor(255, 255, 255, 255);
	ofDisableDepthTest();
	gui.draw();
	ofEnableDepthTest();
}

//--------------------------------------------------------------
void ofApp2::keyPressed(int key) {
}

//--------------------------------------------------------------
void ofApp2::keyReleased(int key) {
}

//--------------------------------------------------------------
void ofApp2::mouseMoved(int x, int y) {
}

//--------------------------------------------------------------
void ofApp2::mouseDragged(int x, int y, int button) {
}

//--------------------------------------------------------------
void ofApp2::mousePressed(int x, int y, int button) {
}

//--------------------------------------------------------------
void ofApp2::mouseReleased(int x, int y, int button) {
	if (y <= 255) {
		color = ofColor::fromHsb(hue * 255, x, 255 - y);
	}
}

//--------------------------------------------------------------
void ofApp2::mouseEntered(int x, int y) {
}

//--------------------------------------------------------------
void ofApp2::mouseExited(int x, int y) {
}

//--------------------------------------------------------------
void ofApp2::windowResized(int w, int h) {
}

//--------------------------------------------------------------
void ofApp2::gotMessage(ofMessage msg) {
}

//--------------------------------------------------------------
void ofApp2::dragEvent(ofDragInfo dragInfo) {
}
