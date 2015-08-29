#include <cmath>
#include <glut.h>
#include <gl\GL.h>
#include <gl\GLU.h>

#define Pi 3.1415

void MyDisplay() {
	GLint ScaleFaactor = 1;
	GLushort Pattern = 0x00FF;
	GLfloat Height;
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);
	glLineWidth(3);
	glEnable(GL_LINE_STIPPLE);
	for (Height = -0.9; Height <= 0.9; Height += 0.4) {
		glLineStipple(ScaleFaactor, Pattern);
		glBegin(GL_LINES);
		glVertex3f(-1.0, Height, 0.0);
		glVertex3f(1.0, Height, 0.0);
		glEnd();
		ScaleFaactor *= 2;
	}
	glDisable(GL_LINE_STIPPLE);
	glFlush();
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("OpenGL Sample Drawing");
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
	glutDisplayFunc(MyDisplay);
	glutMainLoop();
	return 0;
}