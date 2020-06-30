#include "elementy.h"

Elements::Elements()
{

}


StaticObject::StaticObject(float x, float y, float scx, float scy, std::string plik, bool show)
{
    if (!tekstura.loadFromFile(plik)) {
        std::cout << "Could not load texture" << std::endl;
    }
    visible=show;
    setPosition(x,y);
    setScale(scx,scy);

    setTexture(tekstura);
}


PlayButton::PlayButton()
{
    if (!tekstura.loadFromFile("tekst/playbutton.png")) {
        std::cout << "Could not load texture" << std::endl;
    }
    visible=true;
    setPosition(400,550);
    setScale(0.35,0.35);

    setTexture(tekstura);

    if (!buffer.loadFromFile("sound/click.wav"))
    {
        std::cout << "Could not load sound" << std::endl;
    }
    click.setBuffer(buffer);
}

void PlayButton::press(sf::Vector2i mousepos, int& level, bool &on, bool& vis, bool& vi, bool& v, Elements& guy)
{
    sf::FloatRect bounds = getGlobalBounds();
    if(bounds.contains(mousepos.x, mousepos.y)&&visible==true)
    {
        click.play();
        if(on==true&&level<0)
        {
            level ++;
            v=true;
            setPosition(780,380);
            guy.visible=true;

        }
        else if(level==0)
        {
            visible = false;
            v=false;
            guy.setPosition(450,350);
            level++;
        }
        else
        {
            level+=2;
            visible=false;
            guy.visible=true;
            guy.setPosition(450,350);
        }
        vis=false;
        vi=false;

    }
}

TutorialButton::TutorialButton()
{
    visible=true;
    on =true;
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

void TutorialButton::change(sf::Vector2i mousepos)
{
    sf::FloatRect bounds = getGlobalBounds();
    if(bounds.contains(mousepos.x, mousepos.y)&&visible==true)
    {
        click.play();
        if(on==true)
        {
            on = false;
            setTexture(tekstura2);
        }
        else
        {
            on=true;
            setTexture(tekstura);
        }
    }
}

Guy::Guy()
{
    if (!buffer.loadFromFile("sound/shot.wav"))
    {
        std::cout << "Could not load sound" << std::endl;
    }
    sound.setBuffer(buffer);
    visible = false;
    if (!tekstura.loadFromFile("tekst/face.png")) {
        std::cout << "Could not load texture" << std::endl;
    }
    setTextureRect(sf::IntRect(38, 10, 177, 197));
    setPosition(800,150);
    setTexture(tekstura);

    font.loadFromFile("ADVENTURE.otf");

    txtammo.setFont(font);
    txtammo.setCharacterSize(35);
    txtammo.setFillColor(sf::Color::Black);
    txtammo.setPosition(800,13);
    txtammo.setStyle(sf::Text::Bold);
    texta = std::to_string(ammo);
    txtammo.setString("ammo: "+texta);
    txtlevel.setFont(font);
    txtlevel.setCharacterSize(35);
    txtlevel.setFillColor(sf::Color::Black);
    txtlevel.setPosition(320,13);
    txtlevel.setStyle(sf::Text::Bold);
    texta = std::to_string(level);
    txtlevel.setString("ammo: "+texta);
    txthealth.setFont(font);
    txthealth.setCharacterSize(35);
    txthealth.setFillColor(sf::Color::Black);
    txthealth.setPosition(550,13);
    txthealth.setStyle(sf::Text::Bold);
    texta = std::to_string(health);
    txthealth.setString("ammo: "+texta);
    txttime.setFont(font);
    txttime.setCharacterSize(35);
    txttime.setFillColor(sf::Color::Black);
    txttime.setPosition(60,13);
    txttime.setStyle(sf::Text::Bold);
    texta = std::to_string(time);
    txttime.setString("ammo: "+texta);
    txtend.setFont(font);
    txtend.setCharacterSize(35);
    txtend.setFillColor(sf::Color::Black);
    txtend.setPosition(390,370);
    txtend.setStyle(sf::Text::Bold);

}

void Guy::update(sf::RenderWindow &window)
{
    texta = std::to_string(ammo);
    txtammo.setString("ammo: "+texta);
    texta = std::to_string(level);
    txtlevel.setString("level: "+texta);
    texta = std::to_string(time);
    txttime.setString("time: "+texta);
    texta = std::to_string(health);
    txthealth.setString("health: "+texta);

    window.draw(txtammo);
    window.draw(txtlevel);
    window.draw(txttime);
    window.draw(txthealth);
}

void Guy::drawend(sf::RenderWindow &window)
{
    texta = std::to_string(memorylevel);
    txtend.setString("Twoj wynik to: "+texta);
    window.draw(txtend);
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

Baloon::Baloon(int moc)
{
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
        vx=0.1;
        vy=0.1;
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
        vx=0.2;
        vy=0.2;
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

void Baloon::sprawdz(Guy & guy,  std::vector<std::unique_ptr<Baloon>>& vec, bool& vis)
{
    if(guy.balony==0)
    {
        float x = rand()%3+1;
        float y = rand()%3+1;
        float z = rand()%3+1;
        float c = rand()%3+1;
        vec.emplace_back(std::make_unique<Baloon>(x));
        vec.emplace_back(std::make_unique<Baloon>(y));
        vec.emplace_back(std::make_unique<Baloon>(z));
        vec.emplace_back(std::make_unique<Baloon>(c));
        guy.ammo=15;
        guy.time=20;
        guy.balony=4;
        guy.level++;
        guy.bonus+=0.5;
    }

    else if((guy.ammo==0||guy.health==0||guy.time==0)&&guy.level!=-2)
    {
        for(auto &el : vec)
        {
            el->usun=true;
        }

        guy.memorylevel=guy.level;
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


    std::cout << guy.ammo << " " << guy.health << " " << guy.time << " " << guy.level << std::endl;

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

void Baloon::kolizja_bohater(Guy & a, int b, bool red, sf::Clock& facetime)
{
    sf::FloatRect abounds = a.getGlobalBounds();
    sf::FloatRect bounds = getGlobalBounds();

    if(bounds.intersects(abounds)&&b==1)
    {
        vx=-vx;
        facetime.restart();

        move(vx,vy);
        if(red==true&&a.color>2)
        {
            a.color-=4;
            a.setColor(sf::Color(255,a.color,a.color,255));
        }

        a.health --;
        int g = rand()% 2;
        if(g==0)
            a.setTextureRect(sf::IntRect(39, 214, 175, 197));
        else if(g==1)
        {
            a.setTextureRect(sf::IntRect(420, 215, 175, 197));
        }


    }
    if(bounds.intersects(abounds)&&b==2)
    {
        move(-vx,-vy);
        vx=-vx;
        vy=-vy;
    }



}

void Baloon::kolizja_balony(Baloon & a, int b)
{
    sf::FloatRect abounds = a.getGlobalBounds();
    sf::FloatRect bounds = getGlobalBounds();

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

void Baloon::shoot(sf::Vector2i mousepos, Guy& guy, std::vector<std::unique_ptr<Baloon>>& vec)
{
    sf::FloatRect playbounds = getGlobalBounds();
    guy.sound.play();


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
            guy.balony--;
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

PlayAgainButton::PlayAgainButton()
{
    if (!tekstura.loadFromFile("tekst/playbutton.png")) {
        std::cout << "Could not load texture" << std::endl;
    }
    visible=false;
    setPosition(420,470);
    setScale(0.35,0.35);

    setTexture(tekstura);

    if (!buffer.loadFromFile("sound/click.wav"))
    {
        std::cout << "Could not load sound" << std::endl;
    }
    click.setBuffer(buffer);
}

void PlayAgainButton::press(sf::Vector2i mousepos, bool & vis, Guy & guy)
{
    sf::FloatRect bounds = getGlobalBounds();
    if(bounds.contains(mousepos.x, mousepos.y)&&guy.level==-2)
    {
        click.play();
        guy.level=1;
        guy.ammo=15;
        guy.time=20;
        guy.balony=4;
        guy.health=50;
        vis=false;
        guy.bonus=1;
        guy.color=204;
        guy.setColor(sf::Color(255,255,255,255));
    }
}

Texty::Texty(float x, float y)
{
    if (!font.loadFromFile("ADVENTURE.otf"))
    {
        std::cout<< "bleeee:" << std::endl;
    }
    text.setFont(font);
    text.setCharacterSize(35);
    text.setPosition(x,y);
    text.setFillColor(sf::Color::Black);

}
