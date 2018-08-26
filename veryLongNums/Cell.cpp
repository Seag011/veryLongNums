#include "stdafx.h"
#include "Cell.h"
/*===========================================================*/
Cell operator+(Cell const& left, Cell const& right)
{
	Cell result;
	result = left.cell + right.cell;
	return result;
}

Cell operator+(const U& left, const Cell& right)
{
	Cell result;
	result = right.cell + left;
	return result;
}

Cell operator+(const Cell& left, const U& right)
{
	Cell result;
	result = left.cell + right;
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
		result = (left.cell - right.cell)+ TOP_BORDER;
	else 
		result = (left.cell - right.cell);
	return result;
}

Cell operator-(const U& left, const Cell& right)
{
	Cell result = Cell(left) - Cell(right.cell);
	return result;
}

Cell operator-(const Cell & left, const U & right)
{
	Cell result = Cell(left.cell) - Cell(right);
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
	result = left.cell / right.cell;
	return result;
}

Cell operator/(const U& left, const Cell& right)
{
	Cell result;
	result = (left / right.cell);
	return result;
}

Cell operator/(const Cell& left, const U& right)
{
	Cell result;
	result = Cell(left.cell / right);
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
	result = left.cell % right.cell;
	return result;
}

Cell operator % (const U& left, const Cell& right)
{
	Cell result;
	result = left % right.cell;
	return result;
}

Cell operator % (const Cell & left, const U & right)
{
	Cell result;
	result = left.cell % right;
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
	return (left.cell > right.cell);
}

bool operator>=(Cell const& left, Cell const& right)
{
	return (left.cell >= right.cell);
}

bool operator<(Cell const& left, Cell const& right)
{
	return (left.cell < right.cell);
}

bool operator<=(Cell const& left, Cell const& right)
{
	return (left.cell <= right.cell);
}

bool operator==(Cell const& left, Cell const& right)
{
	return (left.cell == right.cell);
}

bool operator!=(const Cell& left, const Cell& right)
{
	return (left.cell != right.cell);
}
/*-----------------------------------------------------------------*/
bool operator>(const Cell& left, const U& right)
{
	return (left.cell > right);
}

bool operator>=(const Cell& left, const U& right)
{
	return (left.cell >= right);
}

bool operator<(const Cell& left, const U& right)
{
	return (left.cell < right);
}

bool operator<=(const Cell& left, const U& right)
{
	return (left.cell <= right);
}

bool operator==(const Cell& left, const U& right)
{
	return (left.cell == right);
}

bool operator!=(const Cell& left, const U& right)
{
	return (left.cell != right);
}
/*-----------------------------------------------------------------*/
bool operator>(const U& left, const Cell& right)
{
	return (left > right.cell);
}

bool operator>=(const U& left, const Cell& right)
{
	return (left >= right.cell);
}

bool operator<(const U& left, const Cell& right)
{
	return (left < right.cell);
}

bool operator<=(const U& left, const Cell& right)
{
	return (left <= right.cell);
}

bool operator==(const U& left, const Cell& right)
{
	return (left == right.cell);
}
bool operator!=(const U& left, const Cell& right)
{
	return (left != right.cell);
}
/*=================================================================*/

Cell& Cell::operator=(const U& right)
{
	this->cell = right;
	return *this;
}

Cell& Cell::operator=(Cell const& right)
{
	this->cell = right.cell;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Cell& obj)
{
	os << obj.cell;
	return os;
}

Cell::Cell()
{
	Cell(0);
}

Cell::Cell(U a) 
: cell(a)
{}
/*=====================-{DONE ALL}-==========================*/