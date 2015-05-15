#include <iostream>
#include <iomanip>
#include <string>
#include "Globals.h"
#include "DirectMapped.h"
#include "FullyAssociative.h"
#include "SetAssociative.h"

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cout << "Direct Mapped:\nMemgen 1:\nLine Size:\n";
	for (int i = 8; i <= 128; i *= 2)
	{
		std::cout << i << ": ";
		Globals::init();
		std::cout << DirectMapped::cacheSimDMHitRatio(i, 10000000, &Globals::memGen1) << '\n';
	}
	std::cout << "Memgen 2:\nLine Size:\n";
	for (int i = 8; i <= 128; i *= 2)
	{
		std::cout << i << ": ";
		Globals::init();
		std::cout << DirectMapped::cacheSimDMHitRatio(i, 10000000, &Globals::memGen2) << '\n';
	}
	std::cout << "Memgen 3:\nLine Size:\n";
	for (int i = 8; i <= 128; i *= 2)
	{
		std::cout << i << ": ";
		Globals::init();
		std::cout << DirectMapped::cacheSimDMHitRatio(i, 10000000, &Globals::memGen3) << '\n';
	}
	std::cout << "Memgen 4:\nLine Size:\n";
	for (int i = 8; i <= 128; i *= 2)
	{
		std::cout << i << ": ";
		Globals::init();
		std::cout << DirectMapped::cacheSimDMHitRatio(i, 10000000, &Globals::memGen4) << '\n';
	}
	
	std::cout << "Memgen 5:\nLine Size:\n";
	for (int i = 8; i <= 128; i *= 2)
	{
		std::cout << i << ": ";
		Globals::init();
		std::cout << DirectMapped::cacheSimDMHitRatio(i, 10000000, &Globals::memGen5) << '\n';
	}
	std::cout << "Memgen 6:\nLine Size:\n";
	for (int i = 8; i <= 128; i *= 2)
	{
		std::cout << i << ": ";
		Globals::init();
		std::cout << DirectMapped::cacheSimDMHitRatio(i, 10000000, &Globals::memGen6) << '\n';
	}
	std::cout << "Fully Associative:\nRandom Line Replacement:\nMemgen 1:\nLine Size:\n";
	for (int i = 8; i <= 128; i *= 2)
	{
		std::cout << i << ": ";
		Globals::init();
		std::cout << FullyAssociative::cacheSimFAHitRatio(i, 10000000, &Globals::memGen1, Globals::RANDOM) << '\n';
	}
	std::cout << "Memgen 2:\nLine Size:\n";
	for (int i = 8; i <= 128; i *= 2)
	{
		std::cout << i << ": ";
		Globals::init();
		std::cout << FullyAssociative::cacheSimFAHitRatio(i, 10000000, &Globals::memGen2, Globals::RANDOM) << '\n';
	}
	std::cout << "Memgen 3:\nLine Size:\n";
	for (int i = 8; i <= 128; i *= 2)
	{
		std::cout << i << ": ";
		Globals::init();
		std::cout << FullyAssociative::cacheSimFAHitRatio(i, 10000000, &Globals::memGen3, Globals::RANDOM) << '\n';
	}
	std::cout << "Memgen 4:\nLine Size:\n";
	for (int i = 8; i <= 128; i *= 2)
	{
		std::cout << i << ": ";
		Globals::init();
		std::cout << FullyAssociative::cacheSimFAHitRatio(i, 10000000, &Globals::memGen4, Globals::RANDOM) << '\n';
	}
	std::cout << "Memgen 5:\nLine Size:\n";
	for (int i = 8; i <= 128; i *= 2)
	{
		std::cout << i << ": ";
		Globals::init();
		std::cout << FullyAssociative::cacheSimFAHitRatio(i, 10000000, &Globals::memGen5, Globals::RANDOM) << '\n';
	}
	std::cout << "Memgen 6:\nLine Size:\n";
	for (int i = 8; i <= 128; i *= 2)
	{
		std::cout << i << ": ";
		Globals::init();
		std::cout << FullyAssociative::cacheSimFAHitRatio(i, 10000000, &Globals::memGen6, Globals::RANDOM) << '\n';
	}
	std::cout << "LRU Line Replacement:\nMemgen 1:\nLine Size:\n";
	for (int i = 8; i <= 128; i *= 2)
	{
		std::cout << i << ": ";
		Globals::init();
		std::cout << FullyAssociative::cacheSimFAHitRatio(i, 10000000, &Globals::memGen1, Globals::LRU) << '\n';
	}
	std::cout << "Memgen 2:\nLine Size:\n";
	for (int i = 8; i <= 128; i *= 2)
	{
		std::cout << i << ": ";
		Globals::init();
		std::cout << FullyAssociative::cacheSimFAHitRatio(i, 10000000, &Globals::memGen2, Globals::LRU) << '\n';
	}
	std::cout << "Memgen 3:\nLine Size:\n";
	for (int i = 8; i <= 128; i *= 2)
	{
		std::cout << i << ": ";
		Globals::init();
		std::cout << FullyAssociative::cacheSimFAHitRatio(i, 10000000, &Globals::memGen3, Globals::LRU) << '\n';
	}
	std::cout << "Memgen 4:\nLine Size:\n";
	for (int i = 8; i <= 128; i *= 2)
	{
		std::cout << i << ": ";
		Globals::init();
		std::cout << FullyAssociative::cacheSimFAHitRatio(i, 10000000, &Globals::memGen4, Globals::LRU) << '\n';
	}
	std::cout << "Memgen 5:\nLine Size:\n";
	for (int i = 8; i <= 128; i *= 2)
	{
		std::cout << i << ": ";
		Globals::init();
		std::cout << FullyAssociative::cacheSimFAHitRatio(i, 10000000, &Globals::memGen5, Globals::LRU) << '\n';
	}
	std::cout << "Memgen 6:\nLine Size:\n";
	for (int i = 8; i <= 128; i *= 2)
	{
		std::cout << i << ": ";
		Globals::init();
		std::cout << FullyAssociative::cacheSimFAHitRatio(i, 10000000, &Globals::memGen6, Globals::LRU) << '\n';
	}
	std::cout << "LFU Line Replacement:\nMemgen 1:\nLine Size:\n";
	for (int i = 8; i <= 128; i *= 2)
	{
		std::cout << i << ": ";
		Globals::init();
		std::cout << FullyAssociative::cacheSimFAHitRatio(i, 10000000, &Globals::memGen1, Globals::LFU) << '\n';
	}
	std::cout << "Memgen 2:\nLine Size:\n";
	for (int i = 8; i <= 128; i *= 2)
	{
		std::cout << i << ": ";
		Globals::init();
		std::cout << FullyAssociative::cacheSimFAHitRatio(i, 10000000, &Globals::memGen2, Globals::LFU) << '\n';
	}
	std::cout << "Memgen 3:\nLine Size:\n";
	for (int i = 8; i <= 128; i *= 2)
	{
		std::cout << i << ": ";
		Globals::init();
		std::cout << FullyAssociative::cacheSimFAHitRatio(i, 10000000, &Globals::memGen3, Globals::LFU) << '\n';
	}
	std::cout << "Memgen 4:\nLine Size:\n";
	for (int i = 8; i <= 128; i *= 2)
	{
		std::cout << i << ": ";
		Globals::init();
		std::cout << FullyAssociative::cacheSimFAHitRatio(i, 10000000, &Globals::memGen4, Globals::LFU) << '\n';
	}
	std::cout << "Memgen 5:\nLine Size:\n";
	for (int i = 8; i <= 128; i *= 2)
	{
		std::cout << i << ": ";
		Globals::init();
		std::cout << FullyAssociative::cacheSimFAHitRatio(i, 10000000, &Globals::memGen5, Globals::LFU) << '\n';
	}
	std::cout << "Memgen 6:\nLine Size:\n";
	for (int i = 8; i <= 128; i *= 2)
	{
		std::cout << i << ": ";
		Globals::init();
		std::cout << FullyAssociative::cacheSimFAHitRatio(i, 10000000, &Globals::memGen6, Globals::LFU) << '\n';
	}
	std::cout << "Set Associative:\nRandom Line Replacement:\n2 Ways:\nMemgen 1:\nLine Size:\n";
	for (int i = 8; i <= 128; i *= 2)
	{
		std::cout << i << ": ";
		Globals::init();
		std::cout << SetAssociative::cacheSimSAHitRatio(i, 10000000, 2, &Globals::memGen1, Globals::RANDOM) << '\n';
	}
	std::cout << "Memgen 2:\nLine Size:\n";
	for (int i = 8; i <= 128; i *= 2)
	{
		std::cout << i << ": ";
		Globals::init();
		std::cout << SetAssociative::cacheSimSAHitRatio(i, 10000000, 2, &Globals::memGen2, Globals::RANDOM) << '\n';
	}
	std::cout << "Memgen 3:\nLine Size:\n";
	for (int i = 8; i <= 128; i *= 2)
	{
		std::cout << i << ": ";
		Globals::init();
		std::cout << SetAssociative::cacheSimSAHitRatio(i, 10000000, 2, &Globals::memGen3, Globals::RANDOM) << '\n';
	}
	std::cout << "Memgen 4:\nLine Size:\n";
	for (int i = 8; i <= 128; i *= 2)
	{
		std::cout << i << ": ";
		Globals::init();
		std::cout << SetAssociative::cacheSimSAHitRatio(i, 10000000, 2, &Globals::memGen4, Globals::RANDOM) << '\n';
	}
	std::cout << "Memgen 5:\nLine Size:\n";
	for (int i = 8; i <= 128; i *= 2)
	{
		std::cout << i << ": ";
		Globals::init();
		std::cout << SetAssociative::cacheSimSAHitRatio(i, 10000000, 2, &Globals::memGen5, Globals::RANDOM) << '\n';
	}
	std::cout << "Memgen 6:\nLine Size:\n";
	for (int i = 8; i <= 128; i *= 2)
	{
		std::cout << i << ": ";
		Globals::init();
		std::cout << SetAssociative::cacheSimSAHitRatio(i, 10000000, 2, &Globals::memGen6, Globals::RANDOM) << '\n';
	}
	std::cout << "4 Ways:\nMemgen 1:\nLine Size:\n";
	for (int i = 8; i <= 128; i *= 2)
	{
		std::cout << i << ": ";
		Globals::init();
		std::cout << SetAssociative::cacheSimSAHitRatio(i, 10000000, 4, &Globals::memGen1, Globals::RANDOM) << '\n';
	}
	std::cout << "Memgen 2:\nLine Size:\n";
	for (int i = 8; i <= 128; i *= 2)
	{
		std::cout << i << ": ";
		Globals::init();
		std::cout << SetAssociative::cacheSimSAHitRatio(i, 10000000, 4, &Globals::memGen2, Globals::RANDOM) << '\n';
	}
	std::cout << "Memgen 3:\nLine Size:\n";
	for (int i = 8; i <= 128; i *= 2)
	{
		std::cout << i << ": ";
		Globals::init();
		std::cout << SetAssociative::cacheSimSAHitRatio(i, 10000000, 4, &Globals::memGen3, Globals::RANDOM) << '\n';
	}
	std::cout << "Memgen 4:\nLine Size:\n";
	for (int i = 8; i <= 128; i *= 2)
	{
		std::cout << i << ": ";
		Globals::init();
		std::cout << SetAssociative::cacheSimSAHitRatio(i, 10000000, 4, &Globals::memGen4, Globals::RANDOM) << '\n';
	}
	std::cout << "Memgen 5:\nLine Size:\n";
	for (int i = 8; i <= 128; i *= 2)
	{
		std::cout << i << ": ";
		Globals::init();
		std::cout << SetAssociative::cacheSimSAHitRatio(i, 10000000, 4, &Globals::memGen5, Globals::RANDOM) << '\n';
	}
	std::cout << "Memgen 6:\nLine Size:\n";
	for (int i = 8; i <= 128; i *= 2)
	{
		std::cout << i << ": ";
		Globals::init();
		std::cout << SetAssociative::cacheSimSAHitRatio(i, 10000000, 4, &Globals::memGen6, Globals::RANDOM) << '\n';
	}
	std::cout << "8 Ways:\nMemgen 1:\nLine Size:\n";
	for (int i = 8; i <= 128; i *= 2)
	{
		std::cout << i << ": ";
		Globals::init();
		std::cout << SetAssociative::cacheSimSAHitRatio(i, 10000000, 8, &Globals::memGen1, Globals::RANDOM) << '\n';
	}
	std::cout << "Memgen 2:\nLine Size:\n";
	for (int i = 8; i <= 128; i *= 2)
	{
		std::cout << i << ": ";
		Globals::init();
		std::cout << SetAssociative::cacheSimSAHitRatio(i, 10000000, 8, &Globals::memGen2, Globals::RANDOM) << '\n';
	}
	std::cout << "Memgen 3:\nLine Size:\n";
	for (int i = 8; i <= 128; i *= 2)
	{
		std::cout << i << ": ";
		Globals::init();
		std::cout << SetAssociative::cacheSimSAHitRatio(i, 10000000, 8, &Globals::memGen3, Globals::RANDOM) << '\n';
	}
	std::cout << "Memgen 4:\nLine Size:\n";
	for (int i = 8; i <= 128; i *= 2)
	{
		std::cout << i << ": ";
		Globals::init();
		std::cout << SetAssociative::cacheSimSAHitRatio(i, 10000000, 8, &Globals::memGen4, Globals::RANDOM) << '\n';
	}
	std::cout << "Memgen 5:\nLine Size:\n";
	for (int i = 8; i <= 128; i *= 2)
	{
		std::cout << i << ": ";
		Globals::init();
		std::cout << SetAssociative::cacheSimSAHitRatio(i, 10000000, 8, &Globals::memGen5, Globals::RANDOM) << '\n';
	}
	std::cout << "Memgen 6:\nLine Size:\n";
	for (int i = 8; i <= 128; i *= 2)
	{
		std::cout << i << ": ";
		Globals::init();
		std::cout << SetAssociative::cacheSimSAHitRatio(i, 10000000, 8, &Globals::memGen6, Globals::RANDOM) << '\n';
	}
	std::cout << "LRU Line Replacement:\n2 Ways:\nMemgen 1:\nLine Size:\n";
	for (int i = 8; i <= 128; i *= 2)
	{
		std::cout << i << ": ";
		Globals::init();
		std::cout << SetAssociative::cacheSimSAHitRatio(i, 10000000, 2, &Globals::memGen1, Globals::LRU) << '\n';
	}
	std::cout << "Memgen 2:\nLine Size:\n";
	for (int i = 8; i <= 128; i *= 2)
	{
		std::cout << i << ": ";
		Globals::init();
		std::cout << SetAssociative::cacheSimSAHitRatio(i, 10000000, 2, &Globals::memGen2, Globals::LRU) << '\n';
	}
	std::cout << "Memgen 3:\nLine Size:\n";
	for (int i = 8; i <= 128; i *= 2)
	{
		std::cout << i << ": ";
		Globals::init();
		std::cout << SetAssociative::cacheSimSAHitRatio(i, 10000000, 2, &Globals::memGen3, Globals::LRU) << '\n';
	}
	std::cout << "Memgen 4:\nLine Size:\n";
	for (int i = 8; i <= 128; i *= 2)
	{
		std::cout << i << ": ";
		Globals::init();
		std::cout << SetAssociative::cacheSimSAHitRatio(i, 10000000, 2, &Globals::memGen4, Globals::LRU) << '\n';
	}
	std::cout << "Memgen 5:\nLine Size:\n";
	for (int i = 8; i <= 128; i *= 2)
	{
		std::cout << i << ": ";
		Globals::init();
		std::cout << SetAssociative::cacheSimSAHitRatio(i, 10000000, 2, &Globals::memGen5, Globals::LRU) << '\n';
	}
	std::cout << "Memgen 6:\nLine Size:\n";
	for (int i = 8; i <= 128; i *= 2)
	{
		std::cout << i << ": ";
		Globals::init();
		std::cout << SetAssociative::cacheSimSAHitRatio(i, 10000000, 2, &Globals::memGen6, Globals::LRU) << '\n';
	}
	std::cout << "4 Ways:\nMemgen 1:\nLine Size:\n";
	for (int i = 8; i <= 128; i *= 2)
	{
		std::cout << i << ": ";
		Globals::init();
		std::cout << SetAssociative::cacheSimSAHitRatio(i, 10000000, 4, &Globals::memGen1, Globals::LRU) << '\n';
	}
	std::cout << "Memgen 2:\nLine Size:\n";
	for (int i = 8; i <= 128; i *= 2)
	{
		std::cout << i << ": ";
		Globals::init();
		std::cout << SetAssociative::cacheSimSAHitRatio(i, 10000000, 4, &Globals::memGen2, Globals::LRU) << '\n';
	}
	std::cout << "Memgen 3:\nLine Size:\n";
	for (int i = 8; i <= 128; i *= 2)
	{
		std::cout << i << ": ";
		Globals::init();
		std::cout << SetAssociative::cacheSimSAHitRatio(i, 10000000, 4, &Globals::memGen3, Globals::LRU) << '\n';
	}
	std::cout << "Memgen 4:\nLine Size:\n";
	for (int i = 8; i <= 128; i *= 2)
	{
		std::cout << i << ": ";
		Globals::init();
		std::cout << SetAssociative::cacheSimSAHitRatio(i, 10000000, 4, &Globals::memGen4, Globals::LRU) << '\n';
	}
	std::cout << "Memgen 5:\nLine Size:\n";
	for (int i = 8; i <= 128; i *= 2)
	{
		std::cout << i << ": ";
		Globals::init();
		std::cout << SetAssociative::cacheSimSAHitRatio(i, 10000000, 4, &Globals::memGen5, Globals::LRU) << '\n';
	}
	std::cout << "Memgen 6:\nLine Size:\n";
	for (int i = 8; i <= 128; i *= 2)
	{
		std::cout << i << ": ";
		Globals::init();
		std::cout << SetAssociative::cacheSimSAHitRatio(i, 10000000, 4, &Globals::memGen6, Globals::LRU) << '\n';
	}
	std::cout << "8 Ways:\nMemgen 1:\nLine Size:\n";
	for (int i = 8; i <= 128; i *= 2)
	{
		std::cout << i << ": ";
		Globals::init();
		std::cout << SetAssociative::cacheSimSAHitRatio(i, 10000000, 8, &Globals::memGen1, Globals::LRU) << '\n';
	}
	std::cout << "Memgen 2:\nLine Size:\n";
	for (int i = 8; i <= 128; i *= 2)
	{
		std::cout << i << ": ";
		Globals::init();
		std::cout << SetAssociative::cacheSimSAHitRatio(i, 10000000, 8, &Globals::memGen2, Globals::LRU) << '\n';
	}
	std::cout << "Memgen 3:\nLine Size:\n";
	for (int i = 8; i <= 128; i *= 2)
	{
		std::cout << i << ": ";
		Globals::init();
		std::cout << SetAssociative::cacheSimSAHitRatio(i, 10000000, 8, &Globals::memGen3, Globals::LRU) << '\n';
	}
	std::cout << "Memgen 4:\nLine Size:\n";
	for (int i = 8; i <= 128; i *= 2)
	{
		std::cout << i << ": ";
		Globals::init();
		std::cout << SetAssociative::cacheSimSAHitRatio(i, 10000000, 8, &Globals::memGen4, Globals::LRU) << '\n';
	}
	std::cout << "Memgen 5:\nLine Size:\n";
	for (int i = 8; i <= 128; i *= 2)
	{
		std::cout << i << ": ";
		Globals::init();
		std::cout << SetAssociative::cacheSimSAHitRatio(i, 10000000, 8, &Globals::memGen5, Globals::LRU) << '\n';
	}
	std::cout << "Memgen 6:\nLine Size:\n";
	for (int i = 8; i <= 128; i *= 2)
	{
		std::cout << i << ": ";
		Globals::init();
		std::cout << SetAssociative::cacheSimSAHitRatio(i, 10000000, 8, &Globals::memGen6, Globals::LRU) << '\n';
	}
	std::cout << "LFU Line Replacement:\n2 Ways:\nMemgen 1:\nLine Size:\n";
	for (int i = 8; i <= 128; i *= 2)
	{
		std::cout << i << ": ";
		Globals::init();
		std::cout << SetAssociative::cacheSimSAHitRatio(i, 10000000, 2, &Globals::memGen1, Globals::LFU) << '\n';
	}
	std::cout << "Memgen 2:\nLine Size:\n";
	for (int i = 8; i <= 128; i *= 2)
	{
		std::cout << i << ": ";
		Globals::init();
		std::cout << SetAssociative::cacheSimSAHitRatio(i, 10000000, 2, &Globals::memGen2, Globals::LFU) << '\n';
	}
	std::cout << "Memgen 3:\nLine Size:\n";
	for (int i = 8; i <= 128; i *= 2)
	{
		std::cout << i << ": ";
		Globals::init();
		std::cout << SetAssociative::cacheSimSAHitRatio(i, 10000000, 2, &Globals::memGen3, Globals::LFU) << '\n';
	}
	std::cout << "Memgen 4:\nLine Size:\n";
	for (int i = 8; i <= 128; i *= 2)
	{
		std::cout << i << ": ";
		Globals::init();
		std::cout << SetAssociative::cacheSimSAHitRatio(i, 10000000, 2, &Globals::memGen4, Globals::LFU) << '\n';
	}
	std::cout << "Memgen 5:\nLine Size:\n";
	for (int i = 8; i <= 128; i *= 2)
	{
		std::cout << i << ": ";
		Globals::init();
		std::cout << SetAssociative::cacheSimSAHitRatio(i, 10000000, 2, &Globals::memGen5, Globals::LFU) << '\n';
	}
	std::cout << "Memgen 6:\nLine Size:\n";
	for (int i = 8; i <= 128; i *= 2)
	{
		std::cout << i << ": ";
		Globals::init();
		std::cout << SetAssociative::cacheSimSAHitRatio(i, 10000000, 2, &Globals::memGen6, Globals::LFU) << '\n';
	}
	std::cout << "4 Ways:\nMemgen 1:\nLine Size:\n";
	for (int i = 8; i <= 128; i *= 2)
	{
		std::cout << i << ": ";
		Globals::init();
		std::cout << SetAssociative::cacheSimSAHitRatio(i, 10000000, 4, &Globals::memGen1, Globals::LFU) << '\n';
	}
	std::cout << "Memgen 2:\nLine Size:\n";
	for (int i = 8; i <= 128; i *= 2)
	{
		std::cout << i << ": ";
		Globals::init();
		std::cout << SetAssociative::cacheSimSAHitRatio(i, 10000000, 4, &Globals::memGen2, Globals::LFU) << '\n';
	}
	std::cout << "Memgen 3:\nLine Size:\n";
	for (int i = 8; i <= 128; i *= 2)
	{
		std::cout << i << ": ";
		Globals::init();
		std::cout << SetAssociative::cacheSimSAHitRatio(i, 10000000, 4, &Globals::memGen3, Globals::LFU) << '\n';
	}
	std::cout << "Memgen 4:\nLine Size:\n";
	for (int i = 8; i <= 128; i *= 2)
	{
		std::cout << i << ": ";
		Globals::init();
		std::cout << SetAssociative::cacheSimSAHitRatio(i, 10000000, 4, &Globals::memGen4, Globals::LFU) << '\n';
	}
	std::cout << "Memgen 5:\nLine Size:\n";
	for (int i = 8; i <= 128; i *= 2)
	{
		std::cout << i << ": ";
		Globals::init();
		std::cout << SetAssociative::cacheSimSAHitRatio(i, 10000000, 4, &Globals::memGen5, Globals::LFU) << '\n';
	}
	std::cout << "Memgen 6:\nLine Size:\n";
	for (int i = 8; i <= 128; i *= 2)
	{
		std::cout << i << ": ";
		Globals::init();
		std::cout << SetAssociative::cacheSimSAHitRatio(i, 10000000, 4, &Globals::memGen6, Globals::LFU) << '\n';
	}
	std::cout << "8 Ways:\nMemgen 1:\nLine Size:\n";
	for (int i = 8; i <= 128; i *= 2)
	{
		std::cout << i << ": ";
		Globals::init();
		std::cout << SetAssociative::cacheSimSAHitRatio(i, 10000000, 8, &Globals::memGen1, Globals::LFU) << '\n';
	}
	std::cout << "Memgen 2:\nLine Size:\n";
	for (int i = 8; i <= 128; i *= 2)
	{
		std::cout << i << ": ";
		Globals::init();
		std::cout << SetAssociative::cacheSimSAHitRatio(i, 10000000, 8, &Globals::memGen2, Globals::LFU) << '\n';
	}
	std::cout << "Memgen 3:\nLine Size:\n";
	for (int i = 8; i <= 128; i *= 2)
	{
		std::cout << i << ": ";
		Globals::init();
		std::cout << SetAssociative::cacheSimSAHitRatio(i, 10000000, 8, &Globals::memGen3, Globals::LFU) << '\n';
	}
	std::cout << "Memgen 4:\nLine Size:\n";
	for (int i = 8; i <= 128; i *= 2)
	{
		std::cout << i << ": ";
		Globals::init();
		std::cout << SetAssociative::cacheSimSAHitRatio(i, 10000000, 8, &Globals::memGen4, Globals::LFU) << '\n';
	}
	std::cout << "Memgen 5:\nLine Size:\n";
	for (int i = 8; i <= 128; i *= 2)
	{
		std::cout << i << ": ";
		Globals::init();
		std::cout << SetAssociative::cacheSimSAHitRatio(i, 10000000, 8, &Globals::memGen5, Globals::LFU) << '\n';
	}
	std::cout << "Memgen 6:\nLine Size:\n";
	for (int i = 8; i <= 128; i *= 2)
	{
		std::cout << i << ": ";
		Globals::init();
		std::cout << SetAssociative::cacheSimSAHitRatio(i, 10000000, 8, &Globals::memGen6, Globals::LFU) << '\n';
	}
}