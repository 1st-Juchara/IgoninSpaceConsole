#ifndef FILEDIALOG_H
#define FILEDIALOG_H

#include <QDialog>
#include <QPainter>
#include <QTimer>
#include <QKeyEvent>
#include <QGridLayout>
#include "IgoninForest.h"

namespace Ui {
class FileDialog;
}

class FileDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FileDialog(QWidget *parent = nullptr);
    ~FileDialog();
    void PaintEvent(QPaintEvent* m);
    QBrush brushOne = QBrush("#DDD");
    QBrush brushTwo = QBrush("#777");
    QBrush brushSub = QBrush("#000000");
    int textHeight = 25;
    QString file = "";
private:
    Ui::FileDialog *ui;
    void paintEvent(QPaintEvent*);
    QGridLayout* myLayout;

private slots:
    void on_verticalScrollBar_valueChanged(int value);
    void on_fileSpinBox_valueChanged(int arg1);
    void on_buttonLoad_clicked();
};

#endif // FILEDIALOG_H
