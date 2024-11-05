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
using namespace std;

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
    //NEW! draw table
    struct TableParams{
        int rows = 0;
        int rowHeight = 0;
        unordered_map<string, int> columnWidths;
        vector<string> head;
    };

    vector<unordered_map<string, string>> table;
    TableParams tableParams;

    pair<int, int> startPos = {0, 30};
    int mergeWidth = 20;
    int mergeHeight = 10;
    int scrollBarSize = 20;
    int upperMerge = 2;

    void getTableSize(QPainter& painter);
    pair<int, int> viewTableSize();
    void setScrolls();
    void paintTable(QPainter& painter);
    //

private slots:

    void on_ButtonMenuFile_triggered();

    void on_ButtonMenuForest_triggered();
    void resizeEvent(QResizeEvent* event);
    void on_verticalScrollBar_valueChanged(int value);
    void on_horizontalScrollBar_valueChanged(int value);
};
#endif // MAINWINDOW_H
