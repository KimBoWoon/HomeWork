#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <glut.h>
// Rotation amounts
static GLfloat xRot = 15.01f;
static GLfloat yRot = 340.0f;
static GLfloat posx, posy;

static GLfloat nRange = 50.f;

// ������ �ʿ��� ���� ����

static GLfloat MercuryY = 90.0f;
static GLfloat VenusY = 320.0f;
static GLfloat EarthY = 120.0f;
static GLfloat MarsY = 280.0f;
static GLfloat JupiterY = 340.0f;
static GLfloat SaturnY = 180.0f;
static GLfloat UranusY = 110.0f;
static GLfloat NeptuneY = 220.0f;
static GLfloat PlutoY = 60.0f;

// ������ �ʿ��� ���� ����
static GLfloat planetRoy = 0.0f;
static GLfloat planetRoz = 0.0f;
static GLfloat planetSpiny = 0.0f;
static GLfloat planetSpinz = 0.0f;
static GLfloat planety = 0.0f;

#define checkImageWidth 256   // ���� �̹��� �ȼ� ũ�� - ����
#define checkImageHeight 256  // ���� �̹��� �ȼ� ũ�� - ����
#define division_n 200         // ����� ��ŭ�� ������� ������ΰ�

typedef float point3[3];
static GLubyte checkImage[checkImageHeight][checkImageWidth][4];
static GLuint texName;


// Light values and coordinates
GLfloat  ambientLight[] = { 0.3f, 0.3f, 0.3f, 1.0f };
GLfloat  diffuseLight[] = { 0.7f, 0.7f, 0.7f, 1.0f };
GLfloat  specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat  specref[] = { 1.0f, 1.0f, 1.0f, 1.0f };

static int iPlanet = 3;
static int mouseon;




void SunRotation(void)
{
	glPushMatrix();
	glColor3ub(230, 50, 0);
	glutWireSphere(30.0, 25, 25);
	glPopMatrix();
}

void MercuryRotation(void)
{
	glPushMatrix();
	glColor3ub(250.0, 50.0, 50.0);
	glutWireSphere(30.0, 25, 25);
	glPopMatrix();
}

void VenusRotation(void)
{
	glPushMatrix();
	glColor3ub(255, 110, 0);
	glutWireSphere(30.0, 25, 25);
	glPopMatrix();
}

void EarthRotation(void)
{
	glPushMatrix();
	glColor3ub(60, 90, 250);
	glutWireSphere(30.0, 25, 25);
	glPopMatrix();
}

void MarsRotation(void)
{
	glPushMatrix();
	glColor3ub(230, 50, 30);
	glutWireSphere(30.0, 25, 25);
	glPopMatrix();
}

void JupiterRotation(void)
{
	glPushMatrix();
	glColor3ub(90, 110, 160);
	glutWireSphere(30.0, 25, 25);
	glPopMatrix();
}

void SaturnRotation(void)
{
	glPushMatrix();
	glColor3ub(130, 80, 30);
	glutWireSphere(30.0, 25, 25);
	glPopMatrix();
}

void UranusRotation(void)
{
	glPushMatrix();
	glColor3ub(80, 150, 240);
	glutWireSphere(30.0, 25, 25);
	glPopMatrix();
}

void NeptuneRotation(void)
{
	glPushMatrix();
	glColor3ub(60, 110, 200);
	glutWireSphere(30.0, 25, 25);
	glPopMatrix();
}

void PlutoRotation(void)
{
	glPushMatrix();
	glColor3ub(130, 220, 250);
	glutWireSphere(30.0, 25, 25);
	glPopMatrix();
}

// Reset flags as appropriate in response to menu selections
void ProcessMenu(int value)
{
	iPlanet = value;
	printf("%d select \n", value);
	switch (iPlanet)
	{
	case 1:
		xRot = 90;
		yRot = 0;
		break;
	case 2:
		xRot = 0;
		yRot = 90;
		break;
	case 3:
		xRot = 15;
		yRot = 340;
		break;
	case 4:
		planetSpiny = 0.4;
		planetRoz = 0.0;
		break;
	case 5:
		planetSpiny = 0.2;
		planetRoz = -0.1;
		nRange = 10.0f;
		break;
	case 6:
		planetSpiny = 0.09;
		planetRoz = -357.0;
		nRange = 10.0f;
		break;
	case 7:
		planetSpiny = 1.0;
		planetRoz = -23.0;
		nRange = 10.0f;
		break;
	case 8:
		planetSpiny = 0.9;
		planetRoz = -25.0;
		nRange = 10.0f;
		break;
	case 9:
		planetSpiny = 2.43;
		planetRoz = -3.0;
		nRange = 10.0f;
		break;
	case 10:
		planetSpiny = 2.34;
		planetRoz = -27.0;
		nRange = 10.0f;
		break;
	case 11:
		planetSpiny = 1.34;
		planetRoz = -98.0;
		nRange = 10.0f;
		break;
	case 12:
		planetSpiny = 1.25;
		planetRoz = -30.0;
		nRange = 10.0f;
		break;
	case 13:
		planetSpiny = 0.156;
		planetRoz = -120.0;
		nRange = 10.0f;
		break;
	}
	glutPostRedisplay();
}


void makeMercury(void)
{
	glPushMatrix();
	glColor3ub(255, 0, 0);
	glTranslatef(0, 0, -7);
	glutSolidSphere(0.6f, 25, 25);
	glPopMatrix();
}

void makeVenus(void)
{
	glPushMatrix();
	glColor3ub(255, 110, 0);
	glTranslatef(0, 0, -10);
	glutSolidSphere(1.8f, 25, 25);
	glPopMatrix();
}

void makeEarth(void)
{
	glPushMatrix();
	glColor3ub(60, 90, 250);
	glTranslatef(0, 0, -14.2);
	glutSolidSphere(1.9f, 25, 25);
	glPopMatrix();
}

void makeMars(void)
{
	glPushMatrix();
	glColor3ub(230, 50, 30);
	glTranslatef(0, 0, -17.8);
	glutSolidSphere(1.0f, 25, 25);
	glPopMatrix();
}

void makeJupiter(void)
{
	glPushMatrix();
	glColor3ub(90, 110, 160);
	glTranslatef(0, 0, -23);
	glutSolidSphere(3.8f, 25, 25);
	glPopMatrix();
}

void makeSaturn(void)
{
	glPushMatrix();
	glColor3ub(130, 80, 30);
	glTranslatef(0, 0, -31);
	glutSolidSphere(3.4f, 25, 25);
	glPopMatrix();
}

void makeUranus(void)
{
	glPushMatrix();
	glColor3ub(80, 150, 240);
	glTranslatef(0, 0, -38);
	glutSolidSphere(2.5f, 25, 25);
	glPopMatrix();
}

void makeNeptune(void)
{
	glPushMatrix();
	glColor3ub(60, 110, 200);
	glTranslatef(0, 0, -44);
	glutSolidSphere(2.4f, 25, 25);
	glPopMatrix();
}

void makePluto(void)
{
	glPushMatrix();
	glColor3ub(130, 220, 250);
	glTranslatef(0, 0, -48);
	glutSolidSphere(0.5f, 25, 25);
	glPopMatrix();
}

void spin(void)
{
	MercuryY += 4.09f;
	VenusY += 1.602f;
	EarthY += 1.0f;
	MarsY += 0.72f;
	JupiterY += 0.5f;
	SaturnY += 0.38f;
	UranusY += 0.2f;
	NeptuneY += 0.1f;
	PlutoY += 0.05f;

	if (MercuryY > 360) MercuryY -= 360;
	else if (VenusY > 360) VenusY -= 360;
	else if (EarthY > 360) EarthY -= 360;
	else if (MarsY > 360) MarsY -= 360;
	else if (JupiterY > 360) JupiterY -= 360;
	else if (SaturnY > 360) SaturnY -= 360;
	else if (UranusY > 360) UranusY -= 360;
	else if (NeptuneY > 360) NeptuneY -= 360;
	else if (PlutoY > 360) PlutoY -= 360;

	glutPostRedisplay();
	//�� �༺���� ������ �޸��ؼ� ���������� ���Ѵ�.
}

void planetRotate(void)
{
	planetRoy += planetSpiny;
	//planetRoz = planetSpinz;
	glutPostRedisplay();
}



// Called to draw scene
void RenderScene(void)
{
	// Clear the window
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	if (1 <= iPlanet && iPlanet <= 3)
	{
		//background stars display
		srand((unsigned)time(NULL));
		int j = 0;
		int temp1 = 0;
		int temp2 = 0;
		while (j<1000)
		{

			j += 1;
			float x = rand() % 1000;
			float y = rand() % 750;
			if (j % 2 == 1)
			{
				temp1 = -x;
				temp2 = -y;

				x = temp1;
				y = temp2;
			}

			glColor3ub(rand() % 255, rand() % 255, rand() % 255);
			glBegin(GL_POLYGON);
			glVertex2f(x, y);
			glVertex2f(x - 0.1, y - 0.05);
			glVertex2f(x - 0.15, y - 0.15);
			glVertex2f(x - 0.1, y - 0.25);
			glVertex2f(x, y - 0.3);
			glVertex2f(x + 0.1, y - 0.25);
			glVertex2f(x + 0.15, y - 0.15);
			glVertex2f(x + 0.1, y - 0.05);
			glEnd();
		}

		// Save matrix state and do the rotation
		glPushMatrix();

		glRotatef(xRot, 1.0f, 0.0f, 0.0f);
		glRotatef(yRot, 0.0f, 1.0f, 0.0f);
		glColor3ub(230, 50, 0);
		glutSolidSphere(6.0f, 25, 25);

		int i = 0;
		int xpoint = 50;
		int zpoint = 50;

		while (i <= 10)
		{
			i++;
			glBegin(GL_LINES);
			glVertex3d(xpoint, -10, 50);
			glVertex3d(xpoint, -10, -50);

			glVertex3d(50, -10, zpoint);
			glVertex3d(-50, -10, zpoint);
			glEnd();

			xpoint -= 10;
			zpoint -= 10;

		}

		// Restore transformations
		glPushMatrix();
		glRotatef(MercuryY, 0.0f, 1.0f, 0.0f);
		makeMercury();
		glPopMatrix();

		glPushMatrix();
		glRotatef(VenusY, 0.0f, 1.0f, 0.0f);
		makeVenus();
		glPopMatrix();

		glPushMatrix();
		glRotatef(EarthY, 0.0f, 1.0f, 0.0f);
		makeEarth();
		glPopMatrix();

		glPushMatrix();
		glRotatef(MarsY, 0.0f, 1.0f, 0.0f);
		makeMars();
		glPopMatrix();

		glPushMatrix();
		glRotatef(JupiterY, 0.0f, 1.0f, 0.0f);
		makeJupiter();
		glPopMatrix();

		glPushMatrix();
		glRotatef(SaturnY, 0.0f, 1.0f, 0.0f);
		makeSaturn();
		glPopMatrix();

		glPushMatrix();
		glRotatef(UranusY, 0.0f, 1.0f, 0.0f);
		makeUranus();
		glPopMatrix();

		glPushMatrix();
		glRotatef(NeptuneY, 0.0f, 1.0f, 0.0f);
		makeNeptune();
		glPopMatrix();

		glPushMatrix();
		glRotatef(PlutoY, 0.0f, 1.0f, 0.0f);
		makePluto();
		glPopMatrix();

		glutIdleFunc(spin);
		glPopMatrix();

	}// �¾�� �׸��� ��� if ����

	else if (iPlanet == 4)
	{
		glLoadIdentity();
		gluLookAt(0.0, 0.0, -5, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
		//glTranslatef(0.0, 0.0, -5.0);    //  Z������ �� �������� �����Ѵ�.
		glPushMatrix();
		glRotatef(planetRoz, 0.0f, 0.0f, 1.0f);
		glRotatef(planetRoy, 0.0f, 1.0f, 0.0f);
		SunRotation();
		glBegin(GL_LINES);
		glColor3ub(0, 255, 0);
		glVertex3d(0.0, -55.0, 0.0);
		glVertex3d(0.0, 55.0, 0.0);
		glEnd();
		glutIdleFunc(planetRotate);
		glPopMatrix();
	}
	else if (iPlanet == 5)
	{
		glPushMatrix();
		glRotatef(planetRoz, 0.0f, 0.0f, 1.0f);
		glRotatef(planetRoy, 0.0f, 1.0f, 0.0f);
		MercuryRotation();
		glBegin(GL_LINES);
		glColor3ub(0, 255, 0);
		glVertex3d(0.0, -55.0, 0.0);
		glVertex3d(0.0, 55.0, 0.0);
		glEnd();
		glutIdleFunc(planetRotate);
		glPopMatrix();
	}
	else if (iPlanet == 6)
	{
		glPushMatrix();
		glRotatef(planetRoz, 0.0f, 0.0f, 1.0f);
		glRotatef(planetRoy, 0.0f, 1.0f, 0.0f);
		VenusRotation();
		glBegin(GL_LINES);
		glColor3ub(0, 255, 0);
		glVertex3d(0.0, -55.0, 0.0);
		glVertex3d(0.0, 55.0, 0.0);
		glEnd();
		glutIdleFunc(planetRotate);
		glPopMatrix();
	}
	else if (iPlanet == 7)
	{
		glPushMatrix();
		glRotatef(planetRoz, 0.0f, 0.0f, 1.0f);
		glRotatef(planetRoy, 0.0f, 1.0f, 0.0f);
		EarthRotation();
		glBegin(GL_LINES);
		glColor3ub(0, 255, 0);
		glVertex3d(0.0, -55.0, 0.0);
		glVertex3d(0.0, 55.0, 0.0);
		glEnd();
		glutIdleFunc(planetRotate);
		glPopMatrix();
	}
	else if (iPlanet == 8)
	{
		glPushMatrix();
		glRotatef(planetRoz, 0.0f, 0.0f, 1.0f);
		glRotatef(planetRoy, 0.0f, 1.0f, 0.0f);
		MarsRotation();
		glBegin(GL_LINES);
		glColor3ub(0, 255, 0);
		glVertex3d(0.0, -55.0, 0.0);
		glVertex3d(0.0, 55.0, 0.0);
		glEnd();
		glutIdleFunc(planetRotate);
		glPopMatrix();
	}
	else if (iPlanet == 9)
	{
		glPushMatrix();
		glRotatef(planetRoz, 0.0f, 0.0f, 1.0f);
		glRotatef(planetRoy, 0.0f, 1.0f, 0.0f);
		JupiterRotation();
		glBegin(GL_LINES);
		glColor3ub(0, 255, 0);
		glVertex3d(0.0, -55.0, 0.0);
		glVertex3d(0.0, 55.0, 0.0);
		glEnd();
		glutIdleFunc(planetRotate);
		glPopMatrix();
	}
	else if (iPlanet == 10)
	{
		glPushMatrix();
		glRotatef(planetRoz, 0.0f, 0.0f, 1.0f);
		glRotatef(planetRoy, 0.0f, 1.0f, 0.0f);
		SaturnRotation();
		glBegin(GL_LINES);
		glColor3ub(0, 255, 0);
		glVertex3d(0.0, -55.0, 0.0);
		glVertex3d(0.0, 55.0, 0.0);
		glEnd();
		glutIdleFunc(planetRotate);
		glPopMatrix();
	}
	else if (iPlanet == 11)
	{
		glPushMatrix();
		glRotatef(planetRoz, 0.0f, 0.0f, 1.0f);
		glRotatef(planetRoy, 0.0f, 1.0f, 0.0f);
		UranusRotation();
		glBegin(GL_LINES);
		glColor3ub(0, 255, 0);
		glVertex3d(0.0, -55.0, 0.0);
		glVertex3d(0.0, 55.0, 0.0);
		glEnd();
		glutIdleFunc(planetRotate);
		glPopMatrix();
	}
	else if (iPlanet == 12)
	{
		glPushMatrix();
		glRotatef(planetRoz, 0.0f, 0.0f, 1.0f);
		glRotatef(planetRoy, 0.0f, 1.0f, 0.0f);
		NeptuneRotation();
		glBegin(GL_LINES);
		glColor3ub(0, 255, 0);
		glVertex3d(0.0, -55.0, 0.0);
		glVertex3d(0.0, 55.0, 0.0);
		glEnd();
		glutIdleFunc(planetRotate);
		glPopMatrix();
	}
	else if (iPlanet == 13)
	{
		glPushMatrix();
		glRotatef(planetRoz, 0.0f, 0.0f, 1.0f);
		glRotatef(planetRoy, 0.0f, 1.0f, 0.0f);
		PlutoRotation();
		glBegin(GL_LINES);
		glColor3ub(0, 255, 0);
		glVertex3d(0.0, -55.0, 0.0);
		glVertex3d(0.0, 55.0, 0.0);
		glEnd();
		glutIdleFunc(planetRotate);
		glPopMatrix();
	}

	// Flush drawing commands
	glutSwapBuffers();
}

// This function does any needed initialization on the rendering
// context. 

void SetupRC()
{
	// Enable Depth Testing
	glEnable(GL_DEPTH_TEST);

	// Enable lighting
	glEnable(GL_LIGHTING);

	// Setup and enable light 0
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
	glEnable(GL_LIGHT0);

	// Enable color tracking
	glEnable(GL_COLOR_MATERIAL);

	// Set Material properties to follow glColor values
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

	// All materials hereafter have full specular reflectivity
	// with a high shine
	glMaterialfv(GL_FRONT, GL_SPECULAR, specref);
	glMateriali(GL_FRONT, GL_SHININESS, 128);

}

void SpecialKeys(int key, int x, int y)
{
	if (key == GLUT_KEY_UP)
		xRot -= 5.0f;

	if (key == GLUT_KEY_DOWN)
		xRot += 5.0f;

	if (key == GLUT_KEY_LEFT)
		yRot -= 5.0f;

	if (key == GLUT_KEY_RIGHT)
		yRot += 5.0f;

	if (key > 356.0f)
		xRot = 0.0f;

	if (key < -1.0f)
		xRot = 355.0f;

	if (key > 356.0f)
		yRot = 0.0f;

	if (key < -1.0f)
		yRot = 355.0f;

	// Refresh the Window
	glutPostRedisplay();
}

void position(int x, int y)
{
	// ���콺�� ������ ���⿡ ���� 5���� ������ x,y�������� ���ϰų� ���ش�.
	if (mouseon == 1){
		if (x > posx) yRot += 4.0f;
		else if (x < posx) yRot -= 4.0f;

		if (y > posy) xRot += 4.0f;
		else if (y < posy) xRot -= 4.0f;

		posx = x;
		posy = y;
	}
	glutPostRedisplay();
}


void mouse(int btn, int state, int x, int y)
{
	if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//mouseon���������� �ξ� position���� ������������, ȸ���ϵ��� ���ش�.
		mouseon = 1;
		posx = x;
		posy = y;

	}
	else mouseon = 0;
}

void ChangeSize(int w, int h)
{
	printf("ChangeSize call, nRange=%f", nRange);
	GLfloat  lightPos[] = { -50.f, 50.0f, 100.0f, 1.0f };
	//nRange = 50.f;

	// Prevent a divide by zero
	if (h == 0)
		h = 1;

	// Set Viewport to window dimensions
	glViewport(0, 0, w, h);

	// Reset projection matrix stack
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// Establish clipping volume (left, right, bottom, top, near, far)
	if (w <= h)
		glOrtho(-nRange, nRange, -nRange*h / w, nRange*h / w, -nRange, nRange);
	else
		glOrtho(-nRange*w / h, nRange*w / h, -nRange, nRange, -nRange, nRange);

	// Reset Model view matrix stack
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
}

int main(int argc, char* argv[])
{
	int nSolidMenu;
	int nWireMenu;
	int nMainMenu;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1000, 750);
	glutCreateWindow("The Solar System");
	//init();

	// Create the Menu
	nWireMenu = glutCreateMenu(ProcessMenu);
	glutAddMenuEntry("up", 1);
	glutAddMenuEntry("side", 2);
	glutAddMenuEntry("quarter view", 3);

	nSolidMenu = glutCreateMenu(ProcessMenu);
	glutAddMenuEntry("Sun", 4);
	glutAddMenuEntry("Mercury", 5);
	glutAddMenuEntry("Venus", 6);
	glutAddMenuEntry("Earth", 7);
	glutAddMenuEntry("Mars", 8);
	glutAddMenuEntry("Jupiter", 9);
	glutAddMenuEntry("Saturn", 10);
	glutAddMenuEntry("Uranus", 11);
	glutAddMenuEntry("Neptune", 12);
	glutAddMenuEntry("Pluto", 13);

	nMainMenu = glutCreateMenu(ProcessMenu);
	glutAddSubMenu("The Solar System", nWireMenu);
	glutAddSubMenu("The Planet's Rotation", nSolidMenu);
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	glutReshapeFunc(ChangeSize);
	glutDisplayFunc(RenderScene);
	glutMouseFunc(mouse);
	glutMotionFunc(position);
	glutSpecialFunc(SpecialKeys);

	SetupRC();

	glutMainLoop();

	return 0;
}
//#include "glut.h"
//static void MyDisplay();
//
//int main(int argc, char* argv[]) {
//	glutCreateWindow("OpenGL Drawing Example");
//	glutDisplayFunc(MyDisplay);
//	glutMainLoop();
//	return 0;
//}
//void MyDisplay() {
//	glClear(GL_COLOR_BUFFER_BIT);
//	glBegin(GL_POLYGON);
//	glVertex3f(-0.5, -0.5, 0.0);
//	glVertex3f(0.5, -0.5, 0.0);
//	glVertex3f(0.5, 0.5, 0.0);
//	glVertex3f(-0.5, 0.5, 0.0);
//
//	glEnd();
//	glFlush();
//}