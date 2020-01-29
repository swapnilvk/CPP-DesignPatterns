#include <iostream>
#include<string>

using namespace std;

struct Address
{
	string street;
	string city;
	int suit;

	Address(const string& s, const string& c)
	{
		street = s;
		city = c;
	}

	friend ostream& operator << (ostream& os, const Address& obj)
	{
		return os << "Street: " << obj.street << "City: " << obj.city << "Suit: " << obj.suit;
	}
};

struct Contact
{
	string name;
	Address* work_address;
	
	Contact(const string& n, Address* a)
	{
		name = n;
		work_address = a;
	}

	~Contact()
	{
		//delete work_address;
	}

	friend ostream& operator << (ostream& os, const Contact & obj)
	{
		return os << "Name: " << obj.name << "Work address" << *obj.work_address;
	}
};

int main()
{ 
	Address* addr = new Address("M G Road", "Pune"); //prototype
	Contact  swapnil("Swapnil Kulkarni", addr);
	swapnil.work_address->suit = 100;
	Contact  smruti("Smruti Kulkarni", addr);
	smruti.work_address->suit = 200;
	cout << swapnil << endl << smruti << endl;

	delete addr;

	getchar();

	return 0;
}

/*Output:
Name: Swapnil KulkarniWork addressStreet: M G RoadCity: PuneSuit: 200
Name: Smruti KulkarniWork addressStreet: M G RoadCity: PuneSuit: 200 */