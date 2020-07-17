#ifndef PLAYBUTTON_H
#define PLAYBUTTON_H

#include "elementy.h"

class PlayButton : public Elements
{
    sf::Texture tekstura;
    sf::SoundBuffer buffer;
    sf::Sound click;

public:

    void press(sf::Vector2i mousepos, int&, bool&, bool&, bool&, bool&, Elements &);
    PlayButton();

};

#endif // PLAYBUTTON_H
