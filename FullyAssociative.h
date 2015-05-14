#ifndef FULLYASSOCIATIVE_H
#define FULLYASSOCIATIVE_H

#include "Globals.h"
#include <vector>

class FullyAssociative
{
public:
	static double cacheSimFAHitRatio(unsigned int, unsigned int, unsigned int(*)(), Globals::LineReplacement);
private:
	static Globals::CacheResType cacheSimFA(unsigned int, std::vector<CacheLine> &, Globals::LineReplacement);
};

#endif
