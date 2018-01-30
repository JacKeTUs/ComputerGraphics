#ifndef LOOKATMATRIX_H
#define LOOKATMATRIX_H

#include "StrategyTransformMatrix.h"

class LookAtMatrix : public StrategyTransformMatrix
{
public:
    ~LookAtMatrix() {}

    TransformMatrix getMatrix(Vec3i eye, Vec3i center, Vec3i up)
    {
        TransformMatrix matr;
        matr.createLookAtMatrix(eye,center,up);
        return matr;
    }
};

#endif // LOOKATMATRIX_H
