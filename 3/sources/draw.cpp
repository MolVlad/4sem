#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include"draw.h"

void drawPowerLines(sf::RenderWindow &window, std::vector<sf::Vector2i> &charges, std::vector<sf::Vector2i> &lines)
{
	for(int i = 0; i < lines.size(); i++)
		drawLine(window, lines[i], charges);
}

void drawLine(sf::RenderWindow &window, sf::Vector2i &position, std::vector<sf::Vector2i> &charges)
{
	// while don't reach charge or end of the screen

	drawFieldStrength(window, position, charges);
}

void drawFieldStrength(sf::RenderWindow &window, sf::Vector2i &position, std::vector<sf::Vector2i> &charges)
{
	sf::Vector2f resulting(10, 10);

	for(int i = 0; i < charges.size(); i++)
	{
	// first step: compute distance from point charge to out position
	// second step: find normal vector of this charge's field strength
	// third step: add vector coordinates to fieldStrength vector
	}

	// normalize resulting vector

	sf::Vector2f start(position.x, position.y);
	sf::Vector2f end(resulting.x + position.x, resulting.y + position.y);

	sf::Vertex line[] =
	{
		start,
		end
	};

	window.draw(line, 2, sf::Lines);
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
