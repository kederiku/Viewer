#ifndef __MATRIX_H__
#define __MATRIX_H__

class Matrix4
{
	private:
		double		__matrix4[16];
	public:
				Matrix4();
		void		Set(int col, int row, double val);
		double		Get(int col, int row);
		double*		Get_Matrix4();
		Matrix4		Mul(Matrix4& matrix4);
		void		Addition(double* matrix4);
		void		Subtraction(double* matrix4);
		void		Rotate(double x, double y, double z);
		void		Translate(double x, double y, double z);

				~Matrix4();

};

#endif
