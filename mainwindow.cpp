#include "mainwindow.h"
#include "ui_mainwindow.h"

#define LOCK_FPS 30

static AdapterFacade facade;
static MacroCommand cmd_list;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow), timerId(0)
{
    ui->setupUi(this);
    connect(ui->LoadModel, SIGNAL(triggered()), this, SLOT(getFileName()));
    connect(ui->actionHelp, SIGNAL(triggered()), this, SLOT(Help()));
    connect(ui->color_w, SIGNAL(sendColor(QColor)), this, SLOT (setTempColor(QColor)));
    connect(ui->bg_color, SIGNAL(sendColor(QColor)), this, SLOT (setBGColor(QColor)));


    connect(ui->cameras, SIGNAL(mPE(QMouseEvent*)), this, SLOT(mousePressEvent(QMouseEvent*)));
    connect(ui->cameras, SIGNAL(mME(QMouseEvent*)), this, SLOT(mouseMoveEvent(QMouseEvent*)));
    connect(ui->cameras, SIGNAL(mRE(QMouseEvent*)), this, SLOT(mouseReleaseEvent(QMouseEvent*)));
    connect(ui->cameras, SIGNAL(wE(QWheelEvent*)), this, SLOT(wheelEvent(QWheelEvent*)));

    tmpColor.setRed(200);
    tmpColor.setGreen(200);
    tmpColor.setBlue(200);
    ui->color_w->setColor(QColor(200,200,200));
    ui->bg_color->setColor(QColor(30,30,30));
    ui->link_color->setColor(Qt::blue);

    timerId = 0;
    index = -1;
    isPressed = false;
    cameraRotateStep = 15;
    ui->checkBox->setChecked(true);
    lightSourceIdx = -1;
    linkIdx = -1;
    ui->spinBox->setValue(lightSourceIdx);
    curScene = 0;
    //addCamera();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Help()
{
    QMessageBox::information(this, "Help", " '0' - поворот\n '1'..'5' - Подгрузить модели \n \
'W, A, S, D, Q, E' - смещение \n '+', '-' - масштабирование");
}

void MainWindow::setTempColor(QColor new_color)
{
    this->tmpColor = new_color;
}

void MainWindow::getFileName()
{
    QString file_name = QFileDialog::getOpenFileName(this, ("Открыть файл"),
                                   "", ("Текстовые документы (*.txt);;Все файлы (*)"));
    if (file_name == "")
    {
        QMessageBox::information(this,"Error","Вы не выбрали файл!");
        return;
    }

    cmd_list.addCommand(new AddModelCommand((char*)file_name.toLocal8Bit().constData()));
    cmd_list.addCommand(new SetColorCommand(facade.getLastIdx()+1,  ui->color_w->getColor()));
    this->redrawScene();
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    // Если нет камеры, добавить
    if (ui->cameras->getScenes()->getElementsNumber() == 0)
        this->addCamera();
    /*!
      WASDQE - УПРАВЛЕНИЕ КАМЕРОЙ
      IJKLUO - УПРАВЛЕНИЕ МОДЕЛЬЮ
      */
    switch (event->key())
    {
    case Qt::Key_Delete:
        cmd_list.addCommand(new DeleteCommand(index));
        break;
    case Qt::Key_0:
        cmd_list.addCommand(new RotateCommand(curScene,3,3,3));
        break;

    case Qt::Key_Plus:
        cmd_list.addCommand(new ZoomCommand(curScene,1.5,1.5,1.5));
        break;
    case Qt::Key_Minus:
        cmd_list.addCommand(new ZoomCommand(curScene,0.6,0.6,0.6));
        break;

    case Qt::Key_2:
        cmd_list.addCommand(new ZoomModelCommand(index,1.1,1.1,1.1));
        break;
    case Qt::Key_1:
        cmd_list.addCommand(new ZoomModelCommand(index,0.9,0.9,0.9));
        break;

        //! Управление камерой
    case Qt::Key_W:
        cmd_list.addCommand(new MoveCommand(curScene,0,-3,0));
        break;
    case Qt::Key_A:
        cmd_list.addCommand(new MoveCommand(curScene,3,0,0));
        break;
    case Qt::Key_S:
        cmd_list.addCommand(new MoveCommand(curScene,0,3,0));
        break;
    case Qt::Key_D:
        cmd_list.addCommand(new MoveCommand(curScene,-3,0,0));
        break;
    case Qt::Key_Q:
        cmd_list.addCommand(new MoveCommand(curScene,0,0,-3));
        break;
    case Qt::Key_E:
        cmd_list.addCommand(new MoveCommand(curScene,0,0,3));
        break;

        //! Управление моделью
    case Qt::Key_I:
        cmd_list.addCommand(new SetVelCommand(index, 0,  -3,  0));
        break;
    case Qt::Key_J:
        cmd_list.addCommand(new SetVelCommand(index, 3, 0,  0));
        break;
    case Qt::Key_K:
        cmd_list.addCommand(new SetVelCommand(index, 0,  3, 0));
        break;
    case Qt::Key_L:
        cmd_list.addCommand(new SetVelCommand(index, -3,  0,  0));
        break;
    case Qt::Key_U:
        cmd_list.addCommand(new SetVelCommand(index, 0,  0,  -3));
        break;
    case Qt::Key_O:
        cmd_list.addCommand(new SetVelCommand(index, 0,  0,  3));
        break;

        //! Управление источником света
    case Qt::Key_T:
        cmd_list.addCommand(new MoveLightSourceCommand(lightSourceIdx, 0,  -3,  0));
        break;
    case Qt::Key_F:
        cmd_list.addCommand(new MoveLightSourceCommand(lightSourceIdx, 3, 0,  0));
        break;
    case Qt::Key_G:
        cmd_list.addCommand(new MoveLightSourceCommand(lightSourceIdx, 0,  3, 0));
        break;
    case Qt::Key_H:
        cmd_list.addCommand(new MoveLightSourceCommand(lightSourceIdx, -3,  0,  0));
        break;
    case Qt::Key_R:
        cmd_list.addCommand(new MoveLightSourceCommand(lightSourceIdx, 0,  0,  -3));
        break;
    case Qt::Key_Y:
        cmd_list.addCommand(new MoveLightSourceCommand(lightSourceIdx, 0,  0,  3));
        break;


        // выделение объектов
    case Qt::Key_Z:
        if (index >= 1) index--;
        else index = facade.getLastIdx();
        cmd_list.addCommand(new SelectModelCommand(index));
        break;
    case Qt::Key_X:
        if (index < facade.getLastIdx()) index++;
        else index = 0;
        cmd_list.addCommand(new SelectModelCommand(index));
        break;

        // выделение камеры
    case Qt::Key_C:
        if (curScene >= 1) curScene--;
        else curScene = ui->cameras->getScenes()->getElementsNumber()-1;
            ui->cameras->selectICamera(curScene);
        break;

    case Qt::Key_V:
        if (curScene < ui->cameras->getScenes()->getElementsNumber()-1) curScene++;
        else curScene = 0;
            ui->cameras->selectICamera(curScene);
        break;

        // выделение источника света
    case Qt::Key_B:
        if (lightSourceIdx >= 1)
            lightSourceIdx--;
        else
            lightSourceIdx = facade.getLastLightSourceIdx();
        cmd_list.addCommand(new SelectLightSourceCommand(lightSourceIdx));
        break;

    case Qt::Key_N:
        if (lightSourceIdx < facade.getLastLightSourceIdx())
            lightSourceIdx++;
        else
            lightSourceIdx = 0;
        cmd_list.addCommand(new SelectLightSourceCommand(lightSourceIdx));
        break;
    }
    ui->mdl_move_idx->setValue(index);
    ui->cam_move_idx->setValue(curScene);
    ui->spinBox->setValue(lightSourceIdx);

    this->redrawScene();
}

/*!
 * \brief MainWindow::on_pushButton_clicked
 * Добавление объекта
 */
void MainWindow::on_pushButton_clicked()
{
    // Если нет камеры, добавить
    if (ui->cameras->getScenes()->getElementsNumber() == 0)
        this->addCamera();
    // Форма
    switch(ui->comboBox->currentIndex())
    {
        case 0:
            cmd_list.addCommand(new AddModelCommand((char*)"cube.txt"));
            cmd_list.addCommand(new SetColorCommand(facade.getLastIdx()+1, this->tmpColor));
        break;
        case 1:
            cmd_list.addCommand(new AddModelCommand((char*)"piram.txt"));
            cmd_list.addCommand(new SetColorCommand(facade.getLastIdx()+1, this->tmpColor));
        break;
        case 2:
            cmd_list.addCommand(new AddModelCommand((char*)"icosahedron.txt"));
            cmd_list.addCommand(new SetColorCommand(facade.getLastIdx()+1, this->tmpColor));
        break;
        case 3:
            cmd_list.addCommand(new AddModelCommand((char*)"sphere512.txt"));
            cmd_list.addCommand(new SetColorCommand(facade.getLastIdx()+1, this->tmpColor));
        break;
    }
    this->redrawScene();
}

/*!
 * \brief MainWindow::on_action_triggered
 * Добавление камеры
 */
void MainWindow::on_action_triggered()
{
    this->addCamera();
}

void MainWindow::addCamera()
{
    if (ui->cameras->getScenes()->getElementsNumber() == ui->cameras->maxCameras())
        QMessageBox::information(this,"Error","Больше камер добавить нельзя!");
    else
    {
        ui->cameras->addCamera();

        cmd_list.addCommand(new AddCameraCommand);
        this->redrawScene();
    }
}

/*!
 * \brief MainWindow::redrawScene
 * Перерисовка сцены
 */
void MainWindow::redrawScene()
{
    for (int i = 0; i < ui->cameras->getScenes()->getElementsNumber(); i++)
        cmd_list.addCommand(new DrawCommand(i, ui->cameras->getScenes()->getIScene(i), ui->checkBox->isChecked(), ui->checkBox_2->isChecked()));

    cmd_list.execute(facade);
    cmd_list.cleanCommandList();

    ui->cameras->redrawAll();

}

/*!
 * \brief MainWindow::on_adding_link_clicked
 * Добавление связей
 */
void MainWindow::on_adding_link_clicked()
{
    cmd_list.addCommand(new AddLinkCommand(ui->mdl_idx_1->value(),
                                            ui->mdl_idx_2->value(),
                                            ui->tension_box->value()));
    cmd_list.addCommand(new SetLinkColorCommand(facade.getLastLinkIdx()+1, ui->link_color->getColor()));
    this->redrawScene();
}

void MainWindow::on_sim_start_clicked()
{
    if (!timerId)
        timerId = startTimer(1000 / LOCK_FPS);
}

void MainWindow::timerEvent(QTimerEvent *)
{
    cmd_list.addCommand(new CalculateForcesCommand);
    this->redrawScene();
}

/*!
 * \brief MainWindow::loadDefaultPattern
 *  загрузка дефолта
 */
void MainWindow::loadDefaultPattern()
{
    if (ui->cameras->getScenes()->getElementsNumber() == 0)
    {
        this->addCamera();
        cmd_list.addCommand(new ZoomCommand(0,0.1,0.1,0.1));
    }
//    cmd_list.addCommand(new AddModelCommand((char*)"icosahedron.txt"));
//    cmd_list.addCommand(new AddModelCommand((char*)"cube.txt"));
//    cmd_list.addCommand(new AddModelCommand((char*)"cube.txt"));
//    cmd_list.addCommand(new AddModelCommand((char*)"cube.txt"));
//    cmd_list.addCommand(new AddModelCommand((char*)"cube.txt"));
//    cmd_list.addCommand(new AddModelCommand((char*)"cube.txt"));
//    cmd_list.addCommand(new AddModelCommand((char*)"cube.txt"));

//    cmd_list.addCommand(new MoveModelCommand(1, 5,  0,  0));
//    cmd_list.addCommand(new MoveModelCommand(2, -5, 0,  0));
//    cmd_list.addCommand(new MoveModelCommand(3, 0,  5,  0));
//    cmd_list.addCommand(new MoveModelCommand(4, 0,  -5,  0));
//    cmd_list.addCommand(new MoveModelCommand(5, 0,  0,  5));
//    cmd_list.addCommand(new MoveModelCommand(6, 0,  0,  -5));

//    cmd_list.addCommand(new AddLinkCommand(0,1,10));
//    cmd_list.addCommand(new AddLinkCommand(0,2,10));
//    cmd_list.addCommand(new AddLinkCommand(0,3,10));
//    cmd_list.addCommand(new AddLinkCommand(0,4,10));
//    cmd_list.addCommand(new AddLinkCommand(0,5,10));
//    cmd_list.addCommand(new AddLinkCommand(0,6,10));

//    cmd_list.addCommand(new ZoomCommand(0,0.6,0.6,0.6));
    int zeroModel = facade.getLastIdx();
    cmd_list.addCommand(new AddModelCommand((char*)"cube.txt"));
    cmd_list.addCommand(new SetColorCommand(zeroModel+1, this->tmpColor));
    cmd_list.addCommand(new AddModelCommand((char*)"cube.txt"));
    cmd_list.addCommand(new SetColorCommand(zeroModel+2, QColor(255,0,0)));
    cmd_list.addCommand(new AddModelCommand((char*)"cube.txt"));
    cmd_list.addCommand(new SetColorCommand(zeroModel+3, QColor(255,0,0)));
    cmd_list.addCommand(new AddModelCommand((char*)"cube.txt"));
    cmd_list.addCommand(new SetColorCommand(zeroModel+4, QColor(255,0,0)));
    cmd_list.addCommand(new AddModelCommand((char*)"cube.txt"));
    cmd_list.addCommand(new SetColorCommand(zeroModel+5, QColor(255,0,0)));
    cmd_list.addCommand(new AddModelCommand((char*)"icosahedron.txt"));
    cmd_list.addCommand(new SetColorCommand(zeroModel+6, QColor(150,0,200)));
    cmd_list.addCommand(new AddModelCommand((char*)"icosahedron.txt"));
    cmd_list.addCommand(new SetColorCommand(zeroModel+7, QColor(150,0,200)));
    cmd_list.addCommand(new AddModelCommand((char*)"icosahedron.txt"));
    cmd_list.addCommand(new SetColorCommand(zeroModel+8, QColor(150,0,200)));
    cmd_list.addCommand(new AddModelCommand((char*)"icosahedron.txt"));
    cmd_list.addCommand(new SetColorCommand(zeroModel+9, QColor(150,0,200)));

    cmd_list.addCommand(new MoveModelCommand(zeroModel+2, 0,  5,  0));
    cmd_list.addCommand(new MoveModelCommand(zeroModel+3, 0, -5,  0));
    cmd_list.addCommand(new MoveModelCommand(zeroModel+4, -5,  0,  0));
    cmd_list.addCommand(new MoveModelCommand(zeroModel+5, 5,  0,  0));
    cmd_list.addCommand(new MoveModelCommand(zeroModel+6, 5,  5,  0));
    cmd_list.addCommand(new MoveModelCommand(zeroModel+7, 5,  -5,  0));
    cmd_list.addCommand(new MoveModelCommand(zeroModel+8, -5,  -5,  0));
    cmd_list.addCommand(new MoveModelCommand(zeroModel+9, -5,  5,  0));

    cmd_list.addCommand(new AddLinkCommand(zeroModel+1, zeroModel+2,50));
    cmd_list.addCommand(new AddLinkCommand(zeroModel+1, zeroModel+3,50));
    cmd_list.addCommand(new AddLinkCommand(zeroModel+1, zeroModel+4,50));
    cmd_list.addCommand(new AddLinkCommand(zeroModel+1, zeroModel+5,50));

    cmd_list.addCommand(new AddLinkCommand(zeroModel+2, zeroModel+6, 20));
    cmd_list.addCommand(new AddLinkCommand(zeroModel+6, zeroModel+5, 20));
    cmd_list.addCommand(new AddLinkCommand(zeroModel+5, zeroModel+7, 20));
    cmd_list.addCommand(new AddLinkCommand(zeroModel+7, zeroModel+3, 20));
    cmd_list.addCommand(new AddLinkCommand(zeroModel+3, zeroModel+8, 20));
    cmd_list.addCommand(new AddLinkCommand(zeroModel+8, zeroModel+4, 20));
    cmd_list.addCommand(new AddLinkCommand(zeroModel+4, zeroModel+9, 20));
    cmd_list.addCommand(new AddLinkCommand(zeroModel+9, zeroModel+2, 20));

//    cmd_list.addCommand(new SetVelCommand(1,5,0,0));
//    cmd_list.addCommand(new SetVelCommand(4,0,-5,0));
//    cmd_list.addCommand(new SetVelCommand(2,-5,0,0));
//    cmd_list.addCommand(new SetVelCommand(3,0,5,0));


//    cmd_list.addCommand(new SetVelCommand(5,5,-5,0));
//    cmd_list.addCommand(new SetVelCommand(6,-5,-5,0));
//    cmd_list.addCommand(new SetVelCommand(7,-5,5,0));
//    cmd_list.addCommand(new SetVelCommand(8,5,5,0));

    this->on_sim_start_clicked();
}

// остановка
void MainWindow::on_pushButton_8_clicked()
{
    killTimer(timerId);
    timerId = 0;
}

// Удаление предыдущей связи (аля Ctrl+Z)
void MainWindow::on_pushButton_15_clicked()
{
    //
    killTimer(timerId);
    timerId = 0;

    cmd_list.addCommand(new DeleteLinkCommand(linkIdx));

    this->redrawScene();
    //
    //this->on_sim_start_clicked();
}

/*!
 * \brief MainWindow::on_pushButton_16_clicked
 * добавить дефолт
 */
void MainWindow::on_pushButton_16_clicked()
{
    this->loadDefaultPattern();
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    isPressed = true;
    this->setCursor(Qt::ClosedHandCursor);
    prevLocation.setX(event->pos().x());
    prevLocation.setY(event->pos().y());
    event->accept();
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if (isPressed == true)
    {
        double ax = (event->pos().x() - prevLocation.getX()) / cameraRotateStep;
        double ay = -(event->pos().y() - prevLocation.getY()) / cameraRotateStep;
        if (event->buttons() == Qt::LeftButton)
            cmd_list.addCommand(new RotateCommand(curScene, ay, ax, 0));
        else
        if (event->buttons() == Qt::RightButton)
            cmd_list.addCommand(new SetVelCommand(index, ax, ay, 0));
        this->redrawScene();
        prevLocation.setX(event->pos().x());
        prevLocation.setY(event->pos().y());
    }
    event->accept();
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    isPressed = false;
    this->setCursor(Qt::ArrowCursor);
    prevLocation.setX(event->pos().x());
    prevLocation.setY(event->pos().y());
    event->accept();
}


void MainWindow::wheelEvent(QWheelEvent *event)
{
    if (event->delta() > 0)
        cmd_list.addCommand(new ZoomCommand(curScene,1.1,1.1,1.1));
    else
        if (event->delta() < 0)
            cmd_list.addCommand(new ZoomCommand(curScene,0.9,0.9,0.9));

    this->redrawScene();
    event->accept();
}

void MainWindow::on_horizontalSlider_sliderMoved(int position)
{
    this->cameraRotateStep = (ui->horizontalSlider->maximum() - position)+1;
}

/*!
 * \brief MainWindow::on_mdl_move_idx_editingFinished
 * Апдейт индекса объекта
 */
void MainWindow::on_mdl_move_idx_editingFinished()
{
    int tmpIndex = ui->mdl_move_idx->text().toInt();

    if ((tmpIndex >= 0) && (tmpIndex <= facade.getLastIdx()))
        index = tmpIndex;
    else
        index = 0;
    ui->mdl_move_idx->setValue(index);
    cmd_list.addCommand(new SelectModelCommand(index));
    this->redrawScene();
}

/*!
 * \brief MainWindow::on_cam_move_idx_editingFinished
 * Апдейт индекса камеры
 */
void MainWindow::on_cam_move_idx_editingFinished()
{
    ui->cameras->selectICamera(ui->cam_move_idx->text().toInt());

    int tmpIndex = ui->cam_move_idx->text().toInt();

    if ((tmpIndex >= 0) && (tmpIndex <= ui->cameras->getScenes()->getElementsNumber() - 1))
        curScene = tmpIndex;
    else
        curScene = 0;
    ui->cam_move_idx->setValue(curScene);
    ui->cameras->selectICamera(curScene);
    this->redrawScene();
}

void MainWindow::on_checkBox_2_clicked()
{
    this->redrawScene();
}

/*!
 * \brief MainWindow::on_pushButton_17_clicked
 * Добавление источника света
 */
void MainWindow::on_pushButton_17_clicked()
{
    float _x = ui->doubleSpinBox->value();
    float _y = ui->doubleSpinBox_2->value();
    float _z = ui->doubleSpinBox_3->value();
    float _i = ui->doubleSpinBox_4->value();
    cmd_list.addCommand(new AddLightSource(_x, _y, _z, _i));
    this->redrawScene();
}

void MainWindow::on_force_out_rb_clicked()
{
    ui->force_in_rb->setChecked(0);
    ui->no_force_rb->setChecked(0);
    ForceBehavior f = ForceOut;
    cmd_list.addCommand(new SetForceBehaviorCommand(f));
    this->redrawScene();
}

void MainWindow::on_force_in_rb_clicked()
{
    ui->force_out_rb->setChecked(0);
    ui->no_force_rb->setChecked(0);
    ForceBehavior f = ForceIn;
    cmd_list.addCommand(new SetForceBehaviorCommand(f));
    this->redrawScene();
}

void MainWindow::on_no_force_rb_clicked()
{
    ui->force_in_rb->setChecked(0);
    ui->force_out_rb->setChecked(0);
    ForceBehavior f = NoForce;
    cmd_list.addCommand(new SetForceBehaviorCommand(f));
    this->redrawScene();
}


/// LIGHTSOURCE
void MainWindow::on_spinBox_editingFinished()
{
    int tmpIndex = ui->spinBox->value();

    if ((tmpIndex >= 0) && (tmpIndex <= facade.getLastLightSourceIdx()))
        lightSourceIdx = tmpIndex;
    else
        lightSourceIdx = 0;
    ui->spinBox->setValue(lightSourceIdx);
    cmd_list.addCommand(new SelectLightSourceCommand(lightSourceIdx));
    this->redrawScene();
}

void MainWindow::on_spinBox_valueChanged(int arg1)
{
    Q_UNUSED(arg1);
    this->on_spinBox_editingFinished();
}

///! LINK
void MainWindow::on_spinBox_5_editingFinished()
{
    int tmpIndex = ui->spinBox_5->value();

    if ((tmpIndex >= 0) && (tmpIndex <= facade.getLastLinkIdx()))
        linkIdx = tmpIndex;
    else
        linkIdx = 0;
    ui->spinBox_5->setValue(linkIdx);
    cmd_list.addCommand(new SelectLinkCommand(linkIdx));
    this->redrawScene();
}

///! Удаление источника света
void MainWindow::on_pushButton_30_clicked()
{
    cmd_list.addCommand(new DeleteLightSourceCommand(lightSourceIdx));
    this->redrawScene();
}

///! Удаление камеры!
void MainWindow::on_pushButton_26_clicked()
{
    cmd_list.addCommand(new DeleteICameraCommand(curScene));
    ui->cameras->deleteCamera(curScene);
    this->redrawScene();
}

///! Удаление объекта
void MainWindow::on_pushButton_27_clicked()
{
    cmd_list.addCommand(new DeleteCommand(index));
    this->redrawScene();
}

void MainWindow::on_spinBox_5_valueChanged(int arg1)
{
    Q_UNUSED(arg1);
    this->on_spinBox_5_editingFinished();
}

void MainWindow::setBGColor(QColor c)
{
    cmd_list.addCommand(new SetBGColorCommand(c));
    this->redrawScene();
}


// object Z-
void MainWindow::on_pushButton_6_clicked()
{
    cmd_list.addCommand(new MoveModelCommand(index,0,0,-1));
    this->redrawScene();
}
// object Y+
void MainWindow::on_pushButton_2_clicked()
{
    cmd_list.addCommand(new MoveModelCommand(index,0,1,0));
    this->redrawScene();
}
// object Z+
void MainWindow::on_pushButton_7_clicked()
{
    cmd_list.addCommand(new MoveModelCommand(index,0,0,1));
    this->redrawScene();
}
// object M+
void MainWindow::on_pushButton_24_clicked()
{
    cmd_list.addCommand(new ZoomModelCommand(index,1.1,1.1,1.1));
    this->redrawScene();
}
// object X-
void MainWindow::on_pushButton_5_clicked()
{
    cmd_list.addCommand(new MoveModelCommand(index,-1,0,0));
    this->redrawScene();
}
// object Y-
void MainWindow::on_pushButton_3_clicked()
{
    cmd_list.addCommand(new MoveModelCommand(index,0,-1,0));
    this->redrawScene();
}
// object X+
void MainWindow::on_pushButton_4_clicked()
{
    cmd_list.addCommand(new MoveModelCommand(index,1,0,0));
    this->redrawScene();
}
// object M-
void MainWindow::on_pushButton_25_clicked()
{
    cmd_list.addCommand(new ZoomModelCommand(index,0.9,0.9,0.9));
    this->redrawScene();
}


// cam Z-
void MainWindow::on_pushButton_14_clicked()
{
    cmd_list.addCommand(new MoveCommand(curScene,0,0,-1));
    this->redrawScene();
}
// cam Y+
void MainWindow::on_pushButton_13_clicked()
{
    cmd_list.addCommand(new MoveCommand(curScene,0,1,0));
    this->redrawScene();
}
// cam Z+
void MainWindow::on_pushButton_10_clicked()
{
    cmd_list.addCommand(new MoveCommand(curScene,0,0,1));
    this->redrawScene();
}
// cam X-
void MainWindow::on_pushButton_11_clicked()
{
    cmd_list.addCommand(new MoveCommand(curScene,-1,0,0));
    this->redrawScene();
}
// cam Y-
void MainWindow::on_pushButton_9_clicked()
{
    cmd_list.addCommand(new MoveCommand(curScene,0,-1,0));
    this->redrawScene();
}
// cam X+
void MainWindow::on_pushButton_12_clicked()
{
    cmd_list.addCommand(new MoveCommand(curScene,1,0,0));
    this->redrawScene();
}


// ls Z-
void MainWindow::on_pushButton_21_clicked()
{
    cmd_list.addCommand(new MoveLightSourceCommand(lightSourceIdx,0,0,-1));
    this->redrawScene();
}
// ls Y+
void MainWindow::on_pushButton_23_clicked()
{
    cmd_list.addCommand(new MoveLightSourceCommand(lightSourceIdx,0,1,0));
    this->redrawScene();
}
// ls Z+
void MainWindow::on_pushButton_20_clicked()
{
    cmd_list.addCommand(new MoveLightSourceCommand(lightSourceIdx,0,0,1));
    this->redrawScene();
}
// ls I+
void MainWindow::on_pushButton_28_clicked()
{
   // cmd_list.addCommand(new MoveLightSourceCommand(lightSourceIdx,0,0,-1));
    cmd_list.addCommand(new ChgIdxIntensityCommand(lightSourceIdx, 0.1));
    this->redrawScene();
}
// ls X-
void MainWindow::on_pushButton_18_clicked()
{
    cmd_list.addCommand(new MoveLightSourceCommand(lightSourceIdx,-1,0,0));
    this->redrawScene();
}
// ls Y-
void MainWindow::on_pushButton_19_clicked()
{
    cmd_list.addCommand(new MoveLightSourceCommand(lightSourceIdx,0,-1,0));
    this->redrawScene();
}
// ls X+
void MainWindow::on_pushButton_22_clicked()
{
    cmd_list.addCommand(new MoveLightSourceCommand(lightSourceIdx,1,0,0));
    this->redrawScene();
}
// ls I-
void MainWindow::on_pushButton_29_clicked()
{
   // cmd_list.addCommand(new MoveLightSourceCommand(lightSourceIdx,0,0,-1));
    cmd_list.addCommand(new ChgIdxIntensityCommand(lightSourceIdx, -0.1));
    this->redrawScene();
}

void MainWindow::on_mdl_move_idx_valueChanged(int arg1)
{
    Q_UNUSED(arg1);
    this->on_mdl_move_idx_editingFinished();
}

void MainWindow::on_cam_move_idx_valueChanged(int arg1)
{
    Q_UNUSED(arg1);
    this->on_cam_move_idx_editingFinished();
}
