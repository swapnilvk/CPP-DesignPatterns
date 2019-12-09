//Interface segregation Principle 
//No client should be forced to depend on methods it does not use

#include<iostream>
#include<vector>
struct Document;

class IMachine
{
public:
	virtual void Print(std::vector<Document*>) = 0;
	virtual void Scan(std::vector<Document*>) = 0;
	virtual void Fax(std::vector<Document*>) = 0;
};

//This is violation of Interface segregation principle because, even if user in not interested in Fax and Scan user has forced this method inside object.
class MFP : public IMachine
{
	void Print(std::vector<Document*>) override;
	void Scan(std::vector<Document*>) override;
	void Fax(std::vector<Document*>) override;
};

//Solution is to declare separate interfaces for each functionality
class IPrinter
{
public:
	virtual void Print(std::vector<Document*>) = 0;
};
class Printer : public IPrinter
{
public:
	void Print(std::vector<Document*>) override;
};

class IScanner
{
public:
	virtual void Scan(std::vector<Document*>) = 0;
};
class Scanner : public IScanner
{
public:
	void Scan(std::vector<Document*>) override;
};

//If user expect common interface all functionalities of Multi functional program
class IMachineMFP : public IPrinter, IScanner
{
};
class Machine : public IMachine
{
public:
	IPrinter& printer;
	IScanner& scanner;

	Machine(IPrinter &printer, IScanner &scanner)
		: printer{printer},
		 scanner{scanner}
	{
	}

	void Print(std::vector<Document*>) override;
	void Scan(std::vector<Document*>) override;
};