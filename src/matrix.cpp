#include "matrix.h"
#include <math.h>
#include <iostream>

#define RADIUS  3.141593f / 180

Matrix4::Matrix4()
{
	for(int i = 0; i < 16; i++)
		this->__matrix4[i] = 0;
}

void
Matrix4::Set(int col, int row, double val)
{
	this->__matrix4[col * 4 + row] = val;
}

double
Matrix4::Get(int col, int row)
{
	return this->__matrix4[col * 4 + row];
}

double*
Matrix4::Get_Matrix4()
{
	return this->__matrix4;
}

Matrix4::~Matrix4()
{
}


void
Matrix4::Addition(double* matrix4)
{
	for (int i = 0; i < 16; i++)
		this->__matrix4[i] = this->__matrix4[i] + matrix4[i];
}


void
Matrix4::Subtraction(double* matrix4)
{
	for (int i = 0; i < 16; i++)
		this->__matrix4[i] = this->__matrix4[i] - matrix4[i];
}

void	print(Matrix4& lol)
{
	std::cout << "---------Matrix-----------" << std::endl;

	for (int x = 0; x < 4; x++)
	{
		for (int y = 0; y < 4; y++)
		{
			std::cout << " " << lol.Get(y, x);
		}
		std::cout << std::endl;
	}
	
}

Matrix4
Matrix4::Mul(Matrix4& right)
{
	Matrix4 ret;

	for (int x = 0; x < 4; x++)
	{
		for (int y = 0; y < 4; y++)
		{
			double tmp = 0;

			for (int k = 0; k < 4; k++)
			{
				tmp +=  this->Get(k, y) * right.Get(x, k);
			}
			ret.Set(x, y, tmp);
		}
	}
	return ret;
}

void
Matrix4::Translate(double x, double y, double z)
{
	Set(0, 0, 1);
	Set(1, 1, 1);
	Set(2, 2, 1);
	Set(3, 0, x);
	Set(3, 1, y);
	Set(3, 2, z);
	Set(3, 3, 1);
}

Matrix4 GetRotateX(double angle)
{
	Matrix4 tmp;

	
	tmp.Set(0,0, 1);
	tmp.Set(1,1, cos(angle* M_PI / 180));
	tmp.Set(2,1, -sin(angle * M_PI / 180));
	tmp.Set(1,2, sin(angle * M_PI / 180));
	tmp.Set(2,2, cos(angle * M_PI / 180));
	tmp.Set(3,3, 1);
	return tmp;
}
Matrix4 GetRotateY(double angle)
{
	Matrix4 tmp;

	
	tmp.Set(1,1, 1);
	tmp.Set(0,0, cos(angle* M_PI / 180));
	tmp.Set(0,2, -sin(angle * M_PI / 180));
	tmp.Set(2,0, sin(angle * M_PI / 180));
	tmp.Set(2,2, cos(angle * M_PI / 180));
	tmp.Set(3,3, 1);
	return tmp;
}
Matrix4 GetRotateZ(double angle)
{
	Matrix4 tmp;

	
	tmp.Set(2,2, 1);
	tmp.Set(0,0, cos(angle* M_PI / 180));
	tmp.Set(1,0, -sin(angle * M_PI / 180));
	tmp.Set(0,1, sin(angle * M_PI / 180));
	tmp.Set(1,1, cos(angle * M_PI / 180));
	tmp.Set(3,3, 1);
	return tmp;
}


void
Matrix4::Rotate(double x, double y, double z)
{
	Matrix4 tmp;
	Matrix4 tmp2;

	tmp = GetRotateX(x);
	tmp2 = GetRotateY(y);
	tmp = tmp.Mul(tmp2);
	tmp2 = GetRotateZ(z);
	tmp = tmp.Mul(tmp2);
	*this = tmp;
}
