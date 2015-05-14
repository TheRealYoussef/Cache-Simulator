#include "DirectMapped.h"

double DirectMapped::cacheSimDMHitRatio(unsigned int lineSize, unsigned int iterations, unsigned int(*memGen)())
{
	unsigned int hits = 0;
	unsigned int addr;
	for (int inst = 0; inst < iterations; inst++)
	{
		addr = (*memGen)();
		if (DirectMapped::cacheSimDM(addr, Globals::caches[Globals::cacheLineSizeToIndex(lineSize)]) == Globals::HIT)
			hits++;
	}
	return hits / (double)iterations;
}

Globals::CacheResType DirectMapped::cacheSimDM(unsigned int addr, std::vector<CacheLine> & cache)
{
	// This function accepts the memory address for the read and 
	// returns whether it caused a cache miss or a cache hit
	unsigned int lines = cache.size();
	unsigned int lineSize = Globals::CACHE_SIZE / lines;
	unsigned int offset = log2(lineSize);
	unsigned int blockAddress = addr / lineSize;
	unsigned int blockNumber = blockAddress % lines;
	unsigned int index = log2(lines);
	unsigned int tag = (addr >> (offset + index));
	if (cache[blockNumber].getValidity() == 0)
	{
		cache[blockNumber].setValidity(1);
		cache[blockNumber].setTag(tag);
		return Globals::MISS;
	}
	else if (tag == cache[blockNumber].getTag())
		return Globals::HIT;
	cache[blockNumber].setTag(tag);
	return Globals::MISS;
}