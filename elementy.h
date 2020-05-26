#ifndef ELEMENTY_H
#define ELEMENTY_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


class Elementy : public sf::Sprite
{
public:
    void kolizja(Elementy, Elementy); //obsluguje kolizje pomiedzy dwoma elementami, sciany tez beda stworzone z tekstur a wiec beda elementami.
    Elementy();
    int iloscobiektow;
};

class Kulka : public Elementy
{
public:
    Kulka(int /*mockulki*/); // tworzy kulke o podanej mocy i w zaleznosci od tej mocy nadaje odpowiednie wlasciwosci czyli, predkosc, kolor, pozycje(rand) , wielkosc.
    bool wrog = false;
    void setwrog(); // ustawia kulke na wroga 
    int mockulki;
    void zmianamocy(); // zmienia moc kulki o jeden po strzale
    
    double vx;
    double vy;
};

class Sciana : public Element
{

 public:
 
    blaaaaaaa'


    njjbkbjkjb
}


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
