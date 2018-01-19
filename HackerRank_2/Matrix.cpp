#include "stdafx.h"
#include "Matrix.h"


Matrix::Matrix(int n, int m)
{
	my_N = n;
	my_M = m;

	myValues.resize(my_N);

	for (int i = 0; i < my_N; ++i)
	{
		myValues[i].resize(my_M);
	}
}


Matrix::~Matrix()
{
}

Matrix MatrixOps::scalar(const Matrix& A, const int c)
{
	Matrix M(A.my_N, A.my_M);

	for (int i = 0; i < A.my_N; ++i)
	{
		for (int j = 0; j < A.my_M; ++j)
		{
			M.myValues[i][j] = c * A.myValues[i][j];
		}
	}

	return M;
}

Matrix MatrixOps::Add(const Matrix& A, const Matrix& B)
{

	Matrix M(A.my_N, A.my_M);

	for (int i = 0; i < A.my_N; ++i)
	{
		for (int j = 0; j < A.my_M; ++j)
		{
			M.myValues[i][j] = A.myValues[i][j] + B.myValues[i][j];
		}
	}

	return M;
}

Matrix MatrixOps::Multiply(const Matrix& A, const Matrix& B)
{
	Matrix M(A.my_N, A.my_M);

	for (int i = 0; i < A.my_N; ++i)
	{
		for (int j = 0; j < A.my_M; ++j)
		{
			M.myValues[i][j] = 0;

			for (int i1 = 0; i1 < A.my_M; ++i1)
			{
				M.myValues[i][j] += A.myValues[i][i1] * B.myValues[i1][j];
			}
		}
	}

	return M;
}

long MatrixOps::determinant(const Matrix& A)
{
	long result = 0;

	if (A.my_N != A.my_M)
	{
		throw;
	}

    return result;
}