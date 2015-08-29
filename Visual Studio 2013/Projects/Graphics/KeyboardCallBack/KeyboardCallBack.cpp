#include <iostream>
#include <glut.h>
#include <gl\GL.h>
#include <gl\GLU.h>
using namespace std;

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_POLYGON);
	glVertex3f(-0.5, -0.5, 0.0);
	glVertex3f(0.5, -0.5, 0.0);
	glVertex3f(0.5, 0.5, 0.0);
	glVertex3f(-0.5, 0.5, 0.0);
	glEnd();
	glFlush();
}
void MyKetboard(unsigned char KeyPressed, int X, int Y) {
	switch (KeyPressed) {
	case 'Q':
		exit(0);
		break;
	case 'q':
		exit(0);
		break;
	case 27:
		exit(0);
		break;
	}
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(300, 300);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("OpenGl Sample Drawing");
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glutDisplayFunc(MyDisplay);
	glutKeyboardFunc(MyKetboard);
	glutMainLoop();
	return 0;
}