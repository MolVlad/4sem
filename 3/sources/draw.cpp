#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include"draw.h"

void drawPowerLines(sf::RenderWindow &window, sf::Vector2i &position, std::vector<sf::Vector2i> &charges)
{

}

void drawCharges(sf::RenderWindow &window, std::vector<sf::Vector2i> &charges)
{
	sf::CircleShape pointCharge(CHARGE_SIZE);
	pointCharge.setFillColor(sf::Color::Red);

	for(int i = 0; i < charges.size(); i++)
	{
		pointCharge.setPosition(charges[i].x, charges[i].y);
		window.draw(pointCharge);
	}
}
