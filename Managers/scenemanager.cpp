#include "SceneManager.h"
#include "./Composite/Model.h"

SceneManager::SceneManager()
{
    BGColor = QColor(30,30,30);
}

void SceneManager::DrawingScene(Composite *models,                          /*! < Модели */
                                Camera *cam,                                /*! < Камера */
                                Draw* draw,                                 /*! < Сцена */
                                Composite *links                            /*! < Связи */,
                                Composite* lightSources,                    /*! < Источники света */
                                bool showLinks                              /*! < Показывать ли связи? */,
                                bool showShadows                            /*! < Показывать ли тени? */)
{
    // рисуем фон (внутри инициализация Zбуфера)
    draw->FillCanvas(BGColor);

    // Рисуем линии, если надо
    if (showLinks)
        links->Drawing(cam, draw);

    // Рисуем модели
    // Тени
    ListPointer<Component*>::iterator it1 = models->CreateComponentsIterator();
    for (; !it1.IsDone(); ++it1)
        ((Model*)(*it1))->setShadows(showShadows);

    // Источники света
    ListPointer<Component*>::iterator it = models->CreateComponentsIterator();
    for (; !it.IsDone(); ++it)
        ((Model*)(*it))->setLightSources(lightSources);

    lightSources->Drawing(cam, draw);

    // И модели, наконец
    models->Drawing(cam, draw);
}


void SceneManager::setBGColor(QColor c)
{
    BGColor = c;
}
