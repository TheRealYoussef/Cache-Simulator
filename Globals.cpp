#include "Globals.h"

const unsigned int Globals::CACHE_LINE_SIZES[NUMBER_OF_CACHES] = { 8, 16, 32, 64, 128 };

std::vector<CacheLine> Globals::caches[NUMBER_OF_CACHES];

void Globals::init()
{
	for (int i = 0; i < NUMBER_OF_CACHES; i++)
	{
		unsigned int cacheNumber = cacheLineSizeToIndex(CACHE_LINE_SIZES[i]);
		unsigned int lines = CACHE_SIZE / CACHE_LINE_SIZES[i];
		caches[cacheNumber].resize(lines);
	}
}

unsigned int Globals::rand_()
{
	static unsigned int m_w = 0xABABAB55;    /* must not be zero, nor 0x464fffff */
	static unsigned int m_z = 0x05080902;    /* must not be zero, nor 0x9068ffff */
	m_z = 36969 * (m_z & 65535) + (m_z >> 16);
	m_w = 18000 * (m_w & 65535) + (m_w >> 16);
	return (m_z << 16) + m_w;  /* 32-bit result */
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