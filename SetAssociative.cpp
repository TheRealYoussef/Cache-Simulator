#include "SetAssociative.h"

double SetAssociative::cacheSimSAHitRatio(unsigned int lineSize, unsigned int iterations, unsigned int ways, unsigned int(*memGen)(), Globals::LineReplacement lineReplace)
{
	unsigned int hits = 0;
	unsigned int addr;
	for (unsigned int inst = 0; inst < iterations; inst++)
	{
		addr = (*memGen)();
		if ((SetAssociative::cacheSimSA)(addr, ways, (caches[(Globals::cacheLineSizeToIndex)(lineSize)]), lineReplace) == (Globals::HIT))
			hits++;
	}
	return (hits / (double)iterations);
}

Globals::CacheResType SetAssociative::cacheSimSA(unsigned int addr, unsigned int ways, std::vector<CacheLine> & cache, Globals::LineReplacement lineReplace)
{
	cachesReset = false;
	accessesReset = false;
	unsigned int lines = cache.size();
	unsigned int lineSize = ((CACHE_SIZE) / lines);
	unsigned int offset = log2(lineSize);
	unsigned int sets = (lines / ways);
	unsigned int setBits = log2(sets);
	unsigned int set = ((addr >> offset) % sets);
	unsigned int cacheTag = (addr >> (offset + setBits));
	unsigned int cacheNumber = ((Globals::cacheLineSizeToIndex)(lineSize));
	//Access all lines in parallel but simulated using a loop
	for (unsigned int i = (set * ways); i < (ways * (set + 1)); i++)
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
		(Globals::lineAccess)(cache, (((Globals::rand_()) % ways) + (set * ways)), cacheTag, cacheNumber);
		break;
	case (Globals::LRU):
		(Globals::lineAccess)(cache, ((Globals::getMin)((timeAccessed[cacheNumber]), lineSize, (set * ways), (ways * (set + 1)))), cacheTag, cacheNumber);
		break;
	case (Globals::LFU):
		(Globals::lineAccess)(cache, ((Globals::getMin)((accesses[cacheNumber]), lineSize, (set * ways), (ways * (set + 1)))), cacheTag, cacheNumber);
	}
	return (Globals::MISS);
}