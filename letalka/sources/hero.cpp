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

void Hero::move(const float timeDif)
{
	sf::Vector2f delta;
	delta.x = speed.x * timeDif;
	delta.y = speed.y * timeDif;

	sf::Vector2f position = sprite.getPosition();
	sprite.setPosition(position + delta);
	returnToScreen();
}

void Hero::setOrigin()
{
	sf::Vector2u size = sprite.getTexture()->getSize();
	sprite.setOrigin(size.x / 2, size.y / 2);
}

void Hero::takeAim(sf::RenderWindow &window)
{
	sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
	sf::Vector2f center = sprite.getPosition();
	sf::Vector2f d = sf::Vector2f(mousePosition.x, mousePosition.y) - center;

	const float pi = 3.1415f;
	sprite.setRotation(90 + atan2f(d.y, d.x) * 180 / pi);
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
	sf::Vector2f scale = sprite.getScale();
	sf::Vector2u size = sprite.getTexture()->getSize();
	size.x *= scale.x;
	size.y *= scale.y;

	if(position.x < (size.x / 2))
		position.x = (size.x / 2);
	if(position.x > (screenWidth - (size.x / 2)))
		position.x = screenWidth - (size.x / 2);
	if(position.y < (size.y / 2))
		position.y = (size.y / 2);
	if(position.y > (screenHeight - (size.y / 2)))
		position.y = screenHeight - (size.y / 2);

	sprite.setPosition(position);
}

bool Hero::isOnScreen() const
{
	sf::Vector2f position = sprite.getPosition();
	sf::Vector2u size = sprite.getTexture()->getSize();
	float half = size.x / 2;

	if(position.x < (size.x / 2))
		return false;
	if(position.x > (screenWidth - (size.x / 2)))
		return false;
	if(position.y < (size.y / 2))
		return false;
	if(position.y > (screenHeight - (size.y / 2)))
		return false;

	return true;
}

Bullet Hero::createBullet(sf::RenderWindow &window)
{
	sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
	sf::Vector2f center = sprite.getPosition();

	game::Bullet bullet;
	my_math::Vector2 speed = my_math::Vector2((float)mousePosition.x - center.x, (float)mousePosition.y - center.y);
	speed = speed.Norm();
	speed = speed * bullet.getSpeedConfig();

	bullet.setSpeed(speed);
	bullet.circle.setPosition(sprite.getPosition());

	return bullet;
}

float Hero::getRechargeTime()
{
	return rechargeTime;
}
