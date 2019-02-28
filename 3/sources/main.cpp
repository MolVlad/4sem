#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include"handlers.h"
#include"draw.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");

	std::vector<sf::Vector2i> charges;
	std::vector<sf::Vector2i> lines;

	while (window.isOpen())
	{
		window.clear();
		handleEvent(window, charges, lines);
		drawCharges(window, charges);
		drawPowerLines(window, charges, lines);

		window.display();
	}

	return 0;
}
