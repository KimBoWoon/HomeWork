#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <iostream>
#include <iomanip>
#include <glut.h>
#include <gL/gl.h>
#include <gL/glu.h>
#include "Matrix.h"


GLfloat My3DCubeV[8][3] =
{
	0.75, 0.75, -0.25,
	1.25, 0.75, -0.25,
	1.25, 1.25, -0.25,
	0.75, 1.25, -0.25,
	0.75, 0.75, 0.25,
	1.25, 0.75, 0.25,
	1.25, 1.25, 0.25,
	0.75, 1.25, 0.25,
};


// GL좌표계를 위한 GlOrth Properties 
static const GLdouble xMax = 2.0;
static const GLdouble yMax = 2.0;
static const GLdouble zMax = 2.0;

// Window Size
static const int widthWidow = 300;
static const int heightWidow = 300;


static void MyDisplay();
static void MyReshape(const int newWidth, const int newHeight);
static void DrawAxis();


int main(int argc, char *argv[])
{
	std::cout << "OpenGL using Matrix" << std::endl;
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(widthWidow, heightWidow);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("OpenGL Scaling Drawing");

	glLoadIdentity();
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glOrtho(-xMax, xMax, -yMax, yMax, zMax, -zMax);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	//KmuCheerUP::Matrix *mat = new KmuCheerUP::Matrix;
	//mat->ReflectO()->Translate(1.f, 1.f, 0.f)->RotateY(45.f)->RotateX(45.f)->RotateZ(45.f)->Translate(-1.f, -1.f, 0.f);
	//float(*re)[3] = reinterpret_cast<float(*)[3]>((*mat) * My3DCubeV);

	KmuCheerUP::Matrix matTo;
	matTo.Translate(-1.f, -1.f, 0.f);
	std::cout << matTo << std::endl;

	KmuCheerUP::Matrix matRz;
	matRz.RotateZ(45.f);
	std::cout << matRz << std::endl;

	KmuCheerUP::Matrix matT;
	matT.Translate(1.f, 1.f, 0.f);
	std::cout << matT << std::endl;

	KmuCheerUP::Matrix matS;
	matS.Scale(1.25f);
	std::cout << matS << std::endl;

	KmuCheerUP::Matrix matRefo;
	matRefo.ReflectO();
	std::cout << matRefo << std::endl;

	float(*re)[3] = reinterpret_cast<float(*)[3]>((matRefo * matS * matT * matRz * matTo) * My3DCubeV);

	//KmuCheerUP::Matrix matTo;
	//matTo.Translate(-1.f, -1.f, 0.f);

	//KmuCheerUP::Matrix matRz;
	//matRz.RotateZ(30.f);

	//KmuCheerUP::Matrix matRx;
	//matRx.RotateX(30.f);

	//KmuCheerUP::Matrix matRy;
	//matRy.RotateY(30.f);

	//KmuCheerUP::Matrix matT;
	//matT.Translate(1.f, 1.f, 0.f);

	//KmuCheerUP::Matrix matRefo;
	//matRefo.ReflectO();

	//float(*re)[3] = reinterpret_cast<float(*)[3]>((matRefo * matT * matRy * matRx * matRz * matTo) * My3DCubeV);

	std::cout << std::fixed << std::setprecision(3);
	for (int row = 0; row < 8; row++)
	{	
		for (int col = 0; col < 3; col++)
		{
			std::cout  << std::setw(8) << re[row][col] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;

	for (int row = 0; row < 8; row++)
	{
		for (int col = 0; col < 3; col++)
		{
			std::cout << std::setw(8) << My3DCubeV[row][col] << " ";
		}
		std::cout << std::endl;
	}

	glutReshapeFunc(MyReshape);
	glutDisplayFunc(MyDisplay);
	glutMainLoop();

	return 0;
}

void MyDisplay() {

	glClear(GL_COLOR_BUFFER_BIT);

	DrawAxis();

	glBegin(GL_QUADS);
	// Top
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3fv(My3DCubeV[6]);
	glVertex3fv(My3DCubeV[2]);
	glVertex3fv(My3DCubeV[3]);
	glVertex3fv(My3DCubeV[7]);

	// Bottom
	glVertex3fv(My3DCubeV[0]);
	glVertex3fv(My3DCubeV[1]);
	glVertex3fv(My3DCubeV[5]);
	glVertex3fv(My3DCubeV[4]);

	// Front
	glVertex3fv(My3DCubeV[4]);
	glVertex3fv(My3DCubeV[5]);
	glVertex3fv(My3DCubeV[6]);
	glVertex3fv(My3DCubeV[7]);

	// Back
	glVertex3fv(My3DCubeV[0]);
	glVertex3fv(My3DCubeV[3]);
	glVertex3fv(My3DCubeV[2]);
	glVertex3fv(My3DCubeV[1]);

	// Left
	glVertex3fv(My3DCubeV[0]);
	glVertex3fv(My3DCubeV[4]);
	glVertex3fv(My3DCubeV[7]);
	glVertex3fv(My3DCubeV[3]);

	// Right
	glVertex3fv(My3DCubeV[1]);
	glVertex3fv(My3DCubeV[5]);
	glVertex3fv(My3DCubeV[6]);
	glVertex3fv(My3DCubeV[2]);
	glEnd();
	glFlush();

}

void MyReshape(const int newWidth, const int newHeight) {

	glViewport(0, 0, newWidth, newHeight);

	GLfloat WidthFactor = (GLfloat)newWidth / (GLfloat)300;
	GLfloat HeightFactor = (GLfloat)newHeight / (GLfloat)300;
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glOrtho(-xMax * WidthFactor, xMax * WidthFactor,
		-yMax * HeightFactor, yMax * HeightFactor,
		-zMax, zMax);
}

void DrawAxis(void)
{
	glColor3f(0.5, 0.5, 0.5);

	glBegin(GL_LINES);
	// X-axis: Red
	glColor3f(0.5, 0.0, 0.0);
	glVertex3f(-xMax / 2, 0.0, 0.0);
	glVertex3f(xMax / 2, 0.0, 0.0);

	// Y-axis: Green
	glColor3f(0.0, 0.5, 0.0);
	glVertex3f(0.0, yMax / 2, 0.0);
	glVertex3f(0.0, -yMax / 2, 0.0);

	// Z-axis: Blue
	glColor3f(0.0, 0.0, 0.5);
	glVertex3f(0.0, 0.0, -zMax / 2);
	glVertex3f(0.0, 0.0, zMax / 2);
	glEnd();
}