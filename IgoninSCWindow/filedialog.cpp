#include "filedialog.h"
#include "ui_filedialog.h"

FileDialog::FileDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::FileDialog)
{
    ui->setupUi(this);
    QPalette p = this->palette();
    p.setColor(this->backgroundRole(), brushTwo.color());
    this->setPalette(p);
}

FileDialog::~FileDialog()
{
    delete ui;
}

void FileDialog::paintEvent(QPaintEvent *)
{
    QPainter* painter = new QPainter(this);
    //painter->drawText(50, 50, "Message in progress");

    int winWidth = this->width();
    int winHeight = this->height();

    QVector<QString> fileNames;
    for (string fileName : getFiles("Saves"))
        fileNames.push_back(QString("").fromStdString(fileName));
    if (fileNames.empty())
        fileNames.push_back("folder is empty");

    painter->setBrush(brushOne);
    painter->drawRect(winWidth / 20, winHeight / 12, winWidth / 20 * 18, winHeight / 12 * 10);
    int rows_cnt = winHeight / 2 / textHeight;

    ui->verticalScrollBar->setMinimum(0);

    if (fileNames.size() <= rows_cnt)
        ui->verticalScrollBar->setMaximum(0);

    ui->verticalScrollBar->setMaximum(fileNames.length() - rows_cnt);

    if ((ui->fileSpinBox->value() > 0) && (ui->fileSpinBox->value() <= ui->verticalScrollBar->value()))
    {
        delete painter;
        ui->verticalScrollBar->setValue(ui->fileSpinBox->value() - 1);
        return;
    }
    else if ((ui->fileSpinBox->value() < fileNames.size()) && (ui->fileSpinBox->value() > ui->verticalScrollBar->value() + rows_cnt - 1))
    {
        delete painter;
        ui->verticalScrollBar->setValue(ui->fileSpinBox->value() - rows_cnt + 1);
        return;
    }

    int min_inx = ui->verticalScrollBar->value();
    int max_inx = min_inx + rows_cnt - 1;

    painter->setPen(brushSub.color());

    for (int inx = min_inx; inx <= max_inx; ++inx)
    {
        int textX = winWidth / 20;
        int textY = winHeight / 12 * (inx - min_inx + 2);
        if (inx + 1 == ui->fileSpinBox->value()) //draw select
        {
            painter->setBrush(QBrush("#DFD"));
            painter->drawRect(textX, textY - textHeight, winWidth / 20 * 18, textHeight);
        }
        if (fileNames[inx].size() > 30)
            painter->drawText(textX, textY - 2, QString("%1. ").arg(inx + 1) + fileNames[inx].mid(0, 15) + "..." + fileNames[inx].mid(14, 15));
        else
            painter->drawText(textX, textY - 2, QString("%1. ").arg(inx + 1) + fileNames[inx]);
    }

    delete painter;
}


void FileDialog::on_verticalScrollBar_valueChanged(int value)
{
    repaint();
}



void FileDialog::on_fileSpinBox_valueChanged(int arg1)
{
    repaint();
}



void FileDialog::on_buttonLoad_clicked()
{

}

