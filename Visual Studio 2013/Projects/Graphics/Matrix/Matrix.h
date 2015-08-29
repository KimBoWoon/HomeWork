#ifndef MATRIX_H
#define MATRIX_H

namespace KmuCheerUP
{	
	class Matrix
	{
		static const int SIZE = 16;
		friend std::ostream &operator<<(std::ostream &os, const Matrix &mat);

	public:
		Matrix();
		Matrix(const float transpose[SIZE]);
		Matrix(const Matrix &mat);

	public:
		Matrix *Translate(const float x, const float y, const float z);

		Matrix *Rotate(const float theta, const float x, const float y, const float z);
		Matrix *RotateX(const float theta);
		Matrix *RotateY(const float theta);
		Matrix *RotateZ(const float theta);

		Matrix *Scale(const float scale);
		Matrix *Scale(const float x, const float y, const float z);

		Matrix *ShearXY(const float x, const float y);		
		Matrix *ShearXZ(const float x, const float z);
		Matrix *ShearYZ(const float y, const float z);

		Matrix *ReflectX();
		Matrix *ReflectY();
		Matrix *ReflectZ();
		Matrix *ReflectO();

		const float *Get() const;
		float **operator*(float(*modelObj)[3]) const;
		float operator[](const int index) const;
		Matrix operator*(const Matrix &mat) const;
		Matrix *operator*=(const Matrix &mat);

	private:
		float model[SIZE];
	};

}
#endif