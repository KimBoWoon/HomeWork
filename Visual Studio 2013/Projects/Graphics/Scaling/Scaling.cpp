#include <memory>
#include "glut.h"
#include <gl\GL.h>
#include <gl\GLU.h>

static float ScaleRatio = 1.0f;
static const float SACLE_FACTOR = 0.1f;

static GLfloat My3DCubeV[8][3] = {
	{ -0.25, -0.25, -0.25 },
	{ 0.25, -0.25, -0.25 },
	{ 0.25, 0.25, -0.25 },
	{ -0.25, 0.25, -0.25 },
	{ -0.25, -0.25, 0.25 },
	{ 0.25, -0.25, 0.25 },
	{ 0.25, 0.25, 0.25 },
	{ -0.25, 0.25, 0.25 },
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

GLfloat** Scale(GLfloat(*scale)[3], GLfloat(*cubeV)[3]);
static void MyDisplay();
static void MyReshape(const int newWidth, const int newHeight);
static void MySpecialKey(int key, int x, int y);

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(300, 300);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("OpenGL Scaling Drawing");
	glLoadIdentity();
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glOrtho(-1.0, 1.0, -1.0, 1.0, 1.0, -1.0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glutSpecialFunc(MySpecialKey);
	glutReshapeFunc(MyReshape);
	glutDisplayFunc(MyDisplay);
	glutMainLoop();
	return 0;
}
GLfloat** Scale(GLfloat(*scale)[3], GLfloat(*cubeV)[3]) {
	GLfloat** result = new GLfloat*[8];
	for (int i = 0; i < 8; i++) {
		result[i] = new GLfloat[3];
		memset(result[i], 0, sizeof(GLfloat) * 3);
	}

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				result[i][j] += cubeV[i][k] * scale[k][j];
			}
		}
	}

	return result;
}
static void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);

	GLfloat scale[3][3] = {
		{ ScaleRatio, 0.0, 0.0 },
		{ 0.0, ScaleRatio, 0.0 },
		{ 0.0, 0.0, ScaleRatio }
	};

	glRotatef(30.0, 1.0, 1.0, 0.0);

	GLfloat** scaled = Scale(scale, My3DCubeV);

	glEnableClientState(GL_COLOR_ARRAY);
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, scaled);
	glColorPointer(3, GL_FLOAT, 0, MyColor);

	glBegin(GL_QUADS);
	glColor3fv(MyColor[0]);	glVertex3fv(scaled[0]);
	glColor3fv(MyColor[3]);	glVertex3fv(scaled[3]);
	glColor3fv(MyColor[7]);	glVertex3fv(scaled[7]);
	glColor3fv(MyColor[4]);	glVertex3fv(scaled[4]);

	glColor3fv(MyColor[3]);	glVertex3fv(scaled[3]);
	glColor3fv(MyColor[7]);	glVertex3fv(scaled[7]);
	glColor3fv(MyColor[6]);	glVertex3fv(scaled[6]);
	glColor3fv(MyColor[2]);	glVertex3fv(scaled[2]);

	glColor3fv(MyColor[0]);	glVertex3fv(scaled[0]);
	glColor3fv(MyColor[4]);	glVertex3fv(scaled[4]);
	glColor3fv(MyColor[5]);	glVertex3fv(scaled[5]);
	glColor3fv(MyColor[1]);	glVertex3fv(scaled[1]);

	glColor3fv(MyColor[1]);	glVertex3fv(scaled[1]);
	glColor3fv(MyColor[2]);	glVertex3fv(scaled[2]);
	glColor3fv(MyColor[6]);	glVertex3fv(scaled[6]);
	glColor3fv(MyColor[5]);	glVertex3fv(scaled[5]);

	glColor3fv(MyColor[7]);	glVertex3fv(scaled[7]);
	glColor3fv(MyColor[4]);	glVertex3fv(scaled[4]);
	glColor3fv(MyColor[5]);	glVertex3fv(scaled[5]);
	glColor3fv(MyColor[6]);	glVertex3fv(scaled[6]);

	glColor3fv(MyColor[0]);	glVertex3fv(scaled[0]);
	glColor3fv(MyColor[3]);	glVertex3fv(scaled[3]);
	glColor3fv(MyColor[2]);	glVertex3fv(scaled[2]);
	glColor3fv(MyColor[1]);	glVertex3fv(scaled[1]);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3fv(My3DCubeV[0]);
	glVertex3fv(My3DCubeV[3]);
	glVertex3fv(My3DCubeV[7]);
	glVertex3fv(My3DCubeV[4]);

	glVertex3fv(My3DCubeV[3]);
	glVertex3fv(My3DCubeV[7]);
	glVertex3fv(My3DCubeV[6]);
	glVertex3fv(My3DCubeV[2]);

	glVertex3fv(My3DCubeV[0]);
	glVertex3fv(My3DCubeV[4]);
	glVertex3fv(My3DCubeV[5]);
	glVertex3fv(My3DCubeV[1]);

	glVertex3fv(My3DCubeV[1]);
	glVertex3fv(My3DCubeV[2]);
	glVertex3fv(My3DCubeV[6]);
	glVertex3fv(My3DCubeV[5]);

	glVertex3fv(My3DCubeV[7]);
	glVertex3fv(My3DCubeV[4]);
	glVertex3fv(My3DCubeV[5]);
	glVertex3fv(My3DCubeV[6]);

	glVertex3fv(My3DCubeV[0]);
	glVertex3fv(My3DCubeV[3]);
	glVertex3fv(My3DCubeV[2]);
	glVertex3fv(My3DCubeV[1]);
	glEnd();
	glFlush();
}
static void MyReshape(const int newWidth, const int newHeight) {
	glViewport(0, 0, newWidth, newHeight);
	GLfloat WidthFactor = (GLfloat)newWidth / (GLfloat)300;
	GLfloat HeightFactor = (GLfloat)newHeight / (GLfloat)300;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0 * WidthFactor, 1.0 * WidthFactor, -1.0 * HeightFactor, 1.0 * HeightFactor, -1.0, 1.0);
}
static void MySpecialKey(int key, int x, int y) {
	if (key == GLUT_KEY_UP)
		ScaleRatio += SACLE_FACTOR;
	else if (key == GLUT_KEY_DOWN)
		ScaleRatio -= SACLE_FACTOR;

	glutPostRedisplay();
}