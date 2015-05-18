#include "Globals.h"
#include <algorithm>
#include <fstream>

const unsigned int NUMBER_OF_CACHES = 5;

const unsigned int NUMBER_OF_MEMGENS = 6;

const unsigned int DRAM_SIZE = (64 * 1024 * 1024);

const unsigned int CACHE_SIZE = (32 * 1024);

const unsigned int CACHE_LINE_SIZES[NUMBER_OF_CACHES] = { 8, 16, 32, 64, 128 };

std::vector<CacheLine> caches[NUMBER_OF_CACHES];

std::vector<unsigned int> accesses[NUMBER_OF_CACHES];

std::vector<unsigned int> timeAccessed[NUMBER_OF_CACHES];

unsigned int addr[NUMBER_OF_MEMGENS];

unsigned int m_w = 0xABABAB55;

unsigned int m_z = 0x05080902;

unsigned int timePassed = 0;

bool cachesReset = false;

bool accessesReset = false;

void Globals::init()
{
	for (int i = 0; i < NUMBER_OF_CACHES; i++)
	{
		unsigned int cacheNumber = ((cacheLineSizeToIndex)(CACHE_LINE_SIZES[i]));
		unsigned int lines = (CACHE_SIZE / CACHE_LINE_SIZES[i]);
		if (!cachesReset)
		{
			caches[cacheNumber].resize(lines);
			for (unsigned int j = 0; j < lines; j++)
				caches[cacheNumber][j].setValidity(0);
		}
		if (!accessesReset)
		{
			accesses[i].resize(lines);
			timeAccessed[i].resize(lines);
			for (unsigned int j = 0; j < lines; j++)
				accesses[i][j] = 0;
		}
	}
	for (int i = 0; i < NUMBER_OF_MEMGENS; i++)
		addr[i] = 0;
	m_w = 0xABABAB55;
	m_z = 0x05080902;
	timePassed = 0;
	cachesReset = true;
	accessesReset = true;
}

unsigned int Globals::rand_()
{
	m_z = 36969 * (m_z & 65535) + (m_z >> 16);
	m_w = 18000 * (m_w & 65535) + (m_w >> 16);
	return (m_z << 16) + m_w;
}

unsigned int Globals::memGen1()
{
	return (addr[0]++) % (DRAM_SIZE);
}

unsigned int Globals::memGen2()
{
	return  rand_() % (8 * 1024);
}

unsigned int Globals::memGen3()
{
	return rand_() % (DRAM_SIZE);
}

unsigned int Globals::memGen4()
{
	return (addr[3]++) % (1024);
}

unsigned int Globals::memGen5()
{
	return (addr[4]++) % (1024 * 64);
}

unsigned int Globals::memGen6()
{
	return (addr[5] += 512) % (DRAM_SIZE);
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
	timeAccessed[cacheNum][line] = timePassed++;
	accesses[cacheNum][line]++;
}

unsigned int Globals::getMin(std::vector<unsigned int> & v, unsigned int lineSize, unsigned int start, unsigned int end)
{
	unsigned int minTime = UINT_MAX, minIdx = UINT_MAX;
	for (unsigned int i = start; i < end; i++)
	{
		minTime = std::min(minTime, v[i]);
		if (minTime == v[i])
			minIdx = i;
	}
	return minIdx;
}