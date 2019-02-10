#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<fstream>
#include<algorithm>
#include <locale>

struct Statistics
{
	int count;
	std::string word;
};

bool more(const struct Statistics & lhs, const struct Statistics & rhs)
{
	return lhs.count > rhs.count;
}

bool isLetter(const char c)
{
	return ((c >= 'a') && (c <= 'z')) || ((c >= 'A') && (c <= 'Z'));
}

std::string prepare(const std::string & s)
{
	std::string result;
	result.resize(s.size());
	int firstLetter = 0;

	std::transform(s.begin(), s.end(), result.begin(), ::tolower);

	while(!isLetter(result[0]))
	{
		result.erase(0,1);
	}

	while(!isLetter(result[result.size() - 1]))
	{
		result.pop_back();
	}

	return result;
}

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
			s = prepare(s);
			dict[s]++;
		}
	}

	struct Statistics stat;
	std::vector<Statistics> vectorStat;

	std::cout << "\n";
	for(auto&[word, amount] : dict)
	{
		stat.count = amount;
		stat.word = word;

		vectorStat.push_back(stat);
	}

	std::sort(vectorStat.begin(), vectorStat.end(), more);

	for(int i = 0; i < vectorStat.size(); i++)
	{
		std::cout << vectorStat[i].count << " - " << vectorStat[i].word << '\n';
	}

	return 0;
}
