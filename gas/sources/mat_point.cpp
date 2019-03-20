#include <SFML/Graphics.hpp>
#include<iostream>
#include"vector2.h"
#include"math.h"
#include<vector>
#include"mat_point.h"

MaterialPoint::MaterialPoint()
{

}

MaterialPoint::~MaterialPoint()
{

}

void MaterialPoint::updatePosition(const float dt)
{
  position += velocity * dt;
}

my_math::Vector2 MaterialPoint::getImpulse() const
{
  return velocity * mass;
}
