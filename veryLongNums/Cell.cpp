#include "stdafx.h"
#include "Cell.h"

Cell operator+(Cell const& left, Cell const& right)
{
	Cell result = (left.body + right.body);
	return result;
}
//DONE:
Cell operator-(Cell const& left, Cell const& right)
{
	if (left < right)
		return (MAX_CELL + 1 + left.body) - right.body;
	else 
		return (left.body - right.body);
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
	body = 0;
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