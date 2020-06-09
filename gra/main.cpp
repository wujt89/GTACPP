#include <iostream>
#include "elementy.h"


using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(1024, 768), "GTACPP");

    sf::Event event;

    sf::Clock clock;
    sf::Clock clock2;
    sf::Time time;
    float elapsed;
    float elapsedshot;



    std::vector<std::unique_ptr<Elementy>> sciany;
    sciany.emplace_back(std::make_unique<Wall>(20,768,0,0));
    sciany.emplace_back(std::make_unique<Wall>(20,768,1004,0));
    sciany.emplace_back(std::make_unique<Wall>(1024,20,0,748));
    sciany.emplace_back(std::make_unique<Wall>(1024,50,0,0));

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




            if(elementy[2]->lvl==1)
            {


                for(size_t i=0; i<level1.size();i++)
                {


                    if(level1[i]->shoot(window,event)==1)
                    {
                        level1[1]->shot.play();
                        level1.erase(level1.begin()+i);
                    }
                    else if(level1[i]->shoot(window,event)==2)
                    {
                        level1.emplace_back(std::make_unique<Balon>(1));
                        level1.erase(level1.begin()+i);
                    }

                    else if(level1[i]->shoot(window,event)==3)
                    {
                        level1.emplace_back(std::make_unique<Balon>(2));
                        level1.erase(level1.begin()+i);
                    }

                    if(elapsed>0.25)
                    {
                        level1[i]->change(window,event);
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
                elementy[2]->setPosition(400,400);
                elementy[3]->pokaz=false;
                elementy[2]->lvl=1;
            }





        }

        elapsed = clock.getElapsedTime().asSeconds();
        elapsedshot = clock2.getElapsedTime().asSeconds();
        //std::cout<< elapsed << std::endl;


        // Hero &boh = dynamic_cast<Hero &>(*elementy[2]);


        window.clear(sf::Color::Black);




        for(auto &el:elementy)
        {
            if(el->pokaz==true)
                window.draw(*el);
        }
        if(elementy[2]->lvl==1)
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

                el->balon_bohater(*elementy[2],1,true);
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

            for(auto &el : sciany)
            {
                window.draw(*el);
            }
            for(auto &el : level1)
            {
                window.draw(*el);
            }
        }

        window.display();
    }

    return 0;
}
