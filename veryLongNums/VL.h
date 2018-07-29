#pragma once
#include "generalOperations.h"

class VL : private GeneralOp //very long 
{
protected: 
	
	friend VL& operator + (const VL& left, const VL& right);
	friend VL& operator - (const VL& left, const VL& right);
	friend VL& operator * (const VL& left, const VL& right);
	friend VL& operator / (const VL& left, const VL& right);

	friend bool operator >  (const VL& left, const VL& right);
	friend bool operator >= (const VL& left, const VL& right);
	friend bool operator <  (const VL& left, const VL& right);
	friend bool operator <= (const VL& left, const VL& right);
	friend bool operator == (const VL& left, const VL& right);

};