#pragma once
struct Cell
{
	US cell : 15; //to 32768
	Cell();
	explicit Cell(U a);
	
	friend Cell operator + (const Cell& left, const Cell& right);
	friend Cell operator - (const Cell& left, const Cell& right);
	friend Cell operator / (const Cell& left, const Cell& right);
	friend Cell operator % (const Cell& left, const Cell& right);

	friend Cell operator + (const Cell& left, const U& right);
	friend Cell operator - (const Cell& left, const U& right);
	friend Cell operator / (const Cell& left, const U& right);
	friend Cell operator % (const Cell& left, const U& right);

	friend Cell operator + (const U& left, const Cell& right);
	friend Cell operator - (const U& left, const Cell& right);
	friend Cell operator / (const U& left, const Cell& right);
	friend Cell operator % (const U& left, const Cell& right);

	Cell&  operator =  (const Cell& right);
	Cell& operator += (const Cell& right);
	Cell& operator -= (const Cell& right);
	Cell& operator /= (const Cell& right);
	Cell& operator %= (const Cell& right);

	Cell&  operator =  (const U& right);
	Cell& operator += (const U& right);
	Cell& operator -= (const U& right);
	Cell& operator /= (const U& right);
	Cell& operator %= (const U& right);

	friend bool operator >  (const Cell& left, const Cell& right);
	friend bool operator >= (const Cell& left, const Cell& right);
	friend bool operator <  (const Cell& left, const Cell& right);
	friend bool operator <= (const Cell& left, const Cell& right);
	friend bool operator == (const Cell& left, const Cell& right);
	friend bool operator != (const Cell& left, const Cell& right);


	friend bool operator >  (const Cell& left, const U& right);
	friend bool operator >= (const Cell& left, const U& right);
	friend bool operator <  (const Cell& left, const U& right);
	friend bool operator <= (const Cell& left, const U& right);
	friend bool operator == (const Cell& left, const U& right);
	friend bool operator != (const Cell& left, const U& right);

	friend bool operator >  (const U& left, const Cell& right);
	friend bool operator >= (const U& left, const Cell& right);
	friend bool operator <  (const U& left, const Cell& right);
	friend bool operator <= (const U& left, const Cell& right);
	friend bool operator == (const U& left, const Cell& right);	
	friend bool operator != (const U& left, const Cell& right);

	friend std::ostream& operator <<(std::ostream& os, const Cell& obj);
};