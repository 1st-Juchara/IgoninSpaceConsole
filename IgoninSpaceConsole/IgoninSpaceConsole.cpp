
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

    IgoninForest forest;
    bool working = true;

    while (working)
    {
            cout << "1. Добавить животное" << endl;
            cout << "2. Изменить животное" << endl;
            cout << "3. Описание животных" << endl;
            cout << "4. Сохранить лес" << endl;
            cout << "5. Загрузить лес" << endl;
            cout << "6. Очистить лес" << endl;
            cout << "0. Выход";

            int choice = tryInputNum(0, 7);

            switch (choice)
            {
            case 1:
                forest.AddAnimalsConsole();
                break;
            case 2:
                forest.ChangeElement();
                break;
            case 3:
                forest.PrintToCosole();
                break;
            case 4:
                forest.SaveSer();
                break;
            case 5:
                forest.LoadSer();
                break;
            case 6:
                forest.Clear();
                break;
            case 0:
                return 0;
            default:
                break;
            }
        }
        
}