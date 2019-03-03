#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include"handlers.h"
#include"elements.h"

void handleEvent(sf::RenderWindow &window, PowerLines::Elements &elements)
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
				handleMouse(window, event, elements);
				break;
		}
	}
}

void handleMouse(sf::RenderWindow &window, sf::Event event, PowerLines::Elements &elements)
{
	sf::Vector2i position = sf::Mouse::getPosition(window);

	switch(event.key.code)
	{
		case sf::Mouse::Left:
			elements.addPosCharge(my_math::Vector2(position));
			break;
		case sf::Mouse::Right:
			elements.addNegCharge(my_math::Vector2(position));
			break;
		case sf::Mouse::Middle:
			elements.addLine(my_math::Vector2(position));
			break;
	}
}
