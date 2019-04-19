#include <SFML/Graphics.hpp>
#include <Scene.hpp>

std::string Scene::getPlayerPositionDebugString(const float x, const float y){
  return std::to_string(x) + "/" + std::to_string(y);
}


Scene::Scene(): player(sf::Color(100, 250, 50)){
  font.loadFromFile("/usr/share/fonts/TTF/impact.ttf");
  debugText.setFont(font);
  debugText.setCharacterSize(24);
  debugText.setPosition(10, 10);
  message.setFont(font);
  message.setCharacterSize(24);
  message.setPosition(300, 10);
}

Player& Scene::getPlayer() {

  return player;
}

sf::Font& Scene::getFont() {

  return font;
}

void Scene::draw(sf::RenderWindow& window) {
  //  player.update();
  debugText.setString(getPlayerPositionDebugString(player.getPositionX(), player.getPositionY()));
  message.setString("Please Connect your controller");
  window.draw(message);
  window.draw(debugText);
  player.draw(window);
}

void Scene::step(const sf::Time deltaTime) {
  player.step(deltaTime);
}
