#include "Animation.h"
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(500,500),"GamePong!");
    sf::RectangleShape  rectangle;
    rectangle.setSize(sf::Vector2f(100.f, 100.f));//kich thuoc
    rectangle.setPosition(sf::Vector2f(100.f, 100.f));//toa do
    //rectangle.setFillColor(sf::Color(196, 137, 27));//mau

    sf::Sprite sprite;

    sf::Texture texture;
    texture.loadFromFile("animaiton.png");

    rectangle.setTexture(&texture);


    sf::Vector2i numFrame(7, 11);

    Animation animation(numFrame,0.1f);
    animation.setTexture(texture);
    animation.CalculateSize();
    animation.ApplyRect();
 
    window.setFramerateLimit(60);
    sf::Clock clock;
    float deltaTime = 0.f;

    while (window.isOpen()) {
        sf::Event mEvent;
        deltaTime = clock.restart().asSeconds();

        while (window.pollEvent(mEvent)) {
            if (mEvent.type == sf::Event::Closed) {
                window.close();
            }
            if (mEvent.type == sf::Event::TextEntered) {
                std::cout << (char) mEvent.key.code;
            }
            if (mEvent.type == sf::Event::Closed) {
                window.close();
            }
        }
        //rectangle.move(sf::Vector2f(100.f, -100.f)*deltaTime);
        animation.Update(deltaTime);

        window.clear();
        //window.draw(rectangle);
        window.draw(animation);


        window.display();
    }
}