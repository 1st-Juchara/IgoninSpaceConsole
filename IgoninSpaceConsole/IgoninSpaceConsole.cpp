
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

    while (true)
    {
            cout << "1. Добавить животное" << endl;
            cout << "2. Изменить животное" << endl;
            cout << "3. Описание животных" << endl;
            cout << "4. Сохранить лес" << endl;
            cout << "5. Загрузить лес" << endl;
            cout << "6. Очистить лес";

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
            default:
                break;
            }
        }
        
}