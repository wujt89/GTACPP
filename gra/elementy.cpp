#include "elementy.h"

void Elementy::hide()
{
    pokaz=false;
}

void Elementy::show()
{
    pokaz=true;
}

Elementy::Elementy()
{

}


Background::Background()
{

    pokaz=true;
    if (!tekstura.loadFromFile("tekst/miasto.png")) {
        std::cout << "Could not load texture" << std::endl;
    }
    //tekstura.setRepeated(true);
    setTexture(tekstura);



}

Playbutton::Playbutton()
{
    pokaz=true;
    if (!tekstura.loadFromFile("tekst/playbutton.png")) {
        std::cout << "Could not load texture" << std::endl;
    }
    //tekstura.setRepeated(true);
    scale(0.35,0.35);
    setPosition(400,550);
    setTexture(tekstura);


    if (!buffer.loadFromFile("sound/click.wav"))
    {
        std::cout << "Could not load sound" << std::endl;
    }
    click.setBuffer(buffer);


}

bool Elementy::schowaj(sf::RenderWindow &window, sf::Event event)
{
    if (event.type == sf::Event::MouseButtonPressed&&pokaz==true)
    {
        if(event.mouseButton.button == sf::Mouse::Left)
        {
            sf::FloatRect playbounds = getGlobalBounds();
            sf::Vector2i mousepos = sf::Mouse::getPosition(window);

            // std::cout << mousepos.x << std::endl;


            if(playbounds.contains(mousepos.x,mousepos.y))
            {

                click.play();

                Sleep(200);
                return true;
            }
        }
    }
    return false;
}

void Elementy::ruch()
{
    if(predkosc==1&&vx<=0)
    {
        vx=vy=(rand()%4)/100;
        move(-vx,vy);
    }
    else if(predkosc==1&&vy<=0)
    {
        vx=vy=(rand()%4)/100;
        move(vx,-vy);
    }
    else if(predkosc==1&&vy<=0&&vx<=0)
    {
        vx=vy=(rand()%4)/100;
        move(-vx,-vy);
    }
    else if(predkosc==1&&vy>=0&&vx>=0)
    {
        vx=vy=(rand()%4)/100;
        move(vx,vy);
    }

    else
        move(vx,vy);
}

bool Elementy::kol(Elementy &a)
{
    sf::FloatRect bounds = getGlobalBounds();
    sf::FloatRect abounds = a.getGlobalBounds();

    if(bounds.intersects(abounds))
        return true;
    else
        return false;


}

int Elementy::shoot(sf::Vector2i mousepos)
{

            sf::FloatRect playbounds = getGlobalBounds();



            shot.play();

            if(vx>0)
            {
                mousepos.x= mousepos.x-15;
            }
            else if(vx<0)
            {
                mousepos.x= mousepos.x+15;
            }

            if(vy>0)
            {
                mousepos.y= mousepos.y-15;
            }
            else if(vy<0)
            {
                mousepos.y= mousepos.y+15;
            }


            if(playbounds.contains(mousepos.x,mousepos.y))
            {

                if(power==1)
                {
                    return 1;
                }
                else if(power==2)
                {
                    return 2;
                }
                else if(power==3)
                {
                    return 3;
                }

                else
                    return 4;

                std::cout << "trafiony" << std::endl;

            }


    return 0;
}

void Elementy::change(sf::Vector2i mousepos)
{

        sf::FloatRect elbounds = getGlobalBounds();

        if(elbounds.contains(mousepos.x, mousepos.y))
        {
            int los=rand()%3;
            // std::cout<< los << std::endl;
            switch(los)
            {
            case 0:
                vx=-vx;
                break;

            case 1:
                vy=-vy;
                break;


            case 2:
                vx=-vx;
                vy=-vy;
                break;

            }
        }


}

bool Elementy::balon_bohater(Elementy & a,int b, bool red)
{
    sf::FloatRect abounds = a.getGlobalBounds();
    sf::FloatRect bounds = getGlobalBounds();

    if(bounds.intersects(abounds)&&b==1)
    {
        vx=-vx;

        move(vx,vy);
        if(red==true&&a.color>2)
        {
            a.color-=4;
            a.setColor(sf::Color(255,a.color,a.color,255));
        }
        return true;
    }
    if(bounds.intersects(abounds)&&b==2)
    {
        move(-vx,-vy);
        vx=-vx;
        vy=-vy;
    }


return false;

}



Title::Title()
{
    pokaz=true;
    if (!tekstura.loadFromFile("tekst/title.png")) {
        std::cout << "Could not load texture" << std::endl;
    }
    //tekstura.setRepeated(true);
    scale(0.33,0.33);
    setPosition(300,150);
    setTexture(tekstura);
}

Tutorialbutton::Tutorialbutton()
{
    pokaz=true;
    if (!tekstura.loadFromFile("tekst/tutorialon.png")) {
        std::cout << "Could not load texture" << std::endl;
    }
    if (!tekstura2.loadFromFile("tekst/tutorialoff.png")) {
        std::cout << "Could not load texture" << std::endl;
    }
    //tekstura.setRepeated(true);
    scale(0.35,0.35);
    setPosition(400,650);
    setTexture(tekstura);


    if (!buffer.loadFromFile("sound/click.wav"))
    {
        std::cout << "Could not load sound" << std::endl;
    }
    click.setBuffer(buffer);

}

bool Elementy::zmien(sf::RenderWindow & window, sf::Event event)
{

    if (event.type == sf::Event::MouseButtonPressed&&pokaz==true)
    {
        if(event.mouseButton.button == sf::Mouse::Left)
        {
            sf::FloatRect playbounds = getGlobalBounds();
            sf::Vector2i mousepos = sf::Mouse::getPosition(window);

            std::cout << mousepos.x << std::endl;


            if(playbounds.contains(mousepos.x,mousepos.y))
            {

                click.play();

                Sleep(200);

                if(active=='z')
                {
                    setTexture(tekstura2);
                    active='c';
                    typ=false;
                }
                else
                {
                    setTexture(tekstura);
                    active='z';
                    typ = true;
                }
            }
        }
    }
    return typ;

}

Hero::Hero()
{
    pokaz=false;
    if (!tekstura.loadFromFile("tekst/face.png")) {
        std::cout << "Could not load texture" << std::endl;
    }
    //tekstura.setRepeated(true);
    setTextureRect(sf::IntRect(0, 0, 208, 208));
    //scale(0.33,0.33);
    setPosition(750,150);
    setTexture(tekstura);

}

Manual::Manual()
{
    pokaz=false;
    if (!tekstura.loadFromFile("tekst/manual.png")) {
        std::cout << "Could not load texture" << std::endl;
    }
    //tekstura.setRepeated(true);
    //setTextureRect(sf::IntRect(0, 0, 208, 208));
    scale(0.45,0.30);
    setPosition(30,30);
    setTexture(tekstura);
}

Nextbutton::Nextbutton()
{
    pokaz=false;
    if (!tekstura.loadFromFile("tekst/playbutton.png")) {
        std::cout << "Could not load texture" << std::endl;
    }
    //tekstura.setRepeated(true);
    scale(0.35,0.35);
    setPosition(780,380);
    setTexture(tekstura);


    if (!buffer.loadFromFile("sound/click.wav"))
    {
        std::cout << "Could not load sound" << std::endl;
    }
    click.setBuffer(buffer);
}

Wall::Wall(int w,int h,int x,int y)
{
    if (!tekstura.loadFromFile("tekst/wall.png")) {
        std::cout << "Could not load texture" << std::endl;
    }
    setTexture(tekstura);
    tekstura.setRepeated(true);

    setPosition(x,y);
    setTextureRect(sf::IntRect(0,0,w,h));



}

Balon::Balon(int moc)
{
    if (!teks.loadFromFile("tekst/balony.png")) {
        std::cout << "Could not load texture" << std::endl;
    }
    setTexture(teks);
    int los = rand() % 2;
    std::cout << los << std::endl;
    scale(0.3,0.3);

    if(los==0)
        setPosition(std::rand() % 150 +20, std::rand() % 500 + 60);

    if(los==1)
        setPosition(std::rand() % 150 +800, std::rand() % 500 + 60);

    if(moc==1)
    {
        setTextureRect(sf::IntRect(522,0,204,273));
        vx=0.05;
        vy=0.05;
        power=1;


    }
    else if(moc==2)
    {
        predkosc=1;
        vx=vy=(rand()%4)/100;
        setTextureRect(sf::IntRect(528,474,197,281));
        power=2;

    }
    else if(moc==3)
    {
        vx=0.1;
        vy=0.1;
        setTextureRect(sf::IntRect(802,0,198,272));
        power=3;
    }

}













