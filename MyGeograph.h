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

void drawCube(vec3d pos, vec3d rotate, float size) {
	glPushMatrix();
	glTranslated(pos.x, pos.y, pos.z);
	glRotatef(rotate.x, 1, 0, 0); 	glRotatef(rotate.y, 0, 1, 0); glRotatef(rotate.z, 0, 0, 1);
	//drawAxis(0.5);
	glutWireCube(size);
	glPopMatrix();
}

void drawSphere(vec3d pos, vec3d rotate, float radius) {
	glPushMatrix();
	glTranslated(pos.x, pos.y, pos.z);
	glRotatef(rotate.x, 1, 0, 0); 	glRotatef(rotate.y, 0, 1, 0); glRotatef(rotate.z, 0, 0, 1);
	//drawAxis(0.5);
	glutSolidSphere(radius, 32, 32);
	glPopMatrix();
}

void loading(float deg) {
	glPushMatrix();
	glRotated(deg, 0, 0, 1);
	for (int i = 0; i < 9; i++) {
		float rad = 2 * PI / 9 * i;
		float x = cosf(rad) / 4;
		float y = sinf(rad) / 4;
		drawSphere({ x,y,0 }, { 0,0,0 }, 0.05);
	}
	glPopMatrix();
}

