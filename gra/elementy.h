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
    bool pokaz = true;
    void kolizja(Elementy, Elementy); //obsluguje kolizje pomiedzy dwoma elementami, sciany tez beda stworzone z tekstur a wiec beda elementami.
    Elementy();
    int iloscobiektow;
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

public:
     sf::Sound click;
    Playbutton();
    void schowaj(Elementy&,sf::RenderWindow&, sf::Event event);

};

class Background : public Elementy
{
    sf::Texture tekstura;
public:
    Background();
};

class Kulka : public Elementy
{
    sf::Texture teks;
public:
    Kulka(int /*mockulki*/); // tworzy kulke o podanej mocy i w zaleznosci od tej mocy nadaje odpowiednie wlasciwosci czyli, predkosc, kolor, pozycje(rand) , wielkosc.
    bool wrog = false;
    void setwrog(); // ustawia kulke na wroga
    int mockulki;
    void zmianamocy(); // zmienia moc kulki o jeden po strzale

    double vx;
    double vy;
};

class Sciana : public Elementy
{
    sf::Texture teks;
 public:
    Sciana(int);

};


class Stan : public Kulka
{
public:
    int czas;
    int amunicja;
    int level;
    int score;
    void shot(); //zmieni score jesli trafimy kulke wroga, jezeli trafimy zielona przegrywamy oraz ilosc amunicji po wykonanym strzale.
    void sprawdz(); // sprawdzi czy przegralismy lub wygralismy, czyli: ilosc obiektow, czas, ilosc amunicji oraz czy trafilismy w zielona kulke.

};

//Mam zamiar prezentować plansze w taki sposób, że na każdym boku umieszczę czarne tekstury na których będzie łatwiej egzekwować kolizje.


#endif // ELEMENTY_H
