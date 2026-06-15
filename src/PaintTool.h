#pragma once

#include "ofMain.h"

class HermitePoly {
public:
	glm::vec2 getPoint(glm::vec2 p0, glm::vec2 p1, glm::vec2 v0, glm::vec2 v1, float t);
};

class CatmullRomSpline {

public:
	HermitePoly poly;
	vector<glm::vec2> controlPoints;

	glm::vec2 getPoint(float t);
};

class PaintTool {
private:
public:
	vector<glm::vec2> preLine;
	vector<glm::vec2> line;

	ofFbo fbo;
	CatmullRomSpline spline;

	PaintTool();
	void saveLine(int x, int y);
	void drawLine();
	void saveCanvas();
	void drawCanvas();
};
