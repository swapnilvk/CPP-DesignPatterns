#define _USE_MATH_DEFINES
#include<iostream>
#include<sstream>
#include <cmath>

enum class PontType
{
	catesian, polar
};

class Point
{
private:
	double x, y;
	Point(const double & x, const double & y)
		:x{ x },
		y{ y }
	{

	}

	friend std::ostream & operator << (std::ostream & os, Point point)
	{
		return os << "x: " << point.x << " y: " << point.y;
	}

	class PointFactory
	{
	public:
		static Point NewCartesian(double x, double y)
		{
			return { x,y };
		}

		static Point NewPolar(double r, double theta)
		{
			return { r*cos(theta), r*sin(theta) };
		}
	};

public:
	static PointFactory Factory;
};


int main()
{
	auto pc = Point::Factory.NewCartesian(1, 2);
	std::cout << pc << std::endl;

	auto pp = Point::Factory.NewPolar(5, M_PI_4);
	std::cout << pp<< std::endl;

	getchar();
	return 0;
}

//output:
//
//x: 1 y : 2
//x : 3.53553 y : 3.53553