#include "StaticObject.h"

StaticObject::StaticObject(float x, float y, float scx, float scy, std::string plik, bool show)
{
    if (!tekstura.loadFromFile(plik)) {
        std::cout << "Could not load texture" << std::endl;
    }
    bool v=getvisible();
    v=show;
    setvisible(v);
    setPosition(x,y);
    setScale(scx,scy);

    setTexture(tekstura);
}
