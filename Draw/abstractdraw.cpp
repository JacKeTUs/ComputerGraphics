#include "AbstractDraw.h"

AbstractDraw::AbstractDraw()
    : height(1), width(1)
{
    zBuffer = new ZBuf(1,1);
}

AbstractDraw::AbstractDraw(int h, int w)
    : height(h), width(w)
{
    if (zBuffer)
        delete zBuffer;
    zBuffer = new ZBuf(this->width, this->height);
}

AbstractDraw::AbstractDraw(const AbstractDraw& obj)
{
    height = obj.height;
    width = obj.width;
    if (zBuffer)
        delete zBuffer;
    zBuffer = new ZBuf(this->width, this->height);
}

AbstractDraw::~AbstractDraw()
{
    delete zBuffer;
}

AbstractDraw& AbstractDraw::operator= (const AbstractDraw& obj)
{
    height = obj.height;
    width = obj.width;
    if (zBuffer)
        delete zBuffer;
    zBuffer = new ZBuf(this->width, this->height);
    return *this;
}

void AbstractDraw::DrawLine(int x1, int y1, int x2, int y2)
{
    Q_UNUSED(x1);
    Q_UNUSED(y1);
    Q_UNUSED(x2);
    Q_UNUSED(y2);
}

void AbstractDraw::setSizeZBuf(int w, int h)
{
    width = w;
    height = h;
    if (zBuffer)
        delete zBuffer;
    zBuffer = new ZBuf(w, h);
}

int AbstractDraw::getHeight()
{
    return height;
}

int AbstractDraw::getWidth()
{
    return width;
}
