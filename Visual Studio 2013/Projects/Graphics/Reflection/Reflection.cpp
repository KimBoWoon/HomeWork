#define _USE_MATH_DEFINES

#include <iostream>
#include <memory>
#include <cmath>
#include "glut.h"
#include <gl\GL.h>
#include <gl\GLU.h>
using namespace std;

static const float xMax = 2.0;
static const float yMax = 2.0;
static const float zMax = 2.0;
static const int widthWindow = 300;
static const int heightWindow = 300;

static GLfloat My3DCubeV[8][3] = {
	{ 0.75, 0.75, -0.25 },
	{ 1.25, 0.75, -0.25 },
	{ 1.25, 1.25, -0.25 },
	{ 0.75, 1.25, -0.25 },
	{ 0.75, 0.75, 0.25 },
	{ 1.25, 0.75, 0.25 },
	{ 1.25, 1.25, 0.25 },
	{ 0.75, 1.25, 0.25 },
};
GLfloat MyColor[8][3] = {
	{ 0.2, 0.2, 0.2 },
	{ 1.0, 0.0, 0.0 },
	{ 1.0, 1.0, 1.0 },
	{ 0.0, 1.0, 0.0 },
	{ 0.0, 0.0, 1.0 },
	{ 1.0, 0.0, 1.0 },
	{ 1.0, 1.0, 1.0 },
	{ 0.0, 1.0, 1.0 }
};

static void MyDisplay();
static void MyReshape(const int newWidth, const int newHeight);
static void ReflectX(GLfloat(*cubeV)[3]);
static void ReflectY(GLfloat(*cubeV)[3]);
static void ReflectZ(GLfloat(*cubeV)[3]);
static void ReflectO(GLfloat(*cubeV)[3]);

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(widthWindow, heightWindow);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("OpenGL Scaling Drawing");
	glLoadIdentity();
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glOrtho(-xMax, xMax, -yMax, yMax, -zMax, zMax);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	ReflectY(My3DCubeV);

	glutReshapeFunc(MyReshape);
	glutDisplayFunc(MyDisplay);
	glutMainLoop();
	return 0;
}
static void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);

	glEnableClientState(GL_COLOR_ARRAY);
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, My3DCubeV);
	glColorPointer(3, GL_FLOAT, 0, MyColor);

	glBegin(GL_QUADS);
	glColor3fv(MyColor[0]);	glVertex3fv(My3DCubeV[0]);
	glColor3fv(MyColor[3]);	glVertex3fv(My3DCubeV[3]);
	glColor3fv(MyColor[7]);	glVertex3fv(My3DCubeV[7]);
	glColor3fv(MyColor[4]);	glVertex3fv(My3DCubeV[4]);

	glColor3fv(MyColor[3]);	glVertex3fv(My3DCubeV[3]);
	glColor3fv(MyColor[7]);	glVertex3fv(My3DCubeV[7]);
	glColor3fv(MyColor[6]);	glVertex3fv(My3DCubeV[6]);
	glColor3fv(MyColor[2]);	glVertex3fv(My3DCubeV[2]);

	glColor3fv(MyColor[0]);	glVertex3fv(My3DCubeV[0]);
	glColor3fv(MyColor[4]);	glVertex3fv(My3DCubeV[4]);
	glColor3fv(MyColor[5]);	glVertex3fv(My3DCubeV[5]);
	glColor3fv(MyColor[1]);	glVertex3fv(My3DCubeV[1]);

	glColor3fv(MyColor[1]);	glVertex3fv(My3DCubeV[1]);
	glColor3fv(MyColor[2]);	glVertex3fv(My3DCubeV[2]);
	glColor3fv(MyColor[6]);	glVertex3fv(My3DCubeV[6]);
	glColor3fv(MyColor[5]);	glVertex3fv(My3DCubeV[5]);

	glColor3fv(MyColor[7]);	glVertex3fv(My3DCubeV[7]);
	glColor3fv(MyColor[4]);	glVertex3fv(My3DCubeV[4]);
	glColor3fv(MyColor[5]);	glVertex3fv(My3DCubeV[5]);
	glColor3fv(MyColor[6]);	glVertex3fv(My3DCubeV[6]);

	glColor3fv(MyColor[0]);	glVertex3fv(My3DCubeV[0]);
	glColor3fv(MyColor[3]);	glVertex3fv(My3DCubeV[3]);
	glColor3fv(MyColor[2]);	glVertex3fv(My3DCubeV[2]);
	glColor3fv(MyColor[1]);	glVertex3fv(My3DCubeV[1]);
	glEnd();
	glFlush();
}
static void MyReshape(const int newWidth, const int newHeight) {
	glViewport(0, 0, newWidth, newHeight);
	GLfloat WidthFactor = (GLfloat)newWidth / (GLfloat)widthWindow;
	GLfloat HeightFactor = (GLfloat)newHeight / (GLfloat)heightWindow;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-xMax * WidthFactor, xMax * WidthFactor, -yMax * HeightFactor, yMax * HeightFactor, -zMax, zMax);
}
static void ReflectX(GLfloat(*cubeV)[3]) {
	float rot[4][4] = {
		{ 1, 0, 0, 0 },
		{ 0 , -1, 0, 0 },
		{ 0, 0, 1, 0 },
		{ 0, 0, 0, 1 },
	};
	float temp[8][4] = { 0 };
	float arr[4][1] = { 0, 0, 0, 1 };
	for (int i = 0; i < 8; i++) {
		for (int q = 0; q < 3; q++) {
			arr[q][0] = cubeV[i][q];
		}
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				temp[i][j] += rot[j][k] * arr[k][0];
			}
			cout << temp[i][j] << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 3; j++) {
			cubeV[i][j] = temp[i][j];
		}
	}
}
static void ReflectY(GLfloat(*cubeV)[3]) {
	float rot[4][4] = {
		{ -1, 0, 0, 0 },
		{ 0, 1, 0, 0 },
		{ 0, 0, 1, 0 },
		{ 0, 0, 0, 1 },
	};
	float temp[8][4] = { 0 };
	float arr[4][1] = { 0, 0, 0, 1 };
	for (int i = 0; i < 8; i++) {
		for (int q = 0; q < 3; q++) {
			arr[q][0] = cubeV[i][q];
		}
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				temp[i][j] += rot[j][k] * arr[k][0];
			}
			cout << temp[i][j] << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 3; j++) {
			cubeV[i][j] = temp[i][j];
		}
	}
}
static void ReflectZ(GLfloat(*cubeV)[3]) {
	float rot[4][4] = {
		{ 1, 0, 0, 0 },
		{ 0, 1, 0, 0 },
		{ 0, 0, -1, 0 },
		{ 0, 0, 0, 1 },
	};
	float temp[8][4] = { 0 };
	float arr[4][1] = { 0, 0, 0, 1 };
	for (int i = 0; i < 8; i++) {
		for (int q = 0; q < 3; q++) {
			arr[q][0] = cubeV[i][q];
		}
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				temp[i][j] += rot[j][k] * arr[k][0];
			}
			cout << temp[i][j] << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 3; j++) {
			cubeV[i][j] = temp[i][j];
		}
	}
}
static void ReflectO(GLfloat(*cubeV)[3]) {
	float rot[4][4] = {
		{ -1, 0, 0, 0 },
		{ 0, -1, 0, 0 },
		{ 0, 0, -1, 0 },
		{ 0, 0, 0, 1 },
	};
	float temp[8][4] = { 0 };
	float arr[4][1] = { 0, 0, 0, 1 };
	for (int i = 0; i < 8; i++) {
		for (int q = 0; q < 3; q++) {
			arr[q][0] = cubeV[i][q];
		}
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				temp[i][j] += rot[j][k] * arr[k][0];
			}
			cout << temp[i][j] << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 3; j++) {
			cubeV[i][j] = temp[i][j];
		}
	}
}