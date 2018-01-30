#include "Zoom.h"

Zoom::Zoom(const Zoom& obj)
{
    kx = obj.get_kx();
    ky = obj.get_ky();
    kz = obj.get_kz();

    x0 = obj.get_x0();
    y0 = obj.get_y0();
    z0 = obj.get_z0();
}

Zoom& Zoom::operator= (const Zoom& obj)
{
    kx = obj.get_kx();
    ky = obj.get_ky();
    kz = obj.get_kz();

    x0 = obj.get_x0();
    y0 = obj.get_y0();
    z0 = obj.get_z0();
    return *this;
}

Zoom Zoom::operator+ (const Zoom& obj)
{
    Zoom new_obj(obj.get_kx() + get_kx(),
                 obj.get_ky() + get_ky(),
                 obj.get_kz() + get_kz(),
                 obj.get_x0() + get_x0(),
                 obj.get_y0() + get_y0(),
                 obj.get_z0() + get_z0());
    return new_obj;
}

Zoom Zoom::operator* (const Zoom& obj)
{
    Zoom new_obj(obj.get_kx() * get_kx(),
                 obj.get_ky() * get_ky(),
                 obj.get_kz() * get_kz(),
                 obj.get_x0() + get_x0(),
                 obj.get_y0() + get_y0(),
                 obj.get_z0() + get_z0());
    return new_obj;
}


