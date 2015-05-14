#include "Globals.h"
#include <algorithm>

const unsigned int Globals::CACHE_LINE_SIZES[NUMBER_OF_CACHES] = { 8, 16, 32, 64, 128 };

std::vector<CacheLine> Globals::caches[NUMBER_OF_CACHES];

std::vector<unsigned int> Globals::accesses[NUMBER_OF_CACHES];

std::vector<unsigned int> Globals::timeAccessed[NUMBER_OF_CACHES];

unsigned int Globals::time;

bool Globals::cachesReset;

bool Globals::accessesReset;

void Globals::init()
{
	for (int i = 0; i < NUMBER_OF_CACHES; i++)
	{
		unsigned int cacheNumber = cacheLineSizeToIndex(CACHE_LINE_SIZES[i]);
		unsigned int lines = CACHE_SIZE / CACHE_LINE_SIZES[i];
		if (!cachesReset)
			caches[cacheNumber].resize(lines, CacheLine());
		if (!accessesReset)
		{
			accesses[i].resize(lines, 0);
			timeAccessed[i].resize(lines);
		}
	}
	time = 0;
	cachesReset = true;
	accessesReset = true;
}

unsigned int Globals::rand_()
{
	static unsigned int m_w = 0xABABAB55;
	static unsigned int m_z = 0x05080902;
	m_z = 36969 * (m_z & 65535) + (m_z >> 16);
	m_w = 18000 * (m_w & 65535) + (m_w >> 16);
	return (m_z << 16) + m_w;
}

unsigned int Globals::memGen1()
{
	static unsigned int addr = 0;
	return (addr++) % (DRAM_SIZE);
}

unsigned int Globals::memGen2()
{
	static unsigned int addr = 0;
	return  rand_() % (8 * 1024);
}

unsigned int Globals::memGen3()
{
	return rand_() % (DRAM_SIZE);
}

unsigned int Globals::memGen4()
{
	static unsigned int addr = 0;
	return (addr++) % (1024);
}

unsigned int Globals::memGen5()
{
	static unsigned int addr = 0;
	return (addr++) % (1024 * 64);
}

unsigned int Globals::memGen6()
{
	static unsigned int addr = 0;
	return (addr += 512) % (DRAM_SIZE);
}

unsigned int Globals::cacheLineSizeToIndex(unsigned int lineSize)
{
	return (log2(lineSize) - 3);
}

void Globals::lineAccess(std::vector<CacheLine> & cache, unsigned int line, unsigned int tag, unsigned int cacheNum)
{
	cache[line].setTag(tag);
	updateArrays(cacheNum, line);
}

void Globals::updateArrays(unsigned int cacheNum, unsigned int line)
{
	timeAccessed[cacheNum][line] = time++;
	accesses[cacheNum][line]++;
}

unsigned int Globals::getMin(std::vector<unsigned int> & v, unsigned int lineSize, unsigned int start, unsigned int end)
{
	unsigned int minTime = UINT_MAX;
	unsigned int lines = v.size();
	for (unsigned int i = start; i < end; i++)
		minTime = std::min(minTime, v[i]);
	return minTime;
}