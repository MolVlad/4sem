#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "elements.h"
#include <math.h>
#include "Vector2.h"

using namespace PowerLines;

void Elements::drawPowerLines(sf::RenderWindow &window)
{
	if((posChargePosition.size() == 0) && (negChargePosition.size() == 0))
		return;
my_math::Vector2 resulting;
	my_math::Vector2 position;

	for(int i = 0; i < lines.size(); i++)
	{
		if(!reachedEdge(lines[i]))
		{
			//positive direction
			position = lines[i];

			while((!reachedCharge(position)) && (!reachedEdge(position)))
			{
				resulting = drawFieldVector(window, position);
				position = position + resulting;
			}

			//negative direction
			position = lines[i];

			while((!reachedCharge(position)) && (!reachedEdge(position)))
			{
				resulting = drawFieldVector(window, position);
				position = position - resulting;
			}
		}
	}
}

bool Elements::reachedCharge(my_math::Vector2 position)
{
	for(int i = 0; i < posChargePosition.size(); i++)
	{
		if(deltaNeighbourhood > posChargePosition[i].computeDistance(position))
			return true;
	}

	for(int i = 0; i < negChargePosition.size(); i++)
	{
		if(deltaNeighbourhood > negChargePosition[i].computeDistance(position))
			return true;
	}

	return false;
}

bool Elements::reachedEdge(my_math::Vector2 position)
{
	bool flag = (position.x >= SCREEN_WIDTH) || (position.x <= 0) || (position.y >= SCREEN_HEIGHT) || (position.y <= 0);

	return flag;
}

my_math::Vector2 Elements::computeResulting(my_math::Vector2 const position, std::vector<my_math::Vector2> const charges)
{
	my_math::Vector2 resulting(0,0);
	my_math::Vector2 fromCharge;
	float distance;

	for(int i = 0; i < charges.size(); i++)
	{
		fromCharge.x = position.x - charges[i].x;
		fromCharge.y = position.y - charges[i].y;
		fromCharge = fromCharge.norm();

		float distance = charges[i].computeDistance(position);
		resulting.x += fromCharge.x * chargeValue / (distance * distance);
		resulting.y += fromCharge.y * chargeValue / (distance * distance);
	}

	//my_math::Vector2 ret = resulting.perpendicular();
	//return ret;

	return my_math::Vector2(resulting.x, resulting.y);
}

my_math::Vector2 Elements::drawFieldVector(sf::RenderWindow &window, my_math::Vector2 const position)
{
	my_math::Vector2 posChargesField = computeResulting(position, posChargePosition);
	my_math::Vector2 negChargesField = computeResulting(position, negChargePosition);
	my_math::Vector2 resulting(posChargesField.x - negChargesField.x, posChargesField.y - negChargesField.y);

	resulting = resulting.norm();
	resulting = resulting * lineStep;

	my_math::Vector2 start(position.x, position.y);
	my_math::Vector2 end(resulting.x + position.x, resulting.y + position.y);

	sf::Vertex line[] =
	{
		sf::Vector2f(start.x, start.y),
		sf::Vector2f(end.x, end.y)
	};

	window.draw(line, 2, sf::Lines);

	return my_math::Vector2(resulting.x, resulting.y);
}

void Elements::drawCharges(sf::RenderWindow &window)
{
	sf::CircleShape pointCharge(chargeSize);

	pointCharge.setFillColor(sf::Color::Red);

	for(int i = 0; i < posChargePosition.size(); i++)
	{
		pointCharge.setPosition(posChargePosition[i].x, posChargePosition[i].y);
		window.draw(pointCharge);
	}

	pointCharge.setFillColor(sf::Color::Blue);

	for(int i = 0; i < negChargePosition.size(); i++)
	{
		pointCharge.setPosition(negChargePosition[i].x, negChargePosition[i].y);
		window.draw(pointCharge);
	}
}

void Elements::addPosCharge(my_math::Vector2 position)
{
	posChargePosition.push_back(position);
}

void Elements::addNegCharge(my_math::Vector2 position)
{
	negChargePosition.push_back(position);
}

void Elements::addLine(my_math::Vector2 position)
{
	lines.push_back(position);
}
