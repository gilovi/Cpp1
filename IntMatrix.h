#include <iostream>

class IntMat {
	public:
		IntMat();
		IntMat(const IntMat& toCopy);
		IntMat(int rows, int cols);
		IntMat(int rows, int cols ,int** mat);
		~IntMat();
		
		IntMat& operator=(IntMat& rval);
		IntMat& operator+=(const IntMat& rval);
		IntMat operator+(const IntMat& rval);
		IntMat& operator-=(const IntMat& rval);
		IntMat operator-(const IntMat& rval);
		IntMat& operator*=(const IntMat& rval);
		IntMat operator*(const IntMat& rval);
		
		friend std::ostream& operator<<(std::ostream& os, const IntMat& mat);
		
		static IntMat trans(const IntMat&);
		static int trace(const IntMat&);
		
	private:
		int _rows;
		int _cols;
		int** _mat;
		
		bool operator==(const IntMat& rhs);
		bool operator!=(const IntMat& rhs);
		
		void swap(IntMat& other);
		void delMat();
		void cpyMat(const IntMat& other);
		void initMat(const int rows, const int cols);
		void getCol(int res[], const IntMat mat, const int colNum) const;
		
};

int mul(int[], int[], int size);
