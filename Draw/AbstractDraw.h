#ifndef AbstractDraw_H
#define AbstractDraw_H

#include "QImage"
#include "QColor"
#include "ZBuf.h"

class AbstractDraw
{
protected:
    int height;
    int width;
    ZBuf* zBuffer;

public:
    AbstractDraw();

    AbstractDraw(int h, int w);

    AbstractDraw(const AbstractDraw& obj);

    AbstractDraw& operator= (const AbstractDraw& obj);

    ~AbstractDraw();

    virtual void DrawLine(int x1, int y1, int x2, int y2);

    virtual void setSizeZBuf(int w, int h);

    virtual int getHeight();

    virtual int getWidth();
};

#endif // AbstractDraw_H
