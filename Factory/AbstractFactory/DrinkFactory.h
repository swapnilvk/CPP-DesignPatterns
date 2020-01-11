#pragma once
#include "CoffeeFactory.h"
#include "TeaFactory.h"
#include "HotDrink.h"
#include<map>

using namespace std;

class DrinkFactory
{
	map<string, unique_ptr<HotDrinkFactory>> mapOfFactories;
public:
	 DrinkFactory()
	{
		 mapOfFactories["Coffee"] = make_unique<CoffeeFactory>();
		 mapOfFactories["Tea"] = make_unique<TeaFactory>();
	}
	 unique_ptr<HotDrink> make_drink(const string & name)
	 {
		 auto drink = mapOfFactories[name]->make();
		 drink->Prepare(200);
		 return drink;
	 }
};