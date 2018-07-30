#include "stdafx.h"
#include "Number.h"

Number & operator+(const Number & left, const Number & right)
{
	
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
{}

const U& Number::size()
{
	return (this->body.size());
}

US Number::pull_num(U pos)
{
	return US();
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

void Number::operator=(const LL& obj)
{
	LL temp = obj;
	if (temp < 0)
		this->sign = false;
	while (temp > 0)
	{
		this->body.push_back(temp % 1000);
		temp /= 1000;
	}
}


std::ostream& operator <<(std::ostream& os, const Number& obj)
{
	Number a = obj;	 
	U obj_size = a.size();	

	if (obj_size != 0)
	{
		if (!a.sign)
			os << "-";
		for (L i = obj_size - 1; i >= 0; i--)
		{
			os << obj.body[i]; 
		}
	}
	else
		os << "0";
	return os;
}