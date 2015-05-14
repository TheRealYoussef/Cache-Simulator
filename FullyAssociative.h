#ifndef FULLYASSOCIATIVE_H
#define FULLYASSOCIATIVE_H

#include "Globals.h"
#include <vector>

class FullyAssociative
{
public:
	static void init();
	static double cacheSimFAHitRatio(unsigned int, unsigned int, unsigned int(*)(), Globals::LineReplacement);
private:
	static Globals::CacheResType cacheSimFA(unsigned int, std::vector<CacheLine> &, Globals::LineReplacement);
	static std::vector<unsigned int> accesses[];
	static std::vector<unsigned int> timeAccessed[];
	static unsigned int time;
	static void lineAccess(std::vector<CacheLine> &, unsigned int, unsigned int, unsigned int);
	static void updateArrays(unsigned int, unsigned int);
	static unsigned int getMin(std::vector<unsigned int> &, unsigned int);
};

#endif
