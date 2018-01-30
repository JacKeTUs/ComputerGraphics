#ifndef MODEL_H
#define MODEL_H

#include "Composite.h"
#include "Component.h"
#include "LinesArray.h"
#include "PointsArray.h"
#include "Polygonsarray.h"
#include "LightSource.h"
#include "TransformData/Convert.h"
#include "Memento/Memento.h"
#include "Camera.h"


class Model : public Component
{
private:
    /// Вершины
    PointsArray koordinates;

    /// Нормали к вершинам
    PointsArray normales;

    /// Полигоны
    PolygonsArray polygons;

    /// Мгновенная скорость
    Vec3f velocity;

    /// Временная скорость
    Vec3f tempVelocity;

    /// Цвет материала модели
    QColor color;

    /// Все остальные модели
    Composite *otherModels;

    /// Выделена ли модель
    bool selected;

    /// Тени
    bool shadows;

    /// Источники света, которые освещают модель
    Composite* lightSources;

    /// Радиус оболочки
    float radius;

    /// Вес модели
    double weight;

public:
    Model();
    Model(int, int, int);
    Model(const Model&);
    ~Model();
    Model& operator=( const Model&);
    Memento* CreateMemento() const;
    void setMemento(const Memento *);

    void UpdateRadius()
    {
        float maxR = INT_MIN;
        Point cp = this->getCenterPoint();
        for (int i = 0; i < this->verts()->getElementsNumber(); i++)
        {
            Point p;
            p = this->verts()->getIPoint(i);

            if (Point::ToVec3f(cp-p).norm() > maxR)
                maxR = Point::ToVec3f(cp-p).norm();
        }

        setRadius(maxR);
    }

    void setRadius(float r)
    {
        radius = r;
    }
    double getWeight();

    float getRadius()
    {
        return radius;
    }

    void setOthersModels(Composite* others)
    {
        otherModels = others;
    }
    void setShadows(bool s)
    {
        shadows = s;
    }

    void setLightSources(Composite* ls)
    {
        this->lightSources = ls;
    }

    void addOtherModel(Component* cmp)
    {
        otherModels->Add(cmp);
    }

    void deleteOthersModels()
    {
        //delete otherModels;
    }

    void Drawing(Component*, Draw*);
    void Update(TransformData trData);

    void setColor(QColor color);

    void setSelect(bool s);

    Point getIKoord(int) const;
    Polygon *getIPolygon(int) const;
    Point getINormal(int i) const;
    void setIKoord(int, Point);
    void setIPolygon(int, Polygon *);
    void setINorm(int i, Point point);
    Point getCenterPoint();
    Vec3i getTransformCenterPoint(Component *cam, Draw* draw);
    std::vector<int> face(int idx);
    int getConnectsNumber() const;
    int getKoordsNumber() const;
    int getNormalesNumber() const;

    void setVelocity(Vec3f vel);

    void setTempVelocity(Vec3f vel);

    Vec3f getVelocity();

    void appendVelocity();

    bool IsEmpty() const;

    void setKoords(int);

    void setConnects(int);

    void setNormales(int kol_normales);

    void setKoords(const PointsArray& arr);

    void setPolygons(const PolygonsArray& arr);

    void setNormales(const PointsArray& arr);

    PointsArray *verts();

    PointsArray *norms();

    PolygonsArray *faces();

    static double getDistance(Model* a, Model *b);

    Vec3f norm(int iface, int nvert);

    void Delete();
};

#endif // MODEL_H
