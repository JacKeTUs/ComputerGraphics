#ifndef VIEWPORTMATRIX_H
#define VIEWPORTMATRIX_H
#include "StrategyTransformMatrix.h"

class ViewPortMatrix : public StrategyTransformMatrix
{
public:
    ViewPortMatrix();


    TransformMatrix getMatrix(int x, int y, int w, int h)
    {
        TransformMatrix Viewport;
        Viewport.createIdentityMatrix();
        Viewport.setVal(0, 3, x+w/2.f);
        Viewport.setVal(1, 3, y+h/2.f);
        Viewport.setVal(2, 3, 255/2.f);

        Viewport.setVal(0, 0, w/2.f);
        Viewport.setVal(1, 1, h/2.f);
        Viewport.setVal(2, 2, 255/2.f);

        return Viewport;
    }
};

#endif // VIEWPORTMATRIX_H
