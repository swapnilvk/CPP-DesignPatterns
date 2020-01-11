#pragma once
#include<iostream>

using namespace std;

class HotDrink
{
public:
	virtual void Prepare(int volume) = 0;
};

class Tea : public HotDrink
{
public:
	void Prepare(int volume)  override
	{
		cout << "Take tea bag, boil water, pour " << volume << " ml" << endl;
	}
};

class Coffee : public HotDrink
{
public:	
	void Prepare(int volume)  override
	{
		cout << "Grind some beans, boil water, pour " << volume << " ml" << endl;
	}
};