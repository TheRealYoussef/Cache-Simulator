#include "FullyAssociative.h"
#include <algorithm>

std::vector<unsigned int> FullyAssociative::accesses[Globals::NUMBER_OF_CACHES];

std::vector<unsigned int> FullyAssociative::timeAccessed[Globals::NUMBER_OF_CACHES];

unsigned int FullyAssociative::time = 0;

void FullyAssociative::init()
{
	for (int i = 0; i < Globals::NUMBER_OF_CACHES; i++)
	{
		unsigned int lines = Globals::CACHE_SIZE / Globals::CACHE_LINE_SIZES[i];
		accesses[i].resize(lines, 0);
		timeAccessed[i].resize(lines);
	}
}

double FullyAssociative::cacheSimFAHitRatio(unsigned int lineSize, unsigned int iterations, unsigned int(*memGen)(), Globals::LineReplacement lineReplace)
{
	unsigned int hits = 0;
	unsigned int addr;
	for (int inst = 0; inst < iterations; inst++)
	{
		addr = (*memGen)();
		if (FullyAssociative::cacheSimFA(addr, Globals::caches[Globals::cacheLineSizeToIndex(lineSize)], lineReplace) == Globals::HIT)
			hits++;
	}
	return hits / (double)iterations;
}

Globals::CacheResType FullyAssociative::cacheSimFA(unsigned int addr, std::vector<CacheLine> & cache, Globals::LineReplacement lineReplace)
{
	//This function accepts the memory address for the read and 
	//returns whether it caused a cache miss or a cache hit
	unsigned int lines = cache.size();
	unsigned int lineSize = Globals::CACHE_SIZE / lines;
	unsigned int byteSelect = log2(lineSize);
	unsigned int cacheTag = (addr >> byteSelect);
	unsigned int cacheNumber = Globals::cacheLineSizeToIndex(lineSize);
	//Access all lines in parallel but simulated using a loop
	for (int i = 0; i < lines; i++)
	{
		if (cache[i].getValidity() == 0)
		{
			cache[i].setValidity(1);
			cache[i].setTag(cacheTag);
			updateArrays(cacheNumber, i);
			return Globals::MISS;
		}
		else if (cacheTag == cache[i].getTag())
		{
			updateArrays(cacheNumber, i);
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
		lineAccess(cache, Globals::rand_() % lines, cacheTag, cacheNumber);
		break;
	case Globals::LRU:
		lineAccess(cache, getMin(timeAccessed[cacheNumber], lineSize), cacheTag, cacheNumber);
		break;
	case Globals::LFU:
		lineAccess(cache, getMin(accesses[cacheNumber], lineSize), cacheTag, cacheNumber);
	}
	return Globals::MISS;
}

void FullyAssociative::lineAccess(std::vector<CacheLine> & cache, unsigned int line, unsigned int tag, unsigned int cacheNum)
{
	cache[line].setTag(tag);
	updateArrays(cacheNum, line);
}

void FullyAssociative::updateArrays(unsigned int cacheNum, unsigned int line)
{
	timeAccessed[cacheNum][line] = time++;
	accesses[cacheNum][line]++;
}

unsigned int FullyAssociative::getMin(std::vector<unsigned int> & v, unsigned int lineSize)
{
	unsigned int minTime = UINT_MAX;
	unsigned int lines = v.size();
	for (unsigned int i = 0; i < lines; i++)
		minTime = std::min(minTime, v[i]);
	return minTime;
}