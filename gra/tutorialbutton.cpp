#include "tutorialbutton.h"

TutorialButton::TutorialButton()
{
    bool v=getvisible();
    v=true;
    setvisible(v);

    on =true;
    if (!tekstura.loadFromFile("tekst/tutorialon.png")) {
        std::cout << "Could not load texture" << std::endl;
    }
    if (!tekstura2.loadFromFile("tekst/tutorialoff.png")) {
        std::cout << "Could not load texture" << std::endl;
    }
    //tekstura.setRepeated(true);
    scale(0.35,0.35);
    setPosition(400,650);
    setTexture(tekstura);


    if (!buffer.loadFromFile("sound/click.wav"))
    {
        std::cout << "Could not load sound" << std::endl;
    }
    click.setBuffer(buffer);
}

void TutorialButton::change(sf::Vector2i mousepos)
{
    sf::FloatRect bounds = getGlobalBounds();
    bool v=getvisible();

    setvisible(v);
    if(bounds.contains(mousepos.x, mousepos.y)&&v==true)
    {
        click.play();
        if(on==true)
        {
            on = false;
            setTexture(tekstura2);
        }
        else
        {
            on=true;
            setTexture(tekstura);
        }
    }
}
