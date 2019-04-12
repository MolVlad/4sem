#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<locale>

int main()
{
  int N;
  std::cin >> N;

  std::vector<std::string> v;
  std::string str;

  for(int i = 0; i < N; i++)
  {
    do {
    std::getline(std::cin, str);
    }
    while(str.empty());

    v.push_back(str);
  }

  std::transform(v.begin(), v.end(), v.begin(), [](auto a)
  {
    std::transform(a.begin(), a.end(), a.begin(), tolower);

    a.erase(std::remove_if(a.begin(), a.end(), [](auto c)
    {
      return c == ' ';
    }), a.end());

    return a;
  });

  std::sort(v.begin(), v.end());

  

  for(auto& i : v)
  {
    std::cout << i << std::endl;
  }
}
