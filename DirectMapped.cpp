#include "DirectMapped.h"

double DirectMapped::cacheSimDMHitRatio(unsigned int lineSize, unsigned int iterations, unsigned int(*memGen)())
{
	unsigned int hits = 0;
	unsigned int addr;
	for (unsigned int inst = 0; inst < iterations; inst++)
	{
		addr = (*memGen)();
		if ((DirectMapped::cacheSimDM)(addr, caches[Globals::cacheLineSizeToIndex(lineSize)]) == (Globals::HIT))
			hits++;
	}
	return (hits / (double)iterations);
}

Globals::CacheResType DirectMapped::cacheSimDM(unsigned int addr, std::vector<CacheLine> & cache)
{
	(cachesReset) = false;
	unsigned int lines = cache.size();
	unsigned int lineSize = ((CACHE_SIZE) / lines);
	unsigned int offset = log2(lineSize);
	unsigned int blockAddress = (addr / lineSize);
	unsigned int blockNumber = (blockAddress % lines);
	unsigned int index = log2(lines);
	unsigned int tag = (addr >> (offset + index));
	if (cache[blockNumber].getValidity() == 0)
	{
		cache[blockNumber].setValidity(1);
		cache[blockNumber].setTag(tag);
		return (Globals::MISS);
	}
	else if (tag == cache[blockNumber].getTag())
		return (Globals::HIT);
	cache[blockNumber].setTag(tag);
	return (Globals::MISS);
}