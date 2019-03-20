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

void Ball::returnToScreen()
{
	sf::Vector2f position = circle.getPosition();

	if((position.x < (radius)) && (velocity.x < 0))
    velocity.x = -velocity.x;
	if((position.x > (800 - (radius))) && (velocity.x > 0))
    velocity.x = -velocity.x;
	if((position.y < (radius)) && (velocity.y < 0))
    velocity.y = -velocity.y;
	if((position.y > (600 - (radius))) && (velocity.y > 0))
    velocity.y = -velocity.y;

	circle.setPosition(position);
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
		window.draw(set[i].circle);

    set[i].updatePosition(dt);

    set[i].circle.setPosition(set[i].position.x, set[i].position.y);

    set[i].returnToScreen();
	}
}

void BallSet::makeCollisions()
{
  float distance;
  my_math::Vector2 dr;
  my_math::Vector2 dv;
  my_math::Vector2 dp;
  my_math::Vector2 n;

  for(int i = set.size() - 1; i >= 0; i--)
	{
    for(int j = i - 1; j >= 0; j--)
    {
      std::cout << "START\n";
      std::cout << set[i].position << '\n';
      std::cout << set[j].position << '\n';
      dr.x = set[i].position.x - set[j].position.x;
      dr.y = set[i].position.y - set[j].position.y;
      std::cout << "dr " << dr << '\n';

      distance = dr.Len();
      std::cout << "dist " << distance << '\n';
      dv = set[j].velocity - set[i].velocity;
      std::cout << "dv " << dv << '\n';

      if((distance < (set[j].radius + set[i].radius)) &&
            ((dv ^ dr) >= 0))
      {
        n = dr.Norm();
        std::cout << "n " << n << '\n';
        float reducedMass = 1 / set[i].mass + 1 / set[j].mass;
        std::cout << "red mas " << reducedMass << '\n';
        float k = (dv / (reducedMass) * 2) ^ n;
        dp = k * n;
        std::cout << "k = " << k << '\n';
        std::cout << "dp " << dp << '\n';

        std::cout << "lol" << '\n';
        std::cout << dp << '\n';
        set[i].velocity += (dp / set[i].mass);
        set[j].velocity -= (dp / set[j].mass);

        std::cout << "loool\n";
      }
    }
	}
}

