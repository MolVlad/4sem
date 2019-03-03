#ifndef __HANDLERS_H__
#define __HANDLERS_H__

#include"elements.h"

void handleEvent(sf::RenderWindow &window, PowerLines::Elements &elements);
void handleMouse(sf::RenderWindow &window, sf::Event event, PowerLines::Elements &elements);

#endif /* __HANDLERS_H__ */
