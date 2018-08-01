#pragma once
#include "stdafx.h"
#include "Cell.h"

struct Number
{
public:
	std::vector <Cell> body;
	/* true - positive 
	*  false - nagative  */
	bool sign = true;
	
				
	Number();
	Number(const L& obj);
	Number(const L& obj, const bool& sign);

	
	//pos the left is the most biggest
	US pull_num(U pos);
	
	void normalize();
	static Number abs(const Number& obj);
	static U size(const Number& obj);

	friend Number& operator + (const Number & left, const Number & right);
	friend Number& operator - (const Number& left, const Number& right);
	friend Number& operator * (const Number& left, const Number& right);
	friend Number& operator / (const Number& left, const Number& right);

	friend bool operator >  (const Number& left, const Number& right);
	friend bool operator >= (const Number& left, const Number& right);
	friend bool operator <  (const Number& left, const Number& right);
	friend bool operator <= (const Number& left, const Number& right);
	friend bool operator == (const Number& left, const Number& right);

	void operator = (const Number& obj);
	void operator = (const LL& obj);
	
	Number& operator += (const Number & right);

	friend std::ostream& operator <<(std::ostream& os, const Number obj);
	
private:
	void insertCell(const Cell& obj);
};

//add isNextInCell
// NextInCell return a va;ue of Cell / 1000