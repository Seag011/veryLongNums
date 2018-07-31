#include "stdafx.h"
#include "Cell.h"

Cell operator+(Cell const& left, Cell const& right)
{
	Cell result = (left.body + right.body);
	return result;
}

Cell operator-(Cell const& left, Cell const& right)
{
	if (left < right)
		return (MAX_CELL + 1 + left.body) - right.body;
	else 
		return (left.body - right.body);
}

Cell operator+(const U& left, const Cell& right)
{
	Cell r;
	r = right.body + left;
	return r;
}

Cell operator+(const Cell& right, const U& left)
{
	Cell r;
	r = right.body + left;
	return r;
}

Cell operator-(const U& left, const Cell& right)
{
	Cell r = Cell(left) - Cell(right.body);
	return r;
}

Cell operator-(const Cell & right, const U & left)
{
	Cell r = Cell(right.body) - Cell(left);
	return r;
}

bool operator>(Cell const& left, Cell const& right)
{
	return (left.body > right.body);
}

bool operator>=(Cell const& left, Cell const& right)
{
	return (left.body >= right.body);
}

bool operator<(Cell const& left, Cell const& right)
{
	return (left.body < right.body);
}

bool operator<=(Cell const& left, Cell const& right)
{
	return (left.body <= right.body);
}

bool operator==(Cell const& left, Cell const& right)
{
	return (left.body == right.body);
}

Cell::Cell()
{
	Cell(0);
}

Cell Cell::operator+=(const U& right)
{
	return (*this + right);
}

Cell Cell::operator-=(const U& right)
{
	return (*this - right);
}

Cell Cell::operator%=(const U & right)
{
	return this->body % right;
}

Cell operator % (const Cell& left, const U& right)
{
	return Cell(left.body % right);
}

Cell Cell::operator+=(const Cell & right)
{
	this->body += right.body;
	return *this;
}

Cell Cell::operator-=(const Cell & right)
{
	this->body -= right.body;
	return *this;
}

Cell Cell::operator%=(const Cell & right)
{
	return this->body % right.body;
}

void Cell::operator=(const U& right)
{
	this->body = right;
}

void Cell::operator=(Cell const& right)
{
	this->body = right.body;
}

std::ostream& operator<<(std::ostream& os, const Cell& obj)
{
	os << obj.body;
	return os;
}
//DONE ALL!------------------------------------------------------