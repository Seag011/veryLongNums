#pragma once
#include "Cell.h"


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
		Cell body[MAX_CELLS];
	};

	Number number;

	friend GeneralOp& operator + (const GeneralOp& left, const GeneralOp& right);
	friend GeneralOp& operator - (const GeneralOp& left, const GeneralOp& right);
	friend GeneralOp& operator * (const GeneralOp& left, const GeneralOp& right);
	friend GeneralOp& operator / (const GeneralOp& left, const GeneralOp& right);

	friend bool operator >  (const GeneralOp& left, const GeneralOp& right);
	friend bool operator >= (const GeneralOp& left, const GeneralOp& right);
	friend bool operator <  (const GeneralOp& left, const GeneralOp& right);
	friend bool operator <= (const GeneralOp& left, const GeneralOp& right);
	friend bool operator == (const GeneralOp& left, const GeneralOp& right);

	void operator = (const GeneralOp& right);

	void operator << (GeneralOp left);
	void operator >> (GeneralOp right);
	//Add equality operators for another types
};