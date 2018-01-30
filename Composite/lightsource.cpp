#include "LightSource.h"

LightSource::LightSource()
{
    selected = 0;
    baseIntensity = 1;
}

void LightSource::setLocation(Point p)
{
    this->location = p;
}

Point LightSource::getLocation()
{
    return location;
}

void LightSource::select(bool IsSelected)
{
   selected = IsSelected;
}

void LightSource::setIntensity(float i)
{
   // if (i > 1)
     //   i = 1;
    /*else*/ if (i < 0)
        i = 0;
    baseIntensity = i;
}

float LightSource::getIntensity()
{
    return baseIntensity;
}

void LightSource::Update(const TransformData &tr)
{
    Point newLocation = this->location;

    newLocation = location.Transform(Convert::DataToMatrix(tr));
    location = newLocation;
}

void LightSource::Drawing(Component *cam, Draw *draw)
{
    TransformMatrix matrix = ((Camera*)cam)->getTransformMatrix();// (*it)->getTransformMatrix();
    Vec3i res = draw->ProjectIntoScreen(Point::ToVec3f(location.Transform(matrix)));

    float some2D = 5;

    QColor color;
    if (selected)
        color = Qt::yellow;
    else
        color = Qt::white;
    draw->DrawLine(res+Vec3i(-some2D,0,0), res + Vec3i(some2D,0,0),color);
    draw->DrawLine(res+Vec3i(0,-some2D,0), res + Vec3i(0,some2D,0),color);
    draw->DrawLine(res+Vec3i(-some2D,-some2D,0), res + Vec3i(some2D,some2D,0),color);
    draw->DrawLine(res+Vec3i(-some2D,some2D,0), res + Vec3i(some2D,-some2D,0),color);
}
