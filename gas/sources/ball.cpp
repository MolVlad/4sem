#include <SFML/Graphics.hpp>
#include<iostream>
#include"vector2.h"
#include"math.h"
#include<vector>
#include"mat_point.h"
#include"ball.h"
#include<cstdlib>

const int maxVelocity = 1000;

Ball::Ball(sf::Vector2i mousePosition)
{
	circle = sf::CircleShape(radius);
	circle.setFillColor(sf::Color::Red);

  position.x = mousePosition.x;
  position.y = mousePosition.y;

  velocity.x = rand() % (maxVelocity * 2) - maxVelocity;
  velocity.y = rand() % (maxVelocity * 2) - maxVelocity;
}

Ball::~Ball()
{

}

BallSet::BallSet()
{

}

BallSet::~BallSet()
{

}

void BallSet::setScreenSize(int width, int height)
{
	screenWidth = width;
	screenHeight = height;
}

void BallSet::push(Ball ball)
{
	set.push_back(ball);
}

void BallSet::moveAndDraw(sf::RenderWindow &window, const float dt)
{
	for(int i = set.size() - 1; i >= 0; i--)
	{
    set[i].updatePosition(dt);

    set[i].circle.setPosition(set[i].position.x, set[i].position.y);

		window.draw(set[i].circle);
	}
}
