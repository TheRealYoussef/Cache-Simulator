#ifndef SETASSOCIATIVE_H
#define SETASSOCIATIVE_H

#include "Globals.h"

class SetAssociative
{
public:
	static double cacheSimSAHitRatio(unsigned int, unsigned int, unsigned int, unsigned int(*)(), Globals::LineReplacement);
private:
	static Globals::CacheResType cacheSimSA(unsigned int, unsigned int, std::vector<CacheLine> &, Globals::LineReplacement);
};

#endif