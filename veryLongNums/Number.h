#pragma once
#include "stdafx.h"
#include "Cell.h"

struct Number
{
public:
	std::vector <Cell> body;
	
	/*  A negative number marks as			*
	 *  1**** in (MAX_CELLS - 1) cell		*
	 *  and 0**** is positive.				*
	 *  **** means 4 any numbers			*
	 *  because this cell is also is used	*
	 *  for the number.						*/
				
	Number();

	US size();

	friend Number& operator + (const Number& left, const Number& right);
	friend Number& operator - (const Number& left, const Number& right);
	friend Number& operator * (const Number& left, const Number& right);
	friend Number& operator / (const Number& left, const Number& right);

	friend bool operator >  (const Number& left, const Number& right);
	friend bool operator >= (const Number& left, const Number& right);
	friend bool operator <  (const Number& left, const Number& right);
	friend bool operator <= (const Number& left, const Number& right);
	friend bool operator == (const Number& left, const Number& right);

	void operator = (const Number& right);
};