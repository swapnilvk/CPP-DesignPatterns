//Single Resposibility Principle

#include<iostream>
#include<vector>
#include<fstream>
#include<string>

class Journal //Responsible to get title and add entries
{
public: 
	std::string title;
	std::vector<std::string> vecEntries;
	Journal(std::string &strTitle)
	{
		title = strTitle;
	}

	void add(const std::string & entry)
	{
		vecEntries.push_back(entry);
	}

	//void Save(const std::string & filename)
	//{
	//	std::ofstream ofs(filename);
	//	for (std::string s : vecEntries)
	//	{
	//		ofs << s << std::endl;
	//	}
	//}
};

class PersistanceManager //Responsible for Persist entries and save to disk
{
	void Save(const Journal & j, const std::string & filename)
	{
		std::ofstream ofs(filename);
		for (std::string s : j.vecEntries)
		{
			ofs << s << std::endl;
		}
	}
};