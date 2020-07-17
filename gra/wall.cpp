#include "wall.h"

Wall::Wall(int w,int h,int x,int y)
{

    if (!tekstura.loadFromFile("tekst/wall.png")) {
        std::cout << "Could not load texture" << std::endl;
    }
    setTexture(tekstura);
    tekstura.setRepeated(true);

    setPosition(x,y);
    setTextureRect(sf::IntRect(0,0,w,h));
}
