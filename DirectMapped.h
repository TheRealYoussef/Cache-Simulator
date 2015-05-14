#ifndef DIRECTMAPPED_H
#define DIRECTMAPPED_H

#include "Globals.h"

class DirectMapped
{
public:
	static double cacheSimDMHitRatio(unsigned int, unsigned int, unsigned int(*)());
private:
	// Direct Mapped Cache Simulator
	static Globals::CacheResType cacheSimDM(unsigned int, std::vector<CacheLine> &);
};

#endif