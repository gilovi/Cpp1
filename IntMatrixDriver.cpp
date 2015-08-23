#include "IntMatrix.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <iostream>
#include <sstream>


using namespace std;
const int TOW_MAT_IN = 3;
const int SCALAR_OUT = 5;
const int NUM_OF_OPTIONS = 5;

//		forward declarations:
//==================================//
void opChoose(int& op);
IntMat getMatrix();
void printMatReqMsg(int op);
int* parseRow(string row ,int len);
IntMat calc(IntMat& a, IntMat& b, int op);
//IntMat calc(IntMat a, int op);
void printRes(int res);
void printRes(IntMat res);

//==================================//

int main()
{
	int op = 0;
	while (!op)
	{
		opChoose(op);
		if (!op)
		{
			cout << "please choose integer in 1-5"<< endl; ;
		}
	}
		printMatReqMsg(op);
		IntMat a = getMatrix();
		cout << a << endl;
		if (op <= TOW_MAT_IN)
		{
			IntMat b = getMatrix();
			cout << b << endl;
			printRes(calc(a,b,op));
		}
		else if (op >= SCALAR_OUT)
		{
			printRes(IntMat::trace(a));
		}
		else 
		{
			printRes(IntMat::trans(a));
		
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
IntMat getMatrix()
{
	int rows, cols;
	string strRow;
	
	cin >> rows;
	cin >> cols;
	int** mat = new int *[rows];
	for (int i=0 ; i < rows ; i++)
	{
		cin >> strRow;
		mat[i] = parseRow(strRow, cols);
	}
	return IntMat(rows, cols, mat);
}

//twoArgsFunc chooseFunc(IntMat a, IntMat b, op)
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
	switch (op)
	{
		case 1:
			return a+b;
		
		case 2:
			return a-b;
		
		case 3:
			return a*b;
			
		default:
			exit(1);
	}
}

void printRes(IntMat res)
{
		cout << "==========" << endl;
		cout << "Resulted matrix:" << endl;
		cout << res << endl;
}

void printRes(int res)
{
		cout << "==========" << endl;
		cout << "Resulted scalar:" << endl;
		cout << res << endl;
}

