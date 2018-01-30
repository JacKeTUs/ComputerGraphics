#ifndef ZOOMMODELCOMMAND_H
#define ZOOMMODELCOMMAND_H

#include "Command.h"

class ZoomModelCommand : public Command
{
private:
    int index;
    double kx;
    double ky;
    double kz;
public:
    ZoomModelCommand(int i, double x, double y, double z): index(i), kx(x), ky(y), kz(z) {}
    ~ZoomModelCommand() {}
    void execute(AdapterFacade &facade)
    {
        facade.ZoomModel(index,kx,ky,kz);
    }

};

#endif // ZOOMMODELCOMMAND_H
