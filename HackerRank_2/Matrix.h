#pragma once
#include <vector>

using namespace std;

class Matrix
{
public:
	Matrix(int n, int m);
	~Matrix();

	vector<vector<int>>myValues;

	int my_N, my_M;
};

class MatrixOps
{
public:
	MatrixOps() {};
	~MatrixOps() {};

	static long determinant(const Matrix& M);
	static long cofactor(const Matrix& M, int theFactor) { return 0; }
	static Matrix scalar(const Matrix& A, int c);
	static Matrix Add(const Matrix& A, const Matrix& B);
	static Matrix Multiply(const Matrix& A, const Matrix& B);

};

