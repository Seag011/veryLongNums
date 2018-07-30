#pragma once
struct Cell
{
	U body : 15;
	Cell();
	Cell(US a) : body(a){};
	

	friend Cell operator +  (const Cell& left, const Cell& right);
	friend Cell operator -  (const Cell& left, const Cell& right);

	friend bool operator >  (const Cell& left, const Cell& right);
	friend bool operator >= (const Cell& left, const Cell& right);
	friend bool operator <  (const Cell& left, const Cell& right);
	friend bool operator <= (const Cell& left, const Cell& right);
	friend bool operator == (const Cell& left, const Cell& right);

	Cell& operator = (const US& right);
	Cell& operator = (const Cell& right);
};