#include <iostream>
#include "glut.h"

static void MyDisplay();
static void MyKeyboard(const unsigned char key, int x, int y);

int main(int argc, char *argv[]) {
	glutCreateWindow("OPenGL Drawing Example");
	glutDisplayFunc(MyDisplay);
	glutKeyboardFunc(MyKeyboard);
	glutMainLoop();

	return 0;
}
void MyKeyboard(const unsigned char key, int x, int y) {
	std::cout << "Key = " << key << ", Pos (" << x << ", " << y << ")" << std::endl;
}
void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POLYGON);
	glVertex3f(-0.5, -0.5, 0.0);
	glVertex3f(0.5, -0.5, 0.0);
	glVertex3f(0.5, 0.5, 0.0);
	glVertex3f(-0.5, 0.5, 0.0);
	glEnd();
	glFlush();
}