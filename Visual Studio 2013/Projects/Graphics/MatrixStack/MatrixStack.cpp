#include <glut.h>
#include <gl\GL.h>
#include <gl\GLU.h>

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glViewport(0, 0, 300, 300);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	//glPushMatrix();
	glRotatef(45.0, 0.0, 0.0, 1.0);
	glTranslatef(0.6, 0.0, 0.0);
	glutWireCube(0.3);
	//glPopMatrix();
	//glPushMatrix();
	//glTranslatef(-0.6, 0.0, 0.0);
	//glRotatef(-45.0, 0.0, 0.0, 1.0);
	//glPopMatrix();
	glFlush();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA);
	glutInitWindowSize(300, 300);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("OpenGL Sample Drawing");
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
	glutDisplayFunc(MyDisplay);
	glutMainLoop();
	return 0;
}