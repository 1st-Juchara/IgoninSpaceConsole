#include "IgoninAnimal.h"
#include "IgoninForest.h"
using namespace std;

std::vector<std::string> IgoninAnimal::setterOptions()
{
    return { "всё", "имя", "тип питания", "возраст", "вес", "цвет" };
}

map<string, string> IgoninAnimal::getAnimalData()
{
    map<string, string> animalData;
    animalData.insert({"Имя", name});
    animalData.insert({"Тип питания", nutritionTypes[Nutrition]});
    animalData.insert({"Возраст", to_string(age)});
    animalData.insert({"Вес", to_string(weight)});
    animalData.insert({"Цвет", animalColors[Color]});
    return animalData;
}
const std::vector<std::string> IgoninAnimal::animalColors = { "красный", "коричневый", "серый", "черный", "белый", "зеленый", "желтый" };
const std::vector<int> IgoninAnimal::colorsCodes = { 12, 6, 8, 240, 15, 10, 14 };
const std::vector<std::string> IgoninAnimal::nutritionTypes = { "плотоядное", "травоядное", "всеядное" };


void IgoninAnimal::SetParamsFromConsole()
{
    SetStringAttribute(name, setterOptions()[1]);
    SetEnumAttribute(nutritionTypes, Nutrition, setterOptions()[2]);
    SetNumAttribute(age, 0, 200, setterOptions()[3]);
    SetNumAttribute(weight, 0, 20000, setterOptions()[4]);
    SetEnumAttribute(animalColors, Color, setterOptions()[5]);
}


void IgoninAnimal::Print()
{
    cout << "Имя: " << name << endl;
    cout << "Тип питания: " << nutritionTypes[Nutrition] << endl;
    cout << "Возраст: " << age << endl;
    cout << "Вес: " << weight << endl;

    cout << "Цвет: ";
    SetConsoleTextAttribute(consoleColor, colorsCodes[Color]);
    cout << animalColors[Color];
    SetConsoleTextAttribute(consoleColor, (WORD)((0 << 4) | 15));
    cout << endl;
}

std::ifstream& operator>>(ifstream& fin, IgoninAnimal& animal)
{
    fin.ignore(10000, '\n');
    getline(fin, animal.name);
    fin >> animal.Color;
    fin >> animal.Nutrition;
    fin >> animal.age;
    fin >> animal.weight;

    return fin;
}

std::ofstream& operator<<(ofstream& fout, IgoninAnimal& animal)
{
    fout << animal.name << endl;
    fout << animal.Color << ' ';
    fout << animal.Nutrition << ' ';
    fout << animal.age << ' ';
    fout << animal.weight << endl;

    return fout;
}

std::ostream& operator<<(std::ostream& stream_out, IgoninAnimal& animal)
{
    animal.Print();
    return stream_out;
}

std::ostream& operator>>(std::ostream& stream_in, IgoninAnimal& animal)
{
    animal.SetParamsFromConsole();
    return stream_in;
}
