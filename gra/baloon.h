#ifndef BALOON_H
#define BALOON_H

#include "elementy.h"
#include "guy.h"

class Baloon : public Elements
{
    sf::Texture teks;
    int moving=1;
    bool usun =false;
    float vx;
    float vy;
    int power;
    sf::SoundBuffer buffer;
    sf::Sound sound;
public:
    void setvx(float b){vx=b;};
    void setvy(float b){vy=b;};
    float getvx(){return vx;};
    float getvy(){return vy;};
    void kolizja(Elements&, Elements&, Elements&, Elements&);
    void kolizja_bohater(Guy&,int,bool, sf::Clock &);
    void kolizja_balony(Baloon&,int);
    void aiming(sf::Event event, sf::Vector2i mousepos);
    void shoot(sf::Vector2i, Guy&, std::vector<std::unique_ptr<Baloon>>& vec);
    void sprawdz(Guy&, std::vector<std::unique_ptr<Baloon>>& vec, bool&);
    void make(std::vector<std::unique_ptr<Baloon>>& vec);
    Baloon(int);
    Baloon();

};


#endif // BALOON_H
