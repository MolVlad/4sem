#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <math.h>
#include "vector2.h"
#include "hero.h"

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

	sf::Clock clock;
	sf::Time lastTime = clock.getElapsedTime();

	//sf::CircleShape bul(3);
	//std::vector<Bullet> bullets;

	while (window.isOpen())
	{
		window.clear();

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		sf::Time time = clock.getElapsedTime();

		hero.updateSpeed();
		std::cout << hero;
		//std::cout << "speed: " << hero.getSpeed() << '\n';

/*
		delta.x = speed.x * (time.asSeconds() - lastTime.asSeconds());
		delta.y = speed.y * (time.asSeconds() - lastTime.asSeconds());

		hero.sprite.setPosition(position);

		//bullets coordinates
		for(int i = 0; i < bullets.size(); i++)
		{
			delta.x = bullets[i].speed.x * (time.asSeconds() - lastTime.asSeconds());
			delta.y = bullets[i].speed.y * (time.asSeconds() - lastTime.asSeconds());

			bullets[i].position += delta;
			bul.setPosition(bullets[i].position);
			window.draw(bul);
		}

		lastTime = time;

		//rotation
		sf::Vector2u circleSize = circle.getTexture()->getSize();
		circle.setOrigin(circleSize.x / 2, circleSize.y / 2);

		sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
		sf::Vector2f center = circle.getPosition();
		sf::Vector2f d = sf::Vector2f(mousePosition.x, mousePosition.y) - center;

		const float pi = 3.1415f;
		circle.setRotation(90 + atan2f(d.y, d.x) * 180 / pi);

		//bullets create
		if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			Bullet bullet;
			bullet.position = position;
			bullet.speed = d;
			normalizeVector(bullet.speed);
			scaleVector(bullet.speed, 500);

			bullets.push_back(bullet);
		}
*/

		window.draw(hero.sprite);
		window.display();
	}

	return 0;
}
