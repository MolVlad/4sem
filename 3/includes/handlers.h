#ifndef __HANDLERS_H__
#define __HANDLERS_H__

void handleEvent(sf::RenderWindow &window, std::vector<sf::Vector2i> &charges, std::vector<sf::Vector2i> &lines);
void handleMouse(sf::RenderWindow &window, sf::Event &event, std::vector<sf::Vector2i> &charges, std::vector<sf::Vector2i> &lines);

#endif /* __HANDLERS_H__ */
