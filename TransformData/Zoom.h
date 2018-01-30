#ifndef ZOOM_H
#define ZOOM_H

class Zoom
{
private:
    double kx;
    double ky;
    double kz;


    double x0;
    double y0;
    double z0;
public:
    Zoom() : kx(1.0), ky(1.0), kz(1.0), x0(0), y0(0), z0(0) {}
    Zoom(double x, double y, double z, double _x0 = 0, double _y0 = 0, double _z0 = 0)
        : kx(x), ky(y), kz(z), x0(_x0), y0(_y0), z0(_z0) {}
    Zoom(const Zoom&);
    ~Zoom() {}
    Zoom& operator= (const Zoom&);
    Zoom operator+ (const Zoom&);
    Zoom operator* (const Zoom&);
    void set_kx(double x) {kx = x;}
    void set_ky(double y) {ky = y;}
    void set_kz(double z) {kz = z;}
    double get_kx() const {return kx;}
    double get_ky() const {return ky;}
    double get_kz() const {return kz;}

    void set_x0(double x) {x0 = x;}
    void set_y0(double y) {y0 = y;}
    void set_z0(double z) {z0 = z;}
    double get_x0() const {return x0;}
    double get_y0() const {return y0;}
    double get_z0() const {return z0;}
};

#endif // ZOOM_H
