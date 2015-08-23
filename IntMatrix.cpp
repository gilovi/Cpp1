#include "IntMatrix.h"

using namespace std;

IntMat::IntMat():
_mat(nullptr), _rows(0),_cols(0)
{
	
}

IntMat::IntMat(const IntMat& toCopy):
_mat(new int* [toCopy._rows]),_rows(toCopy._rows), _cols(toCopy._cols)
{
	if (0 ==_rows && 0 == _cols)
	{
		_mat = nullptr;
	}
	else
	{
		for (int i = 0; i<_rows; i++)
		{
			_mat[i] = new int[_cols];
			std::memcpy(_mat[i],toCopy._mat[i],_cols);
		}
	}
}

IntMat::~IntMat()
{
	if (_mat)
	{
		for(int i=0; i<_rows ; i++)
		{
			delete _mat[i]];
		}
		delete _mat;
	}
	
}
	
IntMat::IntMat(int rows, int cols):
_mat(new int[rows]),_rows(rows), _cols(cols)
{
	for (int i = 0; i < rows ; i++)
	{
		_mat[j] = new int[cols];
	}
}

IntMat& IntMat::operator=(const IntMat& rval)
{
	if (this != rval)
	{
		if (_mat)
		{
			for(int i=0; i<rows ; i++)
			{
				delete _mat[i]];
			}
			delete _mat;
		}
	this IntMat(rval);
	//memcpy(this, tmp, sizeof(IntMat)); //TODO : may cause problems. 
	}
	return *this;
}

IntMat& IntMat::operator+=(const IntMat& rval)
{
	//TODO add a throw /assert to verify correct sizes
	for (int i=0 ; i<_rows, i++)
	{
		for(int j=0; i< _cols; j++)
		{
			mat[i][j] += rval._mat[i][j];
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
 	//TODO add a throw /assert to verify correct sizes
	for (int i=0 ; i<_rows, i++)
	{
		for(int j=0; i< _cols; j++)
		{
			mat[i][j] -= rval._mat[i][j];
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
	res = 
	
}
	
IntMat IntMat::operator*(const IntMat& rval)
{
	
}
	
std::ostream& operator<<(std::ostream& os, const IntMat& mat)
{
	
}

IntMat IntMat::trans(const IntMat&)
{
	
}
	
int IntMat::trace(const IntMat&)
{
	
}
