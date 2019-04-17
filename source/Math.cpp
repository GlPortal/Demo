float getNewPositionY(float y){
    if (sf::Joystick::getAxisPosition(0, sf::Joystick::Y) > 30) {
      y += 0.1;
    }

    if (sf::Joystick::getAxisPosition(0, sf::Joystick::Y) < -30) {
      y -= 0.1;
    }

    return y;
  }

float getNewPositionX(float x){
  if (sf::Joystick::getAxisPosition(0, sf::Joystick::X) > 30) {
    x += 0.1;
  }

  if (sf::Joystick::getAxisPosition(0, sf::Joystick::X) < -30) {
    x -= 0.1;
  }

  return x;
}
