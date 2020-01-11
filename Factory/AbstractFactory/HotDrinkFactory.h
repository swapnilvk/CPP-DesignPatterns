#pragma once
#include "HotDrink.h"

class HotDrinkFactory
{
public:
	virtual std::unique_ptr<HotDrink> make() = 0;
};