#include "baloon.h"

Baloon::Baloon(int moc)
{
    if (!buffer.loadFromFile("sound/shot.wav"))
    {
        std::cout << "Could not load sound" << std::endl;
    }
    sound.setBuffer(buffer);
    if (!teks.loadFromFile("tekst/balony.png")) {
        std::cout << "Could not load texture" << std::endl;
    }
    setTexture(teks);
    int los = rand() % 2;
    std::cout << los << std::endl;
    scale(0.3,0.3);

    if(los==0)
        setPosition(std::rand() % 150 +20, std::rand() % 500 + 90);

    if(los==1)
        setPosition(std::rand() % 150 +700, std::rand() % 500 + 90);

    if(moc==1)
    {
        setTextureRect(sf::IntRect(522,0,204,273));
        vx=0.02;
        vy=0.02;
        power=1;


    }
    else if(moc==2)
    {

        moving=2;
        setTextureRect(sf::IntRect(528,474,197,281));
        scale(0.5,0.5);
        vx=0;
        vy=0;
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

Baloon::Baloon()
{

}

void Baloon::make(std::vector<std::unique_ptr<Baloon> > &vec)
{
    vec.emplace_back(std::make_unique<Baloon>(1));
    vec.emplace_back(std::make_unique<Baloon>(2));
    vec.emplace_back(std::make_unique<Baloon>(1));
    vec.emplace_back(std::make_unique<Baloon>(3));
}

void Baloon::sprawdz(Guy& guy,  std::vector<std::unique_ptr<Baloon>>& vec, bool& vis)
{
    int balonyy = guy.getbalony();
    int ammoo = guy.getammo();
    int timee = guy.gettime();
   // int levell = guy.getlevel();
    int bonuss = guy.getbonus();
    int healthh = guy.gethealth();

    if(balonyy==0)
    {
        float x = rand()%3+1;
        float y = rand()%3+1;
        float z = rand()%3+1;
        float c = rand()%3+1;
        vec.emplace_back(std::make_unique<Baloon>(x));
        vec.emplace_back(std::make_unique<Baloon>(y));
        vec.emplace_back(std::make_unique<Baloon>(z));
        vec.emplace_back(std::make_unique<Baloon>(c));
        ammoo=15;
        guy.setammo(ammoo);
        timee=20;
        guy.settime(timee);
        balonyy=4;
        guy.setbalony(balonyy);
       guy.level++;
        bonuss+=0.5;
        guy.setbonus(bonuss);
    }

    else if((ammoo==0||healthh==0||timee==0)&&guy.level!=-2)
    {
        for(auto &el : vec)
        {
            el->usun=true;
        }
        int memorylevell = guy.getmemorylevel();
        memorylevell =guy.level;
        guy.setmemorylevel(memorylevell);
        guy.level=-2;

        vis=true;
        make(vec);
    }
    for(size_t i=0; i<vec.size(); i++)
    {
        if(vec[i]->usun==true)
        {
            vec.erase(vec.begin()+i);
        }
    }

//std::cout << guy.ammo << " " << guy.health << " " << guy.time << " " << guy.level << std::endl;

}

void Baloon::kolizja(Elements & left, Elements& right, Elements& top, Elements& bottom)
{
    sf::FloatRect bounds = getGlobalBounds();
    sf::FloatRect leftbounds = left.getGlobalBounds();
    sf::FloatRect rightbounds = right.getGlobalBounds();
    sf::FloatRect topbounds = top.getGlobalBounds();
    sf::FloatRect bottombounds = bottom.getGlobalBounds();

    if(bounds.intersects(leftbounds)||bounds.intersects(rightbounds))
    {
        vx=-vx;
    }
    if(bounds.intersects(topbounds)||bounds.intersects(bottombounds))
    {
        vy=-vy;
    }

}

void Baloon::kolizja_(Guy& guy, Elements & a, int b, bool red, sf::Clock& facetime)
{
    sf::FloatRect abounds = a.getGlobalBounds();
    sf::FloatRect bounds = getGlobalBounds();

if(typeid(a).hash_code()==typeid(Guy).hash_code())
{
    if(bounds.intersects(abounds)&&b==1)
    {
        vx=-vx;
        facetime.restart();

        move(vx,vy);
        int colorr = guy.getcolor();
        if(red==true&&colorr>2)
        {
            colorr-=4;
            a.setColor(sf::Color(255,colorr,colorr,255));
            guy.setcolor(colorr);
        }

        int healthh = guy.gethealth();
        healthh --;
        guy.sethealth(healthh);

        int g = rand()% 2;
        if(g==0)
            a.setTextureRect(sf::IntRect(39, 214, 175, 197));
        else if(g==1)
        {
            a.setTextureRect(sf::IntRect(420, 215, 175, 197));
        }
   // }


    }
    if(bounds.intersects(abounds)&&b==2)
    {
        move(-vx,-vy);
        vx=-vx;
        vy=-vy;
    }
}

else
{
    if(bounds.intersects(abounds)&&b==1)
    {
        vx=-vx;

        move(vx,vy);


    }
    if(bounds.intersects(abounds)&&b==2)
    {
        move(-vx,-vy);
        vx=-vx;
        vy=-vy;
    }


}


}


void Baloon::shoot(sf::Vector2i mousepos, Guy& guy, std::vector<std::unique_ptr<Baloon>>& vec)
{
    sf::FloatRect playbounds = getGlobalBounds();
    sound.play();


    if(moving==1)
    {

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
    }


    if(playbounds.contains(mousepos.x,mousepos.y))
    {

        if(power==1)
        {
            usun=true;
            int balonyy = guy.getbalony();

            balonyy--;
            guy.setbalony(balonyy);
        }
        else if(power==2)
        {
            vec.emplace_back(std::make_unique<Baloon>(1));
            usun=true;
        }
        else if(power==3)
        {
            vec.emplace_back(std::make_unique<Baloon>(2));
            usun=true;
        }


        std::cout << "trafiony" << std::endl;

    }
}

void Baloon::aiming(sf::Event event, sf::Vector2i mousepos)
{
    if (event.type == sf::Event::MouseMoved)
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
}
