#ifndef PLAYAGAINBUTTON_H
#define PLAYAGAINBUTTON_H

#include "elementy.h"
#include "guy.h"

class PlayAgainButton : public Elements
{
    sf::Texture tekstura;
    sf::SoundBuffer buffer;
    sf::Sound click;

public:

 void press(sf::Vector2i mousepos, bool &, Guy &);
    PlayAgainButton();



};

#endif // PLAYAGAINBUTTON_H
