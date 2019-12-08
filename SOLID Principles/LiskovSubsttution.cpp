//Liskov substitution principle
//Objects in the program should be replaceable with instances of its subtype

//This program shows the example of violation of Liskove substitution principle

#include <iostream>

class Rectangle
{
protected:
	int height;
	int width;
public: 
	Rectangle(const int width, const int height)
		:height{ height },
		width{ width }
	{

	}
	virtual void set_height(const int height)
	{
		this->height = height;
	}
	virtual void set_width(const int width)
	{
		this->width = width;
	}
	virtual int get_height() const
	{
		return height;
	}
	virtual int get_width() const
	{
		return width;
	}
	int Area() const { return width * height; }
};

void ProcessRectangle(Rectangle & r)
{
	int width = r.get_width();
	r.set_height(10);
	std::cout << "Expected area = " << width * 10 << "Actual area =" << r.Area() <<std::endl;
}

class Square : public Rectangle
{
public:
	Square(const int size)
		:Rectangle{ size,  size }
	{

	}
	void set_height(const int size) override
	{
		this->height = width = size;
	}
	void set_width(const int width) override
	{
		this->width = height = width;
	}
};

int main()
{
	Rectangle r{5,5};
	ProcessRectangle(r);

	Square s{5};
	ProcessRectangle(s);

	getchar();
}

/* Output
Expected area = 50Actual area =50
Expected area = 50Actual area =100
*/