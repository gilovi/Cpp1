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
void printMatReqMsg(int op);
IntMat getMatrix(int op , int matNum);
void printMat(int matNum , IntMat mat);
int* parseRow(string row ,int len);
IntMat calc(IntMat& a, IntMat& b, int op);
void printRes(IntMat res);
void printRes(int res);
//==================================//

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
		printMatReqMsg(op);
		IntMat a = getMatrix(op, ++matNum);
        IntMat b = getMatrix(op, ++matNum);

        printMat(matNum , a);
		if (op <= TOW_MATRICES_IN) // the input suppose to be 2 matrices.
		{
            printMat(matNum , b);
		}
		if (op == SCALAR_OUT) // spacial case when output is scalar
        {
        printRes(IntMat::trace(a));
        }
        else
        {
		printRes(calc(a, b, op));
        }

		exit(0);

}

void opChoose(int& op)
{
	cout << "Choose operation:" << endl;
	cout << "1.\tadd"<< endl;
	cout << "2.\tsub"<< endl;
	cout << "3.\tmul"<< endl;
	cout << "4.\ttrans"<< endl;
	cout << "5.\ttrace"<< endl;

	cin >> op;
	if (!(op <= NUM_OF_OPTIONS && op > 0))
	{
		op = 0;
	}
}

void printMatReqMsg(int op)
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
	cout << "Operation "<< strOp << "requires " << strMatNum <<" operand matrices." << endl;
}

IntMat getMatrix(int op , int matNum)
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
        return IntMat();
    }

    cout << "number of rows:";
	cin >> rows;
	cout << "number of columns:";
	cin >> cols;

    cout << "Now insert the values of the matrix, row by row." << endl;
    cout << "After each cell add the char ',' (including after the last cell of a row)." << endl;
    cout << "Each row should be in a separate line." << endl;
	int** mat = new int *[rows];
	for (int i=0 ; i < rows ; i++)
	{
		cin >> strRow;
		mat[i] = parseRow(strRow, cols);
	}

	return IntMat(rows, cols, mat);
}

void printMat(int matNum , IntMat mat)
{
    string strMatNum = matNum == 1 ? "first" : "second";
    cout << "--------" << endl;
    cout << "Got " << strMatNum << " matrix:"\n << endl;
    cout << mat << endl;
}

int* parseRow(string row ,int len)
{
	int* ret = new int[len];
	int i = 0;
	string str;
	stringstream stream(row);
    while(stream >> ret[i] && i < len)
    {
        if (stream.peek() == ',')
        {
        stream.ignore();
        i++;
		}
	}
	return ret;
}

IntMat calc(IntMat& a, IntMat& b, int op)
{
    assert(op <= NUM_OF_OPTIONS && op > 0);
    try
    {

        switch (op)
        {
            case 1:
                return a+b;

            case 2:
                return a-b;

            case 3:
                return a*b;

            case 5:
                return IntMat::trans(a);

            default:
                exit(1);
        }
    }
    catch (exception e)
    {
        okInput = false;
        return IntMat();
    }
}

void printRes(IntMat res)
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

void printRes(int res)
{
    if (okInput)
    {
        cout << "==========" << endl;
        cout << "The matrix is square and its trace is";
		cout << res << endl;
    }
    else
    {
        cout << "Error: trace failed - The matrix isn't square." << endl;
    }

}

