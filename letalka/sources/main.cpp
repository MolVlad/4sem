#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <math.h>

#define SPEED 200

void normalizeVector(sf::Vector2f &vector)
{
	float length = sqrt(vector.x * vector.x + vector.y * vector.y);
	vector.x /= length;
	vector.y /= length;
}

void scaleVector(sf::Vector2f &vector, int scale)
{
	vector.x *= scale;
	vector.y *= scale;
}

void getSpeed(sf::Vector2f &speed)
{
	speed.x = speed.y = 0;

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		speed.x += -1;
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		speed.y += -1;
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		speed.x += 1;
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		speed.y += 1;

	speed.x *= SPEED;
	speed.y *= SPEED;
}

typedef struct
{
	sf::Vector2f position;
	sf::Vector2f speed;
} Bullet;

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");

	sf::Texture texture;
	texture.loadFromFile("smile.png");

	sf::Sprite circle(texture);
	circle.setScale(1.2f, 1.2f);

	sf::CircleShape bul(3);

	sf::Clock clock;

	sf::Vector2f speed;
	sf::Vector2f delta;
	sf::Vector2f position;

	std::vector<Bullet> bullets;

	sf::Time lastTime = clock.getElapsedTime();

	while (window.isOpen())
	{
		window.clear();

		sf::Time time = clock.getElapsedTime();

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		getSpeed(speed);
		std::cout << "speed: " << speed.x << ' ' << speed.y << '\n';
		delta.x = speed.x * (time.asSeconds() - lastTime.asSeconds());
		delta.y = speed.y * (time.asSeconds() - lastTime.asSeconds());

		position = circle.getPosition() + delta;
		if(position.x < 25)
			position.x = 25;
		if(position.x > (800 - 25))
			position.x = 800 - 25;
		if(position.y < 25)
			position.y = 25;
		if(position.y > (600 - 25))
			position.y = 600 - 25;

		circle.setPosition(position);

		for(int i = 0; i < bullets.size(); i++)
		{
			delta.x = bullets[i].speed.x * (time.asSeconds() - lastTime.asSeconds());
			delta.y = bullets[i].speed.y * (time.asSeconds() - lastTime.asSeconds());

			bullets[i].position += delta;
			bul.setPosition(bullets[i].position);
			window.draw(bul);
		}

		lastTime = time;

		sf::Vector2u circleSize = circle.getTexture()->getSize();
		circle.setOrigin(circleSize.x / 2, circleSize.y / 2);

		sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
		sf::Vector2f center = circle.getPosition();
		sf::Vector2f d = sf::Vector2f(mousePosition.x, mousePosition.y) - center;

		const float pi = 3.1415f;
		circle.setRotation(90 + atan2f(d.y, d.x) * 180 / pi);

		if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			Bullet bullet;
			bullet.position = position;
			bullet.speed = d;
			normalizeVector(bullet.speed);
			scaleVector(bullet.speed, 500);

			bullets.push_back(bullet);
		}

		window.draw(circle);
		window.display();
	}

	return 0;
}
