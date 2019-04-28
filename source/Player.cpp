#include "Player.hpp"
#include <math.h>
#include <iostream>

Player::Player(const sf::Color color) {
  sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
  const float verticalCenter = desktop.height/2;
  const float horizontalCenter = desktop.width/2;
  this->model = sf::CircleShape(width);
  this->model.setOrigin(model.getRadius(), model.getRadius());
  this->weapon.setOrigin(model.getOrigin());
  this->shield.setOrigin(model.getOrigin());
  this->weapon = sf::RectangleShape(sf::Vector2f(5, 135));
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

void Player::setPosition(float x, float y) {
  this->model.setPosition(x, y);
  this->weapon.setPosition(model.getPosition());
}

float Player::getPositionX() {

  return this->model.getPosition().x;
}

float Player::getPositionY() {

  return this->model.getPosition().y;
}

bool Player::isInDeadZone(float x, float y) {
  float radius = 30;
  float centerX = 0, centerY = 0;
  float result = (pow(x - centerX, 2)) + (pow(y - centerY,2));
  if (result < pow(radius, 2)) {
    return true;
  }

  return false;
}

void Player::updateOrientation() {
  const float PI = 3.14159265;
  float rightAnalogueX = sf::Joystick::getAxisPosition(0, sf::Joystick::U);
  float rightAnalogueY = sf::Joystick::getAxisPosition(0, sf::Joystick::V);

  if (!isInDeadZone(rightAnalogueX, rightAnalogueY)) {
    float result = (atan2(rightAnalogueY, rightAnalogueX)) * 180 / PI;
    this->weapon.setRotation(result - 90);
  }
}

void Player::step(const sf::Time deltaTime) {
  updateOrientation();
  float x, y;
  x = getNewPosition(deltaTime, getPositionX(), sf::Joystick::X);
  y = getNewPosition(deltaTime, getPositionY(), sf::Joystick::Y);
  setPosition(x, y);
}
