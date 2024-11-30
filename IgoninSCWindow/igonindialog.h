#ifndef IGONINDIALOG_H
#define IGONINDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include <QListWidgetItem>
#include "IgoninForest.h"

//using namespace std;

namespace Ui {
class IgoninDialog;
}

class IgoninDialog : public QDialog
{
    Q_OBJECT

public:
    explicit IgoninDialog(QWidget *parent = nullptr);
    void inputTable(std::vector<std::unordered_map<std::string, std::string>>& table);
    void inputForest(IgoninForest& forest);
    ~IgoninDialog();
    void closeEvent(QCloseEvent *) override {
        emit requestRepaint();  // Отправляем сигнал о необходимости перерисовки
    }

signals:
    void requestRepaint();

private slots:

    void on_listWidgetAnimal_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);

    void on_buttonChangeAnimal_clicked();
    void on_buttonAddAnimal_clicked();

    void on_buttonComplete_clicked();

private:
    void viewObjectAttributes();
    std::vector<std::unordered_map<std::string, std::string>>* table;
    IgoninForest* forest;
    int inx = -1;
    Ui::IgoninDialog *ui;

    bool checkFields();

    void GetFields();

    void updateTable();

    void clearFields(std::string);


};

#endif // IGONINDIALOG_H
