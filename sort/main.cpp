#include<algorithm>
#include<iostream>
#include<ctime>
#include<vector>
#include"stdlib.h"

#define MAX 100

template <typename T>
struct Comparator {
  static size_t count;
  bool operator()(const T& x, const T& y) {
    ++count;
    return x < y;
  }
};

template<typename T>
size_t Comparator<T>::count = 0;

int main(int argc, char *argv[]) {
  if(argc != 2)
  {
    std::cout << "Arg error\n";
    return 1;
  }

  int number = atoi(argv[1]);

  std::vector<int> v;

  srand(time(NULL));

  for(int i = 0; i < number; i++)
  {
    v.push_back(rand() % MAX);
  }

  std::cout << "NUMBER: " << number << std::endl;

  Comparator<int> comp = Comparator<int>();
  std::sort(v.begin(), v.end(), comp);
  std::cout << "SWAP: " << comp.count << std::endl;

  return 0;
}

