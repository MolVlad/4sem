#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <math.h>
#include "vector2.h"
#include "mat_point.h"
#include "ball.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

int main()
{
	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Letalka");

	sf::Clock clock;
	sf::Time currentTime, movementTimeStamp, ballTimeStamp;
	movementTimeStamp = ballTimeStamp = clock.getElapsedTime();
	float dt;

	BallSet ballSet;
	ballSet.setScreenSize(SCREEN_WIDTH, SCREEN_HEIGHT);

	while (window.isOpen())
	{
		window.clear();

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

    if(event.type == event.MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
		{
			ballTimeStamp = currentTime;
			ballSet.push(Ball(sf::Mouse::getPosition(window)));
		}

		currentTime = clock.getElapsedTime();
		dt = currentTime.asSeconds() - movementTimeStamp.asSeconds();

    ballSet.makeCollisions();
		ballSet.moveAndDraw(window, dt);

		movementTimeStamp = currentTime;

		window.display();
	}

	return 0;
}
