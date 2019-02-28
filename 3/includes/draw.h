#ifndef __DRAW_H__
#define __DRAW_H__

#define CHARGE_SIZE 1

void drawPowerLines(sf::RenderWindow &window, sf::Vector2i &position, std::vector<sf::Vector2i> &charges);
void drawCharges(sf::RenderWindow &window, std::vector<sf::Vector2i> &charges);

#endif /* __DRAW_H__ */
