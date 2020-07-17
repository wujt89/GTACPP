#ifndef ELEMENTS_H
#define ELEMENTS_H


#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
//#include <SFML/Text.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <memory>
#include <vector>
#include <windows.h>
#include <algorithm>
#include <string>


class Elements : public sf::Sprite
{
    bool visible;
public:
    Elements();
    void setvisible(bool b){visible=b;};
    bool getvisible(){return visible;};

};













#endif // ELEMENTS_H
