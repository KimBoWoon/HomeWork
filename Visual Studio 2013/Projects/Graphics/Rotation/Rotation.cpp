#include "glut.h"
#include <cmath>
#include <gl\GL.h>
#include <gl\GLU.h>

const GLdouble pi = 3.13159;

class wcPt2D {
public:
	GLfloat x, y;
};
void rotatePolygon(wcPt2D* verts, GLint nVerts, wcPt2D pivPt, GLdouble theta) {
	wcPt2D* vertsRot = new wcPt2D[nVerts];
	GLint k;

	for (k = 0; k < nVerts; k++) {
		vertsRot[k].x = pivPt.x + (verts[k].x - pivPt.x) * cos(theta) - (verts[k].y - pivPt.y) * sin(theta);
		vertsRot[k].y = pivPt.y + (verts[k].x - pivPt.x) * sin(theta) + (verts[k].y - pivPt.y) * cos(theta);
	}
	glBegin(GL_POLYGON);
	for (k = 0; k < nVerts; k++) {
		glVertex2f(vertsRot[k].x, vertsRot[k].y);
	}
	glEnd();
	delete[] vertsRot;
}
void OriginPolygon(wcPt2D* verts, GLint nVerts) {
	GLint k;

	glBegin(GL_POLYGON);
	for (k = 0; k < nVerts; k++) {
		glVertex2f(verts[k].x, verts[k].y);
	}
	glEnd();
}
void MyDisplay() {
	wcPt2D wc1[3];
	wcPt2D pivPt;

	wc1[0].x = 3.0;
	wc1[0].y = 3.0;
	wc1[1].x = 3.0;
	wc1[1].y = 20.0;
	wc1[2].x = 20.0;
	wc1[2].y = 3.0;

	pivPt.x = 30.0;
	pivPt.y = 30.0;

	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	OriginPolygon(wc1, 3);
	rotatePolygon(wc1, 3, pivPt, 90);
	glFlush();
}
int main() {
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("OpenGL Sample Drawing");
	gluOrtho2D(0.0, 200.0, 0.0, 200.0);
	glutDisplayFunc(MyDisplay);
	glutMainLoop();
}