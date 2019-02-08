#include<algorithm>
#include<iostream>
#include<vector>
#include<string>

bool more(const std::string& lhs, const std::string& rhs)
{
	if(lhs.size() != rhs.size())
		return lhs < rhs;

	return lhs < rhs;
}

int main()
{
	std::vector<std::string> a;
	int N;
	std::cin >> N;

	for(int i = 0; i < N; i++)
	{
		std::string s;
		std::cin >> s;
		a.push_back(s);
	}

	std::sort(a.begin(), a.end(), more);

	for(int i = 0; i < N; i++)
	{
		std::cout << a[i] << '\n';
	}

	return 0;
}
