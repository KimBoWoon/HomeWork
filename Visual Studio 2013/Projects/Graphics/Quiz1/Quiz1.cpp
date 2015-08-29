#include <glut.h>
#include <gl\GL.h>
#include <gl\GLU.h>

GLfloat MyVertices[8][3] = {
	{ -0.25, -0.25, 0.25 },
	{ -0.25, 0.25, 0.25 },
	{ 0.25, 0.25, 0.25 },
	{ 0.25, -0.25, 0.25 },
	{ -0.25, -0.25, -0.25 },
	{ -0.25, 0.25, -0.25 },
	{ 0.25, 0.25, -0.25 },
	{ 0.25, -0.25, -0.25 }
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
GLubyte MyVertexList[24] = { 3, 7, 6, 2, 0, 4, 7, 3, 4, 5, 6, 7, 0, 1, 5, 4, 1, 2, 6, 5, 0, 3, 2, 1};

void MyDisplay() {
	//glEnable(GL_CULL_FACE);
	//glCullFace(GL_FRONT);
	glClear(GL_COLOR_BUFFER_BIT);
	glEnableClientState(GL_COLOR_ARRAY);
	glEnableClientState(GL_VERTEX_ARRAY);
	glColorPointer(3, GL_FLOAT, 0, MyColor);
	glVertexPointer(3, GL_FLOAT, 0, MyVertices);
	glRotated(30.0, 1.0, 1.0, 1.0);
	for (GLint i = 0; i < 6; i++) {
		glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_BYTE, &MyVertexList[4 * i]);
	}
	glEnd();
	glFlush();
}
int main(int argc, char** argv) {
	glutCreateWindow("OpenGL Sample Drawing");
	glutDisplayFunc(MyDisplay);
	glutMainLoop();
	return 0;
}