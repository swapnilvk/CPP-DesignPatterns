//Construct complex object from simple objects step by step
//Example of builder design pattern
#include<iostream>
#include<vector>
#include<sstream>

using namespace std;

class HtmlElement
{
public:
	string name;
	string text;
	vector<HtmlElement> elements;
	const size_t indent_size = 2;

	HtmlElement()
	{
	}

	HtmlElement(const string &name, const string & text)
		:name{name},
		text{text}
	{

	}

	string str(int indent = 0)
	{
		ostringstream oss;
		string i(indent_size*indent, ' ');

		oss<< i << "<" << name << ">" << endl;

		if (text.size() > 0)
			oss << string(indent_size*(indent + 1), ' ') << text << endl;
		for (auto &e : elements)
			oss << e.str(indent + 1);
		oss << i << "</" << name << ">" << endl;
		return oss.str();
	}
};

class HTMLBuilder
{
public:
	HtmlElement root;
	HTMLBuilder(string root_name)
	{
		root.name = root_name;
	}

	void add_child(string child_name, string child_text)
	{
		HtmlElement e(child_name, child_text);
		root.elements.emplace_back(e);
	}

	string str()
	{ 
		return root.str(); 
	}
};

int main()
{
	HTMLBuilder builder("ul");
	builder.add_child("li", "hello");
	builder.add_child("li", "world");
	cout << builder.str();

	getchar();
	return 0;
}

/*Output
<ul>
  <li>
    hello
  </li>
  <li>
    world
  </li>
</ul>
*/