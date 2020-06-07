#include <iostream>
#include "elementy.h"


using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(1024, 768), "GTACPP");

    sf::Event event;

    std::vector<Elementy> elementy;

    Background tlo;
    Title logo;
    Playbutton play;


    while (window.isOpen())
    {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();


            play.schowaj(logo,window, event);
        }

        play.click.play();


        window.clear(sf::Color::Black);
        window.draw(tlo);
        if(logo.pokaz==true)
            window.draw(logo);
        if(play.pokaz==true)
            window.draw(play);

        window.display();
    }
    play.click.play();
    return 0;
}
