#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <SFML/Graphics.hpp>
class Player {
private:
  int health;
  int stamina;
  bool gamePadConnected;
  sf::CircleShape model;
  sf::RectangleShape weapon;
  sf::RectangleShape shield;
  const sf::Color color;
  const float width = 50;
  const float speed = 200;
  float getNewPositionY(const float y);
  float getNewPositionX(const float x);
  float getNewPosition(const sf::Time deltaTime, const float oldPosition, sf::Joystick::Axis axis);
public:
  Player(const sf::Color color);
  bool connectController(int controllerId);
  void setPosition(float x, float y);
  float getPositionX();
  float getPositionY();
  void update();
  void draw(sf::RenderWindow& window);
  void step(const sf::Time deltaTime);
};
#endif /* PLAYER_HPP */
