#ifndef DIRECTMAPPED_H
#define DIRECTMAPPED_H

#include "Globals.h"

class DirectMapped
{
public:
	// Direct Mapped Cache Simulator
	static Globals::CacheResType cacheSimDM(unsigned int, std::vector<CacheLine> &);
};

#endif