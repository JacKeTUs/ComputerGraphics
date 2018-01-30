#ifndef ADDLIGHTSOURCE_H
#define ADDLIGHTSOURCE_H

#include "Command.h"

class AddLightSource : public Command
{
private:
    int x;
    int y;
    int z;
    int intensity;

public:
    AddLightSource(int _x, int _y, int _z, int _i = 1)
        : x(_x), y(_y), z(_z), intensity(_i) {}
    ~AddLightSource() {}
    void execute(AdapterFacade &facade)
    {
        facade.addLightSource(x, y, z, intensity);
    }
};

#endif // ADDLIGHTSOURCE_H
