#ifndef SETLINKCOLORCOMMAND_H
#define SETLINKCOLORCOMMAND_H

#include "Command.h"

class SetLinkColorCommand : public Command
{
private:
    int index;
    QColor color;

public:
    SetLinkColorCommand(int _i, QColor _color): index(_i), color(_color) {}

    ~SetLinkColorCommand() {}
    void execute(AdapterFacade &facade)
    {
        facade.SetLinkColor(index, color);
    }
};

#endif // SETLINKCOLORCOMMAND_H
