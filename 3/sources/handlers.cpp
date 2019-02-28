#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include"handlers.h"
#include"draw.h"

void handleEvent(sf::RenderWindow &window, std::vector<sf::Vector2i> &charges, std::vector<sf::Vector2i> &lines)
{
	sf::Event event;

	while (window.pollEvent(event))
	{
		switch(event.type)
		{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::MouseButtonPressed:
				handleMouse(window, event, charges, lines);
				break;
		}
	}
}

void handleMouse(sf::RenderWindow &window, sf::Event &event, std::vector<sf::Vector2i> &charges, std::vector<sf::Vector2i> &lines)
{
	sf::Vector2i position = sf::Mouse::getPosition(window);

	switch(event.key.code)
	{
		case sf::Mouse::Left:
			charges.push_back(position);
			break;
		case sf::Mouse::Right:
			lines.push_back(position);
			break;
	}
}
