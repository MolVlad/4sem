#include<SFML/Audio.hpp>
#include<SFML/Graphics.hpp>
#include<math.h>
#include<vector>
#include<iostream>
#include<unistd.h>

#define SECS 1
#define DISCR 44100

void getSamples(std::vector<sf::Int16> & samples, double freq)
{
  for(int i = 0; i < SECS; i++)
  {
    for(int j = 0; j < DISCR; j++)
    {
      sf::Int16 x = (sf::Int16)(sin((double)j * freq / DISCR * 2 * M_PI) * 32767);

      samples.push_back(x);
      samples.push_back(x);
    }
  }
}

void play(double freq)
{
  static std::vector<sf::Int16> samples;
  static sf::SoundBuffer buf;
  static sf::Sound sound;

    getSamples(samples, freq);

    buf.loadFromSamples(&samples[0], samples.size(), 2, DISCR);
    sound.setBuffer(buf);
    sound.play();
}

int main()
{
  sf::RenderWindow window(sf::VideoMode(800, 600), "Music");

  while(window.isOpen())
  {
    window.clear();
    window.display();

    sf::Event event;
    while (window.pollEvent(event))
    {
      switch (event.type)
      {
        case sf::Event::Closed:
          window.close();
          break;
        case sf::Event::KeyPressed:
          if(event.key.code == sf::Keyboard::Q)
            play(200);
          if(event.key.code == sf::Keyboard::W)
            play(250);
          if(event.key.code == sf::Keyboard::E)
            play(300);
          if(event.key.code == sf::Keyboard::R)
            play(350);
          if(event.key.code == sf::Keyboard::T)
            play(400);
          if(event.key.code == sf::Keyboard::Y)
            play(450);
          if(event.key.code == sf::Keyboard::U)
            play(500);
          if(event.key.code == sf::Keyboard::I)
            play(550);
          if(event.key.code == sf::Keyboard::O)
            play(600);
          break;
        default:
          break;
      }
    }
  }
}
