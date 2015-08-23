#include <iostream>

class IntMat {
	public:
		IntMat();
		IntMat(const IntMat& toCopy);
		~IntMat();
		
		IntMat(int rows, int cols);
		
		IntMat& operator=(const IntMat& rval);
		IntMat& operator+=(const IntMat& rval);
		IntMat operator+(const IntMat& rval);
		IntMat& operator-=(const IntMat& rval);
		IntMat operator-(const IntMat& rval);
		IntMat& operator*=(const IntMat& rval);
		IntMat operator*(const IntMat& rval);
		
		friend std::ostream& operator<<(std::ostream& os, const IntMat& mat);
		
		IntMat trans(const IntMat&);
		int trace(const IntMat&);
		
	private:
		int** _mat;
		int _rows;
		int _cols;
	 
	
		
};
