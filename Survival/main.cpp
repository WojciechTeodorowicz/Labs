#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");
    // Set Frame rate to 60fps
    window.setFramerateLimit(60);
    sf::Texture texture;
    texture.loadFromFile("/home/wojtek/Desktop/image.png");
    sf::Sprite sprite;
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(10, 10, 50, 30));
    sprite.setPosition(10, 10);

// no texture coordinates here, we'll see that later
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	  {
	    sprite.move(1,0);
	  }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	  {
	    sprite.move(-1,0);
	  }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	  {
	    sprite.move(1,0);
	  }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	  {
	    sprite.move(1,0);
	  }
	

        window.clear();
        window.draw(sprite);
        window.display();
    }

    return 0;
}
