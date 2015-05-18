#include "FullyAssociative.h"
#include <iostream>

double FullyAssociative::cacheSimFAHitRatio(unsigned int lineSize, unsigned int iterations, unsigned int(*memGen)(), Globals::LineReplacement lineReplace)
{
	unsigned int hits = 0;
	unsigned int addr;
	for (unsigned int inst = 0; inst < iterations; inst++)
	{
		addr = (*memGen)();
		if ((FullyAssociative::cacheSimFA)(addr, (caches[Globals::cacheLineSizeToIndex(lineSize)]), lineReplace) == (Globals::HIT))
			hits++;
	}
	return (hits / (double)iterations);
}

Globals::CacheResType FullyAssociative::cacheSimFA(unsigned int addr, std::vector<CacheLine> & cache, Globals::LineReplacement lineReplace)
{
	(cachesReset) = false;
	(accessesReset) = false;
	unsigned int lines = cache.size();
	unsigned int lineSize = ((CACHE_SIZE) / lines);
	unsigned int byteSelect = log2(lineSize);
	unsigned int cacheTag = (addr >> byteSelect);
	unsigned int cacheNumber = ((Globals::cacheLineSizeToIndex)(lineSize));
	//Access all lines in parallel but simulated using a loop
	for (unsigned int i = 0; i < lines; i++)
	{
		if (cache[i].getValidity() == 0)
		{
			cache[i].setValidity(1);
			cache[i].setTag(cacheTag);
			(Globals::updateArrays)(cacheNumber, i);
			return (Globals::MISS);
		}
		else if (cacheTag == cache[i].getTag())
		{
			(Globals::updateArrays)(cacheNumber, i);
			return (Globals::HIT);
		}
	}
	//Cache is full
	switch (lineReplace)
	{
	case (Globals::RANDOM):
		(Globals::lineAccess)(cache, ((Globals::rand_()) % lines), cacheTag, cacheNumber);
		break;
	case (Globals::LRU):
		(Globals::lineAccess)(cache, ((Globals::getMin)((timeAccessed[cacheNumber]), lineSize, 0, lines)), cacheTag, cacheNumber);
		break;
	case (Globals::LFU):
		(Globals::lineAccess)(cache, ((Globals::getMin)((accesses[cacheNumber]), lineSize, 0, lines)), cacheTag, cacheNumber);
	}
	return (Globals::MISS);
}