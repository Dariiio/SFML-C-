#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Game
{
public:
  Game();

  void run();

private:
  RenderWindow ventana;

};

Game::Game()
{
    ventana.create(VideoMode(800,600),"GAME",Style::Close);
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
    ventana.clear();
    ventana.display();

  }
}
