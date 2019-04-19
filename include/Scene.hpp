#ifndef SCENE_HPP
#define SCENE_HPP
#include <SFML/Graphics.hpp>
#include <Player.hpp>
enum  States{SPLASH, GAME, MENU};

class Scene {
private:
  Player player;
  sf::Font font;
  sf::Text debugText;
  sf::Text message;
  std::string getPlayerPositionDebugString(const float x, const float y);
public:
  Scene();
  Player& getPlayer();
  sf::Font& getFont();
  void draw(sf::RenderWindow& window);
  void step(const sf::Time deltaTime);
};
#endif /* SCENE_HPP */
