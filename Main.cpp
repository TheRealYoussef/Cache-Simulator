#include <iostream>
#include <iomanip>
#include <string>
#include "Globals.h"
#include "DirectMapped.h"
#include "FullyAssociative.h"

std::string msg[] = { "Miss", "Hit" };

int main()
{
	//Globals::init();
	FullyAssociative::init();
	Globals::CacheResType r;
	unsigned int addr;
	std::cout << "Direct Mapped Cache Simulator\n";
	for (int i = 0; i < Globals::NUMBER_OF_CACHES; i++)
	{
		Globals::init();
		std::cout << DirectMapped::cacheSimDMHitRatio(pow(2, i + 3), 1000000, &Globals::memGen6) << std::endl;
	}
}