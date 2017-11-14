#include <iostream>
#include <SFML/Graphics.hpp>
#include "entity.cpp"

using namespace std;
using namespace sf;

class Game
{
public:
  Game();

  void run();

private:
  RenderWindow ventana;
  Entity asd;

};

Game::Game()
{
    ventana.create(VideoMode(800,600),"GAME",Style::Close);
    ventana.setVerticalSyncEnabled(true);
    ventana.setFramerateLimit(30);
}

void Game::run()
{
  Event eventGame;

  while(ventana.isOpen())
  {
    while(ventana.pollEvent(eventGame))
    {
      if(eventGame.type == Event::Closed)
        ventana.close();
    }
    ventana.clear(Color::Red);
    asd.draw(ventana);
    ventana.display();

  }
}
