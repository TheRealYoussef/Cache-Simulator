#include "SetAssociative.h"

double SetAssociative::cacheSimSAHitRatio(unsigned int lineSize, unsigned int iterations, unsigned int ways, unsigned int(*memGen)(), Globals::LineReplacement lineReplace)
{
	unsigned int hits = 0;
	unsigned int addr;
	for (int inst = 0; inst < iterations; inst++)
	{
		addr = (*memGen)();
		if (SetAssociative::cacheSimSA(addr, ways, Globals::caches[Globals::cacheLineSizeToIndex(lineSize)], lineReplace) == Globals::HIT)
			hits++;
	}
	return hits / (double)iterations;
}

Globals::CacheResType SetAssociative::cacheSimSA(unsigned int addr, unsigned int ways, std::vector<CacheLine> & cache, Globals::LineReplacement lineReplace)
{
	Globals::cachesReset = false;
	Globals::accessesReset = false;
	unsigned int lines = cache.size();
	unsigned int lineSize = Globals::CACHE_SIZE / lines;
	unsigned int offset = log2(lineSize);
	unsigned int sets = Globals::CACHE_SIZE / ways;
	unsigned int set = (addr >> offset) % sets;
	unsigned int setBits = log2(sets);
	unsigned int cacheTag = (addr >> (offset + setBits));
	unsigned int cacheNumber = Globals::cacheLineSizeToIndex(lineSize);
	//Access all lines in parallel but simulated using a loop
	for (int i = set; i < set + ways; i++)
	{
		if (cache[i].getValidity() == 0)
		{
			cache[i].setValidity(1);
			cache[i].setTag(cacheTag);
			Globals::updateArrays(cacheNumber, i);
			return Globals::MISS;
		}
		else if (cacheTag == cache[i].getTag())
		{
			Globals::updateArrays(cacheNumber, i);
			return Globals::HIT;
		}
	}
	//Cache is full
	unsigned int randNum;
	unsigned int lru;
	unsigned int lfu;
	switch (lineReplace)
	{
	case Globals::RANDOM:
		Globals::lineAccess(cache, Globals::rand_() % sets + set, cacheTag, cacheNumber);
		break;
	case Globals::LRU:
		Globals::lineAccess(cache, Globals::getMin(Globals::timeAccessed[cacheNumber], lineSize, set, set + ways), cacheTag, cacheNumber);
		break;
	case Globals::LFU:
		Globals::lineAccess(cache, Globals::getMin(Globals::accesses[cacheNumber], lineSize, set, set + ways), cacheTag, cacheNumber);
	}
	return Globals::MISS;
}