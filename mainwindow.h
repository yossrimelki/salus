#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "mission.h"
#include "points.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_ajouter_clicked();

    void on_pushButton_2_clicked();

    void on_miseajour_clicked();

    void on_refresh_clicked();

    void on_pb_AJOUTER_clicked();

    void on_pbsupp_clicked();

    void on_pb_tri_clicked();

private:
    Ui::MainWindow *ui;
    Mission Mtmp;
    points Ptmp;
};
#endif // MAINWINDOW_H
