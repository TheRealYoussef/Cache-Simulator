#ifndef GLOBALS_H
#define GLOBALS_H

#include "CacheLine.h"
#include <vector>

class Globals
{
public:
	enum CacheResType { MISS, HIT };
	enum LineReplacement { RANDOM, LRU, LFU };
	const static unsigned int NUMBER_OF_CACHES = 5;
	const static unsigned int DRAM_SIZE = (64 * 1024 * 1024);
	const static unsigned int CACHE_SIZE = (32 * 1024);
	const static unsigned int CACHE_LINE_SIZES[];
	static std::vector<CacheLine> caches[];
	static void init();
	static unsigned int memGen1();
	static unsigned int memGen2();
	static unsigned int memGen3();
	static unsigned int memGen4();
	static unsigned int memGen5();
	static unsigned int memGen6();
	static unsigned int cacheLineSizeToIndex(unsigned int);
	static unsigned int rand_();
};

#endif