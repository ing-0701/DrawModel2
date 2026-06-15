#include "PaintTool.h"

//メモ：今は spline.controlPoints.size() > 3 の時にしか描かれない
//spline.controlPoints.size() > 3 の時はpreLineとかを参照して短い線を描くようにしよう
//カラーピッカーうっかり閉じないように対処

glm::vec2 HermitePoly::getPoint(glm::vec2 p0, glm::vec2 p1, glm::vec2 v0, glm::vec2 v1, float t) {
	glm::vec2 c0 = 2.0f * p0 - 2.0f * p1 + v0 + v1;
	glm::vec2 c1 = -3.0f * p0 + 3.0f * p1 - 2.0f * v0 - v1;
	glm::vec2 c2 = v0;
	glm::vec2 c3 = p0;

	float t2 = t * t;
	float t3 = t2 * t;
	return c0 * t3 + c1 * t2 + c2 * t + c3;
}

glm::vec2 CatmullRomSpline::getPoint(float t) {
	int l = controlPoints.size();
	float progress = (l - 1) * t;
	int i = floor(progress);
	float weight = progress - i;

	if (weight < 0.0001f && i >= l - 1) {
		i = l - 2;
		weight = 1.0f;
	}

	glm::vec2 p0 = controlPoints[i];
	glm::vec2 p1 = controlPoints[i + 1];

	glm::vec2 v0;
	if (i > 0) {
		v0 = 0.5f * (controlPoints[i + 1] - controlPoints[i - 1]);
	} else {
		v0 = controlPoints[i + 1] - controlPoints[i];
	}

	glm::vec2 v1;
	if (i < l - 2) {
		v1 = 0.5f * (controlPoints[i + 2] - controlPoints[i]);
	} else {
		v1 = controlPoints[i + 1] - controlPoints[i];
	}

	return poly.getPoint(p0, p1, v0, v1, weight);
}

PaintTool::PaintTool() {
	fbo.allocate(ofGetWidth(), ofGetHeight());
}

void PaintTool::saveLine(int x, int y) {
	preLine.push_back(glm::vec2(x, y));
}

void PaintTool::drawLine() {
	ofBackground(255, 255, 255, 255);

	fbo.begin();

	spline.controlPoints.clear();
	line.clear();

	for (int i = 0; i < preLine.size(); i++) {
		spline.controlPoints.push_back(preLine[i]);
	}

	if (spline.controlPoints.size() > 3) {
		for (float t = 0; t <= 1.0f; t += 0.004f) {
			//cout << "t is " << t << ".\n";
			glm::vec2 pos = spline.getPoint(t);
			//cout << "pos is " << pos << ".\n";
			line.push_back(pos);
		}
	}

	//if (line.size() > 1) {
	//	for (int i = 0; i < line.size()-1; i++) {
	//		ofDrawLine(line[i], line[i+1]);
	//	}
	//}

	if (line.size() > 0) {
		for (int i = 0; i < line.size() - 1; i++) {
			//switch (i) {
			//case 0:
			//	ofSetColor(0, 255, 0, 20);
			//	break;
			//case 1:
			//	ofSetColor(0, 0, 255, 20);
			//	break;
			//case 2:
			//	ofSetColor(0, 0, 0, 20);
			//	break;
			//}
			ofDrawCircle(line[i], 10);
		}
	}

	//ofSetColor(255, 0, 0, 1);
	//if (preLine.size() > 0) {
	//	for (int i = 0; i < preLine.size() - 1; i++) {
	//		ofDrawCircle(preLine[i], 10);
	//	}
	//}

	//ofSetColor(0, 0, 255, 1);
	//if (spline.controlPoints.size() > 0) {
	//	for (int i = 0; i < spline.controlPoints.size() - 1; i++) {
	//		ofDrawCircle(spline.controlPoints[i], 10);
	//	}
	//}

	fbo.end();
}

void PaintTool::saveCanvas() {

	preLine.clear();
	spline.controlPoints.clear();
	line.clear();
}

void PaintTool::drawCanvas() {
	ofDisableAlphaBlending();
	ofSetColor(255, 255, 255, 255);
	fbo.draw(0, 0, ofGetWidth(), ofGetHeight());
	ofEnableAlphaBlending();
}
