#include "elementy.h"

using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(1024, 768), "GTACPP");

    sf::Event event;
    Guy guy;

    sf::Clock facetime;
    sf::Clock life;



    std::vector<std::unique_ptr<StaticObject>> statyczne;
    statyczne.emplace_back(std::make_unique<StaticObject>(0,0,1,1,"tekst/miasto.png", true));
    statyczne.emplace_back(std::make_unique<StaticObject>(300,150,0.33,0.33,"tekst/title.png", true));
    statyczne.emplace_back(std::make_unique<StaticObject>(30,30,0.45,0.3,"tekst/manual.png", false));
    statyczne.emplace_back(std::make_unique<StaticObject>(400,250,0.1,0.07,"tekst/manual.png", false));

    PlayButton play;
    TutorialButton tut;
    PlayAgainButton playa;


    std::vector<std::unique_ptr<Wall>> sciany;
    sciany.emplace_back(std::make_unique<Wall>(20,768,0,0));
    sciany.emplace_back(std::make_unique<Wall>(20,768,1004,0));
    sciany.emplace_back(std::make_unique<Wall>(1024,70,0,0));
    sciany.emplace_back(std::make_unique<Wall>(1024,30,0,748));

    std::vector<std::unique_ptr<Baloon>> balony;
    balony.emplace_back(std::make_unique<Baloon>(1));
    balony.emplace_back(std::make_unique<Baloon>(2));
    balony.emplace_back(std::make_unique<Baloon>(1));
    balony.emplace_back(std::make_unique<Baloon>(3));
    Baloon check;

    while (window.isOpen())
    {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed)
            {
                sf::Vector2i mousepos = sf::Mouse::getPosition(window);
                if(event.mouseButton.button == sf::Mouse::Left&&guy.level>0)
                {
                    guy.ammo--;
                    for(auto &el : balony)
                    {
                        el->shoot(mousepos, guy, balony);
                    }

                }
                tut.change(mousepos);
                play.press(mousepos, guy.level, tut.on, tut.visible, statyczne[1]->visible,statyczne[2]->visible, guy);
                playa.press(mousepos, statyczne[3]->visible,guy);
            }
        }
        float elapsedshot = life.getElapsedTime().asSeconds();
        if(elapsedshot>1&&guy.level>=1)
        {
            life.restart();
            guy.time--;

        }
        check.sprawdz(guy, balony, statyczne[3]->visible);


        window.clear(sf::Color::Black);
        for(auto &el : statyczne)
        {
            if(el->visible==true)
                window.draw(*el);
        }
        if(play.visible==true) window.draw(play);
        if(tut.visible==true) window.draw(tut);
        if(guy.level==-2) window.draw(playa);
        if(guy.visible==true&&guy.level>=0) window.draw(guy);
        for(auto &el : sciany)
        {
            if(guy.level>0)
                window.draw(*el);
        }
        for(auto &el : balony)
        {
            if(guy.level>0)
            {
                el->move(el->vx,el->vy);
                el->kolizja(*sciany[0], *sciany[1], *sciany[2], *sciany[3]);
                el->kolizja_bohater(guy,1,true, facetime);
                el->kolizja_bohater(guy,2,false, facetime);

                for(size_t i=0; i<balony.size();i++)
                {
                    if(el!=balony[i])
                    {
                        el->kolizja_balony(*balony[i],1);
                        el->kolizja_balony(*balony[i],2);
                    }
                }

                window.draw(*el);
            }

        }
        float passed =facetime.getElapsedTime().asSeconds();
        if(passed>=0.25)
            guy.setTextureRect(sf::IntRect(38, 10, 177, 197));
        window.display();
    }
    return 0;
}
