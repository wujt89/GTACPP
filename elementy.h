#ifndef ELEMENTY_H
#define ELEMENTY_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


class Elementy : public sf::Sprite
{
public:
    void kolizja(Elementy, Elementy);
    Elementy();
};

class Kulka : public Elementy
{
public:
    Kulka(int /*mockulki*/);
    bool wrog = false;
    void setwrog();
    int mockulki;
    void zmianamocy();


};


class Stan
{
public:
    int czas;
    int amunicja;
    int level;
    int score;

};




#endif // ELEMENTY_H
