#ifndef MEMENTO_H
#define MEMENTO_H
#include "Composite/PointsArray.h"
#include "Composite/Polygonsarray.h"

class Model;
class PointsArray;
class PolygonsArray;

class Memento
{
private:
    friend class Model;
    PointsArray memento_koords;
    PointsArray memento_normales;
    PolygonsArray memento_connects;

public:
    Memento();
    ~Memento();

    Memento(const PointsArray *k_obj, const PolygonsArray *c_obj, const PointsArray *n_obj);

    void set(PointsArray k_obj, PolygonsArray c_obj, PointsArray n_obj);
};

#endif // MEMENTO_H
