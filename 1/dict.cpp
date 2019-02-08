#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<fstream>

int main()
{
	std::map<std::string, int> dict;
	std::string s;
	std::ifstream f("book.txt");
	if(f.is_open())
	{
		while(!f.eof())
		{
			f >> s;
			dict[s]++;
			std::cout << s << '=' << dict[s] << '\n';
		}
	}

	std::cout << "\n";
	for(auto&[word, amount] : dict)
	{
		std::cout << word << '=' << amount << '\n';
	}

	return 0;
}
