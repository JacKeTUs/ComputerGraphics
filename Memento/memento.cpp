#include "Memento.h"

Memento::Memento()
{

}

Memento::Memento(const PointsArray *k_obj, const PolygonsArray *c_obj, const PointsArray *n_obj)
{
    memento_koords = *k_obj,
    memento_connects = *c_obj;
    memento_normales = *n_obj;
}
Memento::~Memento()
{
    memento_koords.Delete();
    memento_connects.Delete();
    memento_normales.Delete();
}

void Memento::set(PointsArray k_obj, PolygonsArray c_obj, PointsArray n_obj)
{
    memento_koords = k_obj,
    memento_connects = c_obj;
    memento_normales = n_obj;
}
