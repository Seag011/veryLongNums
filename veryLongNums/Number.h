#pragma once
#include "stdafx.h"
#include "Cell.h"

struct Number : public Cell
{
public:
	std::vector <Cell> body;
	/* true - positive 
	*  false - nagative  */
	bool sign = true;
	
				
	Number();
	Number(const LL& obj);
	Number(const LL& obj, const bool& sign);

	friend Number& operator + (const Number &left, const Number& right);
	friend Number& operator - (const Number& left, const Number& right);
	friend Number& operator * (const Number& left, const Number& right);
	friend Number& operator / (const Number& left, const Number& right);
	friend Number& operator % (const Number& left, const Number& right);

	friend Number& operator + (const Number& left, const LL& right);
	friend Number& operator - (const Number& left, const LL& right);
	friend Number& operator * (const Number& left, const LL& right);
	friend Number& operator / (const Number& left, const LL& right);
	friend Number& operator % (const Number& left, const LL& right);

	friend Number& operator + (const LL& left, const Number& right);
	friend Number& operator - (const LL& left, const Number& right);
	friend Number& operator * (const LL& left, const Number& right);
	friend Number& operator / (const LL& left, const Number& right);
	friend Number& operator % (const LL& left, const Number& right);

	void operator = (const Number& obj);
	void operator = (const LL& obj);

	Number& operator += (const Number& right);
	Number& operator -= (const Number& right);
	Number& operator *= (const Number& right);
	Number& operator /= (const Number& right);
	Number& operator %= (const Number& right);

	Number& operator += (const LL& right);
	Number& operator -= (const LL& right);
	Number& operator *= (const LL& right);
	Number& operator /= (const LL& right);
	Number& operator %= (const LL& right);

	friend bool operator >  (const Number& left, const Number& right);
	friend bool operator >= (const Number& left, const Number& right);
	friend bool operator <  (const Number& left, const Number& right);
	friend bool operator <= (const Number& left, const Number& right);
	friend bool operator == (const Number& left, const Number& right);
	 
	friend bool operator >  (const Number& left, const LL& right);
	friend bool operator >= (const Number& left, const LL& right);
	friend bool operator <  (const Number& left, const LL& right);
	friend bool operator <= (const Number& left, const LL& right);
	friend bool operator == (const Number& left, const LL& right);

	friend bool operator >  (const LL& left, const Number& right);
	friend bool operator >= (const LL& left, const Number& right);
	friend bool operator <  (const LL& left, const Number& right);
	friend bool operator <= (const LL& left, const Number& right);
	friend bool operator == (const LL& left, const Number& right);

	friend std::ostream& operator <<(std::ostream& os, const Number& obj);

	//pos the left is the most biggest
	US pull_num(U pos);

	void normalize();
	static Number abs(const Number& obj);
	static U size(const Number& obj);
	
private:
	void insertCell(const Cell& obj);
};

//add isNextInCell
// NextInCell return a va;ue of Cell / 1000