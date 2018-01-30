#ifndef STRATEGYTRANSFORMMATRIX_H
#define STRATEGYTRANSFORMMATRIX_H


#include "TransformData/TransformData.h"

class StrategyTransformMatrix
{
public:
    virtual ~StrategyTransformMatrix() {}
    virtual TransformMatrix getTransformMatrix(const TransformData&) {return TransformMatrix();}
};

#endif // STRATEGYTRANSFORMMATRIX_H
