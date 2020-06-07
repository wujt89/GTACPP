#include "elementy.h"

Elementy::Elementy()
{

}

Background::Background()
{

    if (!tekstura.loadFromFile("tekst/miasto.png")) {
        std::cout << "Could not load texture" << std::endl;
    }
    //tekstura.setRepeated(true);
    setTexture(tekstura);



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

    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile("sound/click2.wav"))
    {
         std::cout << "Could not load sound" << std::endl;
    }
    click.setBuffer(buffer);


}

void Playbutton::schowaj(Elementy & a, sf::RenderWindow &window, sf::Event event)
{
  if (event.type == sf::Event::MouseButtonPressed)
  {
    if(event.mouseButton.button == sf::Mouse::Left)
    {
        sf::FloatRect playbounds = getGlobalBounds();
        sf::Vector2i mousepos = sf::Mouse::getPosition(window);

        std::cout << mousepos.x << std::endl;
        click.play();

        if(playbounds.contains(mousepos.x,mousepos.y))
        {



            Sleep(200);
            pokaz=false;
            a.pokaz=false;
        }
    }
  }
}

Title::Title()
{
    if (!tekstura.loadFromFile("tekst/title.png")) {
        std::cout << "Could not load texture" << std::endl;
    }
    //tekstura.setRepeated(true);
    scale(0.33,0.33);
    setPosition(300,150);
    setTexture(tekstura);
}
