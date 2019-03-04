#ifndef __BULLET_H__
#define __BULLET_H__

#include <string>

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

	private:

	my_math::Vector2 speed;

	int screenWidth = 800;
	int screenHeight = 600;

	// configuration constants
	const float bulletSize = 3;
	const float speedConfig = 1000;
};

std::ostream& operator<<(std::ostream& stream, const Hero& hero);

}	/* namespace game */

#endif /* __BULLET_H__ */
