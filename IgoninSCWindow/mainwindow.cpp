#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QString>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    table.resize(30);

    for (int i = 0; i < 30; i++)
    {
        for (int j = 0; j < 50; j++)
        {
            table[i].insert({to_string(j*10), to_string((i + j*10) * 5)});
        }
    }

    /*
    table[0].insert({"NAME", "name_111"});
    table[0].insert({"AGE", "11"});
    table[0].insert({"POCT", "111"});

    table[1].insert({"NAME", "name_222"});
    table[1].insert({"AGE", "12"});
    table[1].insert({"POCT", "122"});
    table[1].insert({"JOB", "govno4ist"});

    table[2].insert({"NAME", "name_333"});
    table[2].insert({"AGE", "13"});
    table[2].insert({"POCT", "133"});
    table[2].insert({"HOBBY", "fishing"});

    table[3].insert({"NAME", "name_444"});
    table[3].insert({"AGE", "14"});
    table[3].insert({"POCT", "144"});
    table[3].insert({"JOB", "miner"});
    table[3].insert({"HOBBY", "mine"});
    */
}

MainWindow::~MainWindow()
{
    forest.Clear();
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter* painter = new QPainter(this);

    if (tableParams.rows == 0)
    {
        getTableSize(*painter);
    }

    paintTable(*painter);

    delete painter;
}

void MainWindow::getTableSize(QPainter& painter)
{
    int rows = 0; // кол-во строк
    rows = table.size();
    int rowHeight = painter.fontMetrics().height() + mergeHeight;

    unordered_map<string, int> widths; // кол-во и размеры столбцов
    vector<string> head;
    int columns = 0;
    int ggg = 0;
    for (auto tableRow : table)
    {
        for (auto cell : tableRow)
        {
            int headWidth = painter.fontMetrics().horizontalAdvance(QString("").fromStdString(cell.first));
            int cellWidth = painter.fontMetrics().horizontalAdvance(QString("").fromStdString(cell.second));
            ++columns;
            //debug
            QString key = QString("").fromStdString(cell.first);
            painter.drawText(columns * 60 + 50, 200 + ggg*30, key);
            //
            bool newHead = true;
            for (string columnHead : head)
                if (columnHead.find(cell.first) != string::npos)
                {
                    newHead = false;
                    break;
                }

            if (newHead)
            {
                widths.insert({cell.first, headWidth + mergeWidth});
                head.push_back(cell.first);
            }
            if (widths[cell.first] < cellWidth + mergeWidth)
                widths[cell.first] = cellWidth + mergeWidth;

        }
        columns = 0;
        ggg++;
    }

    tableParams.rows = rows;
    tableParams.rowHeight = rowHeight;
    tableParams.columnWidths = widths;
    tableParams.head = head;

    setScrolls();
}

pair<int, int> MainWindow::viewTableSize()
{
    int winHeight = this->height() - scrollBarSize;
    int winWidth = this->width() - scrollBarSize;
    pair<int, int> viewTableParams;
    viewTableParams.first = winHeight / tableParams.rowHeight; // window_height div font_height
    viewTableParams.second = winWidth;
    return viewTableParams;
}

void MainWindow::setScrolls()
{
    int winHeight = this->height() - scrollBarSize;
    int winWidth = this->width() - scrollBarSize;
    ui->horizontalScrollBar->setGeometry(0, winHeight, winWidth, scrollBarSize);
    ui->verticalScrollBar->setGeometry(winWidth, 0, scrollBarSize, winHeight);

    int width = 0;
    for (pair<string, int> columnWidth : tableParams.columnWidths){
        width += columnWidth.second;
    }
    int height = tableParams.rows;

    if (width - winWidth <= 0) {
        ui->horizontalScrollBar->setDisabled(true);
        ui->horizontalScrollBar->setVisible(false);
    }
    else {
        ui->horizontalScrollBar->setMaximum(width - winWidth);
        ui->horizontalScrollBar->setMinimum(0);
    }
    if (height - winHeight / tableParams.rowHeight + upperMerge <= 0) {
        ui->verticalScrollBar->setDisabled(true);
        ui->verticalScrollBar->setVisible(false);
    }
    else {
        ui->verticalScrollBar->setMaximum(height - winHeight / tableParams.rowHeight + upperMerge);
        ui->verticalScrollBar->setMinimum(upperMerge);
    }

    startPos = {0, upperMerge};
}

void MainWindow::paintTable(QPainter& painter)
{
    // table, tableParams, viewTableSize(pair int), ui ScrollBars values
    int rowsCnt = (this->height() - scrollBarSize) / tableParams.rowHeight;
    pair<int, int> leftRightInx = {ui->verticalScrollBar->value(), ui->verticalScrollBar->value() + this->width() - scrollBarSize};
    pair<int, int> topDownInx = {ui->horizontalScrollBar->value(), ui->horizontalScrollBar->value() + rowsCnt};

    pair<int, int> pos = startPos;
    for (int inx = 0; inx < tableParams.head.size(); inx++)
    {
        QString columnHead = QString("").fromStdString(tableParams.head[inx]);
        //painter.drawText(pos.first, pos.second, columnHead);
        for (auto row : table)
        {
            pos.second += tableParams.rowHeight;
            if (row.find(tableParams.head[inx]) != row.end())
            {
                QString cell = QString("").fromStdString(row[tableParams.head[inx]]);
                painter.drawText(pos.first, pos.second, cell);
            }
            else
                painter.drawText(pos.first, pos.second, "---");
        }
        pos.second = startPos.second;
        pos.first += tableParams.columnWidths[tableParams.head[inx]];
    }
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

void MainWindow::resizeEvent(QResizeEvent* event)
{
    QMainWindow::resizeEvent(event);
    if (tableParams.rows != 0)
        setScrolls();
}


void MainWindow::on_verticalScrollBar_valueChanged(int value)
{
    if (value != ui->verticalScrollBar->maximum() && value != ui->verticalScrollBar->minimum())
    {
        startPos.second = -value * tableParams.rowHeight;
        repaint();
    }
}


void MainWindow::on_horizontalScrollBar_valueChanged(int value)
{
    if (value != ui->horizontalScrollBar->maximum() && value != ui->verticalScrollBar->minimum())
    {
        startPos.first = -value;
        repaint();
    }
}

