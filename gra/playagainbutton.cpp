#include "playagainbutton.h"

PlayAgainButton::PlayAgainButton()
{
    if (!tekstura.loadFromFile("tekst/playbutton.png")) {
        std::cout << "Could not load texture" << std::endl;
    }
    bool v=getvisible();
    v=false;
    setvisible(v);
    setPosition(420,470);
    setScale(0.35,0.35);

    setTexture(tekstura);

    if (!buffer.loadFromFile("sound/click.wav"))
    {
        std::cout << "Could not load sound" << std::endl;
    }
    click.setBuffer(buffer);
}

void PlayAgainButton::press(sf::Vector2i mousepos, bool & vis, Guy & guy)
{
    sf::FloatRect bounds = getGlobalBounds();
    int levell = guy.getlevel();
    if(bounds.contains(mousepos.x, mousepos.y)&&levell==-2)
    {
        click.play();
        int ammoo = guy.getammo();
        int timee = guy.gettime();
        int balonyy = guy.getbalony();
        int healthh = guy.gethealth();
        int bonuss = guy.getbonus();
        int colorr = guy.getcolor();

        levell=1;
        guy.setlevel(levell);

        ammoo=15;
        timee=20;
        balonyy=4;
        healthh=50;
        vis=false;
        bonuss=1;
        colorr=204;

        guy.setammo(ammoo);
        guy.settime(timee);
        guy.setbonus(bonuss);
        guy.setcolor(colorr);
        guy.sethealth(healthh);
        guy.setbalony(balonyy);
        guy.setColor(sf::Color(255,255,255,255));
    }
}
