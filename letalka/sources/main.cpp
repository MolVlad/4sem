#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <math.h>
#include "vector2.h"
#include "hero.h"
#include "bullet.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

#define SPEED 200

int main()
{
	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Letalka");

	game::Hero hero;
	hero.setScreenSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	hero.texture.loadFromFile("smile.png");
	hero.sprite = sf::Sprite(hero.texture);
	hero.sprite.setScale(2.0f, 2.0f);
	hero.setOrigin();

	sf::Clock clock;
	sf::Time currentTime, movementTimeStamp, bulletsTimeStamp;
	movementTimeStamp = bulletsTimeStamp = clock.getElapsedTime();
	float timeDif;

	game::BulletsSet bulletsSet;
	bulletsSet.setScreenSize(SCREEN_WIDTH, SCREEN_HEIGHT);

	while (window.isOpen())
	{
		window.clear();

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		hero.takeAim(window);
		hero.updateSpeed();

		currentTime = clock.getElapsedTime();
		timeDif = currentTime.asSeconds() - movementTimeStamp.asSeconds();

		hero.move(timeDif);
		bulletsSet.moveAndDraw(window, timeDif);

		if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if(currentTime.asSeconds() >= (bulletsTimeStamp.asSeconds() + hero.getRechargeTime()))
			{
				bulletsTimeStamp = currentTime;
				bulletsSet.push(hero.createBullet(window));
			}
		}

		movementTimeStamp = currentTime;

		window.draw(hero.sprite);
		window.display();
	}

	return 0;
}
