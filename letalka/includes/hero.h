#ifndef __HERO_H__
#define __HERO_H__

#include <string>
#include"bullet.h"

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
	void move(const float timeDif);
	void setOrigin();
	void takeAim(sf::RenderWindow &window);

	void setScreenSize(int width, int height);
	bool isOnScreen() const;
	void returnToScreen();

	Bullet createBullet(sf::RenderWindow &window);
	float getRechargeTime();

	private:

	my_math::Vector2 speed;

	int screenWidth = 800;
	int screenHeight = 600;

	// configuration constants
	const float speedConfig = 500;
	const float rechargeTime = 0.001f;
};

std::ostream& operator<<(std::ostream& stream, const Hero& hero);

}	/* namespace game */

#endif /* __HERO_H__ */
