#include <iostream>

class IntMat {
	public:
        /**
        * A default constructor
        */
		IntMat();
        /**
        * A copy constructor
        */
		IntMat(const IntMat& toCopy);
        /**
        * A constructor for an empty matrix at given size.
        * @param rows the rows of the output matrix
        * @param cols the columns of the output matrix
        */
		IntMat(int rows, int cols);
        /**
        * A constructor for a matrix at given size ,
        * and given matrix in matrix[][] format.
        * @param rows the rows of the output matrix.
        * @param cols the columns of the output matrix.
        * @param mat the matrix values.
        */
		IntMat(int rows, int cols ,int** mat);
		/**
        * A destructor
        */
		~IntMat();

		IntMat& operator=(IntMat& rval);
		IntMat& operator+=(const IntMat& rval);
		IntMat operator+(const IntMat& rval);
		IntMat& operator-=(const IntMat& rval);
		IntMat operator-(const IntMat& rval);
		IntMat& operator*=(const IntMat& rval);
		IntMat operator*(const IntMat& rval);

		friend std::ostream& operator<<(std::ostream& os, const IntMat& mat);
        /**
        * trasnposes the matrix.
        */
		static IntMat s_trans(const IntMat& orig);
		/**
        * calculates the matrix's trace.
        */
		static int s_trace(const IntMat& mat);

	private:
		int _rows; /**< the matrix rows */
		int _cols; /**< the matrix columns */
		int** _mat; /**< the matrix itself */

		bool operator==(const IntMat& rhs);
		bool operator!=(const IntMat& rhs);
        /**
        * a swap metod.
        * swaps a given matrix with this matrix
        */
		void swap(IntMat& other);
		/**
		* frees the memory of _mat
        */
		void delMat();
        /**
		* initiates _mat (allocating memory, etc..)
        */
		void initMat(const int rows, const int cols);
        /**
		* @return a specific column of a matrix
		* @param res the result reference output.
		* @param mat the input matrix object
		* @param colNum the wanted column.
        */
		void getCol(int res[], const IntMat& mat, const int colNum) const;

};
/** A vector operator.
* @return the vector multiplication of tow vectors
* @param vec1 the first vector.
* @param vec2 the second vector.
* @param size the size of the tow vectors(must be the same).
*/
int mul(int vec1[], int vec2[], int size);
