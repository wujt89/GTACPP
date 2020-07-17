#ifndef TUTORIALBUTTON_H
#define TUTORIALBUTTON_H


#include "elementy.h"
class TutorialButton : public Elements
{
    sf::Texture tekstura;
    sf::Texture tekstura2;
    sf::SoundBuffer buffer;

    sf::Sound click;
    bool on;


public:
    bool geton(){return on;};

    void change(sf::Vector2i mousepos);

    TutorialButton();

};


#endif // TUTORIALBUTTON_H
