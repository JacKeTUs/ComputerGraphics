#ifndef ADDLINKCOMMAND_H
#define ADDLINKCOMMAND_H
#include "Command.h"

class AddLinkCommand : public Command
{
private:
    int idx1;       ///< Индекс 1 модели
    int idx2;       ///< Индекс 2 модели
    double tension; ///< Коэф.упругости
public:
    AddLinkCommand(int a, int b, double t) : idx1(a), idx2(b), tension(t) {}
    ~AddLinkCommand() {}
    void execute(AdapterFacade &facade)
    {
        facade.addLink(idx1, idx2, tension);
    }
};

#endif // ADDLINKCOMMAND_H
