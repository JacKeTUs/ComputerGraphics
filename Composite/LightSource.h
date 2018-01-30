#ifndef LIGHTSOURCE_H
#define LIGHTSOURCE_H

#include "QColor"
#include "Camera.h"
#include "Draw/Draw.h"
#include "./Composite/Point.h"

class LightSource : public Component
{
private:
    Point location;
    //QColor color;
    float baseIntensity;
    bool selected;

public:
    LightSource();// {baseIntensity = 1;}

    void setLocation(Point p);

    void select(bool isSelected = 1);

    Point getLocation();

    void setIntensity(float i);

    void Update(const TransformData& tr);

    float getIntensity();

    void Drawing(Component *cam, Draw *draw);
};

#endif // LIGHTSOURCE_H
