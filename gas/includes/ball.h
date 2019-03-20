#ifndef __BULLET_H__
#define __BULLET_H__

#include"mat_point.h"

class Ball: public MaterialPoint
{
  public:
    Ball(sf::Vector2i mousePosition);

    ~Ball();

    float radius = 1;
    int type;

    sf::CircleShape circle;
};

class BallSet
{
  public:
    BallSet();

    ~BallSet();

    void setScreenSize(int width, int height);

    void push(Ball ball);
    void moveAndDraw(sf::RenderWindow &window, const float dt);

	private:
	  std::vector<Ball> set;

    int screenWidth = 800;
    int screenHeight = 600;

    static const int maxVelocity;
};

#endif /* __BULLET_H__ */
