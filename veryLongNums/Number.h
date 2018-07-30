#pragma once
#include "stdafx.h"
#include "Cell.h"

struct Number
{
public:
	std::vector <Cell> body;
	bool sign = true;
	/* False - negative * 
	 * true - positive  */
				
	Number();

	const U& size();
	US pull_num(U pos);
	/* pos the left 
	 * is the most biggest 
	 */
	
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
	void operator = (const LL& obj);
	

	friend std::ostream& operator <<(std::ostream& os, const Number obj);
	
};