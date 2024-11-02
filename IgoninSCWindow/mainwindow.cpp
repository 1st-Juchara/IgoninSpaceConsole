#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QString>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    forest.Clear();
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter* painter = new QPainter(this);
    //paint animals
    //vector<map<string, string>> data_list = forest.GetAnimals();
    /*
     * не тут ошибо4ка
    for (auto data : data_list)
        for (auto param : data)
        {
            //QString message = QString("").fromStdString(param.first + ": " + param.second);
            //QString message = "00";
            //painter->drawText(50, 50, message);
        }
    */
    delete painter;
}


void MainWindow::on_ButtonMenuFile_triggered()
{
    //file menu
    /*
    QVector<QString> fileNames;
    for (string fileName : getFiles("Saves"))
        fileNames.push_back(QString("").fromStdString(fileName));
    if (fileNames.empty())
        fileNames.push_back("folder is empty");
    */
    d.show();
}


void MainWindow::on_ButtonMenuForest_triggered()
{
    repaint();
}

