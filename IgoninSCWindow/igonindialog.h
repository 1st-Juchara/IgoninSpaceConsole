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
        clearFields();
        toViewMode();
        inx = -1;
    }

signals:
    void requestRepaint();

private slots:

    void on_listWidgetAnimal_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);

    void on_buttonChangeAnimal_clicked();
    void on_buttonAddAnimal_clicked();

    void on_buttonComplete_clicked();

    void on_buttonHaram_clicked();

    void on_buttonCloseDialog_clicked();

    void on_buttonDeleteAnimal_clicked();

private:

    enum objectTypes {
        animal = 0,
        reptile = 1
    };

    void viewObjectAttributes();
    std::vector<std::unordered_map<std::string, std::string>>* table;
    IgoninForest* forest;
    int inx = -1;
    Ui::IgoninDialog *ui;

    bool checkFields();

    unordered_map<string, string> GetFields();

    void updateTable();

    void clearFields();

    void setObjType(objectTypes objType);

    void setFieldsDisabled(bool disabledState);

    void toViewMode();

    void toAddMode();

    void toChangeMode();

};

#endif // IGONINDIALOG_H
