#include "stdafx.h"
#include "Number.h"
#include <algorithm>

Number & operator+(const Number & left, const Number & right)
{
	Number l, r;
	l = left;
	r = right;
	U max = std::max(Number::size(left), Number::size(right));
	l.body.resize(max);
	r.body.resize(max);
	for(U i = 0; i < max; i++)
	{
		l.body[i] += r.body[i];
		if (l.body[i - 1] > MAX_CELL && i > 0)
		{
			l.body[i] += 1;
			l.body[i] %= (MAX_CELL + 1);
		}
		else 
			if (i == max - 1 && l.body[i] > MAX_CELL)
			{
				l.body.resize(max + 1);
				l.body[i + 1] += 1;
				l.body[i] %= (MAX_CELL + 1);
			}
	}
	return l;
}//UNDONE
//TEST
Number & operator-(const Number & left, const Number & right)
{
	// TODO: insert return statement here
}
//TODO
Number & operator*(const Number & left, const Number & right)
{
	// TODO: insert return statement here
}//TODO

Number & operator/(const Number & left, const Number & right)
{
	// TODO: insert return statement here
}//TODO

bool operator>(const Number & left, const Number & right)
{
	if (left.sign != right.sign)
		return left.sign && !right.sign;
	else
	{
		if (Number::size(left) != Number::size(right))
			return Number::size(left) > Number::size(right);
		else
		{
			for (L i = Number::size(left) - 1; i >= 0; i--)
			{
				if (left.body[i] > right.body[i])
					return (left.sign ? true : false);
				if (left.body[i] < right.body[i])
					return (!left.sign ? true : false);
			}
		}
	}
	return false;
}
//TEST
bool operator>=(const Number & left, const Number & right)
{
	if (left.sign != right.sign)
		return left.sign && !right.sign;
	else
	{
		if (Number::size(left) != Number::size(right))
			return Number::size(left) > Number::size(right);
		else
		{
			for (L i = Number::size(left) - 1; i >= 0; i--)
			{
				if (left.body[i] > right.body[i])
					return (left.sign ? true : false);
				if (left.body[i] < right.body[i])
					return (!left.sign ? true : false);
			}
		}
	}
	return true;
}
//TEST
bool operator<(const Number & left, const Number & right)
{
	if (left.sign != right.sign)
		return right.sign && !left.sign;
	else
	{
		if (Number::size(left) != Number::size(right))
			return Number::size(left) < Number::size(right);
			else
			{
				for (L i = Number::size(left) - 1; i >= 0; i--)
				{
					if (left.body[i] < right.body[i])
						return (left.sign ? true : false);
					if (left.body[i] > right.body[i])
						return (!left.sign ? true : false);
				}
			}
		}
		return false; //for equality
}
//TEST
bool operator<=(const Number & left, const Number & right)
{
	if (left.sign != right.sign)
		return right.sign && !left.sign;
	else
	{
		if (Number::size(left) != Number::size(right))
			return Number::size(left) < Number::size(right);
		else
		{
			for (L i = Number::size(left) - 1; i >= 0; i--)
			{
				if (left.body[i] < right.body[i])
					return (left.sign ? true : false);
				if (left.body[i] > right.body[i])
					return (!left.sign ? true : false);
			}
		}
	}
	return true; //for equality
}
 //TEST
bool operator==(const Number & left, const Number & right)
{
	if (Number::size(left) != Number::size(right))
		return false;
	if (left.sign != right.sign)
		return false;

	for (size_t i = 0; i < Number::size(left); i++)
	{
		if (left.body != right.body)
			return false;
	}
	return true;
}
//TEST
bool operator!=(const Number & left, const Number & right)
{
	if(Number::size(left) != Number::size(right))
		return true;
	if (left.sign != right.sign)
		return true;

	for (size_t i = 0; i < Number::size(left); i++)
	{
		if (left.body != right.body)
			return true;
	}
	return false;
}
//TEST
Number::Number()
{
	sign = true;
	Cell a(0);
	body.push_back(a);
}
//TEST
U Number::size(const Number& obj)
{
	return obj.body.size();
}
//TEST
US Number::pull_num(U pos)
{
	return US();
}//TODO 
 //TEST
void Number::operator=(const Number& obj)
{
	U obj_size = Number::size(obj);
	for (size_t i = 0; i < obj_size; i++)
	{
		this->body.resize(obj_size);
		this->body[i] = obj.body[i];
	}
}
//TEST
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
//TEST
std::ostream& operator <<(std::ostream& os, const Number& obj)
{
	Number a = obj;	 
	U obj_size = Number::size(obj);

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
//TEST