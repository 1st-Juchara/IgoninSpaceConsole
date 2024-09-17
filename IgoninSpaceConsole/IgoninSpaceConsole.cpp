
#include <iostream>
#include <Windows.h>
#include "SubFunc.h"
#include "IgoninAnimal.h"
#include "IgoninForest.h"

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    IgoninForest* forest = new IgoninForest;
    int state = 1;

    while (true)
    {
        if (state == 1) {
            cout << "1. Добавить животное" << endl;
            cout << "2. Изменить животное" << endl;
            cout << "3. Описание животных" << endl;
            cout << "4. Сохранить лес" << endl;
            cout << "5. Загрузить лес" << endl;
            cout << "6. Очистить лес" << endl;
            cout << "7. Удалить лес";

            int choice = tryChoose(0, 7);

            switch (choice)
            {
            case 1:
                forest->AddAnimalsConsole();
                break;
            case 2:
                forest->ChangeAnimal();
                break;
            case 3:
                forest->CastForestToCosole();
                break;
            case 4:
                forest->CastForestToFile();
                break;
            case 5:
                forest->AddAnimalsFile();
                break;
            case 6:
                forest->ClearForest();
                break;
            case 7:
                forest->~IgoninForest();
                state = 0;
                break;
            default:
                break;
            }
        }
        else {
            cout << "1. Создать новый лес" << endl;
            cout << "2. Выйти";
            int choice = tryChoose(1, 2);
            if (choice == 1) {
                state = 1;
                IgoninForest* forest = new IgoninForest;
            }
            else
                break;
        }
        
    }
}