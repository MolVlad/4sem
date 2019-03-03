#include<iostream>

struct Vector2
{
	int x;

	Vector2(const Vector2& other)
	{
		x = other.x;
		std::cout << "copying constructor = " << x << '\n';
	}


	explicit Vector2(int a = 0)
	{
		x = a;
		std::cout << "constructor x = " << x << '\n';
	}

	~Vector2()
	{
		std::cout << "destructor x = " << x << '\n';
	}
};

int main()
{
	//constructors
	Vector2 a;
	//Vector2 b = 1;	// it works only when not explicit
	Vector2 c(2);

	//copying
	Vector2 kek = c;

	return 0;
}

