#include "ofApp.h"
#include "ofMain.h"

//========================================================================
int main() {
	ofGLFWWindowSettings settings2;
	settings2.setSize(255, 355);
	settings2.resizable = false;
	settings2.setGLVersion(3, 2);
	settings2.windowMode = OF_WINDOW; //can also be OF_FULLSCREEN

	auto window2 = ofCreateWindow(settings2);
	auto app2 = std::make_shared<ofApp2>();

	ofRunApp(window2, app2);

	// Use ofGLFWWindowSettings for more options like multi-monitor fullscreen
	ofGLFWWindowSettings settings1;
	settings1.setSize(1024, 768);
	settings1.resizable = false;
	settings1.setGLVersion(3, 2);
	settings1.windowMode = OF_WINDOW; //can also be OF_FULLSCREEN

	auto window1 = ofCreateWindow(settings1);
	auto app1 = std::make_shared<ofApp1>();
	app1->window2 = window2;
	app1->app2 = app2;

	ofRunApp(window1, app1);
	ofRunMainLoop();
}
