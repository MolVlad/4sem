#ifndef __BULLET_H__
#define __BULLET_H__

#include <string>
#include <vector>

namespace game {

class Bullet
{
	public:

	Bullet();

	~Bullet();

	sf::CircleShape circle;

	my_math::Vector2 getSpeed() const;
	void setSpeed(my_math::Vector2 vector);
	void move(const sf::Time currentTime, sf::Time &timeStamp);

	bool isOnScreen(int width, int height) const;

	float getSpeedConfig();

	private:

	my_math::Vector2 speed;

	// configuration constants
	const float bulletSize = 2;
	const float speedConfig = 1500;
};

std::ostream& operator<<(std::ostream& stream, const Bullet& bullet);

class BulletsSet
{
	public:

	BulletsSet();

	~BulletsSet();

	void setScreenSize(int width, int height);
	void push(Bullet bullet);

	void moveAndDraw(sf::RenderWindow &window, const float timeDif);
	void draw(sf::RenderWindow &window);

	private:

	int screenWidth = 800;
	int screenHeight = 600;

	std::vector<Bullet> set;
};

}	/* namespace game */

#endif /* __BULLET_H__ */
