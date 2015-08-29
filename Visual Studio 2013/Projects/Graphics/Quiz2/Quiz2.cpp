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

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glEnableClientState(GL_COLOR_ARRAY);
	glEnableClientState(GL_VERTEX_ARRAY);
	glColorPointer(3, GL_FLOAT, 0, MyColor);
	glVertexPointer(3, GL_FLOAT, 0, MyVertices);
	glRotatef(30.0, 1.0, 1.0, 1.0);
	//glEnable(GL_CULL_FACE);
	//glCullFace(GL_FRONT);
	glBegin(GL_POLYGON);

	glColor3fv(MyColor[0]);	glVertex3fv(MyVertices[0]);
	glColor3fv(MyColor[3]);	glVertex3fv(MyVertices[3]);
	glColor3fv(MyColor[7]);	glVertex3fv(MyVertices[7]);
	glColor3fv(MyColor[4]);	glVertex3fv(MyVertices[4]);

	glColor3fv(MyColor[3]);	glVertex3fv(MyVertices[3]);
	glColor3fv(MyColor[7]);	glVertex3fv(MyVertices[7]);
	glColor3fv(MyColor[6]);	glVertex3fv(MyVertices[6]);
	glColor3fv(MyColor[2]);	glVertex3fv(MyVertices[2]);

	glColor3fv(MyColor[0]);	glVertex3fv(MyVertices[0]);
	glColor3fv(MyColor[4]);	glVertex3fv(MyVertices[4]);
	glColor3fv(MyColor[5]);	glVertex3fv(MyVertices[5]);
	glColor3fv(MyColor[1]);	glVertex3fv(MyVertices[1]);

	glColor3fv(MyColor[1]);	glVertex3fv(MyVertices[1]);
	glColor3fv(MyColor[2]);	glVertex3fv(MyVertices[2]);
	glColor3fv(MyColor[6]);	glVertex3fv(MyVertices[6]);
	glColor3fv(MyColor[5]);	glVertex3fv(MyVertices[5]);

	glColor3fv(MyColor[7]);	glVertex3fv(MyVertices[7]);
	glColor3fv(MyColor[4]);	glVertex3fv(MyVertices[4]);
	glColor3fv(MyColor[5]);	glVertex3fv(MyVertices[5]);
	glColor3fv(MyColor[6]);	glVertex3fv(MyVertices[6]);

	glColor3fv(MyColor[0]);	glVertex3fv(MyVertices[0]);
	glColor3fv(MyColor[3]);	glVertex3fv(MyVertices[3]);
	glColor3fv(MyColor[2]);	glVertex3fv(MyVertices[2]);
	glColor3fv(MyColor[1]);	glVertex3fv(MyVertices[1]);

	glEnd();
	glFlush();
}
int main(int argc, char** argv) {
	glutCreateWindow("OpenGL Sample Drawing");
	glutDisplayFunc(MyDisplay);
	glutMainLoop();
	return 0;
}