#include <iostream>

/**
 * An integer matrix class
 */
class IntMatrix
{
public:
	/**
	 * A default constructor
	 */
	IntMatrix();
	/**
	 * A copy constructor
	 */
	IntMatrix(const IntMatrix& toCopy);
	/**
	 * A constructor for an empty matrix at given size.
	 * @param rows the rows of the output matrix
	 * @param cols the columns of the output matrix
	 */
	IntMatrix(int rows, int cols);
	/**
	 * A constructor for a matrix at given size ,
	 * and given matrix in matrix[][] format.
	 * @param rows the rows of the output matrix.
	 * @param cols the columns of the output matrix.
	 * @param mat the matrix values.
	 */
	IntMatrix(int rows, int cols, int** mat);
	/**
	 * A destructor
	 */
	~IntMatrix();
	/**
	 * Basic assignmentoperator.
	 */
	IntMatrix& operator=(IntMatrix& rval);
	/**
	 * Addition assignment
	 */
	IntMatrix& operator+=(const IntMatrix& rval);
	/**
	 * Addition operator
	 */
	IntMatrix operator+(const IntMatrix& rval);
	/**
	 * Subtraction assignment
	 */
	IntMatrix& operator-=(const IntMatrix& rval);
	/**
	 * Subtraction operator
	 */
	IntMatrix operator-(const IntMatrix& rval);
	/**
	 * Multiplication assignment
	 */
	IntMatrix& operator*=(const IntMatrix& rval);
	/**
	 * matrix Multiplication operator
	 */
	IntMatrix operator*(const IntMatrix& rval);
	/**
	 * printing operator
	 */
	friend std::ostream& operator<<(std::ostream& os, const IntMatrix& mat);
	/**
	 * trasnposes the matrix.
	 */
	static IntMatrix trans(const IntMatrix& orig);
	/**
	 * calculates the matrix's trace.
	 */
	static int trace(const IntMatrix& mat);

private:
	int _rows; /**< the matrix rows */
	int _cols; /**< the matrix columns */
	int** _mat; /**< the matrix itself */

	//bool operator==(const IntMatrix& rhs);
	//bool operator!=(const IntMatrix& rhs);
	/**
	 * a swap metod.
	 * swaps a given matrix with this matrix
	 */
	void _swap(IntMatrix& other);
	/**
	 * frees the memory of _mat
	 */
	void _delMat();
	/**
	 * initiates _mat (allocating memory, etc..)
	 */
	void _initMat(const int rows, const int cols);
	/**
	 * @return a specific column of a matrix
	 * @param res the result reference output.
	 * @param mat the input matrix object
	 * @param colNum the wanted column.
	 */
	void _getCol(int res[], const IntMatrix& mat, const int colNum) const;

};
/** A vector operator.
 * @return the vector multiplication of tow vectors
 * @param vec1 the first vector.
 * @param vec2 the second vector.
 * @param size the size of the tow vectors(must be the same).
 */
int mul(int vec1[], int vec2[], int size);
