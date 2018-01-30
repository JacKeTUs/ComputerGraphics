#include "Composite.h"
#include "Model.h"

Composite::Composite()
{

}

Composite::~Composite()
{
    components.clean();
}

// cam - i-тая камера
void Composite::Drawing(Component *cam, Draw* draw)
{
    if (!components.Size())
        return;

    // Проходим по всем компонентам и рисуем их
    iter_model = components.begin();
    int i = 0;
    for (; !iter_model.IsDone(); ++iter_model, i++)
    {
        (*iter_model)->Drawing(cam, draw);
    }

}

int Composite::getComponentsNumber()
{
    return components.Size();
}

bool Composite::Add(Component* comp)
{
    components.push_back(comp);
    return true;
}

bool Composite::Remove(ListPointer<Component *>::iterator it)
{
    components.erase(it);
    return true;
}

ListPointer<Component*>::iterator Composite::CreateComponentsIterator()
{
    return components.begin();
}
