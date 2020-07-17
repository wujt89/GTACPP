#include "texty.h"

Texty::Texty(float x, float y)
{
    if (!font.loadFromFile("ADVENTURE.otf"))
    {
        std::cout<< "bleeee:" << std::endl;
    }
    text.setFont(font);
    text.setCharacterSize(35);
    text.setPosition(x,y);
    text.setFillColor(sf::Color::Black);

}
