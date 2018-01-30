#ifndef DELETELINK_H
#define DELETELINK_H

#include "Command.h"

class DeleteLinkCommand : public Command
{
private:
    int index; ///< Индекс удаляемой связи

public:
    DeleteLinkCommand(int idx) {this->index = idx;}
    ~DeleteLinkCommand() {}

    void execute(AdapterFacade& facade)
    {
        facade.deleteLink(index);
    }
};

#endif // DELETELINK_H
