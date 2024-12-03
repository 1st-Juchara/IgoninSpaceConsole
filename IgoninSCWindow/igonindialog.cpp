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

    //inx = 0;
    viewObjectAttributes();
    toViewMode();
}

void IgoninDialog::inputTable(vector<unordered_map<string, string>>& table)
{
    this->table = &table;
    inx = this->table->size() - 1;
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
        if (!((*table)[inx].find("Ядовитость") == (*table)[inx].end())) // проверка животное это или рептилия
        {
            setObjType(objectTypes::reptile);
            ui->checkBoxPoisonous->setCheckState(Qt::CheckState((*table)[inx]["Ядовитость"] == "ядовито"));
            ui->textEditTail->setPlainText(QString::fromLocal8Bit((*table)[inx]["Длина хвоста"]));
        }
        else
            setObjType(objectTypes::animal);

        ui->textEditName->setPlainText(QString::fromLocal8Bit((*table)[inx]["Имя"].c_str()));
        ui->textEditAge->setPlainText(QString::fromLocal8Bit((*table)[inx]["Возраст"]));
        ui->textEditWeight->setPlainText(QString::fromLocal8Bit((*table)[inx]["Вес"]));

        string color = IgoninAnimal::animalColors[stoi((*table)[inx]["Цвет"])];
        ui->listBoxColor->setCurrentText(QString::fromStdString(color));
        string nutrition = IgoninAnimal::nutritionTypes[stoi((*table)[inx]["Тип питания"])];
        ui->listBoxNutrition->setCurrentText(QString::fromStdString(nutrition));
    }
}

void IgoninDialog::on_buttonChangeAnimal_clicked()
{
    if (inx >= 0)
    {
        toChangeMode();
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
        QString rowText = QString::fromStdString(row["id"] + ")").leftJustified(10, ' ')  + QString::fromLocal8Bit(row["Имя"].c_str());
        ui->listWidgetAnimal->addItem(rowText);
    }
    if (inx >= 0)
    {
        ui->listWidgetAnimal->setCurrentRow(inx);
        viewObjectAttributes();
    }
}

void IgoninDialog::clearFields()
{
    ui->textEditName->setPlainText("");
    ui->textEditAge->setPlainText("");
    ui->textEditWeight->setPlainText("");

    ui->listBoxColor->setCurrentText("");
    ui->listBoxNutrition->setCurrentText("");

    ui->checkBoxPoisonous->setCheckState(Qt::CheckState(false));
    ui->textEditTail->setPlainText("");

}

void IgoninDialog::setObjType(objectTypes objType)
{
    if (objType == objectTypes::animal)
    {
        ui->label_6->setVisible(false);
        ui->checkBoxPoisonous->setVisible(false);
        ui->label_7->setVisible(false);
        ui->textEditTail->setVisible(false);
    }
    else
    {
        ui->label_6->setVisible(true);
        ui->checkBoxPoisonous->setVisible(true);
        ui->label_7->setVisible(true);
        ui->textEditTail->setVisible(true);
    }
}

void IgoninDialog::setFieldsDisabled(bool disabledState)
{
    ui->textEditName->setDisabled(disabledState);
    ui->textEditAge->setDisabled(disabledState);
    ui->textEditWeight->setDisabled(disabledState);
    ui->listBoxColor->setDisabled(disabledState);
    ui->listBoxNutrition->setDisabled(disabledState);

    ui->checkBoxPoisonous->setDisabled(disabledState);
    ui->textEditTail->setDisabled(disabledState);
}

void IgoninDialog::toViewMode()
{
    setFieldsDisabled(true);
    ui->listWidgetAnimal->setDisabled(false);
    ui->buttonComplete->setVisible(false);
    ui->buttonHaram->setVisible(false);
}

void IgoninDialog::toAddMode()
{
    clearFields();
    setFieldsDisabled(false);
    ui->buttonComplete->setVisible(true);
    ui->buttonHaram->setVisible(true);
    ui->listWidgetAnimal->setDisabled(true);
}

void IgoninDialog::toChangeMode()
{
    setFieldsDisabled(false);
    ui->buttonComplete->setVisible(true);
    ui->buttonHaram->setVisible(true);
    ui->listWidgetAnimal->setDisabled(false);
}


void IgoninDialog::on_buttonAddAnimal_clicked()
{
    //TODO: Close dialog - do not clear fields and show complete button
    QMessageBox msgBox;
    msgBox.setText("Кого добавить?");
    msgBox.addButton("Рептилию", QMessageBox::NoRole);
    msgBox.addButton("Животное", QMessageBox::YesRole);
    auto reply = msgBox.exec();
    if (reply == 3)
    {
        toAddMode();
        setObjType(objectTypes::animal);
    }
    else if (reply == 2)
    {
        toAddMode();
        setObjType(objectTypes::reptile);
    }
    else
    {
        toAddMode();
    }

}


void IgoninDialog::on_buttonComplete_clicked()
{
    bool allRight = checkFields();
    if (allRight)
    {
        unordered_map<string, string> newTableObj = GetFields();

        if (!ui->listWidgetAnimal->isEnabled())
        {
            if (table->size() == 0)
                newTableObj.insert({"id", "1"});
            else
                newTableObj.insert({"id", to_string(stoi((*table)[table->size() - 1]["id"]) + 1)});
            table->push_back(newTableObj);
            if (ui->label_6->isVisible())
                forest->addReptileMap(newTableObj);
            else
                forest->addAnimalMap(newTableObj);
            inx = table->size() - 1;
        }
        else
        {
            for (auto rowPair : newTableObj)
                (*table)[inx][rowPair.first] = rowPair.second;
        }
        toChangeMode();
    }
    updateTable();
}

bool IgoninDialog::checkFields()
{
    try
    {
        bool isNormalFields = true;
        if (stoi(ui->textEditAge->toPlainText().toStdString()) < 0)
            isNormalFields = false;
        if (stoi(ui->textEditWeight->toPlainText().toStdString()) < 0)
            isNormalFields = false;
        if (ui->label_6->isVisible())
            if (stoi(ui->textEditTail->toPlainText().toStdString()) < 0)
                isNormalFields = false;
        if (!isNormalFields)
        {
            QMessageBox message;
            message.setWindowTitle("ERROR");
            message.addButton("Ок", QMessageBox::NoRole);
            message.setText("Введите положительные числа!");
            message.exec();
            return false;
        }
    } catch (...)
    {
        QMessageBox message;
        message.setWindowTitle("ERROR");
        message.addButton("Ок", QMessageBox::NoRole);
        message.setText("Введите корректные числа!");
        message.exec();
        return false;
    }

    if (ui->listBoxColor->currentIndex() <= 0)
    {
        QMessageBox message;
        message.setWindowTitle("ERROR");
        message.addButton("Ок", QMessageBox::NoRole);
        message.setText("Выберите цвет!");
        message.exec();
        return false;
    }

    if (ui->listBoxNutrition->currentIndex() <= 0)
    {
        QMessageBox message;
        message.setWindowTitle("ERROR");
        message.addButton("Ок", QMessageBox::NoRole);
        message.setText("Выберите тип питания!");
        message.exec();
        return false;
    }

    return true;
}

unordered_map<string, string> IgoninDialog::GetFields()
{
    unordered_map<string, string> newTableObj;

    newTableObj.insert({"Имя", ui->textEditName->toPlainText().toLocal8Bit().toStdString()});
    newTableObj.insert({"Возраст", ui->textEditAge->toPlainText().toStdString()});
    newTableObj.insert({"Вес", ui->textEditWeight->toPlainText().toStdString()});

    newTableObj.insert({"Цвет", to_string(ui->listBoxColor->currentIndex() - 1)});

    newTableObj.insert({"Тип питания", to_string(ui->listBoxNutrition->currentIndex() - 1)});


    if (ui->label_6->isVisible()) // проверка рептилия ли
    {
        if (ui->checkBoxPoisonous->checkState())
            newTableObj.insert({"Ядовитость", "ядовито"});
        else
            newTableObj.insert({"Ядовитость", "не ядовито"});

        newTableObj.insert({"Длина хвоста", ui->textEditTail->toPlainText().toStdString()});

    }

    return newTableObj;
}


void IgoninDialog::on_buttonHaram_clicked()
{
    clearFields();
    toViewMode();
    viewObjectAttributes();
}


void IgoninDialog::on_buttonCloseDialog_clicked()
{
    close();
}


void IgoninDialog::on_buttonDeleteAnimal_clicked()
{
    if (inx >= 0)
    {
        QMessageBox msgBox;
        msgBox.setText("Вы уверены?");
        msgBox.addButton("Нет", QMessageBox::NoRole);
        msgBox.addButton("Да", QMessageBox::YesRole);
        auto reply = msgBox.exec();
        clearFields();
        if (reply == 3)
        {
            (*table).erase((*table).begin() + inx);
            forest->deleteAnimal(inx);
            if (inx >= ui->listWidgetAnimal->count() - 1)
                inx -= 1;
            updateTable();
        }
    }
}

