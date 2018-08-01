#include "stdafx.h"
#include "Number.h"
#include <algorithm>

Number & operator+(const Number & left, const Number & right)
{
	static Number l;
	Number r;
	l = left;
	r = right;
	if (l.sign == r.sign)
	{
		U max = std::max(Number::size(left), Number::size(right));
		l.body.resize(max);
		r.body.resize(max);
		for (U i = 0; i < max; i++)
		{
			l.body[i] += r.body[i];
			if (l.body[i] > MAX_CELL)
			{
				if (i < max - 1)
				{
					l.body[i + 1] += l.body[i] / TOP_BORDER;
					l.body[i] %= TOP_BORDER;
				}
				else
				{
					l.body.push_back(l.body[i] / TOP_BORDER);
					l.body[i] %= TOP_BORDER;
				}
			}
		}
	}
	else
		return (l - r);
	return l;
}
//TEST
Number & operator-(const Number & left, const Number & right)
{
	Number r;
	static Number l;
	l = left;
	if (Number::abs(left) < Number::abs(right))
	{
		Number temp = l;
		l = r;
		r = temp;
	}
	U max = std::max(Number::size(left), Number::size(right));
	l.body.resize(max);
	r.body.resize(max);
	for(L i = max - 1; i >= 0; i--)
	{
		l.body[i] -= r.body[i];
		if (l.body[i] < r.body[i])
			l.body[i + 1] += 1;
	}
	l.normalize();
	return l;
}
//TEST
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

Number::Number(const L & obj)
{
	L temp = obj;
	if (obj < 0)
	{
		this->sign = false;
		temp *= -1;
	}
	else
		this->sign = true;

	while (temp > 0)
	{
		this->body.push_back(Cell(temp % TOP_BORDER));
		temp /= TOP_BORDER;
	}
}

Number::Number(const L& obj, const bool& Sign)
{
	Number a(obj);
	sign = Sign;
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
}

void Number::normalize()
{
	for(L i = this->body.size() - 1; i >= 0; i--)
	{
		if (this->body[i] == 0)
			this->body.erase(this->body.end());
		else
			break;
	}
}
//TODO 
Number Number::abs(const Number& obj)
{
	Number temp = obj;
	temp.sign = true;
	return temp;
}
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