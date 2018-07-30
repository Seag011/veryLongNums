#pragma once
#include "stdafx.h"
#include "Cell.h"

struct Number
{
public:
	std::vector <Cell> body;
	
	/* The biggest digits consists in 0th cell.  *
	 * It's also contains a minus and plus of	 *
	 * the number as 1**** or 0**** respectively *
	 * where * is any number					 */
				
	Number();

	const U& size();
	
	friend Number& operator + (const Number& left, const Number& right);
	friend Number& operator - (const Number& left, const Number& right);
	friend Number& operator * (const Number& left, const Number& right);
	friend Number& operator / (const Number& left, const Number& right);

	friend bool operator >  (const Number& left, const Number& right);
	friend bool operator >= (const Number& left, const Number& right);
	friend bool operator <  (const Number& left, const Number& right);
	friend bool operator <= (const Number& left, const Number& right);
	friend bool operator == (const Number& left, const Number& right);

	void operator = (Number& obj);
	void operator = (const long long int& obj);
	

	friend std::ostream& operator <<(std::ostream& os, const Number obj);
	
};