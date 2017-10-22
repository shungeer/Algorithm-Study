// DivideAndConquer.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include "demo.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "-----------algorithm study by shungeer-------------" << endl;
	cout << "-----------D & C-------------" << endl;
	cout << "-----------sum example:-------------" << endl;
	int a1[4] = { 10, 20, 30, 50 };
	cout <<sum(a1, 4) << endl; 
	int b1[5] = { 10, 20, 30, 50, 100 };
	cout << sum(b1, 5) << endl;
	cout << "-----------max number example:-------------" << endl;
	int a2[4] = { 10, 20, 30, 50 };
	cout << maxnumber(a2, 4) << endl;
	int b2[5] = { 10, -20, 30, -50, -100 };
	cout << maxnumber(b2, 5) << endl;
	cout << "-----------bearch example:-------------" << endl;
	int a3[4] = { 10, 20, 30, 50 };
	cout << bsearch(a3, 4, 10) << endl;
	int b3[5] = { -30, -20, -10, 50, 100 };
	cout << bsearch(b3, 5, 100) << endl;
	int a4[4] = { 10, 20, 30, 50 };
	cout << bsearch(a4, 4, 1) << endl;
	int b5[5] = { -30, -20, -10, 50, 100 };
	cout << bsearch(b5, 5, 1100) << endl;
	getchar();
	return 0;
}

