#pragma once

#include "PaintTool.h"
#include "ofMain.h"
#include "ofxGui.h"


class ofApp1;
class ofApp2;


class ofApp1 : public ofBaseApp {

public:
	shared_ptr<ofAppBaseWindow> window2;
	shared_ptr<ofApp2> app2;

	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);

	PaintTool pt;
};

class ofApp2 : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);

	ofShader shader;

	ofxFloatSlider hue;
	ofxFloatSlider size;
	ofxFloatSlider alpha;
	ofxPanel gui;
};
