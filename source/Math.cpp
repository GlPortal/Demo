#include <SFML/Graphics.hpp>

float getNewPositionY(const float y){
  float result = y;
  if (sf::Joystick::getAxisPosition(0, sf::Joystick::Y) > 30) {
    result = y + 0.1;
  }

  if (sf::Joystick::getAxisPosition(0, sf::Joystick::Y) < -30) {
    result = y - 0.1;
  }

  return result;
}

float getNewPositionX(const float x){
  float result = x;
  if (sf::Joystick::getAxisPosition(0, sf::Joystick::X) > 30) {
    result = x + 0.1;
  }

  if (sf::Joystick::getAxisPosition(0, sf::Joystick::X) < -30) {
    result = x - 0.1;
  }

  return result;
}
