#include "DrawArray.h"

DrawArray::DrawArray()
{

}

DrawArray::~DrawArray()
{
    delete[] scenes;
}

Draw* DrawArray::getIScene(int i)
{
    if ((scenes) && (i >= 0) && (i < elements_number))
        return scenes[i];
    return NULL;
}

void DrawArray::DeleteScene(int i)
{
    Q_UNUSED(i);
    //elements_number--;
    //delete scenes[i];

}

bool DrawArray::AddScene(Draw *newScene)
{
    if(!elements_number)
    {
        scenes = (Draw**)calloc(1, sizeof(Draw*));
    }
    else
    {
        scenes = (Draw**)realloc(scenes, (elements_number+1)*sizeof(Draw*));
    }
    scenes[elements_number] = newScene;
    elements_number++;
    return true;
}
