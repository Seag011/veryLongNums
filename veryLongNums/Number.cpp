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

const U& Number::size()
{
	return (this->body.size());
}

void Number::operator=(Number& obj)
{
	U obj_size = obj.size();
	for (size_t i = 0; i < obj_size; i++)
	{
		this->body.resize(obj_size);
		this->body[i] = obj.body[i];
	}
}

void Number::operator=(const long long int& obj)
{

}


std::ostream& operator <<(std::ostream& os, const Number& obj)
{
	Number a = obj;	 
	U obj_size = a.size();	

	if (obj_size != 0)
	{
		if (obj_size < 0)
			os << "-";
		for (size_t i = obj_size - 1; i > 0; i++)
		{
			os << obj.body[i]; 
		}
	}
	else
		os << "0";
}