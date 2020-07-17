#include "guy.h"

Guy::Guy()
{

    bool v=getvisible();
    v = false;
    setvisible(v);
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

void Guy::update(sf::RenderWindow &window, int a)
{
    if(a==1)
        ammo--;
    else if(a==2)
        time--;


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
