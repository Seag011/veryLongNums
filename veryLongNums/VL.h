#pragma once
#include "generalOperations.h"

class VL : private GeneralOp //very long 
{
protected: 
	
	friend VL& operator + (VL left, VL right);
	friend VL& operator - (VL left, VL right);
	friend VL& operator * (VL left, VL right);
	friend VL& operator / (VL left, VL right);

	friend VL& operator > (VL left, VL right);
	friend VL& operator >= (VL left, VL right);
	friend VL& operator < (VL left, VL right);
	friend VL& operator <= (VL left, VL right);
	friend VL& operator == (VL left, GeneralOp right);

};