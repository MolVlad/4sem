#include<iostream>
#include"Vector2.h"

int main()
{
	std::cout << "Vector2 test\n";

	my_math::Vector2 a1;
	std::cout << "Print vector a1:\n";
	std::cin >> a1;

	my_math::Vector2 a2(1, 2);
	std::cout << "another vector a2: " << a2 << '\n';

	a1 += a2;
	std::cout << "a1 += a2; a1 = " << a1;

	a1 -= a2;
	std::cout << "a1 -= a2; a1 = " << a1;

	std::cout << "a1 + a2 = " << a1 + a2;
	std::cout << "a1 - a2 = " << a1 - a2;
	std::cout << "|a1| = " << a1.Len() << '\n';
	std::cout << "(a1, a1) = " << a1.SquareLen() << '\n';
	std::cout << "(a1, a2) = " << a1 * a2 << '\n';
	std::cout << "[a1, a2] = " << (a1 ^ a2) << '\n';

	float k = 5;
	std::cout << "Print scalar k = ";
	//std::cin >> k;
	std::cout << '\n';
	//std::cout << "a1 * k = " << a1 * k << '\n';
	std::cout << "k * a1 = " << k * a1 << '\n';
	std::cout << "-a1 = " << -a1 << '\n';
	std::cout << "a1 / k = " << a1 / k << '\n';
	std::cout << "perpendicular for a1 = " << a1.Perpendicular() << '\n';
	std::cout << "norm for a1 = " << a1.Norm() << '\n';
	std::cout << "rotation a1 angle 15 radians: " << a1.GetRotated(15);
	std::cout << "rotate a1; a1 = " << a1.GetRotated(15) << '\n';

	return 0;
}
