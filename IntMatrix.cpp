#include "IntMatrix.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <iostream>

using namespace std;

IntMat::IntMat():
_rows(0),_cols(0),_mat(nullptr)
{

}

IntMat::IntMat(const IntMat& toCopy):
_rows(toCopy._rows), _cols(toCopy._cols)
{

	initMat(_rows,_cols);
	if (0 == toCopy._rows && 0 == toCopy._cols)
	{
		_mat = nullptr;
	}
	else
	{
		for (int i = 0; i<_rows; i++)
		{
			memcpy(_mat[i], toCopy._mat[i], _cols*sizeof(int));
		}
	}

}

IntMat::IntMat(int rows, int cols ,int** mat):
_rows(rows), _cols(cols), _mat(mat)
{
}

IntMat::~IntMat()
{
	delMat();
}

IntMat::IntMat(int rows, int cols):
_rows(rows), _cols(cols)
{
	initMat(_rows, _cols);
}

IntMat& IntMat::operator=(IntMat& rval)
{
	swap(rval);
	return *this;
}

IntMat& IntMat::operator+=(const IntMat& rval)
{
	if (_rows != rval._rows || _cols != rval._cols)
    {
        throw "matrix sizes don't match.";
    }

	for (int i=0 ; i<_rows ; i++)
	{
		for(int j=0; j< _cols; j++)
		{
			_mat[i][j] += rval._mat[i][j];
		}
	}
	return *this;
}

IntMat IntMat::operator+(const IntMat& rval)
{

	IntMat res = *this;
	res += rval;
	return res;
}

IntMat& IntMat::operator-=(const IntMat& rval)
{
    if (_rows != rval._rows || _cols != rval._cols)
    {
        throw "matrix sizes don't match.";
    }

	for (int i=0 ; i<_rows; i++)
	{
		for(int j=0; j< _cols; j++)
		{
			_mat[i][j] -= rval._mat[i][j];
		}
	}
	return *this;
}

IntMat IntMat::operator-(const IntMat& rval)
{

	IntMat res = *this;
	res -= rval;

	return res;
}

IntMat& IntMat::operator*=(const IntMat& rval)
{
    if (_cols == rval._rows)
    {
        throw "matrix sizes don't match.";
    }

	IntMat res = IntMat(_rows, rval._cols);
	for (int j = 0; j < res._cols; j++)
	{
		int rCol[rval._rows];
		getCol(rCol, rval , j);
		for (int i = 0; i < res._rows; i++)
		{
			res._mat[i][j] = mul(_mat[i] , rCol, _cols) ;
		}
	}
	swap(res);
	return *this;
}

IntMat IntMat::operator*(const IntMat& rval)
{
	IntMat res = *this;
	res *= rval;
	return res;
}

std::ostream& operator<<(std::ostream& os, const IntMat& mat)
{
	for (int i=0 ; i < mat._rows ; i++)
		{
			for (int j = 0 ; j < mat._cols; j++)
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

IntMat IntMat::trans(const IntMat& orig)
{
	IntMat res = IntMat(orig._cols, orig._rows);
	for (int i=0 ; i < orig._rows ; i++)
	{
		for (int j = 0 ; j < orig._cols; j++)
		{
			res._mat[j][i] = orig._mat[i][j];
		}

	}
	return res;
}

int IntMat::s_trace(const IntMat& mat)
{
    if (mat._rows != mat._cols)
    {
        throw "matrix not square.";
    }
	int res = 0;
	//assert(mat._rows==mat._cols);
	for (int i = 0 ; i<mat._rows ; i++)
	{
		res += mat._mat[i][i];
	}
	return res;
}
/*
 *
 * name: IntMat::operator ==
 * @param
 * @return
 *
 */
bool IntMat::operator==(const IntMat& rhs)
{
	if (_rows != rhs._rows || _cols != rhs._cols  )
	{
	return false;
	}
	else
	{
		for (int i=0 ; i < _rows ; i++)
		{
			for (int j = 0 ; j < _cols; j++)
			{
				if (_mat[i][j] != rhs._mat[i][j])
				{
					return false;
				}
			}
		}
		return true;
	}
}

bool IntMat::operator!=(const IntMat& rhs)
{
	return !(*this == rhs);
}

void IntMat::swap(IntMat& other)
{
	int** tmp = _mat;
	_mat = other._mat;
	other._mat = tmp;

	int r,c;
	r = _rows;
	c = _cols;

	_rows = other._rows;
	_cols = other._cols;
	other._rows = r;
	other._cols = c;
}

void IntMat::delMat()
{
	if (_mat)
	{
		for(int i=0; i<_rows ; i++)
		{
			delete _mat[i];
		}
		delete _mat;
	}
}

/**
 * initialization method for _mat
 * assumes the old _mat doesn't need to be deleted.
 **/
void IntMat::initMat(const int rows, const int cols)
{
	_mat = new int *[rows];
	for (int i = 0; i < rows ; i++)
	{
		_mat[i] = new int[cols];
	}
}

void IntMat::getCol(int res[], const IntMat& mat, const int colNum) const
{
    assert(mat._cols < colNum);
	for (int i = 0 ; i<mat._rows ; i++)
	{
		res[i]=mat._mat[i][colNum];
	}
}

/*
 * a helper function to perform a vector '*' operator on tow vectors.
 * name: mul
 * @param a the first vector
 * @param b the second vector
 * @return the vector * operator result.
 *
 */

int mul(int a[] , int b[], const int size)
{
	int res = 0;
	for(int i=0; i < size; i++)
	{
		res += a[i] * b[i];
	}
	return res;
}
