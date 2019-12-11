//Groovy Style Builder
//Initializer lists let you implement Groovy - style builders with ease.

#include<iostream>
#include<vector>
#include<sstream>

using namespace std;

class Tag
{
public:
	string text;
	string name;
	vector<Tag> children;
	vector<pair<string, string>> attributes;

	friend ostream& operator <<(ostream &os, const Tag & tag)
	{
		os << "<" << tag.name;

		for (const auto &att : tag.attributes)
			os << " " << att.first << "=\"" << att.second << "\"";
		if (tag.children.size() == 0 && tag.text.length() == 0)
		{
			os << "/>" << endl;
		}
		else
		{
			os << ">"<<endl;
			if (tag.text.length())
				os << tag.text << endl;

			for (const auto & child : tag.children)
				os << child;
			
			os << "</" << tag.name << ">"<<endl;
		}

		return os;
	}

protected:
	Tag(const string & name, const string & text)
		:name{ name },
		text{ text }
	{

	}
	Tag(const string & name, const vector<Tag> & children)
		:name{ name },
		children{ children }
	{

	}
};

class P : public Tag
{
public:
	explicit P(const string & text)
		:Tag("P", text)
	{

	}

	P(initializer_list<Tag> children)
		:Tag("p", children)
	{

	}

};

class Img : public Tag
{
public:
	explicit Img(const string & url)
		:Tag("Img", "")
	{
		attributes.emplace_back(make_pair("src", url));
	}
};

int main()
{
	cout<<
		P{
	Img{ "https://spiritual-geek.github.io/"}
	};
	getchar();
	return 0;
}

/*output:
<p>
<Img src="https://spiritual-geek.github.io/"/>
</p>*/