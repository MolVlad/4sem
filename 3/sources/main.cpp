#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include"handlers.h"
#include"draw.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");

	std::vector<sf::Vector2i> charges;

	while (window.isOpen())
	{
		window.clear();
		handleEvent(window, charges);
		drawCharges(window, charges);

		window.display();
	}

	return 0;
}

		/*
		sf::Vertex line[2];
		for(int i = 0; i < 10; i++)
		{
			line[0] = sf::Vertex(sf::Vector2f(10 * i, 10 * i));
			line[1] = sf::Vertex(sf::Vector2f(10 * (i + 1), 10 * (i + 1)));

			window.draw(line, 2, sf::Lines);
		}
		*/
