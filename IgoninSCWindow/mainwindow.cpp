#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QString>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //table.resize(30);

    //for (int i = 0; i < 30; i++)
    //{
    //    for (int j = 0; j < 50; j++)
    //    {
    //        table[i].insert({to_string(j*10), to_string((i + j*10) * 5)});
    //    }
    //}
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
            //QString key = QString("").fromStdString(cell.first);
            //painter.drawText(columns * 60 + 50, 200 + ggg*30, key);
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

void MainWindow::setScrolls()
{
    int winHeight = this->height();
    int winWidth = this->width();
    ui->horizontalScrollBar->setGeometry(0, winHeight - scrollBarSize*2, winWidth - scrollBarSize, scrollBarSize);
    ui->verticalScrollBar->setGeometry(winWidth - scrollBarSize, 0, scrollBarSize, winHeight - scrollBarSize*2);
    ui->pushButton->setGeometry(winWidth - scrollBarSize, winHeight - scrollBarSize*2, scrollBarSize, scrollBarSize);

    int width = scrollBarSize;
    for (pair<string, int> columnWidth : tableParams.columnWidths){
        width += columnWidth.second;
    }
    int height = tableParams.rows * tableParams.rowHeight + scrollBarSize + upperMerge;

    //qDebug() << QString::number(width) << " : " << QString::number(height);

    if (width - winWidth + mergeWidth <= 0) {
        ui->horizontalScrollBar->setDisabled(true);
        ui->horizontalScrollBar->setVisible(false);
        ui->pushButton->setVisible(false);
    }
    else {
        ui->horizontalScrollBar->setDisabled(false);
        ui->horizontalScrollBar->setVisible(true);
        ui->pushButton->setVisible(true);
        ui->horizontalScrollBar->setMaximum(int(sqrt(width - winWidth + mergeWidth)) + 1);
        ui->horizontalScrollBar->setMinimum(0);
        startPos.first = ui->horizontalScrollBar->value() + mergeWidth;
    }
    if (height - winHeight + scrollBarSize <= 0) {
        ui->verticalScrollBar->setDisabled(true);
        ui->verticalScrollBar->setVisible(false);
        ui->pushButton->setVisible(false);
    }
    else {
        ui->verticalScrollBar->setDisabled(false);
        ui->verticalScrollBar->setVisible(true);
        ui->pushButton->setVisible(true);
        ui->verticalScrollBar->setMaximum((height - winHeight + scrollBarSize) / tableParams.rowHeight + 1);
        ui->verticalScrollBar->setMinimum(0);
        startPos.second = ui->verticalScrollBar->value() + upperMerge;
    }
}

void MainWindow::paintTable(QPainter& painter)
{
    auto drawTextFunc = static_cast<void (QPainter::*)(int, int, const QString&)>(&QPainter::drawText);
    auto drawCell = std::bind(drawTextFunc, &painter, placeholders::_1, placeholders::_2, placeholders::_3);

    pair<int, int> pos = startPos;
    for (int inx = 0; inx < tableParams.head.size(); inx++)
    {
        QString columnHead = QString("").fromStdString(tableParams.head[inx]);
        drawCell(pos.first, pos.second, columnHead);
        painter.drawLine(pos.first - mergeWidth / 2, pos.second, pos.first - mergeWidth / 2,
                         pos.second + tableParams.rowHeight*tableParams.rows);
        painter.drawLine(pos.first + tableParams.columnWidths[tableParams.head[inx]] - mergeWidth / 2, pos.second,
                         pos.first + tableParams.columnWidths[tableParams.head[inx]] - mergeWidth / 2, pos.second + tableParams.rowHeight*tableParams.rows);

        for (auto row : table)
        {
            pos.second += tableParams.rowHeight;
            if (row.find(tableParams.head[inx]) != row.end())
            {
                QString cell;
                if (tableParams.head[inx].compare("Имя") == 0)
                    cell = QString("").fromLocal8Bit(row[tableParams.head[inx]].c_str());
                else
                    cell = QString("").fromStdString(row[tableParams.head[inx]].c_str());
                drawCell(pos.first, pos.second, cell);
            }
            else
                drawCell(pos.first, pos.second, "---");
        }
        pos.second = startPos.second;
        pos.first += tableParams.columnWidths[tableParams.head[inx]];
    }

    painter.drawLine(startPos.first - mergeWidth / 2, startPos.second + mergeHeight / 2,
                     pos.first - mergeWidth / 2, startPos.second + mergeHeight / 2);
}

void MainWindow::clearTable()
{
    table.clear();
    forest.Clear();
    tableParams = TableParams();
}

void MainWindow::on_ButtonMenuFile_triggered()
{
    QString filename = QFileDialog::getOpenFileName(nullptr, "Открыть файл", "Saves", "Все Файлы (*)");
    if (filename.isEmpty()) {
        return;
    }

    string convertedFilename = filename.toStdString();

    string message = forest.Load(convertedFilename);
    if (message.empty())
    {
        table = forest.GetAnimals();
        QMessageBox::information(nullptr, "Успех", "Загрузка удалась");
    }
    else
    {
        QMessageBox::information(nullptr, "Ошибка", QString("").fromStdString(message));
    }

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
    startPos.second = -value * tableParams.rowHeight + upperMerge;
    repaint();
}


void MainWindow::on_horizontalScrollBar_valueChanged(int value)
{
    startPos.first = -value*value  + mergeWidth;
    repaint();
}


void MainWindow::on_ButtonMenuSave_triggered()
{
    if (forest.IsAnimalsEmpty()) {
        QMessageBox::information(nullptr, "Ошибка", "Лес пуст...");
        return;
    }

    QString filename = QFileDialog::getSaveFileName(nullptr, "Сохранить файл", "Saves", "Все Файлы (*)");
    if (filename.isEmpty()) {
        return;
    }

    string convertedFilename = filename.toStdString();

    string message = forest.Save(convertedFilename);

    if (message.empty())
    {
        QMessageBox::information(nullptr, "Успех", "Лес сохранён");
    }
    else
    {
        QMessageBox::information(nullptr, "Ошибка", QString("").fromStdString(message));
    }
}


void MainWindow::on_ButtonMenuClear_triggered()
{
    clearTable();
    repaint();
}


void MainWindow::on_pushButton_clicked()
{

    ui->verticalScrollBar->setValue(ui->verticalScrollBar->maximum() / 2);
    ui->horizontalScrollBar->setValue(ui->horizontalScrollBar->maximum() / 2);
    repaint();

}

