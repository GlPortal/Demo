#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <SFML/Graphics.hpp>
class Player {
private:
  int health;
  int stamina;
  bool blocking;
  bool gamePadConnected;
  sf::CircleShape model;
  sf::RectangleShape weapon;
  sf::RectangleShape shield;
  const sf::Color color;
  const float width = 50;
  const float speed = 300;
  float getNewPosition(const sf::Time deltaTime, const float oldPosition, sf::Joystick::Axis axis);
  bool isInDeadZone(float x, float y);
public:
  Player(const sf::Color color);
  void updateOrientation();
  bool connectController(int controllerId);
  void setPosition(float x, float y);
  float getPositionX();
  float getPositionY();
  void draw(sf::RenderWindow& window);
  void step(const sf::Time deltaTime);
};
#endif /* PLAYER_HPP */
