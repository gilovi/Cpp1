#include <iostream>

class IntMat {
	public:
		IntMat();
		IntMat(IntMat toCopy);
		~IntMat();
		
		IntMat& operator=(const IntMat& rval);
		IntMat& operator+=(const IntMat& rval);
		IntMat& operator+(const IntMat& rval);
		IntMat& operator-=(const IntMat& rval);
		IntMat& operator-(const IntMat& rval);
		IntMat& operator*=(const IntMat& rval);
		IntMat& operator*(const IntMat& rval);
		std::ostream& operator<<(std::ostream& os, const IntMat& mat);
		
		IntMat trans(const IntMat&);
		int trace(const IntMat&);
		
}
