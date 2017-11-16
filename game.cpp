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

  static const float PlayerSpeed;
  static const Time TimePerFrame;

  void processEvents();
  void update(Time deltaTime);
  void render();
  void handlePlayerInput(Keyboard::Key key, bool isPressed);

  RenderWindow ventana;
  Texture mTexture;
  Sprite mPlayer;

  bool mIsMovingUp, mIsMovingDown, mIsMovingLeft, mIsMovingRight;

};

const float Game::PlayerSpeed = 100.f;
const Time Game::TimePerFrame = seconds(1.f/60.f);

Game::Game(): ventana(VideoMode(800,600),"GAME",Style::Close)
{
    ventana.setVerticalSyncEnabled(true);
    ventana.setFramerateLimit(60);
    
    if(!mTexture.loadFromFile("Media/Textures/player.png")){

    }
    mPlayer.setTexture(mTexture);
    mPlayer.setPosition(100.f, 100.f);

}

void Game::run()
{

  Clock clock;
  Time timeSinceLastUpdate = Time::Zero;
  while(ventana.isOpen())
  {
    timeSinceLastUpdate += clock.restart();
    while( timeSinceLastUpdate > TimePerFrame){
      timeSinceLastUpdate -= TimePerFrame;
      processEvents();
      update(TimePerFrame);
    }
    render();
  }
}

void Game::processEvents()
{
  Event event;
  while(ventana.pollEvent(event))
  {
    switch(event.type){
      case Event::KeyPressed:
        handlePlayerInput(event.key.code, true);
        break;
      case Event::KeyReleased:
        handlePlayerInput(event.key.code, false);
        break;
      case Event::Closed:
        ventana.close();
        break;
    }
  }
}

void Game::update(Time deltaTime)
{
  Vector2f movement(0.f, 0.f);
  if(mIsMovingUp)
    movement.y -= PlayerSpeed;
  if(mIsMovingDown)
    movement.y += PlayerSpeed;
  if(mIsMovingLeft)
    movement.x -= PlayerSpeed;
  if(mIsMovingRight)
    movement.x += PlayerSpeed;

  mPlayer.move(movement * deltaTime.asSeconds());

}

void Game::render()
{
  ventana.clear();
  ventana.draw(mPlayer);
  ventana.display();
}

void Game::handlePlayerInput(Keyboard::Key key, bool isPressed)
{
  if(key == Keyboard::W)
    mIsMovingUp = isPressed;
  if(key == Keyboard::S)
    mIsMovingDown = isPressed;
  if(key == Keyboard::A)
    mIsMovingLeft = isPressed;
  if(key == Keyboard::D)
    mIsMovingRight = isPressed;
}