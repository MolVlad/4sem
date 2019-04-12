#include<iostream>

template<int n, int k>
struct C
{
  static const int result = C<n -1, k - 1>::result + C<n, k - 1>::result;
};

template<int n>
struct C<n, 0>
{
  static const int result = 1;
};

template<int n>
struct C<n, n>
{
  static const int result = 1;
};

template<>
struct C<0, 0>
{
  static const int result = 1;
};

int main()
{
  std::cout << "C(n,k) = " << C<0,0>::result << std::endl;

  return 0;
}
