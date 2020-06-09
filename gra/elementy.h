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

    int power;

    void ruch();
    float vx;
    float vy;
    int predkosc;


    bool kol(Elementy&);

     sf::Sound shot;
    //bool shot;
    int shoot(sf::Vector2i mousepos);

    void change(sf::Vector2i mousepos);
    bool balon_bohater(Elementy&,int,bool);
    int color=204;




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
    int health;

    sf::SoundBuffer buffer;

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
