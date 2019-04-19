#include <SFML/Graphics.hpp>
#include <string>
#include "Math.cpp"
#include "Scene.hpp"
#include "Player.hpp"

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

int main()
{
  Scene scene = Scene();
  sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
  sf::ContextSettings settings;
  sf::RenderWindow window(getDesktopVideoMode(desktop), "Graphics Demo", sf::Style::Fullscreen, settings);


  sf::Clock deltaClock;

  while (window.isOpen()) {
    sf::Time deltaTime = deltaClock.restart();
    exitIfNoJoystickDetected();
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();
    }
    window.clear(sf::Color::Black);
    scene.draw(window);
    window.display();
  }

  return 0;
}
