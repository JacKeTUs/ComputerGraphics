#ifndef SELECTLINKCOMMAND_H
#define SELECTLINKCOMMAND_H

#include "Command.h"

class SelectLinkCommand : public Command
{
private:
    int index;

public:
    SelectLinkCommand(int i): index(i) {}
    ~SelectLinkCommand() {}
    void execute(AdapterFacade &facade)
    {
        facade.selectLink(index);
    }
};

#endif // SELECTLINKCOMMAND_H
