#include "stdafx.h"
#include "Number.h"
#include <algorithm>

U static setMaxOfTwoSizes(Number& first, Number& second)
{
	U max = std::max(Number::size(first), Number::size(second));
	first.number.resize(max);
	second.number.resize(max);
	return max;
}

void Number::insertLowerDigitCell(const Cell& obj)
{
	this->number.resize(this->number.size() + 1);
	for (LL i = this->number.size(); i > 0; i--)
		this->number[i] = this->number[i - 1];
	this->number[0] = obj;
}

void Number::normalize()
{
	for (LL i = this->number.size() - 1; i >= 0; i--)
	{
		if (this->number[i] == 0)
			this->number.erase(this->number.end());
		else
			break;
	}
	if (this->number.size() == 0)
		this->sign = true;
}
void Number::swapIsLess(Number & left, Number & right)
{
	if (Number::abs(left) < Number::abs(right))
	{
		Number temp = left;
		left = right;
		right = temp;
	}
}
//TODO 

Number::Number()
{
	sign = true;
	Cell a(0);
	number.push_back(a);
}

Number::Number(const LL& obj)
{
	LL temp = obj;
	if (obj < 0)
	{
		this->sign = false;
		temp *= -1;
	}
	else
		this->sign = true;

	while (temp > 0)
	{
		this->number.push_back(Cell(temp % TOP_BORDER));
		temp /= TOP_BORDER;
	}
}

Number::Number(const LL& obj, const bool& Sign)
{
	Number a(obj);
	sign = Sign;
}

//TEST
LL Number::size(const Number& obj)
{
	return obj.number.size();
}
//TEST
US Number::pull_num(U pos)
{
	return US();
}
//UNDONE
Number Number::abs(const Number& obj)
{
	Number temp = obj;
	temp.sign = true;
	return temp;
}
//TEST
/*=================================================================*/
Number& operator+(const Number& left, const Number& right)
{
	static Number l;
	Number r;
	if (left.sign == right.sign)
	{	
		l = left;
		r = right;
		LL max = setMaxOfTwoSizes(l, r);
		for (LL i = 0; i < max; i++)
		{
			l.number[i] += r.number[i];
			if (l.number[i] > MAX_CELL)
			{
				if (i < max - 1)
				{
					l.number[i + 1] += l.number[i] / TOP_BORDER;
					l.number[i] %= TOP_BORDER;
				}
				else
				{
					l.number.push_back(l.number[i] / TOP_BORDER);
					l.number[i] %= TOP_BORDER;
				}
			}
		}
	}
	else
		return (l - r);
	return l;
}
//TEST
Number& operator-(const Number& left, const Number& right)
{
	static Number l;
	Number r;
	//---------
	if (left.sign != right.sign)
	{
		if (Number::abs(left) < Number::abs(right))
		{
			Number temp = l;
			l = r;
			r = temp;
		}
		//TODO: put into swapIsLess()
	

		LL max = setMaxOfTwoSizes(l, r);

		for (LL i = max - 1; i >= 0; i--)
		{
			l.number[i] -= r.number[i];
			if (l.number[i] < r.number[i])
				l.number[i + 1] += 1;
		}
		l.normalize();
	}
	else 
		return (l + r);
	return l;
}
//TEST
Number& operator*(const Number& left, const Number& right)
{
	static Number result;
	Number l;
	Number r;
	l = left;
	r = right;

	LL max_size = l.number.size() * r.number.size();
	result.number.resize(max_size);

	for (LL i = 0; i < r.number.size(); i++)
	{
		Number current(0);
		current.number.resize(max_size);
		for (LL j = 0; j < l.number.size(); j++)
		{
			LL temp = r.number[i].cell * l.number[j].cell;
			current.number[i] += temp % TOP_BORDER;
			current.number[i+1] += temp / TOP_BORDER;
		}
		for (LL j = 0; j < i; j++)
			current.insertLowerDigitCell(Cell(0));

		current.normalize();
		result += current;
	}
	result.normalize();
	return result;
}//TODO

Number& operator/(const Number& left, const Number& right)
{
	static Number result(0);
	Number l = left;
	Number r = right;
	if (Number::abs(l) > Number::abs(r))
	{
		if (l == r)
			result = 1;
		else
		{
			//ищем делитель делением на отрезки вдвое меньшей длины
			U sizeOfResult = l.number.size() - r.number.size();
			ULL compareHighBorder = pow(10, sizeOfResult) - 1;
			ULL compareLowBorder = (compareHighBorder + 1) / 10;
			while(compareHighBorder - compareLowBorder > 1)
			{
				// доделать если верхнаяя граница и результат будет равен 
				Number temp = (Number)(compareHighBorder)* r;
				if (temp > l)
					compareHighBorder = (compareHighBorder + compareLowBorder) / 2;
				else
					if (temp == l)
						result = compareHighBorder;
						else
							compareLowBorder = 
							(compareHighBorder + compareLowBorder) / 2;
			}
			result = compareLowBorder;
		}
	}
	if (l.sign != r.sign)
		result.sign = false;
	else
		result.sign = l.sign;
	return result;
}//TODO

Number& operator%(const Number& left, const Number& right)
{
	static Number result(0);
	Number l = left;
	Number r = right;
	l /= r;
	return  left - l;
}//TODO

Number& operator+(const Number& left, const LL& right)
{
	Number _right(right);
	return left + _right;
}

Number& operator-(const Number& left, const LL& right)
{
	Number _right(right);
	return left - _right;
}

Number& operator*(const Number& left, const LL& right)
{
	Number _right(right);
	return left * _right;
}

Number& operator/(const Number& left, const LL& right)
{
	Number _right(right);
	return left / _right;
}

Number& operator%(const Number& left, const LL& right)
{
	Number _right(right);
	return left % _right;
}

Number& operator+(const LL& left, const Number& right)
{
	Number _left(left);
	return _left + right;
}

Number& operator-(const LL& left, const Number& right)
{
	Number _left(left);
	return _left - right;
}

Number& operator*(const LL& left, const Number& right)
{
	Number _left(left);
	return _left * right;
}

Number& operator/(const LL& left, const Number& right)
{
	Number _left(left);
	return _left / right;
}

Number& operator%(const LL& left, const Number& right)
{
	Number _left(left);
	return _left % right;
}
/*=================================================================*/
bool operator>(const Number& left, const Number& right)
{
	if (left.sign != right.sign)
		return left.sign && !right.sign;
	else
	{
		if (Number::size(left) != Number::size(right))
			return Number::size(left) > Number::size(right);
		else
		{
			for (LL i = Number::size(left) - 1; i >= 0; i--)
			{
				if (left.number[i] > right.number[i])
					return (left.sign ? true : false);
				if (left.number[i] < right.number[i])
					return (!left.sign ? true : false);
			}
		}
	}
	return false;
}
//TEST
bool operator>=(const Number& left, const Number& right)
{
	if (left.sign != right.sign)
		return left.sign && !right.sign;
	else
	{
		if (Number::size(left) != Number::size(right))
			return Number::size(left) > Number::size(right);
		else
		{
			for (LL i = Number::size(left) - 1; i >= 0; i--)
			{
				if (left.number[i] > right.number[i])
					return (left.sign ? true : false);
				if (left.number[i] < right.number[i])
					return (!left.sign ? true : false);
			}
		}
	}
	return true;
}
//TEST
bool operator<(const Number& left, const Number& right)
{
	if (left.sign != right.sign)
		return right.sign && !left.sign;
	else
	{
		if (Number::size(left) != Number::size(right))
			return Number::size(left) < Number::size(right);
			else
			{
				for (LL i = Number::size(left) - 1; i >= 0; i--)
				{
					if (left.number[i] < right.number[i])
						return (left.sign ? true : false);
					if (left.number[i] > right.number[i])
						return (!left.sign ? true : false);
				}
			}
		}
		return false; //for equality
}
//TEST
bool operator<=(const Number& left, const Number& right)
{
	if (left.sign != right.sign)
		return right.sign && !left.sign;
	else
	{
		if (Number::size(left) != Number::size(right))
			return Number::size(left) < Number::size(right);
		else
		{
			for (LL i = Number::size(left) - 1; i >= 0; i--)
			{
				if (left.number[i] < right.number[i])
					return (left.sign ? true : false);
				if (left.number[i] > right.number[i])
					return (!left.sign ? true : false);
			}
		}
	}
	return true; //for equality
}
 //TEST
bool operator==(const Number& left, const Number& right)
{
	if (Number::size(left) != Number::size(right))
		return false;
	if (left.sign != right.sign)
		return false;

	for (LL i = 0; i < Number::size(left); i++)
	{
		if (left.number != right.number)
			return false;
	}
	return true;
}

bool operator>(const Number& left, const LL& right)
{
	return (left > Number(right));
}

bool operator>=(const Number& left, const LL& right)
{
	return (left >= Number(right));
}

bool operator<(const Number& left, const LL& right)
{
	return (left > Number(right));
}

bool operator<=(const Number& left, const LL& right)
{
	return (left <= Number(right));
}

bool operator==(const Number& left, const LL& right)
{
	return (left == Number(right));
}

bool operator>(const LL& left, const Number& right)
{
	return (Number(left) > right);
}

bool operator>=(const LL& left, const Number& right)
{
	return (Number(left) >= right);
}

bool operator<(const LL& left, const Number& right)
{
	return (Number(left) < right);
}

bool operator<=(const LL& left, const Number& right)
{
	return (Number(left) <= right);
}

bool operator==(const LL& left, const Number& right)
{
	return (Number(left) == right);
}
//TEST
bool operator!=(const Number& left, const Number& right)
{
	if (Number::size(left) != Number::size(right))
		return true;
	if (left.sign != right.sign)
		return true;

	for (LL i = 0; i < Number::size(left); i++)
	{
		if (left.number != right.number)
			return true;
	}
	return false;
}
//TEST
/*=================================================================*/

Number& Number::operator = (const Number& obj)
{
	LL obj_size = Number::size(obj);
	for (LL i = 0; i < obj_size; i++)
	{
		this->number.resize(obj_size);
		this->number[i] = obj.number[i];
	}
	return *this;
}
//TEST
Number& Number::operator = (const LL& obj)
{
	LL temp = obj;
	if (temp < 0)
		this->sign = false;
	while (temp > 0)
	{
		//this->number.push_back(temp % 1000);
		temp /= 1000;
	}
	return *this;
}

Number& Number::operator += (const Number& right)
{
	*this = *this + right;
	return *this;
}

Number& Number::operator-=(const Number& right)
{
	*this = *this - right;
	return *this;
}

Number& Number::operator*=(const Number& right)
{
	*this = *this * right;
	return *this;
}

Number& Number::operator/=(const Number& right)
{
	*this = *this / right;
	return *this;
}

Number& Number::operator%=(const Number& right)
{
	*this = *this % right;
	return *this;
}

Number& Number::operator+=(const LL& right)
{
	*this = *this + right;
	return *this;
}

Number& Number::operator-=(const LL& right)
{
	*this = *this - right;
	return *this;
}

Number& Number::operator*=(const LL& right)
{
	*this = *this * right;
	return *this;
}

Number& Number::operator/=(const LL& right)
{
	*this = *this / right;
	return *this;
}

Number& Number::operator%=(const LL& right)
{
	*this = *this % right;
	return *this;
}

//TEST
std::ostream& operator << (std::ostream& os, const Number& obj)
{
	Number a = obj;	 
	U obj_size = Number::size(obj);

	if (obj_size != 0)
	{
		if (!a.sign)
			os << "-";
		for (LL i = obj_size - 1; i >= 0; i--)
		{
			os << obj.number[i]; 
		}
	}
	else
		os << "0";
	return os;
}
//TEST