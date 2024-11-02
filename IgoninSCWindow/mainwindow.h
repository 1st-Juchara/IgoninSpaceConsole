#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#pragma once
#include <QMainWindow>
#include <QPainter>
#include <QTimer>
#include <QKeyEvent>
#include <QGridLayout>
#include "filedialog.h"
#include "IgoninForest.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void PaintEvent(QPaintEvent* m);
    IgoninForest forest;

private:
    Ui::MainWindow *ui;
    void paintEvent(QPaintEvent*);
    QGridLayout* myLayout;
    FileDialog d;

private slots:

    void on_ButtonMenuFile_triggered();

    void on_ButtonMenuForest_triggered();

};
#endif // MAINWINDOW_H
