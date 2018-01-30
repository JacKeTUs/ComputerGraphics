#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include <QKeyEvent>

#include "Singleton/Singleton.h"
#include "Facade/AdapterFacade.h"
#include "Command/MacroCommand.h"
#include "Draw/DrawArray.h"
#include "./Widget/CameraBox.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();



private slots:
    void getFileName();
    void Help();

    void on_pushButton_clicked();

    void on_action_triggered();

    void redrawScene();

    void on_adding_link_clicked();

    void on_sim_start_clicked();

    void timerEvent(QTimerEvent *event);
    void loadDefaultPattern();

    void on_pushButton_8_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_16_clicked();

    void setTempColor(QColor);

    void setBGColor(QColor);

    void on_horizontalSlider_sliderMoved(int position);

    void on_mdl_move_idx_editingFinished();

    void on_cam_move_idx_editingFinished();

    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent *event);

    void on_checkBox_2_clicked();

    void on_pushButton_17_clicked();

    void on_force_out_rb_clicked();

    void on_force_in_rb_clicked();

    void on_no_force_rb_clicked();

    void on_spinBox_editingFinished();

    void on_spinBox_valueChanged(int arg1);

    void on_spinBox_5_editingFinished();

    void on_pushButton_30_clicked();

    void on_pushButton_26_clicked();

    void on_pushButton_27_clicked();

    void on_spinBox_5_valueChanged(int arg1);

    void on_pushButton_6_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_24_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_25_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_21_clicked();

    void on_pushButton_23_clicked();

    void on_pushButton_20_clicked();

    void on_pushButton_28_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_22_clicked();

    void on_pushButton_29_clicked();

    void on_mdl_move_idx_valueChanged(int arg1);

    void on_cam_move_idx_valueChanged(int arg1);

private:
    Ui::MainWindow *ui;
    int timerId;
    int index;
    int lightSourceIdx;
    int linkIdx;
    QColor tmpColor;

    bool isPressed;
    Point prevLocation;
    double cameraRotateStep;
    int curScene;

public:
    void keyPressEvent(QKeyEvent*);
    void addCamera();
};

#endif // MAINWINDOW_H
