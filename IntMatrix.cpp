#include "IntMatrix.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <iostream>

using namespace std;
// --------------------------------------------------------------------------------------
// This file contains the implementation of the class IntMatrix.
// --------------------------------------------------------------------------------------

// ------------------ Constructors ------------------------
/**
 * A default constructor
 */
IntMatrix::IntMatrix() :
		_rows(0), _cols(0), _mat(nullptr)
{

}

/**
 * A copy constructor
 */
IntMatrix::IntMatrix(const IntMatrix& toCopy) :
		_rows(toCopy._rows), _cols(toCopy._cols)
{

	_initMat(_rows, _cols);
	if (0 == toCopy._rows && 0 == toCopy._cols)
	{
		_mat = nullptr;
	}
	else
	{
		for (int i = 0; i < _rows; i++)
		{
			memcpy(_mat[i], toCopy._mat[i], _cols * sizeof(int));
		}
	}

}

/**
 * A constructor for an empty matrix at given size.
 * @param rows the rows of the output matrix
 * @param cols the columns of the output matrix
 */
IntMatrix::IntMatrix(int rows, int cols) :
		_rows(rows), _cols(cols)
{
	_initMat(_rows, _cols);
}

/**
 * A constructor for a matrix at given size ,
 * and given matrix in matrix[][] format.
 * @param rows the rows of the output matrix.
 * @param cols the columns of the output matrix.
 * @param mat the matrix values.
 */

IntMatrix::IntMatrix(int rows, int cols, int** mat) :
		_rows(rows), _cols(cols), _mat(mat)
{
}

/**
 * A destructor
 */
IntMatrix::~IntMatrix()
{
	_delMat();
}

// ------------------ Operator methods ------------------------
/**
 * Basic assignmentoperator.
 */
IntMatrix& IntMatrix::operator=(IntMatrix& rval)
{
	_swap(rval);
	return *this;
}

/**
 * Addition assignment
 */
IntMatrix& IntMatrix::operator+=(const IntMatrix& rval)
{
	if (_rows != rval._rows || _cols != rval._cols)
	{
		throw "matrix sizes don't match.";
	}

	for (int i = 0; i < _rows; i++)
	{
		for (int j = 0; j < _cols; j++)
		{
			_mat[i][j] += rval._mat[i][j];
		}
	}
	return *this;
}

/**
 * Addition operator
 */
IntMatrix IntMatrix::operator+(const IntMatrix& rval)
{

	IntMatrix res = *this;
	res += rval;
	return res;
}

/**
 * Subtraction assignment
 */
IntMatrix& IntMatrix::operator-=(const IntMatrix& rval)
{
	if (_rows != rval._rows || _cols != rval._cols)
	{
		throw "matrix sizes don't match.";
	}

	for (int i = 0; i < _rows; i++)
	{
		for (int j = 0; j < _cols; j++)
		{
			_mat[i][j] -= rval._mat[i][j];
		}
	}
	return *this;
}

/**
 * Subtraction operator
 */
IntMatrix IntMatrix::operator-(const IntMatrix& rval)
{

	IntMatrix res = *this;
	res -= rval;

	return res;
}

/**
 * Multiplication assignment
 */
IntMatrix& IntMatrix::operator*=(const IntMatrix& rval)
{
	if (_cols == rval._rows)
	{
		throw "matrix sizes don't match.";
	}

	IntMatrix res = IntMatrix(_rows, rval._cols);
	for (int j = 0; j < res._cols; j++)
	{
		int rCol[rval._rows];
		_getCol(rCol, rval, j);
		for (int i = 0; i < res._rows; i++)
		{
			res._mat[i][j] = mul(_mat[i], rCol, _cols);
		}
	}
	_swap(res);
	return *this;
}

/**
 * matrix Multiplication operator
 */
IntMatrix IntMatrix::operator*(const IntMatrix& rval)
{
	IntMatrix res = *this;
	res *= rval;
	return res;
}

/**
 * printing operator
 */
std::ostream& operator<<(std::ostream& os, const IntMatrix& mat)
{
	for (int i = 0; i < mat._rows; i++)
	{
		for (int j = 0; j < mat._cols; j++)
		{
			os << mat._mat[i][j];
			if (j != mat._cols - 1)
			{
				os << " ";
			}
		}
		os << endl;
	}
	return os;
}

/**
 * trasnposes the matrix.
 */
IntMatrix IntMatrix::trans(const IntMatrix& orig)
{
	IntMatrix res = IntMatrix(orig._cols, orig._rows);
	for (int i = 0; i < orig._rows; i++)
	{
		for (int j = 0; j < orig._cols; j++)
		{
			res._mat[j][i] = orig._mat[i][j];
		}

	}
	return res;
}

/**
 * calculates the matrix's trace.
 */
int IntMatrix::trace(const IntMatrix& mat)
{
	if (mat._rows != mat._cols)
	{
		throw "matrix not square.";
	}
	int res = 0;
	//assert(mat._rows==mat._cols);
	for (int i = 0; i < mat._rows; i++)
	{
		res += mat._mat[i][i];
	}
	return res;
}

///*
// *
// * name: IntMatrix::operator ==
// */
//bool IntMatrix::operator==(const IntMatrix& rhs)
//{
//	if (_rows != rhs._rows || _cols != rhs._cols)
//	{
//		return false;
//	}
//	else
//	{
//		for (int i = 0; i < _rows; i++)
//		{
//			for (int j = 0; j < _cols; j++)
//			{
//				if (_mat[i][j] != rhs._mat[i][j])
//				{
//					return false;
//				}
//			}
//		}
//		return true;
//	}
//}
///*
// *
// * name: IntMatrix::operator !=
// */
//bool IntMatrix::operator!=(const IntMatrix& rhs)
//{
//	return !(*this == rhs);
//}
//
void IntMatrix::_swap(IntMatrix& other)
{
	int** tmp = _mat;
	_mat = other._mat;
	other._mat = tmp;

	int r, c;
	r = _rows;
	c = _cols;

	_rows = other._rows;
	_cols = other._cols;
	other._rows = r;
	other._cols = c;
}

/**
 * frees the memory of _mat
 */
void IntMatrix::_delMat()
{
	if (_mat)
	{
		for (int i = 0; i < _rows; i++)
		{
			delete _mat[i];
		}
		delete _mat;
	}
}

/**
 * initialization method for _mat
 * assumes the old _mat doesn't need to be deleted.
 */
void IntMatrix::_initMat(const int rows, const int cols)
{
	_mat = new int *[rows];
	for (int i = 0; i < rows; i++)
	{
		_mat[i] = new int[cols];
	}
}

/**
 * @return a specific column of a matrix
 * @param res the result reference output.
 * @param mat the input matrix object
 * @param colNum the wanted column.
 */
void IntMatrix::_getCol(int res[], const IntMatrix& mat, const int colNum) const
{
	assert(mat._cols < colNum);
	for (int i = 0; i < mat._rows; i++)
	{
		res[i] = mat._mat[i][colNum];
	}
}

// ------------------ Other methods ------------------------

/**
 * a helper function to perform a vector '*' operator on tow vectors.
 */

int mul(int a[], int b[], const int size)
{
	int res = 0;
	for (int i = 0; i < size; i++)
	{
		res += a[i] * b[i];
	}
	return res;
}
