#include "stdafx.h"
#include "Cell.h"
/*===========================================================*/
Cell operator+(Cell const& left, Cell const& right)
{
	Cell result;
	result = left.body + right.body;
	return result;
}

Cell operator+(const U& left, const Cell& right)
{
	Cell result;
	result = right.body + left;
	return result;
}

Cell operator+(const Cell& left, const U& right)
{
	Cell result;
	result = left.body + right;
	return result;
}

Cell& Cell::operator+=(const Cell& right)
{
	*this = *this + right;
	return *this;
}

Cell& Cell::operator+=(const U& right)
{
	*this = *this + right;
	return *this;
}
/*===========================================================*/
Cell operator-(Cell const& left, Cell const& right)
{
	Cell result;
	if (left < right)
		result = (left.body - right.body)+ TOP_BORDER;
	else 
		result = (left.body - right.body);
	return result;
}

Cell operator-(const U& left, const Cell& right)
{
	Cell result = Cell(left) - Cell(right.body);
	return result;
}

Cell operator-(const Cell & left, const U & right)
{
	Cell result = Cell(left.body) - Cell(right);
	return result;
}

Cell& Cell::operator-=(const Cell& right)
{
	*this = *this - right;
	return *this;
}

Cell& Cell::operator-=(const U& right)
{
	*this = *this - right;
	return *this;
}
/*===========================================================*/
Cell operator/(const Cell& left, const Cell& right)
{
	Cell result;
	result = left.body / right.body;
	return result;
}

Cell operator/(const U& left, const Cell& right)
{
	Cell result;
	result = (left / right.body);
	return result;
}

Cell operator/(const Cell& left, const U& right)
{
	Cell result;
	result = Cell(left.body / right);
	return result;
}

Cell& Cell::operator/=(const Cell& right)
{
	*this = *this / right;
	return *this;
}

Cell& Cell::operator/=(const U& right)
{
	*this = *this / right;
	return *this;
}
/*===========================================================*/
Cell operator % (const Cell& left, const Cell& right)
{
	Cell result;
	result = left.body % right.body;
	return result;
}

Cell operator % (const U& left, const Cell& right)
{
	Cell result;
	result = left % right.body;
	return result;
}

Cell operator % (const Cell & left, const U & right)
{
	Cell result;
	result = left.body % right;
	return result;
}

Cell& Cell::operator%=(const Cell & right)
{
	*this = *this % right;
	return *this;
}

Cell& Cell::operator%=(const U & right)
{
	*this = *this % right;
	return *this;
}
/*===========================================================*/

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

bool operator!=(const Cell& left, const Cell& right)
{
	return (left.body != right.body);
}
/*-----------------------------------------------------------------*/
bool operator>(const Cell& left, const U& right)
{
	return (left.body > right);
}

bool operator>=(const Cell& left, const U& right)
{
	return (left.body >= right);
}

bool operator<(const Cell& left, const U& right)
{
	return (left.body < right);
}

bool operator<=(const Cell& left, const U& right)
{
	return (left.body <= right);
}

bool operator==(const Cell& left, const U& right)
{
	return (left.body == right);
}

bool operator!=(const Cell& left, const U& right)
{
	return (left.body != right);
}
/*-----------------------------------------------------------------*/
bool operator>(const U& left, const Cell& right)
{
	return (left > right.body);
}

bool operator>=(const U& left, const Cell& right)
{
	return (left >= right.body);
}

bool operator<(const U& left, const Cell& right)
{
	return (left < right.body);
}

bool operator<=(const U& left, const Cell& right)
{
	return (left <= right.body);
}

bool operator==(const U& left, const Cell& right)
{
	return (left == right.body);
}
bool operator!=(const U& left, const Cell& right)
{
	return (left != right.body);
}
/*=================================================================*/

Cell Cell::operator=(const U& right)
{
	this->body = right;
	return *this;
}

Cell Cell::operator=(Cell const& right)
{
	this->body = right.body;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Cell& obj)
{
	os << obj.body;
	return os;
}

Cell::Cell()
{
	Cell(0);
}

Cell::Cell(U a) 
: body(a)
{}
/*=====================-{DONE ALL}-==========================*/