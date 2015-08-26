#include "IntMatrix.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <iostream>
#include <sstream>

using namespace std;
const int TOW_MATRICES_IN = 3;
const int SCALAR_OUT = 5;
const int NUM_OF_OPTIONS = 5;
const int TRANS = 4;
const int TRACE = 5;

static bool okInput = true;

//		forward declarations:
//==================================//
void opChoose(int& op);
void prIntMatrixReqMsg(int op);
IntMatrix getMatrix(int op, int matNum);
void prIntMatrix(int matNum, IntMatrix mat);
int* parseRow(string row, int len);
IntMatrix calc(IntMatrix& a, IntMatrix& b, int op);
void printRes(IntMatrix res);
void printRes(int res);
//==================================//

/**
* the main function
*/
int main()
{

	int matNum = 0;
	int op = 0;
	while (!op)
	{
		opChoose(op);
//		if (!op)
//		{
//			cout << "please choose integer in 1-5"<< endl; ;
//		}
	}
	prIntMatrixReqMsg(op);
	IntMatrix a = getMatrix(op, ++matNum);
	IntMatrix b = getMatrix(op, ++matNum);

	matNum = 0;
	prIntMatrix(++matNum, a);
	if (op <= TOW_MATRICES_IN) // the input suppose to be 2 matrices.
	{
		prIntMatrix(++matNum, b);
	}
	if (op == SCALAR_OUT) // spacial case when output is scalar
	{
		printRes(IntMatrix::trace(a));
	}
	else if (op == TRANS)
	{
		printRes(IntMatrix::trans(a));
	}
	else
	{
        printRes(calc(a, b, op));
	}

	exit(0);

}
/**
 * prints a message for getting the user desired operation
 * and changes the input op accordingly
 * @param op the output operation
 */

void opChoose(int& op)
{
	cout << "Choose operation:" << endl;
	cout << "1. add" << endl;
	cout << "2. sub" << endl;
	cout << "3. mul" << endl;
	cout << "4. trans" << endl;
	cout << "5. trace" << endl;

	cin >> op;
	if (!(op <= NUM_OF_OPTIONS && op > 0))
	{
		op = 0;
	}
}
/**
 * prints the openning message for the driver.
 */
void prIntMatrixReqMsg(int op)
{
	string strOp = "";
	string strMatNum = "";
	switch (op)
	{
        case 1:
            strOp = "add";
            strMatNum = "2";
            break;

        case 2:
            strOp = "sub";
            strMatNum = "2";
            break;

        case 3:
            strOp = "mul";
            strMatNum = "2";
            break;

        case 4:
            strOp = "transpose";
            strMatNum = "1";
            break;

        case 5:
            strOp = "trace";
            strMatNum = "1";
            break;

	}
	cout << "Operation " << strOp << " requires " << strMatNum
			<< " operand matrices." << endl;
}
/**
 * prints a request for inserting a matrix by a certain flow
 * and makes a IntMatrixrix out of it
 *
 */
IntMatrix getMatrix(int op, int matNum)
{

	int rows, cols;
	string strRow;

	if (op <= TOW_MATRICES_IN)
	{
		string strMatNum = matNum > 1 ? "second" : "first";
		cout << "Insert " << strMatNum << " matrix:" << endl;
	}
	else if (matNum > 1)
	{
		return IntMatrix();
	}

	cout << "number of rows:";
	cin >> rows;
	cout << "number of columns:";
	cin >> cols;

	cout << "Now insert the values of the matrix, row by row." << endl;
	cout
			<< "After each cell add the char ',' (including after the last cell of a row)."
			<< endl;
	cout << "Each row should be in a separate line." << endl;
	int** mat = new int *[rows];
	for (int i = 0; i < rows; i++)
	{
		cin >> strRow;
		mat[i] = parseRow(strRow, cols);
	}

	return IntMatrix(rows, cols, mat);
}
/**
 * prints a preceding message for matrix print
 */
void prIntMatrix(int matNum, IntMatrix mat)
{
	string strMatNum = matNum == 1 ? "first" : "second";
	cout << "--------" << endl;
	cout << "Got " << strMatNum << " matrix:\n" << endl;
	cout << mat << endl;
}
/**
 * parses a row of user input matrix
 */

int* parseRow(string row, int len)
{
	int* ret = new int[len];
	int i = 0;
	string str;
	stringstream stream(row);
	while (stream >> ret[i] && i < len)
	{
		if (stream.peek() == ',')
		{
			stream.ignore();
			i++;
		}
	}
	return ret;
}
/**
 * calculates the wanted operation using the IntMatrixrix public methods
 */

IntMatrix calc(IntMatrix& a, IntMatrix& b, int op)
{
	assert(op <= NUM_OF_OPTIONS && op > 0);
	try
	{

		switch (op)
		{
            case 1:
                return a + b;

            case 2:
                return a - b;

            case 3:
                return a * b;

            case 5:
                return IntMatrix::trans(a);

            default:
                exit(1);
		}
	} catch (exception e)
	{
		okInput = false;
		return IntMatrix();
	}
}
/**
 * prints a preceding message for the resulted matrix, (or an error massage)
 */

void printRes(IntMatrix res)
{
	if (okInput)
	{
		cout << "==========" << endl;
		cout << "Resulted matrix:\n" << endl;
		cout << res << endl;
	}
	else
	{
		cout << "Error: add failed - different dimensions." << endl;
	}
}
/**
 * prints a preceding message for the resulted scalar, (or an error massage)
 */
void printRes(int res)
{
	if (okInput)
	{
		//cout << "==========" << endl;
		cout << "The matrix is square and its trace is ";
		cout << res << endl;
	}
	else
	{
		cout << "Error: trace failed - The matrix isn't square." << endl;
	}

}

