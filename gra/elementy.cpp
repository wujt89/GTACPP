#include "elementy.h"

Elementy::Elementy()
{

}

Background::Background(int a)
{
    if(a==1)
    {
    if (!tekstura.loadFromFile("tekst/miasto.png")) {
        std::cout << "Could not load texture" << std::endl;
    }
    //tekstura.setRepeated(true);
    setTexture(tekstura);
    }

    if(a==2)
    {
        if (!tekstura.loadFromFile("tekst/title.png")) {
            std::cout << "Could not load texture" << std::endl;
        }
        //tekstura.setRepeated(true);
        scale(0.33,0.33);
        setPosition(300,150);
        setTexture(tekstura);
    }
}

Kulka::Kulka(int moc)
{
    if(moc==1)
    {
        if (!teks.loadFromFile("tekst/red.png")) {
            std::cout << "Could not load texture" << std::endl;
        }
        setTexture(teks);
        setPosition(std::rand() % 800, std::rand() % 600);
    }

    else if(moc==2)
    {
        if (!teks.loadFromFile("tekst/blue.png")) {
            std::cout << "Could not load texture" << std::endl;
        }
        setTexture(teks);
        setPosition(std::rand() % 800, std::rand() % 600);
    }

    else if(moc==3)
    {
        if (!teks.loadFromFile("tekst/yellow.png")) {
            std::cout << "Could not load texture" << std::endl;
        }
        setTexture(teks);
        setPosition(std::rand() % 800, std::rand() % 600);
    }

    else if(moc==0)
    {
        if (!teks.loadFromFile("tekst/green.png")) {
            std::cout << "Could not load texture" << std::endl;
        }
        setTexture(teks);
        setPosition(std::rand() % 800, std::rand() % 600);
    }
}

Sciana::Sciana(int)
{
    if (!teks.loadFromFile("tekst/wall.png")) {
        std::cout << "Could not load texture" << std::endl;
    }
}

Playbutton::Playbutton()
{
    if (!tekstura.loadFromFile("tekst/playbutton.png")) {
        std::cout << "Could not load texture" << std::endl;
    }
    //tekstura.setRepeated(true);
    scale(0.35,0.35);
    setPosition(400,550);
    setTexture(tekstura);
}
