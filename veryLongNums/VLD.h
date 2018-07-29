#pragma once
#include "generalOperations.h"

class VLD;

class VLD : private
	GeneralOp
{
protected:
	struct Number
	{
		GeneralOp::Number number[MAX_CELLS];
		double fraction = 0;
	};

	friend VLD& operator + (VLD left, VLD right);
	friend VLD& operator - (VLD left, VLD right);
	friend VLD& operator * (VLD left, VLD right);
	friend VLD& operator / (VLD left, VLD right);

	friend VLD& operator > (VLD left, VLD right);
	friend VLD& operator >= (VLD left, VLD right);
	friend VLD& operator < (VLD left, VLD right);
	friend VLD& operator <= (VLD left, VLD right);
	friend VLD& operator == (VLD left, VLD right);


};