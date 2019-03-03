#ifndef __ELEMENTS_H__
#define __ELEMENTS_H__

#include "Vector2.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

namespace PowerLines {

class Elements
{
	public:

	std::vector<my_math::Vector2> posChargePosition;
	std::vector<my_math::Vector2> negChargePosition;
	std::vector<my_math::Vector2> lines;

	void drawPowerLines(sf::RenderWindow &window);
	void drawCharges(sf::RenderWindow &window);

	void addPosCharge(my_math::Vector2 position);
	void addNegCharge(my_math::Vector2 position);
	void addLine(my_math::Vector2 position);

	private:

	my_math::Vector2 computeResulting(my_math::Vector2 const position, std::vector<my_math::Vector2> const charges);
	my_math::Vector2 drawFieldVector(sf::RenderWindow &window, my_math::Vector2 const position);

	bool reachedCharge(my_math::Vector2 position);
	bool reachedEdge(my_math::Vector2 position);

	// configuration constants
	unsigned int chargeSize = 1;	// size of charge on the screen
	float chargeValue = 10;
	unsigned int lineStep = 2;	// power line step in pixel
	float deltaNeighbourhood = 3;
};

} /* namespace PowerLines */

#endif /* __ELEMENTS_H__ */
