#include <SFML/Graphics.hpp>
#include<iostream>
#include"vector2.h"
#include"math.h"
#include"hero.h"

using namespace game;

Hero::Hero()
{

}

Hero::~Hero()
{

}

std::ostream& game::operator<<(std::ostream& stream, const Hero& hero)
{
	sf::Vector2f position = hero.sprite.getPosition();
	stream << "position: " << position.x << ' ' << position.y << '\n';
	my_math::Vector2 speed = hero.getSpeed();
	stream << " speed: " << speed << '\n';

	return stream;
}

my_math::Vector2 Hero::getSpeed() const
{
	return my_math::Vector2(speed.x, speed.y);
}

void Hero::updateSpeed()
{
	speed.x = speed.y = 0;

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		speed.x += -1;
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		speed.y += -1;
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		speed.x += 1;
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		speed.y += 1;

	speed.x *= speedConfig;
	speed.y *= speedConfig;
}

void Hero::setSpeed(my_math::Vector2 vector)
{
	speed = vector;
}

void Hero::setScreenSize(int width, int height)
{
	screenWidth = width;
	screenHeight = height;
}

void Hero::returnToScreen()
{
	sf::Vector2f position = sprite.getPosition();
	sf::Vector2u size = sprite.getTexture()->getSize();
	float half = size.x / 2;

	if(position.x < half)
		position.x = half;
	if(position.x > (screenWidth - half))
		position.x = screenWidth - half;
	if(position.y < half)
		position.y = half;
	if(position.y > (screenHeight - half))
		position.y = screenHeight - half;
}

bool Hero::isOnScreen() const
{
	sf::Vector2f position = sprite.getPosition();
	sf::Vector2u size = sprite.getTexture()->getSize();
	float half = size.x / 2;

	if(position.x < half)
		return false;
	if(position.x > (screenWidth - half))
		return false;
	if(position.y < half)
		return false;
	if(position.y > (screenHeight - half))
		return false;

	return true;
}
