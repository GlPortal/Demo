#include <SFML/Graphics.hpp>
#include <string>

sf::VideoMode getDesktopVideoMode(sf::VideoMode desktop) {

  return sf::VideoMode(desktop.width, desktop.height, desktop.bitsPerPixel);
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
  sf::CircleShape shape(10.f);
  shape.setFillColor(sf::Color(100, 250, 50));

  float x = desktop.width/2;
  float y = desktop.height/2;
    bool connected;
    while (window.isOpen())
    {
      connected = sf::Joystick::isConnected(0);
      if (!connected) {
        exit(1);
      }
      sf::Event event;
      while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
          window.close();
      }
      text.setString(std::to_string(x) + "/" + std::to_string(y));
      shape.setPosition(x, y);
      if (sf::Joystick::getAxisPosition(0, sf::Joystick::Y) > 50) {
        y += 0.1;
      }

      if (sf::Joystick::getAxisPosition(0, sf::Joystick::Y) < -50) {
        y -= 0.1;
      }

      if (sf::Joystick::getAxisPosition(0, sf::Joystick::X) > 50) {
        x += 0.1;
      }

      if (sf::Joystick::getAxisPosition(0, sf::Joystick::X) < -50) {
        x -= 0.1;
      }

      window.clear(sf::Color::Black);
      window.draw(text);
      window.draw(shape);
      window.display();
    }

    return 0;
}
