// veryLongNums.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Cell.h"

int compare(int a, int b);

int main()
{
	Cell a(25);
	Cell b(1);
	Cell c(120);
	c = a - 25;
	std::cout << c;
	return 0;
}