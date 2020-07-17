#ifndef GUY_H
#define GUY_H

#include "elementy.h"
//#include "baloon.h"

class Guy : public Elements
{
    sf::Texture tekstura;

    sf::Font font;
    sf::Text txtammo;
    sf::Text txtlevel;
    sf::Text txthealth;
    sf::Text txttime;
    sf::Text txtend;
    std::string texta;
    int color=204;

    int memorylevel=0;
    int ammo=15;
    int health=50;
    int balony=4;
    int time =20;
    int bonus=1;


public:


    int getcolor(){return color;};
    void setcolor(int b){color=b;};
    int getlevel(){return level;};
    void setlevel(int b){level=b;};
    int getmemorylevel(){return memorylevel;};
    void setmemorylevel(int b){memorylevel=b;};
    int getammo(){return ammo;};
    void setammo(int b){ammo=b;};
    int gethealth(){return health;};
    void sethealth(int b){health=b;};
    int getbalony(){return balony;};
    void setbalony(int b){balony=b;};
    int gettime(){return time;};
    void settime(int b){time=b;};
    int getbonus(){return bonus;};
    void setbonus(int b){bonus=b;};
    int level= -1;
    void drawend(sf::RenderWindow &window);
    void update(sf::RenderWindow &window, int);
    Guy();


};

#endif // GUY_H
