#include <SFML/Graphics.hpp>
#include <string>
#include "Math.cpp"

sf::VideoMode getDesktopVideoMode(sf::VideoMode desktop) {

  return sf::VideoMode(desktop.width, desktop.height, desktop.bitsPerPixel);
}

void exitIfNoJoystickDetected() {
  bool connected;
  connected = sf::Joystick::isConnected(0);
  if (!connected) {
    exit(1);
  }
}

std::string getPlayerPositionDebugString(sf::Vector2f playerPosition){
  return std::to_string(playerPosition.x) + "/" + std::to_string(playerPosition.y);
}

int main()
{
  sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
  sf::RenderWindow window(getDesktopVideoMode(desktop), "Graphics Demo");
  sf::Text text;
  sf::Font font;
  font.loadFromFile("/usr/share/fonts/TTF/impact.ttf");
  text.setFont(font);
  text.setCharacterSize(24);
  text.setPosition(10, 10);
  sf::CircleShape player(10.f);
  player.setFillColor(sf::Color(100, 250, 50));
  player.setPosition(desktop.width/2, desktop.height/2);
  while (window.isOpen())
    {
      exitIfNoJoystickDetected();
      sf::Event event;
      while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
          window.close();
      }
      const sf::Vector2f playerPosition = player.getPosition();
      text.setString(getPlayerPositionDebugString(playerPosition));
      player.setPosition(getNewPositionX(playerPosition.x), getNewPositionY(playerPosition.y));

      window.clear(sf::Color::Black);
      window.draw(text);
      window.draw(player);
      window.display();
    }

    return 0;
}
