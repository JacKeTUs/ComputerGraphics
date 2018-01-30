#include "ZBuf.h"

ZBuf::ZBuf(int width, int height)
{
    this->width = width;
    this->height = height;

    this->data = (int**)malloc(this->width * sizeof(int*));
    for(int i = 0; i < this->width; i++)
        this->data[i] = (int*)malloc(this->height * sizeof(int));

    initZBuf(INT_MIN);
}

void ZBuf::initZBuf(int value)
{
    // qDebug("init zBuf %d %d", this->width, this->height);
    for (int i = 0; i < this->width; i++)
        for(int j = 0; j < this->height; j++)
            this->data[i][j] = value;
}
ZBuf::~ZBuf()
{
    for(int i = 0; i < width; i++)
        free(this->data[i]);

    free(this->data);
}

int ZBuf::getWidth() {return width;}
int ZBuf::getHeight() {return height;}
int ZBuf::getZ(int x, int y)
{
    if ((x >= this->width) || (y >= this->height)
            || (x < 0) || (y < 0))
        return INT_MAX;
    else
        return data[x][y];
}
void ZBuf::setZ(int z, int x, int y)
{
    if (!((x >= this->width) || (y >= this->height)
          || (x < 0) || (y < 0)))
        data[x][y] = z;
}
