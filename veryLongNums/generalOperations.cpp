#include "stdafx.h"
#include "generalOperations.h"


GeneralOp& operator+(GeneralOp left, GeneralOp right)
{
	for(size_t i = 0; i < MAX_CELLS - 1; i++)
	{
		US current = left.number.body[i] + left.number.body[i];
		if ( )
	}
}

GeneralOp& operator-(GeneralOp left, GeneralOp right)
{
}

GeneralOp& operator*(GeneralOp left, GeneralOp right)
{
}

GeneralOp& operator/(GeneralOp left, GeneralOp right)
{
}

GeneralOp& operator>(GeneralOp left, GeneralOp right)
{
}

GeneralOp& operator>=(GeneralOp left, GeneralOp right)
{
}

GeneralOp& operator<(GeneralOp left, GeneralOp right)
{
}

GeneralOp& operator<=(GeneralOp left, GeneralOp right)
{
}

GeneralOp& operator==(GeneralOp left, GeneralOp right)
{
}

GeneralOp GeneralOp::operator=(GeneralOp right)
{
	
}
