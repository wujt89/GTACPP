#ifndef STATICOBJECT_H
#define STATICOBJECT_H

#endif // STATICOBJECT_H

#include "elementy.h"

class StaticObject : public Elements
{
    sf::Texture tekstura;


public:
    StaticObject(float x, float y, float scx, float scy, std::string plik, bool show);

};
