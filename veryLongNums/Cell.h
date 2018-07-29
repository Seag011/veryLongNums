#pragma once 
struct Cell
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

};

s