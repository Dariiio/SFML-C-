#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Entity : public Transformable
{
public:
  Entity();

  void draw(RenderWindow &ventana);

private:
  RectangleShape circle;

};

Entity::Entity()
{
  circle.setSize(Vector2f(100,100));
  circle.setFillColor(Color::Blue);
}

void Entity::draw(RenderWindow &ventana)
{
  ventana.draw(circle);
  circle.setPosition(40,100);
}
