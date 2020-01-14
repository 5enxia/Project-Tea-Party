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

	// MODEL
	//objl::Loader miku;

	// texture
	//MyTexture mikuTextrues[4] = {
	//	MyTexture("Miku/Miku.png"),
	//	MyTexture("Miku/Miku2.png"),
	//	MyTexture("Miku/Miku3.png"),
	//	MyTexture("Miku/Miku1.png"),
	//};
	MyTexture penguin = MyTexture("img/penguin.png");

	// Valiable
	double degX, degY, degZ = 0;
	double bias = 45; // Bias (degrees)
	float as = 0;
	float tilt = 0;

	//----------------------------------------------------------------------------//
	void setup(double width, double height) {
		GLdouble aspect = (GLdouble)width / (GLdouble)height;
		glClearColor(0, 0, 0, 1);
		glViewport(0, 0, width, height);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(60.0, aspect, 0.01, 20.0);

		gluLookAt(0.0, 1.0, 2.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

		glShadeModel(GL_SMOOTH);

		// Load Model 
		/*miku.LoadFile("Miku/Miku.obj");
		for (int i = 0; i < miku.LoadedMeshes.size(); i++) {
			printf("%d\n", miku.LoadedMeshes[i].Vertices.size());
		}*/
	}
	//----------------------------------------------------------------------------//
	void update(float as, float tilt) {

	}

	void update(double ex, double ey, double ez) {
		degX = (180 / PI) * asin(ex);
		degY = (180 / PI) * asin(ey);
		degZ = (180 / PI) * asin(ez);
	}
	//----------------------------------------------------------------------------//
	void draw() {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // OpenGL‚É‚æ‚é•`‰æ
		glEnable(GL_DEPTH_TEST);

		// axis
		glPushMatrix();
		glTranslatef(-1.2, -1.2, 0);
		drawAxis(0.25);
		double div = 0.3;
		glRasterPos2f(0 + div, 0); glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'x');
		glRasterPos2f(0, 0 + div); glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'y');
		glRasterPos2f(0 - div, 0 - div);	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'z');
		glPopMatrix();

		// Cube
		drawCube(degX, degY, degZ);

		// Picture (Single Texture)
		penguin.beginTexture();
		penguin.drawTexture({ 0,0,0 }, { 135,0,0 }, 0.005,1, 1);
		penguin.endTexture();

		glDisable(GL_DEPTH_TEST);
		glFlush();
	}
	//----------------------------------------------------------------------------//
};


