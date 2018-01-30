#ifndef LINKMANAGER_H
#define LINKMANAGER_H
#include "BaseManager.h"
#include "ModelManager.h"
#include <Composite/Composite.h>
#include "Composite/Link.h"

class LinkManager : public BaseManager
{
protected:
    // Композит связей
    Composite comp;

    int selectedLink;

public:
    LinkManager();
    ~LinkManager();

    void AddLink(Model* m1, Model* m2, double tension);

    void DeleteLink(int index_link);

    void SelectILink(int selIdx);

    Link* getILink(int index_link);

    Composite* getComposite();

    void setIColor(int i, QColor c);

};

#endif // LINKMANAGER_H
