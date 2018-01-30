#ifndef MOVELIGHTSOURCECOMMAND_H
#define MOVELIGHTSOURCECOMMAND_H

#include "Command.h"

class MoveLightSourceCommand : public Command
{
private:
    int index;
    double dx;
    double dy;
    double dz;
public:
    MoveLightSourceCommand(int i, double x, double y, double z): index(i), dx(x), dy(y), dz(z) {}
    ~MoveLightSourceCommand() {}
    void execute(AdapterFacade& facade)
    {
        facade.moveLightSource(index,dx,dy,dz);
    }
};

#endif // MOVELIGHTSOURCECOMMAND_H
