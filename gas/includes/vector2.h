#ifndef __VECTOR_2__
#define __VECTOR_2__

#include<iostream>

namespace my_math {

class Vector2
{
	public:

	Vector2(const Vector2 &a);
	Vector2(float x1 = 0, float y0 = 0);

	~Vector2();

	float Len() const;
	float SquareLen() const;
	Vector2 Perpendicular() const;
	Vector2 Norm() const;
	void Rotate(float angle);
	Vector2 GetRotated(float angle);

	Vector2 operator+(const Vector2& other) const;
	void operator+=(const Vector2& other);

	Vector2 operator-(const Vector2& other) const;
	void operator-=(const Vector2& other);

	//float operator*(const Vector2& other);
	float operator^(const Vector2& other) const;

	Vector2 operator*(float k) const;
	Vector2 operator-();
	Vector2 operator/(float k);

	float x, y;

	private:
};

std::ostream& operator<<(std::ostream& stream, const Vector2& v);
std::istream& operator>>(std::istream& stream, Vector2& v);
Vector2 operator*(float k, const Vector2& v);

} /* namespace my_math */

#endif /* __VECTOR_2__ */
