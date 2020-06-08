#ifndef ELEMENTY_H
#define ELEMENTY_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <memory>
#include <vector>
#include <windows.h>
#include <algorithm>




class Elementy : public sf::Sprite
{
public:
    bool pokaz;
    void hide();
    void show();
    void kolizja(Elementy, Elementy); //obsluguje kolizje pomiedzy dwoma elementami, sciany tez beda stworzone z tekstur a wiec beda elementami.
    Elementy();
    int iloscobiektow;
    char active = 'z';
    bool typ =true;
    sf::Texture tekstura;
    sf::Texture tekstura2;
    sf::Sound click;
    bool zmien(sf::RenderWindow&, sf::Event event);
    bool schowaj(sf::RenderWindow&, sf::Event event);
    int lvl;

    void ruch();
    float vx;
    float vy;
    int predkosc;


    bool kol(Elementy&);



};



class Title : public Elementy
{
    sf::Texture tekstura;
public:
    Title();
};

class Playbutton : public Elementy
{
    sf::Texture tekstura;
    sf::SoundBuffer buffer;
public:

    Playbutton();


};

class Nextbutton : public Elementy
{
    sf::Texture tekstura;
    sf::SoundBuffer buffer;
public:

    Nextbutton();


};

class Tutorialbutton : public Elementy
{

    sf::SoundBuffer buffer;

public:


    Tutorialbutton();


};

class Manual : public Elementy
{
    sf::Texture tekstura;
public:
    Manual();
};

class Background : public Elementy
{
    sf::Texture tekstura;
public:
    Background();
};

class Hero : public Elementy
{
    sf::Texture tekstura;
public:

    Hero();
};


class Balon : public Elementy
{
    sf::Texture teks;
public:
    Balon(int);
};

class Wall : public Elementy
{
    sf::Texture teks;
public:
    Wall(int,int,int,int);

};




#endif // ELEMENTY_H
