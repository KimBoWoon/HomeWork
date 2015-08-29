#define _USE_MATH_DEFINES

#include <cmath>
#include <iostream>
#include <iomanip>
#include <glut.h>
#include <gl\GL.h>
#include <gl\GLU.h>
using namespace std;

GLfloat My3DCubeV[8][3] = {
	{ -0.15, -0.15, -0.15 },
	{ 0.15, -0.15, -0.15 },
	{ 0.15, 0.15, -0.15 },
	{ -0.15, 0.15, -0.15 },
	{ -0.15, -0.15, 0.15 },
	{ 0.15, -0.15, 0.15 },
	{ 0.15, 0.15, 0.15 },
	{ -0.15, 0.15, 0.15 }
};

void MyDisplay1() {
	glClear(GL_COLOR_BUFFER_BIT);
	glViewport(0, 0, 300, 300);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glRotatef(45.0, 0.0, 0.0, 1.0);
	glTranslatef(0.6, 0.0, 0.0);
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3fv(My3DCubeV[6]);
	glVertex3fv(My3DCubeV[2]);
	glVertex3fv(My3DCubeV[3]);
	glVertex3fv(My3DCubeV[7]);
	glVertex3fv(My3DCubeV[0]);
	glVertex3fv(My3DCubeV[1]);
	glVertex3fv(My3DCubeV[5]);
	glVertex3fv(My3DCubeV[4]);
	glVertex3fv(My3DCubeV[4]);
	glVertex3fv(My3DCubeV[5]);
	glVertex3fv(My3DCubeV[6]);
	glVertex3fv(My3DCubeV[7]);
	glVertex3fv(My3DCubeV[0]);
	glVertex3fv(My3DCubeV[3]);
	glVertex3fv(My3DCubeV[2]);
	glVertex3fv(My3DCubeV[1]);
	glVertex3fv(My3DCubeV[0]);
	glVertex3fv(My3DCubeV[4]);
	glVertex3fv(My3DCubeV[7]);
	glVertex3fv(My3DCubeV[3]);
	glVertex3fv(My3DCubeV[1]);
	glVertex3fv(My3DCubeV[5]);
	glVertex3fv(My3DCubeV[6]);
	glVertex3fv(My3DCubeV[2]);
	glEnd();
	cout << fixed << setprecision(3);
	for (int row = 0; row < 8; row++) {
		for (int col = 0; col < 3; col++) {
			cout << setw(8) << My3DCubeV[row][col] << " ";
		}
		cout << endl;
	}
	glFlush();
}
void MyDisplay2() {
	glClear(GL_COLOR_BUFFER_BIT);
	glViewport(0, 0, 300, 300);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	const float degree = static_cast<float> (45 * (M_PI / 180.));
	const float rot[16] = {
		cosf(degree), -sinf(degree), 0, 0,
		sinf(degree), cosf(degree), 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1
	};
	glLoadMatrixf(rot);
	glRotatef(45.0, 0.0, 0.0, 1.0);
	glTranslatef(0.6, 0.0, 0.0);
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3fv(My3DCubeV[6]);
	glVertex3fv(My3DCubeV[2]);
	glVertex3fv(My3DCubeV[3]);
	glVertex3fv(My3DCubeV[7]);
	glVertex3fv(My3DCubeV[0]);
	glVertex3fv(My3DCubeV[1]);
	glVertex3fv(My3DCubeV[5]);
	glVertex3fv(My3DCubeV[4]);
	glVertex3fv(My3DCubeV[4]);
	glVertex3fv(My3DCubeV[5]);
	glVertex3fv(My3DCubeV[6]);
	glVertex3fv(My3DCubeV[7]);
	glVertex3fv(My3DCubeV[0]);
	glVertex3fv(My3DCubeV[3]);
	glVertex3fv(My3DCubeV[2]);
	glVertex3fv(My3DCubeV[1]);
	glVertex3fv(My3DCubeV[0]);
	glVertex3fv(My3DCubeV[4]);
	glVertex3fv(My3DCubeV[7]);
	glVertex3fv(My3DCubeV[3]);
	glVertex3fv(My3DCubeV[1]);
	glVertex3fv(My3DCubeV[5]);
	glVertex3fv(My3DCubeV[6]);
	glVertex3fv(My3DCubeV[2]);
	glEnd();
	cout << fixed << setprecision(3);
	for (int row = 0; row < 8; row++) {
		for (int col = 0; col < 3; col++) {
			cout << setw(8) << My3DCubeV[row][col] << " ";
		}
		cout << endl;
	}
	glFlush();
}
void MyDisplay3() {
	glClear(GL_COLOR_BUFFER_BIT);
	glViewport(0, 0, 300, 300);
	glMatrixMode(GL_MODELVIEW);

	glLoadIdentity();
	glRotatef(45.0, 0.0, 0.0, 1.0);
	glTranslatef(0.6, 0.0, 0.0);
	glutWireCube(0.3f);

	glFlush();
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA);
	glutInitWindowSize(300, 300);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("OpenGl Sample Drawing");
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glLoadIdentity();
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
	glutDisplayFunc(MyDisplay3);
	glutMainLoop();
	return 0;
}