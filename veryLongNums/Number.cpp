#include "stdafx.h"
#include "Number.h"

Number & operator+(const Number & left, const Number & right)
{
	Number result;
	Cell temp;
	for(size_t i = 0; i < MAX_CELLS; i++)
	{
		result.body[i] = (left.body[i] + right.body[i]);
	}
}

Number & operator-(const Number & left, const Number & right)
{
	// TODO: insert return statement here
}

Number & operator*(const Number & left, const Number & right)
{
	// TODO: insert return statement here
}

Number & operator/(const Number & left, const Number & right)
{
	// TODO: insert return statement here
}

bool operator>(const Number & left, const Number & right)
{
	return false;
}

bool operator>=(const Number & left, const Number & right)
{
	return false;
}

bool operator<(const Number & left, const Number & right)
{
	return false;
}

bool operator<=(const Number & left, const Number & right)
{
	return false;
}

bool operator==(const Number & left, const Number & right)
{
	return false;
}

Number::Number()
{
	for(size_t i = 0; i < MAX_CELLS; i++)
	{
		this->body[i] = 0;
	}
}

US Number::size()
{
	return (this->body.size());
}

void Number::operator=(const Number& right)
{
	for (size_t i = 0; i < MAX_CELLS || i < (right.size()); i++)
	{
		
	}
}
