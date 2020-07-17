#ifndef WALL_H
#define WALL_H

#include "elementy.h"

class Wall : public Elements
{
    sf::Texture tekstura;
public:

    Wall(int,int,int,int);

};
#endif // WALL_H
