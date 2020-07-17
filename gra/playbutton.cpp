#include "playbutton.h"

PlayButton::PlayButton()
{
    if (!tekstura.loadFromFile("tekst/playbutton.png")) {
        std::cout << "Could not load texture" << std::endl;
    }
    bool v=getvisible();
    v=true;
    setvisible(v);
    setPosition(400,550);
    setScale(0.35,0.35);

    setTexture(tekstura);

    if (!buffer.loadFromFile("sound/click.wav"))
    {
        std::cout << "Could not load sound" << std::endl;
    }
    click.setBuffer(buffer);
}

void PlayButton::press(sf::Vector2i mousepos, int& level, bool &on, bool& vis, bool& vi, bool& v, Elements& guy)
{
    sf::FloatRect bounds = getGlobalBounds();
    bool w=getvisible();
    if(bounds.contains(mousepos.x, mousepos.y)&&w==true)
    {
        click.play();
        if(on==true&&level<0)
        {
            level ++;
            v=true;
            setPosition(780,380);
            bool vguy=guy.getvisible();
            vguy=true;
            guy.setvisible(vguy);


        }
        else if(level==0)
        {

            w=false;



            v=false;
            bool vguy=guy.getvisible();
            vguy=true;
            guy.setvisible(vguy);
            guy.setPosition(450,350);
            level++;
        }
        else
        {
            level+=2;

            w=false;
            v=false;
            bool vguy=guy.getvisible();
            vguy=true;
            guy.setvisible(vguy);

            guy.setPosition(450,350);
        }
        setvisible(w);
        vis=false;
        vi=false;

    }
}
