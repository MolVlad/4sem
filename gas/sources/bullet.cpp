#include <SFML/Graphics.hpp>
#include<iostream>
#include"vector2.h"
#include"math.h"
#include"bullet.h"
#include<vector>

using namespace game;

	const float Bullet::bulletSize = 5;
	const float Bullet::speedConfig = 10000;

Bullet::Bullet()
{
	circle = sf::CircleShape(bulletSize);
	circle.setFillColor(sf::Color::Red);
}

Bullet::~Bullet()
{

}

std::ostream& game::operator<<(std::ostream& stream, const Bullet& bullet)
{
	sf::Vector2f position = bullet.circle.getPosition();
	stream << "position: " << position.x << ' ' << position.y << '\n';
	my_math::Vector2 speed = bullet.getSpeed();
	stream << " speed: " << speed << '\n';

	return stream;
}

my_math::Vector2 Bullet::getSpeed() const
{
	return my_math::Vector2(speed.x, speed.y);
}

void Bullet::move(const sf::Time currentTime, sf::Time &timeStamp)
{
	float timeDif = currentTime.asSeconds() - timeStamp.asSeconds();

	sf::Vector2f delta;
	delta.x = speed.x * timeDif;
	delta.y = speed.y * timeDif;

	sf::Vector2f position = circle.getPosition();
	circle.setPosition(position + delta);
}

void Bullet::setSpeed(my_math::Vector2 vector)
{
	speed = vector;
}

bool Bullet::isOnScreen(int width, int height) const
{
	sf::Vector2f position = circle.getPosition();

	if(position.x < (float)0)
		return false;
	if(position.x > (float)width)
		return false;
	if(position.y < (float)0)
		return false;
	if(position.y > (float)height)
		return false;

	return true;
}

BulletsSet::BulletsSet()
{

}

BulletsSet::~BulletsSet()
{

}

void BulletsSet::setScreenSize(int width, int height)
{
	screenWidth = width;
	screenHeight = height;
}

void BulletsSet::push(Bullet bullet)
{
	set.push_back(bullet);
}

void BulletsSet::moveAndDraw(sf::RenderWindow &window, const float timeDif)
{
	sf::Vector2f delta;
	my_math::Vector2 speed;

	for(int i = set.size() - 1; i >= 0; i--)
	{
		speed = set[i].getSpeed();

		delta.x = speed.x * timeDif;
		delta.y = speed.y * timeDif;
		set[i].circle.move(delta);

		if(!(set[i].isOnScreen(screenWidth, screenHeight)))
		{
			set[i] = set[set.size() - 1];
			set.erase(set.begin() + i);
		}
		else
		{
			window.draw(set[i].circle);
			std::cout << set[i] << '\n';
		}
	}
}

float Bullet::getSpeedConfig()
{
	return speedConfig;
}
