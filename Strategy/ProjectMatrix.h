#ifndef PROJECTMATRIX_H
#define PROJECTMATRIX_H

#include "StrategyTransformMatrix.h"


class ProjectMatrix : public StrategyTransformMatrix
{
public:
    ProjectMatrix();

    TransformMatrix getMatrix(float coeff)
    {
        TransformMatrix result;
        result.createIdentityMatrix();

        result.setVal(3, 2, coeff);
        return result;
    }
};

#endif // PROJECTMATRIX_H
