#include <iostream>
#include "elementy.h"


using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(1024, 768), "GTACPP");

    sf::Event event;

    Background tlo(1);
    Background tytul(2);
    Playbutton button;


    while (window.isOpen())
    {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }


        window.clear(sf::Color::Black);

        window.draw(tlo);
        window.draw(tytul);
         window.draw(button);
        window.display();
    }
    return 0;
}
