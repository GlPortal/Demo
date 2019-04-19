#include "Player.hpp"

float Player::getNewPositionY(const float y){
  float result = y;
  if (sf::Joystick::getAxisPosition(0, sf::Joystick::Y) > 30) {
    result = y + 0.1;
  }

  if (sf::Joystick::getAxisPosition(0, sf::Joystick::Y) < -30) {
    result = y - 0.1;
  }

  return result;
}

float Player::getNewPositionX(const float x){
  float result = x;
  if (sf::Joystick::getAxisPosition(0, sf::Joystick::X) > 30) {
    result = x + 0.1;
  }

  if (sf::Joystick::getAxisPosition(0, sf::Joystick::X) < -30) {
    result = x - 0.1;
  }

  return result;
}

float Player::getNewPosition(const sf::Time deltaTime, const float oldPosition, sf::Joystick::Axis axis){
  float result = oldPosition;
  if (sf::Joystick::getAxisPosition(0, axis) > 30) {
    result = oldPosition + speed * deltaTime.asSeconds();
  }

  if (sf::Joystick::getAxisPosition(0, axis) < -30) {
    result = oldPosition - speed * deltaTime.asSeconds();
  }

  return result;
}


Player::Player(const sf::Color color) {
  sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
  const float verticalCenter = desktop.height/2;
  const float horizontalCenter = desktop.width/2;
  this->model = sf::CircleShape(width);
  this->weapon = sf::RectangleShape(sf::Vector2f(5, 35));
  this->shield = sf::RectangleShape(sf::Vector2f(5, 35));
  this->model.setFillColor(color);
  this->weapon.setFillColor(color);
  this->model.setPosition(horizontalCenter, verticalCenter);
  this->weapon.setPosition(horizontalCenter, verticalCenter);

}
void Player::draw(sf::RenderWindow& window) {
  window.draw(this->model);
  window.draw(this->weapon);
}

void Player::update() {
  setPosition(getNewPositionX(getPositionX()), getNewPositionY(getPositionY()));
}

void Player::setPosition(float x, float y) {
  this->model.setPosition(x, y);
  this->weapon.setPosition(x, y);
}

float Player::getPositionX() {

  return this->model.getPosition().x;
}

float Player::getPositionY() {

  return this->model.getPosition().y;
}

void Player::step(const sf::Time deltaTime) {
  float x, y;
  x = getNewPosition(deltaTime, getPositionX(), sf::Joystick::X);
  y = getNewPosition(deltaTime, getPositionY(), sf::Joystick::Y);
  setPosition(x, y);
}
