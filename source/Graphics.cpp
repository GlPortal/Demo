#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Graphics Demo");
    sf::CircleShape shape(50.f);
    shape.setFillColor(sf::Color(100, 250, 50));
    shape.setPosition(400, 300);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color::Black);
        window.draw(shape);
        window.display();
    }

    return 0;
}
