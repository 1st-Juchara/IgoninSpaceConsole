#include "igonindialog.h"
#include "ui_igonindialog.h"


using namespace std;

IgoninDialog::IgoninDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::IgoninDialog)
{
    ui->setupUi(this);

    ui->listBoxColor->addItem("");
    for (string color : IgoninAnimal::animalColors)
        ui->listBoxColor->addItem(QString::fromStdString(color));

    ui->listBoxNutrition->addItem("");
    for (string nutrition : IgoninAnimal::nutritionTypes)
        ui->listBoxNutrition->addItem(QString::fromStdString(nutrition));

    ui->buttonComplete->setVisible(false);
    ui->buttonComplete->setDisabled(true);
}

void IgoninDialog::inputTable(vector<unordered_map<string, string>>& table)
{
    this->table = &table;
    updateTable();
}

void IgoninDialog::inputForest(IgoninForest &forest)
{
    this->forest = &forest;
}

IgoninDialog::~IgoninDialog()
{
    delete ui;
}

void IgoninDialog::on_listWidgetAnimal_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
    if (previous)
    {
        inx = current->listWidget()->currentRow();
        viewObjectAttributes();
    }
}
void IgoninDialog::viewObjectAttributes()
{
    if (inx >= 0)
    {
        ui->textEditName->setPlainText(QString::fromLocal8Bit((*table)[inx]["Имя"]));
        ui->textEditAge->setPlainText(QString::fromLocal8Bit((*table)[inx]["Возраст"]));
        ui->textEditWeight->setPlainText(QString::fromLocal8Bit((*table)[inx]["Вес"]));

        string color = IgoninAnimal::animalColors[stoi((*table)[inx]["Цвет"])];
        ui->listBoxColor->setCurrentText(QString::fromStdString(color));
        string nutrition = IgoninAnimal::nutritionTypes[stoi((*table)[inx]["Тип питания"])];
        ui->listBoxNutrition->setCurrentText(QString::fromStdString(nutrition));

        if (!((*table)[inx].find("Ядовитость") == (*table)[inx].end()))
        {
            ui->label_6->setVisible(true);
            ui->checkBoxPoisonous->setDisabled(false);
            ui->checkBoxPoisonous->setVisible(true);
            ui->checkBoxPoisonous->setCheckState(Qt::CheckState((*table)[inx]["Ядовитость"] == "ядовито"));
            ui->label_7->setVisible(true);
            ui->textEditTail->setDisabled(false);
            ui->textEditTail->setVisible(true);
            ui->textEditTail->setPlainText(QString::fromLocal8Bit((*table)[inx]["Длина хвоста"]));
        }
        else
        {
            ui->label_6->setVisible(false);
            ui->checkBoxPoisonous->setDisabled(true);
            ui->checkBoxPoisonous->setVisible(false);
            ui->label_7->setVisible(false);
            ui->textEditTail->setDisabled(true);
            ui->textEditTail->setVisible(false);

        }
    }
}


void IgoninDialog::on_buttonChangeAnimal_clicked()
{
    if (inx >= 0)
    {
        (*table)[inx]["Имя"] = ui->textEditName->toPlainText().toLocal8Bit();
        (*table)[inx]["Возраст"] = ui->textEditAge->toPlainText().toStdString();
        (*table)[inx]["Вес"] = ui->textEditWeight->toPlainText().toStdString();

        if (ui->listBoxColor->currentIndex() > 0)
            (*table)[inx]["Цвет"] = to_string(ui->listBoxColor->currentIndex() - 1);

        if (ui->listBoxNutrition->currentIndex() > 0)
            (*table)[inx]["Тип питания"] = to_string(ui->listBoxNutrition->currentIndex() - 1);


        if (!((*table)[inx].find("Ядовитость") == (*table)[inx].end()))
        {
            if (ui->checkBoxPoisonous->checkState())
                (*table)[inx]["Ядовитость"] = "ядовито";
            else
                (*table)[inx]["Ядовитость"] = "не ядовито";

            (*table)[inx]["Длина хвоста"] = ui->textEditTail->toPlainText().toStdString();
        }

        if (inx > ui->listWidgetAnimal->count() - 1)
        forest->changeAnimalMap(inx, (*table)[inx]);
        updateTable();
    }
}

void IgoninDialog::updateTable()
{
    bool oldState = ui->listWidgetAnimal->blockSignals(true);
    ui->listWidgetAnimal->clear();
    ui->listWidgetAnimal->blockSignals(oldState);
    for (auto row : *this->table)
    {
        QString rowText = QString::fromStdString(row["id"] + ")").leftJustified(10, ' ')  + QString::fromLocal8Bit(row["Имя"]);
        ui->listWidgetAnimal->addItem(rowText);
    }
}

void IgoninDialog::clearFields(string newObj)
{
    ui->textEditName->setPlainText("");
    ui->textEditAge->setPlainText("");
    ui->textEditWeight->setPlainText("");

    ui->listBoxColor->setCurrentText("");
    ui->listBoxNutrition->setCurrentText("");

    if (newObj == "reptile")
    {
        ui->label_6->setVisible(true);
        ui->checkBoxPoisonous->setDisabled(false);
        ui->checkBoxPoisonous->setVisible(true);
        ui->checkBoxPoisonous->setCheckState(Qt::CheckState(false));
        ui->label_7->setVisible(true);
        ui->textEditTail->setDisabled(false);
        ui->textEditTail->setVisible(true);
        ui->textEditTail->setPlainText("");
    }
    else
    {
        ui->label_6->setVisible(false);
        ui->checkBoxPoisonous->setDisabled(true);
        ui->checkBoxPoisonous->setVisible(false);
        ui->label_7->setVisible(false);
        ui->textEditTail->setDisabled(true);
        ui->textEditTail->setVisible(false);

    }


}


void IgoninDialog::on_buttonAddAnimal_clicked()
{
    string newObj = "reptile";
    QMessageBox msgBox;
    msgBox.setText("Кого добавить?");
    msgBox.addButton("Рептилию", QMessageBox::NoRole);
    msgBox.addButton("Животное", QMessageBox::YesRole);
    auto reply = msgBox.exec();
    if (reply == 3)
        newObj = "animal";

    clearFields(newObj);

    ui->buttonComplete->setVisible(true);
    ui->buttonComplete->setDisabled(false);

}


void IgoninDialog::on_buttonComplete_clicked()
{
    bool allRight = checkFields();
    if (allRight)
    {
        GetFields();
    }

    updateTable();
        // add animal
}

bool IgoninDialog::checkFields()
{
    try
    {
        stoi(ui->textEditAge->toPlainText().toStdString());
        stoi(ui->textEditWeight->toPlainText().toStdString());
        if (ui->label_6->isVisible())
            stoi(ui->textEditTail->toPlainText().toStdString());
    } catch (...)
    {
        QMessageBox message;
        message.setWindowTitle("ERROR");
        message.setText("Введите корректные числа!");
        message.show();
        return false;
    }

    if (ui->listBoxColor->currentIndex() <= 0)
    {
        QMessageBox message;
        message.setWindowTitle("ERROR");
        message.setText("Выберите цвет!");
        message.show();
        return false;
    }

    if (ui->listBoxNutrition->currentIndex() <= 0)
    {
        QMessageBox message;
        message.setWindowTitle("ERROR");
        message.setText("Выберите тип питания!");
        message.show();
        return false;
    }

    return true;
}

void IgoninDialog::GetFields()
{
    unordered_map<string, string> newTableObj;

    newTableObj.insert({"Имя", ui->textEditName->toPlainText().toStdString()});
    newTableObj.insert({"Возраст", ui->textEditAge->toPlainText().toStdString()});
    newTableObj.insert({"Вес", ui->textEditWeight->toPlainText().toStdString()});

    newTableObj.insert({"Цвет", to_string(ui->listBoxColor->currentIndex() - 1)});

    newTableObj.insert({"Тип питания", to_string(ui->listBoxNutrition->currentIndex() - 1)});


    if (ui->label_6->isVisible())
    {
        if (ui->checkBoxPoisonous->checkState())
            newTableObj.insert({"Ядовитость", "ядовито"});
        else
            newTableObj.insert({"Ядовитость", "не ядовито"});

        newTableObj.insert({"Длина хвоста", ui->textEditTail->toPlainText().toStdString()});

    }

    inx = table->size() - 1;
    table->push_back(newTableObj);

    if (ui->label_6->isVisible())
        forest->addReptileMap((*table)[inx]);
}

