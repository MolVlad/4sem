#include<iostream>
#include"Vector2.h"

int main()
{
	std::cout << "Vector2 test\n";
	my_math::Vector2 a1(1, 2);
	my_math::Vector2 a2(2, 3);
	std::cout << a1 + a2;
	a1 += a2;
	std::cout << a1;

	std::cout << a1 - a2;
	a1 -= a2;
	std::cout << a1;


	
	/*std::cout << "Print two vectors:\n";
	std::cin >> a1;
	std::cin >> a2;
	std::cout << a1;
	std::cout << a2;
	*/

	/*
	my_math::Vector2 a(3, 4);
	std::cout << "Length = " << a.Len() << '\n';
	std::cout << "Square length = " << a.SquareLen() << '\n';
	*/

	return 0;
}
