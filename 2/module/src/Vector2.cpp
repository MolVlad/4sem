#include<iostream>
#include"Vector2.h"
#include"math.h"

my_math::Vector2::Vector2(const Vector2 &a)
{
	x = a.x;
	y = a.x;

	std::cout << "copy Vector2\n";
	std::cout << "x = " << x << '\n';
	std::cout << "y = " << y << '\n';
}

my_math::Vector2::Vector2(float x1, float y1)
{
	x = x1;
	y = y1;

	std::cout << "constructor Vector2\n";
	std::cout << "x = " << x << '\n';
	std::cout << "y = " << y << '\n';
}

my_math::Vector2::~Vector2()
{
	std::cout << "destructor x = " << x << " y = " << y << '\n';
}

float my_math::Vector2::Len() const
{
	return sqrt(x * x + y * y);
}

float my_math::Vector2::SquareLen() const
{
	return x * x + y * y;
}

std::ostream& my_math::operator<<(std::ostream& stream, const my_math::Vector2& v)
{
	stream << v.x << " " << v.y << '\n';
	return stream;
}

std::istream& my_math::operator>>(std::istream& stream, const my_math::Vector2& v)
{
	//stream >> v.x >> v.y;
	return stream;
}

my_math::Vector2 my_math::Vector2::operator+(const my_math::Vector2& other) const
{
	return my_math::Vector2(other.x + x, other.y + y);
}

void my_math::Vector2::operator+=(const my_math::Vector2& other)
{
	x = x + other.x;
	y = y + other.y;
}

my_math::Vector2 my_math::Vector2::operator-(const my_math::Vector2& other) const
{
	return my_math::Vector2(x - other.x, y - other.y);
}

void my_math::Vector2::operator-=(const my_math::Vector2& other)
{
	x = x - other.x;
	y = y - other.y;
}

