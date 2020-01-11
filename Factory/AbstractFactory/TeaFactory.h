#pragma once
#include "HotDrink.h"
#include "HotDrinkFactory.h"

class TeaFactory : public HotDrinkFactory
{
public:
	std::unique_ptr<HotDrink> make() override
	{
		return std::make_unique<Tea>();
	}
};