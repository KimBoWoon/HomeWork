#define _USE_MATH_DEFINES

#include <iostream>
#include <memory>
#include <cmath>
#include "glut.h"
#include <gl\GL.h>
#include <gl\GLU.h>
using namespace std;

static const float xMax = 2.0;
static const float yMax = 2.0;
static const float zMax = 2.0;
static const int widthWindow = 900;
static const int heightWindow = 700;
static float ScaleRatio = 1.0f;
static const float SACLE_FACTOR = 0.1f;
float** result;

static float mat[8][3] = {
	{ 0.75, 0.75, -0.25 },
	{ 1.25, 0.75, -0.25 },
	{ 1.25, 1.25, -0.25 },
	{ 0.75, 1.25, -0.25 },
	{ 0.75, 0.75, 0.25 },
	{ 1.25, 0.75, 0.25 },
	{ 1.25, 1.25, 0.25 },
	{ 0.75, 1.25, 0.25 },
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

class Matrix {
private:
	float** matrix;
public:
	Matrix();
	Matrix(const float(*transpose)[3]);
	Matrix(const Matrix& mat);

	void Translate(float x, float y, float z);
	void rotate(float theta, float x, float y, float z);
	void RotateX(float theta);
	void RotateY(float theta);
	void RotateZ(float theta);
	void scale(float scale);
	void scale(float x, float y, float z);
	void ShearYZ(float y, float z);
	void ShearXZ(float x, float z);
	void ShearXY(float x, float y);

	const float** get() const;
	float operator[] (int index) const;
	float** operator* (float(*model)[3]) const;
	Matrix* operator*= (const Matrix& mat);
	friend ostream& operator<< (ostream& os, const Matrix& m);
};

Matrix::Matrix() {
	matrix = new float*[4];
	for (int i = 0; i < 4; i++)
		matrix[i] = new float[4];
	result = new float*[8];
	for (int i = 0; i < 8; i++) {
		result[i] = new float[4];
		memset(result[i], 0, sizeof(float) * 4);
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (i == j)
				matrix[i][i] = 1;
			else
				matrix[i][j] = 0;
		}
	}
}
Matrix::Matrix(const float(*transpose)[3]) {
	matrix = new float*[4];
	for (int i = 0; i < 4; i++) {
		matrix[i] = new float[4];
		memset(matrix[i], 0, sizeof(float) * 4);
	}
	result = new float*[8];
	for (int i = 0; i < 8; i++) {
		result[i] = new float[4];
		memset(result[i], 0, sizeof(float) * 4);
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++)
			matrix[i][j] = transpose[i][j];
	}
}
Matrix::Matrix(const Matrix& mat) {
	matrix = new float*[4];
	for (int i = 0; i < 4; i++) {
		matrix[i] = new float[4];
		memset(matrix[i], 0, sizeof(float) * 4);
	}
	matrix = mat.matrix;
	result = new float*[8];
	for (int i = 0; i < 8; i++) {
		result[i] = new float[4];
		memset(result[i], 0, sizeof(float) * 4);
	}
}
void Matrix::Translate(float x, float y, float z) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (i == j)
				matrix[i][i] = 1;
			else
				matrix[i][j] = 0;
		}
	}
	float trans[4][4] = {
		{ 1, 0, 0, x },
		{ 0, 1, 0, y },
		{ 0, 0, 1, z },
		{ 0, 0, 0, 1 },
	};
	float temp[4][4] = { 0 };
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++)
				temp[i][j] += matrix[j][k] * trans[i][k];
			cout << temp[i][j] << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			matrix[i][j] = temp[i][j];
		}
	}
}
void Matrix::rotate(float theta, float x, float y, float z) {
	if (x == 1.0)
		RotateX(theta);
	if (y == 1.0)
		RotateY(theta);
	if (z == 1.0)
		RotateZ(theta);
}
void Matrix::RotateX(float theta) {
	const float degree = theta * (M_PI / 180.);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (i == j)
				matrix[i][i] = 1;
			else
				matrix[i][j] = 0;
		}
	}

	float rot[4][4] = {
		{ 1, 0, 0, 0 },
		{ 0, cosf(degree), -sinf(degree), 0 },
		{ 0, sinf(degree), cosf(degree), 0 },
		{ 0, 0, 0, 1 },
	};
	float temp[4][4] = { 0 };
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++)
				temp[i][j] += matrix[j][k] * rot[i][k];
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			matrix[i][j] = temp[i][j];
		}
	}
	float tempmat[8][4] = { 0 };
	float arr[4][1] = { 0, 0, 0, 1 };
	for (int i = 0; i < 8; i++) {
		for (int q = 0; q < 3; q++) {
			arr[q][0] = mat[i][q];
		}
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				tempmat[i][j] += matrix[j][k] * arr[k][0];
			}
			cout << tempmat[i][j] << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 3; j++) {
			mat[i][j] = tempmat[i][j];
		}
	}
}
void Matrix::RotateY(float theta) {
	const float degree = theta * (M_PI / 180.);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (i == j)
				matrix[i][i] = 1;
			else
				matrix[i][j] = 0;
		}
	}

	float rot[4][4] = {
		{ cosf(degree), 0, sinf(degree), 0 },
		{ 0, 1, 0, 0 },
		{ -sinf(degree), 0, cosf(degree), 0 },
		{ 0, 0, 0, 1 },
	};
	float temp[4][4] = { 0 };
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++)
				temp[i][j] += matrix[j][k] * rot[i][k];
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			matrix[i][j] = temp[i][j];
		}
	}
	float tempmat[8][4] = { 0 };
	float arr[4][1] = { 0, 0, 0, 1 };
	for (int i = 0; i < 8; i++) {
		for (int q = 0; q < 3; q++) {
			arr[q][0] = mat[i][q];
		}
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				tempmat[i][j] += matrix[j][k] * arr[k][0];
			}
			cout << tempmat[i][j] << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 3; j++) {
			mat[i][j] = tempmat[i][j];
		}
	}
}
void Matrix::RotateZ(float theta) {
	const float degree = theta * (M_PI / 180.);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (i == j)
				matrix[i][i] = 1;
			else
				matrix[i][j] = 0;
		}
	}

	float rot[4][4] = {
		{ cosf(degree), -sinf(degree), 0, 0 },
		{ sinf(degree), cosf(degree), 0, 0 },
		{ 0, 0, 1, 0 },
		{ 0, 0, 0, 1 },
	};
	float temp[4][4] = { 0 };
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++)
				temp[i][j] += matrix[j][k] * rot[i][k];
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			matrix[i][j] = temp[i][j];
		}
	}
	float tempmat[8][4] = { 0 };
	float arr[4][1] = { 0, 0, 0, 1 };
	for (int i = 0; i < 8; i++) {
		for (int q = 0; q < 3; q++) {
			arr[q][0] = mat[i][q];
		}
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				tempmat[i][j] += matrix[j][k] * arr[k][0];
			}
			cout << tempmat[i][j] << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 3; j++) {
			mat[i][j] = tempmat[i][j];
		}
	}
}
void Matrix::scale(float scale) {
	/*GLfloat** result = new GLfloat*[8];
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

	return result;*/
}
void Matrix::scale(float x, float y, float z) {
	/*GLfloat** result = new GLfloat*[8];
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

	return result;*/
}
void Matrix::ShearYZ(float y, float z) {
	const float rot[4][4] = {
		{ 1, 0, 0, 0 },
		{ y, 1, 0, 0 },
		{ z, 0, 1, 0 },
		{ 0, 0, 0, 1 },
	};
	float temp[4][4] = { 0 };
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++)
				temp[i][j] += matrix[j][k] * rot[i][k];
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			matrix[i][j] = temp[i][j];
		}
	}
	float tempmat[8][4] = { 0 };
	float arr[4][1] = { 0, 0, 0, 1 };
	for (int i = 0; i < 8; i++) {
		for (int q = 0; q < 3; q++) {
			arr[q][0] = mat[i][q];
		}
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				tempmat[i][j] += matrix[j][k] * arr[k][0];
			}
			cout << tempmat[i][j] << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 3; j++) {
			mat[i][j] = tempmat[i][j];
		}
	}
}
void Matrix::ShearXZ(float x, float z) {
	const float rot[4][4] = {
		{ 1, x, 0, 0 },
		{ 0, 1, 0, 0 },
		{ 0, z, 1, 0 },
		{ 0, 0, 0, 1 },
	};
	float temp[4][4] = { 0 };
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++)
				temp[i][j] += matrix[j][k] * rot[i][k];
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			matrix[i][j] = temp[i][j];
		}
	}
	float tempmat[8][4] = { 0 };
	float arr[4][1] = { 0, 0, 0, 1 };
	for (int i = 0; i < 8; i++) {
		for (int q = 0; q < 3; q++) {
			arr[q][0] = mat[i][q];
		}
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				tempmat[i][j] += matrix[j][k] * arr[k][0];
			}
			cout << tempmat[i][j] << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 3; j++) {
			mat[i][j] = tempmat[i][j];
		}
	}
}
void Matrix::ShearXY(float x, float y) {
	const float rot[4][4] = {
		{ 1, 0, x, 0 },
		{ 0, 1, y, 0 },
		{ 0, 0, 1, 0 },
		{ 0, 0, 0, 1 },
	};
	float temp[4][4] = { 0 };
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++)
				temp[i][j] += matrix[j][k] * rot[i][k];
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			matrix[i][j] = temp[i][j];
		}
	}
	float tempmat[8][4] = { 0 };
	float arr[4][1] = { 0, 0, 0, 1 };
	for (int i = 0; i < 8; i++) {
		for (int q = 0; q < 3; q++) {
			arr[q][0] = mat[i][q];
		}
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				tempmat[i][j] += matrix[j][k] * arr[k][0];
			}
			cout << tempmat[i][j] << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 3; j++) {
			mat[i][j] = tempmat[i][j];
		}
	}
}

const float** Matrix::get() const {
	return NULL;
}
float Matrix::operator[] (int index) const {
	return 0;
}
float** Matrix::operator* (float(*model)[3]) const {
	float temp[8][4] = { 0 };
	float arr[4][1] = { 0, 0, 0, 1 };
	for (int i = 0; i < 8; i++) {
		for (int q = 0; q < 3; q++) {
			arr[q][0] = mat[i][q];
		}
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				temp[i][j] += matrix[j][k] * arr[k][0];
			}
			cout << temp[i][j] << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 3; j++) {
			mat[i][j] = temp[i][j];
		}
	}
	return NULL;
}
Matrix* Matrix::operator*= (const Matrix& mat) {
	return NULL;
}
ostream& operator<< (ostream& os, const Matrix& m) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++)
			os << m.matrix[i][j] << " ";
		os << endl;
	}
	
	return os;
}

static void MyDisplay();
static void MyReshape(const int newWidth, const int newHeight);
static void MySpecialKey(int key, int x, int y);

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(widthWindow, heightWindow);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("OpenGL Scaling Drawing");
	glLoadIdentity();
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glOrtho(-xMax, xMax, -yMax, yMax, -zMax, zMax);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	Matrix m1;
	m1.Translate(-1.f, -1.f, 0.f);
	m1 * mat;
	Matrix m2;
	m2.rotate(30.f, 1.0, 1.0, 1.0);
	m2 * mat;
	Matrix m3;
	m3.Translate(1.f, 1.f, 0.f);
	m3 * mat;
	
	glutReshapeFunc(MyReshape);
	glutDisplayFunc(MyDisplay);
	glutMainLoop();
	return 0;
}
static void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);

	glEnableClientState(GL_COLOR_ARRAY);
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, mat);
	glColorPointer(3, GL_FLOAT, 0, MyColor);

	glBegin(GL_QUADS);
	glColor3fv(MyColor[0]);	glVertex3fv(mat[0]);
	glColor3fv(MyColor[3]);	glVertex3fv(mat[3]);
	glColor3fv(MyColor[7]);	glVertex3fv(mat[7]);
	glColor3fv(MyColor[4]);	glVertex3fv(mat[4]);

	glColor3fv(MyColor[3]);	glVertex3fv(mat[3]);
	glColor3fv(MyColor[7]);	glVertex3fv(mat[7]);
	glColor3fv(MyColor[6]);	glVertex3fv(mat[6]);
	glColor3fv(MyColor[2]);	glVertex3fv(mat[2]);

	glColor3fv(MyColor[0]);	glVertex3fv(mat[0]);
	glColor3fv(MyColor[4]);	glVertex3fv(mat[4]);
	glColor3fv(MyColor[5]);	glVertex3fv(mat[5]);
	glColor3fv(MyColor[1]);	glVertex3fv(mat[1]);

	glColor3fv(MyColor[1]);	glVertex3fv(mat[1]);
	glColor3fv(MyColor[2]);	glVertex3fv(mat[2]);
	glColor3fv(MyColor[6]);	glVertex3fv(mat[6]);
	glColor3fv(MyColor[5]);	glVertex3fv(mat[5]);

	glColor3fv(MyColor[7]);	glVertex3fv(mat[7]);
	glColor3fv(MyColor[4]);	glVertex3fv(mat[4]);
	glColor3fv(MyColor[5]);	glVertex3fv(mat[5]);
	glColor3fv(MyColor[6]);	glVertex3fv(mat[6]);

	glColor3fv(MyColor[0]);	glVertex3fv(mat[0]);
	glColor3fv(MyColor[3]);	glVertex3fv(mat[3]);
	glColor3fv(MyColor[2]);	glVertex3fv(mat[2]);
	glColor3fv(MyColor[1]);	glVertex3fv(mat[1]);
	glEnd();
	glFlush();
}
static void MyReshape(const int newWidth, const int newHeight) {
	glViewport(0, 0, newWidth, newHeight);
	GLfloat WidthFactor = (GLfloat)newWidth / (GLfloat)widthWindow;
	GLfloat HeightFactor = (GLfloat)newHeight / (GLfloat)heightWindow;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-xMax * WidthFactor, xMax * WidthFactor, -yMax * HeightFactor, yMax * HeightFactor, -zMax, zMax);
}
static void MySpecialKey(int key, int x, int y) {
	if (key == GLUT_KEY_UP)
		ScaleRatio += SACLE_FACTOR;
	else if (key == GLUT_KEY_DOWN)
		ScaleRatio -= SACLE_FACTOR;

	glutPostRedisplay();
}