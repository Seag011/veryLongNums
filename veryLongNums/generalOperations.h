#pragma once
#define "Cell.h"
typedef unsigned U;
typedef int I;
typedef short unsigned US;
typedef long unsigned UL;
typedef long long unsigned ULL;

#define MAX_CELLS 10000
#define MAX_NUMBER_IN_CELL 999
#define CONTROL_DIGIT (MAX_NUMBER_IN_CELL + 1)

class GeneralOp
{
protected:
	/*struct Cell
	{
		unsigned short body : 10;
		Cell(US a) : body(a) {};

		friend Cell operator + (Cell left, Cell right);
		friend Cell operator - (Cell left, Cell right);
		
		friend Cell& operator > (Cell left, Cell right);
		friend Cell& operator >= (Cell left, Cell right);
		friend Cell& operator < (Cell left, Cell right);
		friend Cell& operator <= (Cell left, Cell right);
		friend Cell& operator == (Cell left, Cell right);

		Cell operator = (Cell right);

	}; */
	
	struct Number
	{
		GeneralOp::Cell body[MAX_CELLS];
	};

	Number number;

	friend GeneralOp& operator + (GeneralOp left, GeneralOp right);
	friend GeneralOp& operator - (GeneralOp left, GeneralOp right);
	friend GeneralOp& operator * (GeneralOp left, GeneralOp right);
	friend GeneralOp& operator / (GeneralOp left, GeneralOp right);

	friend GeneralOp& operator > (GeneralOp left, GeneralOp right);
	friend GeneralOp& operator >= (GeneralOp left, GeneralOp right);
	friend GeneralOp& operator < (GeneralOp left, GeneralOp right);
	friend GeneralOp& operator <= (GeneralOp left, GeneralOp right);
	friend GeneralOp& operator == (GeneralOp left, GeneralOp right);

	GeneralOp operator = (GeneralOp right);

	void operator << (GeneralOp left);
	void operator >> (GeneralOp right);
	//Add equality operators for another types
};