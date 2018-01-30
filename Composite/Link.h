#ifndef LINK_H
#define LINK_H

#include "Model.h"

class Link : public Component
{
private:
    // Связанные объекты
    Model* p1;
    Model* p2;

    // Цвет связи
    QColor color;

    // базовая длина
    double baseLength;

    // коэффициент упругости текущей связи
    double tension;

    // выделена ли модель
    bool selected;

public:
    Link();

    Link(Model* a, Model* b, double t);

    ~Link();

    void CalculateForces();

    void Drawing(Component* it, Draw* draw);

    Model* getSourceModel();

    Model* getDestModel();

    double getLength();

    double getBaseLength();

    double getTension();

    void setColor(QColor c);

    void select(bool isSelected = true);

};

#endif // LINK_H
