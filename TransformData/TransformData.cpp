#include "TransformData.h"

TransformData::TransformData()
{
    offset.set_dx(0);
    offset.set_dy(0);
    offset.set_dz(0);

    zoom.set_kx(1);
    zoom.set_ky(1);
    zoom.set_kz(1);

    rotate.set_arc_x(0);
    rotate.set_arc_y(0);
    rotate.set_arc_z(0);
}

TransformData::TransformData(const TransformData& obj)
{
    offset = obj.getOffset();
    zoom = obj.getZoom();
    rotate = obj.getRotate();
}


void TransformData::setOffset(const Offset &obj)
{
    offset = obj;
}

void TransformData::setRotate(const Rotate & obj)
{
    rotate = obj;
}

void TransformData::setZoom(const Zoom & obj)
{
    zoom = obj;
}


Offset TransformData::getOffset() const
{
    return offset;
}

Rotate TransformData::getRotate() const
{
    return rotate;
}

Zoom TransformData::getZoom() const
{
    return zoom;
}



TransformData TransformData::operator + (const TransformData& obj)
{
    TransformData new_obj;
    new_obj.setOffset(obj.getOffset() + getOffset());
    new_obj.setRotate(obj.getRotate() + getRotate());
    new_obj.setZoom(obj.getZoom() * getZoom());
    return new_obj;
}

TransformData& TransformData::operator+= (const TransformData& obj)
{
    Zoom zoom = obj.getZoom();
    if ((zoom.get_kx() != 0) && (zoom.get_ky() != 0) && (zoom.get_kz() != 0))
        *this = *this + obj;
    return *this;
}

TransformData& TransformData::operator= (const TransformData& obj)
{
    offset = obj.getOffset();
    zoom = obj.getZoom();
    rotate = obj.getRotate();
    return *this;
}
