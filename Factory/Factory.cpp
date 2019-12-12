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
public:

	friend std::ostream & operator << (std::ostream & os, Point point)
	{
		return os << "x: " << point.x << " y: " << point.y;
	}

private:
	double x, y;
	Point(const double & x, const double & y)
		:x{ x },
		y{ y }
	{

	}

	friend class PointFactory;
};

class PointFactory
{
public:
	static Point NewCartesian(double x, double y)
	{
		return { x,y };
	}

	static Point NewPolar(double r, double theta)
	{
		return { r*cos(theta),r*sin(theta) };
	}
};

int main()
{
	auto pc = PointFactory::NewCartesian(1, 2);
	std::cout << pc << std::endl;

	auto pp = PointFactory::NewPolar(5, M_PI_4);
	std::cout << pp << std::endl;

	getchar();
	return 0;
}

//output:
//
//x: 1 y : 2
//x : 3.53553 y : 3.53553