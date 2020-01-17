#pragma once

#include "stdafx.h"

#include "MyTexture.h"
#include "MyModel.h"
#include "MyGeograph.h"


namespace Viewer {
	// CAMERA
	vec3d camPos, camLookAt;
	unsigned char mouseFlag = GL_FALSE;
	vec2d angle;

	MyTexture elegant_images[3] = {
		MyTexture("src/img/rosehip.png"),
		MyTexture("src/img/orengepekoe.png"),
		MyTexture("src/img/darjiling.png")
	};

	// Valiable
	double deg = 0;

	float as = 0;
	float tilt = 0;

	int scene = 0;
	int elegance = 0;
	int learning = 0;

	//----------------------------------------------------------------------------//
	void setup(double width, double height) {
		GLdouble aspect = (GLdouble)width / (GLdouble)height;
		glClearColor(0, 0, 0, 1);
		glViewport(0, 0, width, height);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(60.0, aspect, 0.01, 20.0);

		//gluLookAt(0.0, 1.0, 2.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
		gluLookAt(0.0, 0.0, 2.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

		glShadeModel(GL_SMOOTH);

		
	}
	//----------------------------------------------------------------------------//
	void update() {
		deg += 180 / PI / 600;
	}

	void update(double ex, double ey, double ez) {
		deg += 180/PI / 600;
	}
	//----------------------------------------------------------------------------//
	void draw() {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // OpenGL‚É‚æ‚é•`‰æ
		glEnable(GL_DEPTH_TEST);
		
		if (scene == 0) {
			loading(deg);
		}
		else{
			if (elegance == 1) {
				elegant_images[0].beginTexture(false);
				elegant_images[0].drawTexture({ 0,0,0 }, { 180,0,0 }, 0.005, 1, 1);
				elegant_images[0].endTexture();
			}
			else if (elegance == 2) {
				elegant_images[1].beginTexture(false);
				elegant_images[1].drawTexture({ 0,0,0 }, { 180,0,0 }, 0.01, 1, 1);
				elegant_images[1].endTexture();
			}
			else {
				elegant_images[2].beginTexture(false);
				elegant_images[2].drawTexture({ 0,0,0 }, { 180,0,0 }, 0.01, 1, 1);
				elegant_images[2].endTexture();
			}
		}

		glDisable(GL_DEPTH_TEST);
		glFlush();
	}
	//----------------------------------------------------------------------------//
};


