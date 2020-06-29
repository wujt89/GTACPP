#ifndef ELEMENTS_H
#define ELEMENTS_H


#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <memory>
#include <vector>
#include <windows.h>
#include <algorithm>


class Elements : public sf::Sprite
{
public:
    Elements();
    bool visible;
};

class StaticObject : public Elements
{
    sf::Texture tekstura;


public:
    StaticObject(float x, float y, float scx, float scy, std::string plik, bool show);

};

class PlayButton : public Elements
{
    sf::Texture tekstura;
    sf::SoundBuffer buffer;
public:

    sf::Sound click;
    PlayButton();
    void press(sf::Vector2i mousepos, int&, bool&, bool&, bool&, bool&, Elements &);
};

class TutorialButton : public Elements
{
    sf::Texture tekstura;
    sf::Texture tekstura2;
    sf::SoundBuffer buffer;

public:

    bool on;
    sf::Sound click;
    TutorialButton();
    void change(sf::Vector2i mousepos);
};

class Guy : public Elements
{
    sf::Texture tekstura;
    sf::SoundBuffer buffer;

public:
    int level= -1;
    int ammo=15;
    int health=50;
    int balony=4;
    int time =20;
    Guy();
    int color=204;
    sf::Sound sound;

};

class Wall : public Elements
{
    sf::Texture tekstura;
public:

    Wall(int,int,int,int);

};

class Baloon : public Elements
{
    sf::Texture teks;
    int moving=1;

public:
    Baloon(int);
    Baloon();
    float vx;
    float vy;
    int power;
    bool usun =false;

    void make(std::vector<std::unique_ptr<Baloon>>& vec);
    void sprawdz(Guy&, std::vector<std::unique_ptr<Baloon>>& vec, bool&);
    void kolizja(Elements&, Elements&, Elements&, Elements&);
    void kolizja_bohater(Guy&,int,bool, sf::Clock &);
    void kolizja_balony(Baloon&,int);
    void shoot(sf::Vector2i, Guy&, std::vector<std::unique_ptr<Baloon>>& vec);
};

class PlayAgainButton : public Elements
{
    sf::Texture tekstura;
    sf::SoundBuffer buffer;
public:

    sf::Sound click;
    PlayAgainButton();
    void press(sf::Vector2i mousepos, bool &, Guy &);


};

#endif // ELEMENTS_H
