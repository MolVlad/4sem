#include<iostream>
#include"Vector2.h"
#include"math.h"

using namespace my_math;

Vector2::Vector2(const Vector2 &a)
{
	x = a.x;
	y = a.y;
}

Vector2::Vector2(const sf::Vector2i &a)
{
	x = a.x;
	y = a.y;
}

Vector2::Vector2(const sf::Vector2f &a)
{
	x = a.x;
	y = a.y;
}

Vector2::Vector2(float x1, float y1)
{
	x = x1;
	y = y1;
}

Vector2::~Vector2()
{

}

float Vector2::len() const
{
	return sqrt(x * x + y * y);
}

float Vector2::squareLen() const
{
	return x * x + y * y;
}

std::ostream& operator<<(std::ostream& stream, const Vector2& v)
{
	stream << v.x << " " << v.y << '\n';
	return stream;
}

std::istream& operator>>(std::istream& stream, Vector2& v)
{
	stream >> v.x >> v.y;
	return stream;
}

Vector2 Vector2::operator+(const Vector2& other) const
{
	return Vector2(other.x + x, other.y + y);
}

void Vector2::operator+=(const Vector2& other)
{
	x = x + other.x;
	y = y + other.y;
}

Vector2 Vector2::operator-(const Vector2& other) const
{
	return Vector2(x - other.x, y - other.y);
}

void Vector2::operator-=(const Vector2& other)
{
	x = x - other.x;
	y = y - other.y;
}

float Vector2::operator^(const Vector2& other) const
{
	return x * other.y - y * other.x;
}

Vector2 Vector2::operator*(float k) const
{
	return Vector2(x * k, y * k);
}

Vector2 operator*(float k, const Vector2& v)
{
	return Vector2(v.x * k, v.y * k);
}

Vector2 Vector2::operator-()
{
	return Vector2(-x, -y);
}

Vector2 Vector2::operator/(float k)
{
	return Vector2(x/k, y/k);
}

Vector2 Vector2::perpendicular() const
{
	return Vector2(y, -x);
}

Vector2 Vector2::norm() const
{
	float length = len();
	return Vector2(x / length, y / length);
}

void Vector2::rotate(float angle)
{
	float last_x = x;
	float last_y = y;
	float sin_angle = sin(angle);
	float cos_angle = cos(angle);
	x = last_x * cos_angle - last_y * sin_angle;
	y = last_x * sin_angle + last_y * cos_angle;
}

Vector2 Vector2::getRotated(float angle)
{
	float sin_angle = sin(angle);
	float cos_angle = cos(angle);

	return Vector2(x * cos_angle - y * sin_angle, x * sin_angle + y * cos_angle);
}

float Vector2::computeDistance(const Vector2& other) const
{
	float delta_x, delta_y;
	delta_x = x - other.x;
	delta_y = y - other.y;

	return sqrt(delta_x * delta_x + delta_y * delta_y);
}

void Vector2::print() const
{
	std::cout << x << ' ' << y << '\n';
}
