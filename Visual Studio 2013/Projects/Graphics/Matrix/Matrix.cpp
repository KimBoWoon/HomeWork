#define _USE_MATH_DEFINES
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string.h>
#include "Matrix.h"

namespace KmuCheerUP
{
	Matrix::Matrix()
		:model()
	{	
		model[0] = 1.f; model[5] = 1.f; model[10] = 1.f; model[15] = 1.f;
	}

	Matrix::Matrix(const float transpose[SIZE])
	{
		memcpy(model, transpose, SIZE * sizeof(float));
	}

	Matrix::Matrix(const Matrix &mat)
	{
		memcpy(model, mat.model, SIZE * sizeof(float));
	}

	Matrix *Matrix::Translate(const float x, const float y, const float z)
	{
		model[3] = x;
		model[7] = y;
		model[11] = z;

		return this;
	}

	Matrix *Matrix::Rotate(const float theta, const float x, const float y, const float z)
	{
		// Not Implementation
		return this;
	}

	Matrix *Matrix::RotateX(const float theta)
	{
		const float degree = static_cast<float> (theta * (M_PI / 180.));
		model[5] = cosf(degree); 
		model[6] = -sinf(degree);
		model[9] = sinf(degree);
		model[10] = cosf(degree);
		return this;

	}
	Matrix *Matrix::RotateY(const float theta)
	{
		const float degree = static_cast<float> (theta * (M_PI / 180.));
		model[0] = cosf(degree);
		model[2] = sinf(degree);
		model[8] = -sinf(degree);
		model[10] = cosf(degree);

		return this;
	}

	Matrix *Matrix::RotateZ(const float theta)
	{
		const float degree = static_cast<float> (theta * (M_PI / 180.));
		model[0] = cosf(degree);
		model[1] = -sinf(degree);
		model[4] = sinf(degree);
		model[5] = cosf(degree);

		return this;
	}

	Matrix *Matrix::Scale(const float scale)
	{
		model[0] = scale;
		model[5] = scale;
		model[10] = scale;
		model[15] = scale;

		return this;
	}

	Matrix *Matrix::Scale(const float x, const float y, const float z)
	{
		model[0] = x;
		model[5] = y;
		model[10] = z;

		return this;
	}

	Matrix *Matrix::ShearXY(const float x, const float y)
	{
		model[2] = x;
		model[6] = y;

		return this;
	}

	Matrix *Matrix::ShearXZ(const float x, const float z)
	{
		model[1] = x;
		model[9] = z;

		return this;
	}

	Matrix *Matrix::ShearYZ(const float y, const float z)
	{
		model[4] = y;
		model[8] = z;

		return this;
	}

	Matrix *Matrix::ReflectX()
	{
		model[5] = -model[5];

		return this;
	}

	Matrix *Matrix::ReflectY()
	{
		model[0] = -model[0];

		return this;
	}

	Matrix *Matrix::ReflectZ()
	{
		model[10] = -model[10];

		return this;
	}

	Matrix *Matrix::ReflectO()
	{
		model[0] = -model[0];
		model[5] = -model[5];
		model[10] = -model[10];
		model[15] = -model[15];

		return this;
	}

	const float *Matrix::Get() const
	{
		return model;
	}

	float **Matrix::operator*(float(*modelObj)[3]) const
	{
		const int rows = 4;
		const int cols = 4;
		const int size = 8;

		float *begin = modelObj[0];
		float *end = modelObj[8];
		float *cur = begin;

		while (begin <= end)
		{
			const float target[rows] = { *begin++, *begin++, *begin++, 1 };
			float result[cols] = { 0.f, };

			for (int row = 0; row < rows; row++)
			{
				float sum = 0.f;
				for (int col = 0; col < cols; col++)
				{
					sum += *(model + (row * cols + col)) * target[col];
				}
				result[row] = sum;
			}
			*cur++ = result[0];
			*cur++ = result[1];
			*cur++ = result[2];
		}
		return reinterpret_cast<float **>(modelObj);
	}

	float Matrix::operator[](int index) const
	{
		return model[index];
	}

	Matrix Matrix::operator*(const Matrix &mat) const
	{	
		const int cols = 4;
		const int rows = 4;
		float re[SIZE] = { 0x00, };

		const float *begin = mat.model;

		for (int row = 0; row < rows; row++)
		{	
			for (int col = 0; col < cols; col++)
			{	
				begin = mat.model + col;
				for (int co = 0; co < cols; co++)
				{	
					*(re + (row * cols + col))  += *(model + (row * cols + co))  *  *(begin + co * cols);
				}
			}
			begin = mat.model;
		}
		return Matrix(re);
	}

	Matrix *Matrix::operator *= (const Matrix &mat)
	{
		*this = *this * mat;
		return this;
	}

	std::ostream &operator<<(std::ostream &os, const Matrix &mat)
	{
		const int cols = 4;
		const int rows = 4;

		const float *begin = mat.model;
		os << std::fixed << std::setprecision(3);

		for (int row = 0; row < rows; row++)
		{
			for (int col = 0; col < cols; col++)
				os << std::setw(8) << *(begin + (row * cols + col)) << " ";
			os << "\n";
		}
		return os;
	}
}