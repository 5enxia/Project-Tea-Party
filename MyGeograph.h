#include <GL/glut.h>

void drawAxis(float len) {
	glLineWidth(3);
	// x
	glColor3f(1, 0, 0);
	glBegin(GL_LINES); glVertex3f(0, 0, 0); glVertex3f(len, 0, 0); glEnd();
	// y
	glColor3f(0, 1, 0);
	glBegin(GL_LINES); glVertex3f(0, 0, 0); glVertex3f(0, len, 0);	glEnd();
	// z
	glColor3f(0, 0, 1);
	glBegin(GL_LINES); glVertex3f(0, 0, 0); glVertex3f(0, 0, len); glEnd();

	glColor3f(1.0, 1.0, 1.0);
}

void drawCube(double degX, double degY, double degZ) {
	glPushMatrix();
	glRotatef(degX - 90, 1, 0, 0); // x
	glRotatef(degY, 0, 1, 0); // y
	glRotatef(degZ, 0, 0, 1); // z
	drawAxis(0.5);
	glutWireCube(1);
	glPopMatrix();
}

