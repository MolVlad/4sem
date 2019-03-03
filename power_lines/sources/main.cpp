#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include"handlers.h"
#include"elements.h"
#include "Vector2.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Power Lines!");

	PowerLines::Elements elements;

	while(window.isOpen())
	{
		window.clear();
		handleEvent(window, elements);
		elements.drawCharges(window);
		elements.drawPowerLines(window);

		window.display();
	}

	return 0;
}
