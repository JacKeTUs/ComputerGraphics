#ifndef ZOOMMATRIX_H
#define ZOOMMATRIX_H

#include "StrategyTransformMatrix.h"

class ZoomMatrix: public StrategyTransformMatrix
{
public:
    ~ZoomMatrix() {}

    TransformMatrix getTransformMatrix(const TransformData& obj)
    {
        TransformMatrix matr, zoomMatr;
        Zoom zoom = obj.getZoom();
        TransformMatrix tuda;
        tuda.createMoveMatrix(-zoom.get_x0(), -zoom.get_y0(), -zoom.get_z0());


        zoomMatr.createZoomMatrix(zoom.get_kx(),
                                    zoom.get_ky(),
                                    zoom.get_kz());

        TransformMatrix obratno;
        obratno.createMoveMatrix(zoom.get_x0(), zoom.get_y0(), zoom.get_z0());

        matr = tuda * zoomMatr * obratno;
        return matr;
    }
};

#endif // ZOOMMATRIX_H
