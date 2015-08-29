#include <iostream>
#include <glut.h>
#include <gl\GL.h>
#include <gl\GLU.h>
using namespace std;

static void MyReshape(const int NewWidth, const int NewHeight);

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glRotatef(30, 1.0, 1.0, 1.0);

	glColor3f(1.0, 1.0, 0.0);
	glTranslatef(-0.6, 1.1, 0);
	glutSolidCube(0.1);
	glColor3f(0.0, 0.0, 1.0);
	glutWireCube(0.1);

	glColor3f(1.0, 1.0, 0.0);
	glTranslatef(0, -0.5, 0);
	glutSolidSphere(0.1, 5, 5);
	glColor3f(0.0, 0.0, 1.0);
	glutWireSphere(0.1, 5, 5);

	glColor3f(1.0, 1.0, 0.0);
	glTranslatef(0, -0.5, 0);
	glutSolidSphere(0.1, 10, 10);
	glColor3f(0.0, 0.0, 1.0);
	glutWireSphere(0.1, 10, 10);

	glColor3f(1.0, 1.0, 0.0);
	glTranslatef(0, -0.5, 0);
	glutSolidTorus(0.1, 0.1, 10, 10);
	glColor3f(0.0, 0.0, 1.0);
	glutWireTorus(0.1, 0.1, 10, 10);

	glColor3f(1.0, 1.0, 0.0);
	glTranslatef(1.0, 1.1, 0);
	glutSolidCone(0.1, 0.5, 10, 10);
	glColor3f(0.0, 0.0, 1.0);
	glutWireCone(0.1, 0.5, 10, 10);

	glColor3f(1.0, 1.0, 0.0);
	glTranslatef(0, -0.5, 0);
	glutSolidCone(0.1, 0.5, 3, 1);
	glColor3f(0.0, 0.0, 1.0);
	glutWireCone(0.1, 0.5, 3, 1);

	glColor3f(1.0, 1.0, 0.0);
	glTranslatef(0, -0.5, 0);
	glutSolidTeapot(0.2);
	glColor3f(0.0, 0.0, 1.0);
	glutWireTeapot(0.2);

	glFlush();
}
void MyReshape(const int NewWidth, const int NewHeight) {
	cout << "Width : " << NewWidth << ", Height : " << NewHeight << endl;

	glViewport(0, 0, NewWidth, NewHeight);
	GLfloat WidthFactor = (GLfloat)NewWidth / (GLfloat)1000;
	GLfloat HeightFactor = (GLfloat)NewHeight / (GLfloat)700;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0 * WidthFactor, 1.0 * WidthFactor, -1.0 * HeightFactor, 1.0 * HeightFactor, -1.0, 1.0);
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitWindowSize(1000, 700);
	glutCreateWindow("OpenGL Sample Drawing");
	glutDisplayFunc(MyDisplay);
	glutReshapeFunc(MyReshape);
	glutMainLoop();
	return 0;
}