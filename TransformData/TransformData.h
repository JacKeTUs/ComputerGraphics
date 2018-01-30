#ifndef TRANSFORMDATA_H
#define TRANSFORMDATA_H

#include "Offset.h"
#include "Zoom.h"
#include "Rotate.h"
#include "TransformMatrix/TransformMatrix.h"

class TransformData
{
private:
    Offset offset;
    Zoom zoom;
    Rotate rotate;

public:
    TransformData();

    TransformData(const TransformData&);

    ~TransformData() {}

    TransformData operator+ (const TransformData&);

    TransformData& operator+= (const TransformData&);

    TransformData& operator= (const TransformData&);

    void setOffset(const Offset&);

    void setZoom(const Zoom&);

    void setRotate(const Rotate&);

    Offset getOffset() const;

    Zoom getZoom() const;

    Rotate getRotate() const;
};

#endif // TRANSFORMDATA_H
