#include<iostream>
#include"vector2.h"
#include"math.h"

my_math::Vector2::Vector2(const Vector2 &a)
{
	x = a.x;
	y = a.y;
}

my_math::Vector2::Vector2(float x1, float y1)
{
	x = x1;
	y = y1;
}

my_math::Vector2::~Vector2()
{

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

std::istream& my_math::operator>>(std::istream& stream, my_math::Vector2& v)
{
	stream >> v.x >> v.y;
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

/*
float my_math::Vector2::operator*(const my_math::Vector2& other)
{
	return x * other.x + y * other.y;
}
*/

float my_math::Vector2::operator^(const my_math::Vector2& other) const
{
	return x * other.y - y * other.x;
}

my_math::Vector2 my_math::Vector2::operator*(float k) const
{
	return my_math::Vector2(x * k, y * k);
}

my_math::Vector2 my_math::operator*(float k, const my_math::Vector2& v)
{
	return my_math::Vector2(v.x * k, v.y * k);
}

my_math::Vector2 my_math::Vector2::operator-()
{
	return my_math::Vector2(-x, -y);
}

my_math::Vector2 my_math::Vector2::operator/(float k)
{
	return my_math::Vector2(x/k, y/k);
}

my_math::Vector2 my_math::Vector2::Perpendicular() const
{
	return Vector2(y, -x);
}

my_math::Vector2 my_math::Vector2::Norm() const
{
	float len = Len();
	return Vector2(x / len, y / len);
}

void my_math::Vector2::Rotate(float angle)
{
	float last_x = x;
	float last_y = y;
	float sin_angle = sin(angle);
	float cos_angle = cos(angle);
	x = last_x * cos_angle - last_y * sin_angle;
	y = last_x * sin_angle + last_y * cos_angle;
}

my_math::Vector2 my_math::Vector2::GetRotated(float angle)
{
	float sin_angle = sin(angle);
	float cos_angle = cos(angle);

	return Vector2(x * cos_angle - y * sin_angle, x * sin_angle + y * cos_angle);
}
