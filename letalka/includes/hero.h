#ifndef __HERO_H__
#define __HERO_H__

#include <string>

namespace game {

class Hero
{
	public:

	Hero();

	~Hero();

	sf::Sprite sprite;
	sf::Texture texture;

	my_math::Vector2 getSpeed() const;
	void setSpeed(my_math::Vector2 vector);
	void updateSpeed();

	void setScreenSize(int width, int height);
	bool isOnScreen() const;
	void returnToScreen();

	private:

	my_math::Vector2 speed;

	const float speedConfig = 1;

	int screenWidth = 800;
	int screenHeight = 600;
};

std::ostream& operator<<(std::ostream& stream, const Hero& hero);

}	/* namespace object */

#endif /* __HERO_H__ */
