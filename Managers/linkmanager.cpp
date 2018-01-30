#include "LinkManager.h"

LinkManager::LinkManager()
{
    selectedLink = -1;
}

LinkManager::~LinkManager()
{
}


void LinkManager::AddLink(Model* m1, Model* m2, double tension)
{
    Link *my_link = new Link(m1, m2, tension);
    comp.Add(my_link);
}

void LinkManager::DeleteLink(int index_link)
{
    ListPointer<Component*>::iterator it = comp.CreateComponentsIterator();
    it += (index_link);
    if (!it.IsDone())
        comp.Remove(it);
}

Link* LinkManager::getILink(int index_link)
{
    ListPointer<Component*>::iterator it = comp.CreateComponentsIterator();
    it += (index_link);
    return LINK(it);
}

Composite* LinkManager::getComposite()
{
    return &comp;
}

void LinkManager::SelectILink(int selIdx)
{
    ListPointer<Component*>::iterator it = comp.CreateComponentsIterator();
    it += (selectedLink);
    LINK(it)->select(0);
    it = comp.CreateComponentsIterator();
    it += (selIdx);
    LINK(it)->select(1);

    selectedLink = selIdx;
}

void LinkManager::setIColor(int i, QColor c)
{
    ListPointer<Component*>::iterator it = comp.CreateComponentsIterator();
    it += (i);
    LINK(it)->setColor(c);
}
