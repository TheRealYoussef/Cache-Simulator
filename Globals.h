#ifndef GLOBALS_H
#define GLOBALS_H

#include "CacheLine.h"
#include <vector>

const extern unsigned int NUMBER_OF_CACHES;
const extern unsigned int NUMBER_OF_MEMGENS;
const extern unsigned int DRAM_SIZE;
const extern unsigned int CACHE_SIZE;
const extern unsigned int CACHE_LINE_SIZES[];
extern std::vector<CacheLine> caches[];
extern std::vector<unsigned int> accesses[];
extern std::vector<unsigned int> timeAccessed[];
extern bool cachesReset;
extern bool accessesReset;
extern unsigned int timePassed;
extern unsigned int m_w;
extern unsigned int m_z;
extern unsigned int addr[];

class Globals
{
public:
	enum CacheResType { MISS, HIT };
	enum LineReplacement { RANDOM, LRU, LFU };
	static void lineAccess(std::vector<CacheLine> &, unsigned int, unsigned int, unsigned int);
	static void updateArrays(unsigned int, unsigned int);
	static unsigned int getMin(std::vector<unsigned int> &, unsigned int, unsigned int, unsigned int);
	static void init();
	static unsigned int memGen1();
	static unsigned int memGen2();
	static unsigned int memGen3();
	static unsigned int memGen4();
	static unsigned int memGen5();
	static unsigned int memGen6();
	static unsigned int memGen();
	static unsigned int cacheLineSizeToIndex(unsigned int);
	static unsigned int rand_();
};

#endif