#ifndef TEXTY_H
#define TEXTY_H

#include "elementy.h"

class Texty : public Elements
{
    sf::Font font;
    sf::Text text;
public:
    Texty(float x, float y);


};

#endif // TEXTY_H
