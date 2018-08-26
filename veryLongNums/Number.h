#pragma once
#include "stdafx.h"
#include "Cell.h"

struct Number : public Cell
{
private:
	U static setMaxOfTwoSizes(Number& first, Number& second);
	void insertLowerDigitCell(const Cell& obj);
	void normalize();
	void swapIsLess(Number& left, Number& right);
public:
	std::vector <Cell> number;
	/**
	 * \brief
	 * true - positive;
	 *  false - nagative  */
	bool sign = true;
	
	//pos the left is the most biggest
	US pull_num(U pos);

	static Number abs(const Number& obj);
	static LL size(const Number& obj);
	//UNDONE
				
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

	
	Number& operator =  (const Number& obj);
	Number& operator += (const Number& right);
	Number& operator -= (const Number& right);
	Number& operator *= (const Number& right);
	Number& operator /= (const Number& right);
	Number& operator %= (const Number& right);

	Number& operator =  (const LL& obj);
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
};