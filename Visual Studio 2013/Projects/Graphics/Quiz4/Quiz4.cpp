#include <iostream>
#include <ctime>
#include <glut.h>
#include <gl\GL.h>
#include <gl\GLU.h>
using namespace std;

int FlatShaded = 0;
int Wireframed = 0;
int ViewX = 0;
int ViewY = 0;

void InitLight() {
	GLfloat mat_diffuse[] = { 0.5, 0.4, 0.3, 1.0 };
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_ambient[] = { 0.5, 0.4, 0.3, 1.0 };
	GLfloat mat_shininess[] = { 15.0 };
	GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat light_diffuse[] = { 0.8, 0.8, 0.8, 1.0 };
	GLfloat light_ambient[] = { 0.3, 0.3, 0.3, 1.0 };
	GLfloat light_position[] = { -3, 6, 3.0, 0.0 };
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
}

void MyMouseMove(GLint X, GLint Y) {
	cout << "X : " << X << ", " << Y << endl;
	ViewX = X;
	ViewY = Y;
	glutPostRedisplay();
}

void MyKeyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 'q':
	case 'Q':
	case '\033':
		exit(0);
		break;
	case 's':
		if (FlatShaded) {
			FlatShaded = 0;
			glShadeModel(GL_SMOOTH);
		}
		else {
			FlatShaded = 1;
			glShadeModel(GL_FLAT);
		}
		glutPostRedisplay();
		break;
	case 'w':
		if (Wireframed) {
			Wireframed = 0;
			glPolygonMode(GL_BACK, GL_FILL);
		}
		else {
			Wireframed = 1;
			glPolygonMode(GL_BACK, GL_LINE);
		}
		glutPostRedisplay();
		break;
	}
}

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0, 0.0, 0.0, 0.0, 0.0, -1.0, 1.0, 1.0, 0.0);
	glRotatef(ViewX, 0.2, 0.0, 0.0);
	glRotatef(ViewY, 0.0, 0.2, 0.0);

	glutSolidTeapot(0.2);
	glTranslatef(-0.6, 0.0, 0);
	glutSolidCube(0.3);
	glTranslatef(0.6, 0.0, 0);

	glTranslatef(0.6, 0.0, 0);
	glutSolidSphere(0.3, 3, 3);
	glTranslatef(-0.6, 0.0, 0);

	glRotatef(90, 1.0, 0.0, 0.0);
	glTranslatef(0.0, 0.0, 0.15);
	glBegin(GL_POLYGON);
	glVertex3f(-1.0, -0.5, 0.0);
	glVertex3f(1.0, -0.5, 0.0);
	glVertex3f(1.0, 0.5, 0.0);
	glVertex3f(-1.0, 0.5, 0.0);
	glEnd();
	glTranslatef(0.0, 0.0, -0.15);
	glRotatef(-90, 1.0, 0.0, 0.0);

	glTranslatef(-0.1, 0.0, 0.3);
	glBegin(GL_POLYGON);
	glVertex3f(-0.7, -0.1, 0.0);
	glVertex3f(-0.6, -0.1, 0.0);
	glVertex3f(-0.6, -0.6, 0.0);
	glVertex3f(-0.7, -0.6, 0.0);
	glEnd();
	glTranslatef(0.1, 0.0, -0.3);

	glTranslatef(-1.5, 0.0, -0.3);
	glBegin(GL_POLYGON);
	glVertex3f(0.7, -0.1, 0.0);
	glVertex3f(0.6, -0.1, 0.0);
	glVertex3f(0.6, -0.6, 0.0);
	glVertex3f(0.7, -0.6, 0.0);
	glEnd();
	glTranslatef(1.5, 0.0, 0.3);

	glTranslatef(0.0, 0.0, 0.3);
	glBegin(GL_POLYGON);
	glVertex3f(0.7, -0.1, 0.0);
	glVertex3f(0.6, -0.1, 0.0);
	glVertex3f(0.6, -0.6, 0.0);
	glVertex3f(0.7, -0.6, 0.0);
	glEnd();
	glTranslatef(0.0, 0.0, -0.3);

	glTranslatef(0.0, 0.0, -0.3);
	glBegin(GL_POLYGON);
	glVertex3f(0.7, -0.1, 0.0);
	glVertex3f(0.6, -0.1, 0.0);
	glVertex3f(0.6, -0.6, 0.0);
	glVertex3f(0.7, -0.6, 0.0);
	glEnd();
	glTranslatef(0.0, 0.0, 0.3);

	glFlush();
}

void MyReshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(400, 400);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("OpenGL Sample Drawing");
	glClearColor(0.4, 0.4, 0.4, 0.0);
	InitLight();
	glutDisplayFunc(MyDisplay);
	glutKeyboardFunc(MyKeyboard);
	glutMotionFunc(MyMouseMove);
	glutReshapeFunc(MyReshape);
	glutMainLoop();
}