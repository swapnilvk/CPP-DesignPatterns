#include <iostream>
#include<string>
#include<memory>

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
		return os << "Street: " << obj.street << " City: " << obj.city << " Suit: " << obj.suit;
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
		return os << "Name: " << obj.name << " Work address: " << *obj.work_address;
	}
};

class EmployeeFactory
{
    public:
        static Contact main;
        static Contact aux;

        static unique_ptr<Contact> NewMainOfficeEmployee(string name, int suit)
        {
            return NewEmpoyee(name,suit, main);
        }
        static unique_ptr<Contact> NewAuxOfficeEmployee(string name, int suit)
        {
            return NewEmpoyee(name,suit, aux);
        }
    private:
    static unique_ptr<Contact> NewEmpoyee(string name, int suit, Contact & proto)
    {
        auto result = make_unique<Contact>(proto);
        result->name = name;
        result->work_address->suit = suit;

        return result;
    }
};

Contact EmployeeFactory :: main{"", new Address("Mahatma Gandhi Road", "Pune")};
Contact EmployeeFactory :: aux{"", new Address("V D Savarkar Road", "Pune")};

int main()
{ 
    auto swapnil = EmployeeFactory::NewMainOfficeEmployee("Swapnil", 100);
    auto smruti = EmployeeFactory::NewAuxOfficeEmployee("Smruti", 200);

	cout << *swapnil << endl << *smruti << endl;

	return 0;
}

/*Output:
Name: Swapnil Work address: Street: Mahatma Gandhi Road City: Pune Suit: 100
Name: Smruti Work address: Street: V D Savarkar Road City: Pune Suit: 200 */