#include <iostream>
#include "elementy.h"


using namespace std;



int main()
{
    sf::RenderWindow window(sf::VideoMode(1024, 768), "GTACPP");

    sf::Event event;

    sf::Clock clock;
    sf::Clock clock2;
    sf::Clock facetime;
    sf::Time time;
    float elapsed;
    float elapsedshot;

    sf::Font font;

    if (!font.loadFromFile("ADVENTURE.otf"))
    {
        std::cout<< "bleeee:" << std::endl;
    }
    int ammo=15;
    int balony=4;
    int czas=30;
    int lvl=0;
    int health=50;

    auto texta = std::to_string(ammo);
    sf::Text txtammo("ammo "+texta,font,35);
    txtammo.setFillColor(sf::Color::Black);
    txtammo.setPosition(800,13);
    txtammo.setStyle(sf::Text::Bold);

    auto textl = std::to_string(ammo);
    sf::Text txtlevel("level "+textl,font,35);
    txtlevel.setFillColor(sf::Color::Black);
    txtlevel.setPosition(320,13);
    txtlevel.setStyle(sf::Text::Bold);

    auto textt = std::to_string(czas);
    sf::Text txttime("time "+textt,font,35);
    txttime.setFillColor(sf::Color::Black);
    txttime.setPosition(60,13);
    txttime.setStyle(sf::Text::Bold);

    auto texth = std::to_string(health);
    sf::Text txthealth("health "+texth,font,35);
    txthealth.setFillColor(sf::Color::Black);
    txthealth.setPosition(550,13);
    txthealth.setStyle(sf::Text::Bold);

    sf::Sound sound;
    sf::SoundBuffer buffer;

    if (!buffer.loadFromFile("sound/shot.wav"))
    {
        std::cout << "Could not load sound" << std::endl;
    }
    sound.setBuffer(buffer);

    //Dzwiek shot("sound/shot.wav");





    std::vector<std::unique_ptr<Elementy>> sciany;
    sciany.emplace_back(std::make_unique<Wall>(20,768,0,0));
    sciany.emplace_back(std::make_unique<Wall>(20,768,1004,0));
    sciany.emplace_back(std::make_unique<Wall>(1024,20,0,748));
    sciany.emplace_back(std::make_unique<Wall>(1024,70,0,0));

    std::vector<std::unique_ptr<Elementy>> level1;
    level1.emplace_back(std::make_unique<Balon>(1));
    level1.emplace_back(std::make_unique<Balon>(2));
    level1.emplace_back(std::make_unique<Balon>(1));
    level1.emplace_back(std::make_unique<Balon>(3));



    std::vector<unique_ptr<Elementy>> elementy;
    elementy.emplace_back(std::make_unique<Background>());
    elementy.emplace_back(std::make_unique<Manual>());
    elementy.emplace_back(std::make_unique<Hero>());
    elementy.emplace_back(std::make_unique<Nextbutton>());
    elementy.emplace_back(std::make_unique<Playbutton>());
    elementy.emplace_back(std::make_unique<Title>());
    elementy.emplace_back(std::make_unique<Tutorialbutton>());


    while (window.isOpen())
    {



        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if(lvl>=1)
            {


                if (event.type == sf::Event::MouseButtonPressed)
                {

                    std::cout<< ammo << " " << czas <<" " << balony <<  std::endl;
                    if(event.mouseButton.button == sf::Mouse::Left)
                    {
                           sound.play();
                        ammo--;
                        texta = std::to_string(ammo);

                        txtammo.setString("ammo "+texta);

                        sf::Vector2i mousepos = sf::Mouse::getPosition(window);
                        for(size_t i=0; i<level1.size();i++)
                        {

                            elementy[0]->shoot(mousepos);

                            if(level1[i]->shoot(mousepos)==1)
                            {
                                balony--;
                                level1.erase(level1.begin()+i);
                            }
                            else if(level1[i]->shoot(mousepos)==2)
                            {

                                level1.emplace_back(std::make_unique<Balon>(1));
                                level1.erase(level1.begin()+i);
                            }

                            else if(level1[i]->shoot(mousepos)==3)
                            {

                                level1.emplace_back(std::make_unique<Balon>(2));
                                level1.erase(level1.begin()+i);
                            }

                        }
                    }
                }
            }

            if (event.type == sf::Event::MouseMoved)
            {
                sf::Vector2i mousepos = sf::Mouse::getPosition(window);
                for(size_t i=0; i<level1.size();i++)
                {
                    if(elapsed>0.5)
                    {
                        level1[i]->change(mousepos);
                        clock.restart();
                    }
                }
            }



            if(elementy[6]->zmien(window,event)==true&&elementy[4]->schowaj(window,event)==true)
            {

                elementy[1]->pokaz=true;
                elementy[2]->pokaz=true;
                elementy[3]->pokaz=true;
                elementy[4]->pokaz=false;
                elementy[5]->pokaz=false;
                elementy[6]->pokaz=false;


            }
            if(elementy[3]->schowaj(window,event)==true)
            {

                elementy[1]->pokaz=false;
                elementy[2]->setPosition(450,350);
                elementy[3]->pokaz=false;
                lvl=1;

                textl = std::to_string(lvl);

                txtlevel.setString("level: "+textl);
            }





        }
        if(elapsedshot>1&&lvl>=1)
        {
            clock2.restart();
            czas--;
            textt = std::to_string(czas);


            txttime.setString("time: " + textt);

        }

        if(balony==0&&lvl>=1)
        {
            level1.emplace_back(std::make_unique<Balon>(1));
            level1.emplace_back(std::make_unique<Balon>(2));
            level1.emplace_back(std::make_unique<Balon>(3));
            level1.emplace_back(std::make_unique<Balon>(3));
            balony=4;
            czas=30;
            lvl++;
            ammo=15;

            textt = std::to_string(czas);
            txttime.setString("time " + textt);
            textl = std::to_string(lvl);
            txtlevel.setString("level " + textl);
            texta = std::to_string(ammo);
            txtammo.setString("ammo " + texta);
            texth = std::to_string(health);
            txthealth.setString("helath " + texth);


        }


        elapsed = clock.getElapsedTime().asSeconds();
        elapsedshot = clock2.getElapsedTime().asSeconds();
        window.clear(sf::Color::Black);

        for(auto &el:elementy)
        {
            if(el->pokaz==true)
                window.draw(*el);
        }
        if(lvl>=1)
        {
            for(auto &el : level1)
            {
                el->ruch();
                if(el->kol(*sciany[0])||el->kol(*sciany[1]))
                {
                    el->vx=-(el->vx);
                }
                if(el->kol(*sciany[2])||el->kol(*sciany[3]))
                {
                    el->vy=-(el->vy);
                }

                if(el->balon_bohater(*elementy[2],1,true))
                {
                    elementy[2]->face=rand()%2+1;
                    facetime.restart();
                    health--;
                    texth = std::to_string(health);
                    txthealth.setString("helath " + texth);
                }
                el->balon_bohater(*elementy[2],2,false);

                for(size_t i=0; i<level1.size();i++)
                {
                    if(el!=level1[i])
                    {
                        el->balon_bohater(*level1[i],1,false);
                        el->balon_bohater(*level1[i],2,false);
                    }
                }

            }
            float passed =facetime.getElapsedTime().asSeconds();
            if(passed>=0.25)
                elementy[2]->face=0;
            elementy[2]->hurt(elementy[2]->face);

            for(auto &el : sciany)
            {
                window.draw(*el);
            }
            for(auto &el : level1)
            {
                window.draw(*el);
            }
                window.draw(txtammo);
                window.draw(txtlevel);
                window.draw(txttime);
                window.draw(txthealth);
        }

        if(ammo==0||czas==0||health==0)
        {
            window.close();
            std::cout << "Niestety Przegrałes. Twoj wynik to: " << lvl << std::endl;
        }

        window.display();
    }


}

