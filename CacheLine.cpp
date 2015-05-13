#include "CacheLine.h"

CacheLine::CacheLine()
{
	validity = 0;
}

bool CacheLine::getValidity() const
{
	return validity;
}

int CacheLine::getTag() const
{
	return tag;
}

void CacheLine::setValidity(bool v)
{
	validity = v;
}

void CacheLine::setTag(int t)
{
	tag = t;
}