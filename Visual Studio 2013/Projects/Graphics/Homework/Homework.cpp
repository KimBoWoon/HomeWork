#include <iostream>
#include <string>
#include <glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
using namespace std;

static int Sun = 0, Mercury = 34, Venus = 223, Earth = 56, Moon = 0, Mars = 123, Jupiter = 333, Satrun = 154, Uranus = 20, Neptune = 280;
static GLfloat eyeX = 0.0;
static GLfloat eyeY = 0.0;
static GLfloat eyeZ = 10.0;
static GLfloat centerX = 0.0;
static GLfloat centerY = 0.0;
static GLfloat centerZ = 0.0;
static GLfloat xRot = 0;
static GLfloat yRot = 0;
static GLboolean keyDown = false;

void text(char* string, float x, float y, float z){
	glRasterPos3f(x, y, z);
	for (; *string != ' '; string++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, *string);
}
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
void Draw() {
	glRotatef(90, 1.0, 0.0, 0.0);
	glColor3f(1.0, 1.0, 1.0);
	glutWireTorus(0.00001, 0.15, 10, 50);
	glutWireTorus(0.00001, 0.24, 10, 50);
	glutWireTorus(0.00001, 0.33, 10, 50);
	glutWireTorus(0.00001, 0.42, 10, 50);
	glutWireTorus(0.00001, 0.47, 10, 50);
	glutWireTorus(0.00001, 0.52, 10, 50);
	glutWireTorus(0.00001, 0.57, 10, 50);
	glutWireTorus(0.00001, 0.62, 10, 50);
	glutWireTorus(0.00001, 0.67, 10, 50);
	glRotatef(-90, 1.0, 0.0, 0.0);
	//태양
	glPushMatrix();
		glRotatef(Sun, 0.0, 1.0, 0.0);
		glPushMatrix();
			glColor3f(1.0, 1.0, 1.0);
			text("Sun ", 0.0, 0.1, 0.0);
			glColor3f(1.0, 0.3, 0.3);
			glRotatef((GLfloat)Sun, 0.0, 1.0, 0.0);
			glutSolidSphere(0.08, 20, 16);
		glPopMatrix();
	glPopMatrix();
	//수성
	glPushMatrix();
		glRotatef((GLfloat)Mercury, 0.0, 1.0, 0.0);
		glPushMatrix();
			glTranslatef(0.15, 0.0, 0.0);
			glColor3f(1.0, 1.0, 1.0);
			text("Mercury ", 0.0, 0.05, 0.0);
			glRotatef((GLfloat)Mercury, 0.0, 2.0, 0.0);
			glColor3f(0.0, 0.0, 1.0);
			glutSolidSphere(0.02, 10, 8);
		glPopMatrix();
	glPopMatrix();
	//금성
	glPushMatrix();
		glRotatef((GLfloat)Venus, 0.0, 1.0, 0.0);
		glPushMatrix();
			glTranslatef(0.24, 0.0, 0.0);
			glColor3f(1.0, 1.0, 1.0);
			text("Venus ", 0.0, 0.05, 0.0);
			glRotatef((GLfloat)Venus, 0.0, 1.0, 0.0);
			glColor3f(1.0, 0.4, 0.2);
			glutSolidSphere(0.03, 10, 8);
		glPopMatrix();
	glPopMatrix();
	//지구
	glPushMatrix();
		glRotatef((GLfloat)Earth, 0.0, 1.0, 0.0);
		glPushMatrix();
			glTranslatef(0.33, 0.0, 0.0);
			glColor3f(1.0, 1.0, 1.0);
			text("Earth ", 0.0, 0.05, 0.0);
			glRotatef((GLfloat)Earth, 0.0, 1.0, 0.0);
			glColor3f(0.5, 0.6, 0.7);
			glutSolidSphere(0.05, 10, 8);
		glPopMatrix();
	glPopMatrix();
	//달
	glPushMatrix();
		glRotatef((GLfloat)Moon, 0.0, 1.0, 0.0);
		glPushMatrix();
			glTranslatef(0.42, 0.0, 0.0);
			glColor3f(1.0, 1.0, 1.0);
			text("Moon ", 0.0, 0.05, 0.0);
			glRotatef((GLfloat)Moon, 0.0, 1.0, 0.0);
			glColor3f(0.9, 0.8, 0.2);
			glutSolidSphere(0.02, 10, 8);
		glPopMatrix();
	glPopMatrix();
	//화성
	glPushMatrix();
		glRotatef((GLfloat)Mars, 0.0, 1.0, 0.0);
		glPushMatrix();
			glTranslatef(0.47, 0.0, 0.0);
			glColor3f(1.0, 1.0, 1.0);
			text("Mars ", 0.0, 0.05, 0.0);
			glRotatef((GLfloat)Mars, 0.0, 1.0, 0.0);
			glColor3f(1.0, 0.7, 0.5);
			glutSolidSphere(0.02, 10, 8);
		glPopMatrix();
	glPopMatrix();
	//목성
	glPushMatrix();
		glRotatef((GLfloat)Jupiter, 0.0, 1.0, 0.0);
		glPushMatrix();
			glTranslatef(0.52, 0.0, 0.0);
			glColor3f(1.0, 1.0, 1.0);
			text("Jupiter ", 0.0, 0.05, 0.0);
			glRotatef((GLfloat)Jupiter, 0.0, 1.0, 0.0);
			glColor3f(0.3, 0.4, 0.2);
			glutSolidSphere(0.02, 10, 8);
		glPopMatrix();
	glPopMatrix();
	//토성
	glPushMatrix();
		glRotatef((GLfloat)Satrun, 0.0, 1.0, 0.0);
		glPushMatrix();
			glTranslatef(0.57, 0.0, 0.0);
			glColor3f(1.0, 1.0, 1.0);
			text("Satrun ", 0.0, 0.05, 0.0);
			glRotatef((GLfloat)Satrun, 0.0, 1.0, 0.0);
			glColor3f(0.0, 0.7, 1.0);
			glutSolidSphere(0.02, 10, 8);
		glPopMatrix();
	glPopMatrix();
	//천왕성
	glPushMatrix();
		glRotatef((GLfloat)Uranus, 0.0, 1.0, 0.0);
		glPushMatrix();
			glTranslatef(0.62, 0.0, 0.0);
			glColor3f(1.0, 1.0, 1.0);
			text("Uranus ", 0.0, 0.05, 0.0);
			glRotatef((GLfloat)Uranus, 0.0, 1.0, 0.0);
			glColor3f(0.3, 0.7, 0.5);
			glutSolidSphere(0.02, 10, 8);
		glPopMatrix();
	glPopMatrix();
	//해왕성
	glPushMatrix();
		glRotatef((GLfloat)Neptune, 0.0, 1.0, 0.0);
		glPushMatrix();
			glTranslatef(0.67, 0.0, 0.0);
			glColor3f(1.0, 1.0, 1.0);
			text("Neptune ", 0.0, 0.05, 0.0);
			glRotatef((GLfloat)Neptune, 0.0, 1.0, 0.0);
			glColor3f(0.5, 0.3, 1.0);
			glutSolidSphere(0.02, 10, 8);
		glPopMatrix();
	glPopMatrix();
}
void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(eyeX, eyeY, eyeZ, centerX, centerY, centerZ, 0.0, 1.0, 0.0);
	glRotatef(xRot, 1.0f, 0.0f, 0.0f);
	glRotatef(yRot, 0.0f, 1.0f, 0.0f);
	InitLight();
	Draw();
	glFlush();
}
void MyReshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(10, (GLdouble)w / (GLdouble)h, 0.1, 1000);
	glutPostRedisplay();
}
void MyKeyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 'q':
	case 'Q':
		exit(0);
		break;
	case 'm':
	case 'M':
		keyDown = !keyDown;
	default:
		break;
	}
	glutPostRedisplay();
}
void MySpecialKey(int key, int x, int y) {
	if (keyDown == false) {
		switch (key) {
		case GLUT_KEY_UP:
			eyeZ += 0.1;
			centerZ += 0.1;
			break;
		case GLUT_KEY_DOWN:
			eyeZ -= 0.1;
			centerZ -= 0.1;
			break;
		case GLUT_KEY_LEFT:
			eyeX -= 0.01;
			centerX -= 0.01;
			break;
		case GLUT_KEY_RIGHT:
			eyeX += 0.01;
			centerX += 0.01;
			break;
		default:
			break;
		}
	}
	else {
		switch (key)
		{
		case GLUT_KEY_UP:
			xRot -= 1.0;
			break;
		case GLUT_KEY_DOWN:
			xRot += 1.0;
			break;
		case GLUT_KEY_LEFT:
			yRot -= 1.0;
			break;
		case GLUT_KEY_RIGHT:
			yRot += 1.0;
			break;
		default:
			break;
		}
		if (key > 356.0f)
			xRot = 0.0f;
		if (key < -1.0f)
			xRot = 355.0f;
		if (key > 356.0f)
			yRot = 0.0f;
		if (key < -1.0f)
			yRot = 355.0f;
	}

	glutPostRedisplay();
}
void MyTimer(int value) {
	Sun = (Sun + 10) % 360;
	Mercury = (Mercury + 4) % 360;
	Venus = (Venus + 3) % 360;
	Earth = (Earth + 1) % 360;
	Moon = (Moon + 1) % 360;
	Mars = (Mars + 2) % 360;
	Jupiter = (Jupiter + 1) % 360;
	Satrun = (Satrun + 1) % 360;
	Uranus = (Uranus + 2) % 360;
	Neptune = (Neptune + 1) % 360;
	glutPostRedisplay();
	glutTimerFunc(10, MyTimer, 1);
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800, 700);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("OpenGL Sample Drawing");
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_DEPTH_TEST);
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glutDisplayFunc(MyDisplay);
	glutReshapeFunc(MyReshape);
	glutKeyboardFunc(MyKeyboard);
	glutSpecialFunc(MySpecialKey);
	glutTimerFunc(10, MyTimer, 1);
	glutMainLoop();
	return 0;
}