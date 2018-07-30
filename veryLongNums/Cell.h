#pragma once
struct Cell
{
	U body : 15; //to 32768
	Cell();
	Cell(U a) : body(a){};
	
	friend Cell operator +  (const Cell& left, const Cell& right);
	friend Cell operator -  (const Cell& left, const Cell& right);

	friend bool operator >  (const Cell& left, const Cell& right);
	friend bool operator >= (const Cell& left, const Cell& right);
	friend bool operator <  (const Cell& left, const Cell& right);
	friend bool operator <= (const Cell& left, const Cell& right);
	friend bool operator == (const Cell& left, const Cell& right);

	void operator = (const U& right);
	void operator = (const Cell& right);

	friend std::ostream& operator <<(std::ostream& os, const Cell& obj);
};