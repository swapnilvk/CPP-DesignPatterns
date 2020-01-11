#include "HotDrink.h"
#include<memory>
#include "DrinkFactory.h"

using namespace std;

unique_ptr<HotDrink> make_drink(string type)
{
	unique_ptr<HotDrink> drink;
	if (type == "Tea")
	{
		drink = make_unique<Tea>();
		drink->Prepare(200);
	}
	else
	{
		drink = make_unique<Coffee>();
		drink->Prepare(200);
	}

	return drink;
}

int main()
{
	auto d = make_drink("Coffee");

	DrinkFactory Df;
	Df.make_drink("Tea");

	getchar();

	return 0;
}