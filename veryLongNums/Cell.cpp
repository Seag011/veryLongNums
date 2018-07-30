#include "stdafx.h"
#include "Cell.h"

Cell operator+(Cell const& left, Cell const& right)
{
	Cell result = (left.body + right.body);
	return result;
}

Cell operator-(Cell const& left, Cell const& right)
{
	Cell result = (left.body - right.body);
	return result;
}

bool operator>(Cell const& left, Cell const& right)
{
	if (left.body > right.body)
		return true;
	return false;
}

bool operator>=(Cell const& left, Cell const& right)
{
	if (left.body >= right.body)
		return true;
	return false;
}

bool operator<(Cell const& left, Cell const& right)
{
	if (left.body < right.body)
		return true;
	return false;
}

bool operator<=(Cell const& left, Cell const& right)
{
	if (left.body <= right.body)
		return true;
	return false;
}

bool operator==(Cell const& left, Cell const& right)
{
	if (left.body == right.body)
		return true;
	return false;
}

Cell& Cell::operator = (US const& right)
{
	this->body = right;
}

Cell& Cell::operator=(Cell const& right)
{
	this->body = right.body;
}

std::ostream& operator<<(std::ostream& os, const Cell& obj)
{
	os << obj.body;
}