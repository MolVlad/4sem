t #include<future>
#include<numeric>
#include<functional>
#include<iostream>
#include<vector>

const int Size = 1000000;

int main()
{
  unsigned int N;
  std::cout << "Enter N: ";
  std::cin >> N;

  std::vector<int> v(N * Size);
  for(int& x : v)
  {
    x = rand() % 10;
  }

  std::cout << "start" << std::endl;
  std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();

  std::vector<std::future<int> > f;
  for(int i = 0; i < N; i++)
  {
    f.push_back(std::async([&v, i]() {
      int sum = std::accumulate(v.begin() + i * Size, v.begin() + (i + 1) * Size,
        0, std::plus<int>());
      return sum;
      })
    );
  }

  for(auto& result : f) std::cout << result.get() << " ";
  std::cout << std::endl;

  std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;
  std::cout << diff.count() << " s" << std::endl;

  return 0;
}
