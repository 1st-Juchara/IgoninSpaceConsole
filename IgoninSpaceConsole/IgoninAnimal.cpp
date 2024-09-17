#include "IgoninAnimal.h"

using namespace std;

void IgoninAnimal::SetName()
{
	cout << "Введите имя животного:" << "\n\n> ";
	inputString(cin, name);
}

void IgoninAnimal::SetAnimalColor()
{
	cout << "Выберите цвет животного:";
	for (int i = 0; i < animalColors.size(); i++) {
		cout << endl << i + 1 << ". " << animalColors[i];
	}
	animalColor = tryChoose(1, animalColors.size()) - 1;
}

void IgoninAnimal::SetAnimalNutrition()
{
	cout << "Выберите тип питания животного:";
	for (int i = 0; i < nutritionTypes.size(); i++) {
		cout << endl << i + 1 << ". " << nutritionTypes[i];
	}
	animalNutrition = tryChoose(1, nutritionTypes.size()) - 1;
}

void IgoninAnimal::SetAge()
{
	cout << "Введите возраст животного:";
	age = tryInputNum(0, 100);
}

void IgoninAnimal::SetWeight()
{
	cout << "Введите вес животного (в кг):";
	weight = tryInputNum(0.001, 200000);
}

void IgoninAnimal::SetParamsFromConsole(const int& mode)
{
	int userChoice = mode;
	if (mode == 0) {
		cout << "Что вы хотите ввести?" << endl;
		cout << "1. Ввести имя животного" << endl;
		cout << "2. Ввести цвет животного" << endl;
		cout << "3. Ввести тип питания животного" << endl;
		cout << "4. Ввести возраст животного" << endl;
		cout << "5. Ввести вес животного" << endl;
		cout << "6. ВВЕСТИ ВСЕ ПАРАМЕТРЫ";
		userChoice = tryChoose(1, 6);
	}
	switch (userChoice)
	{
	case 1:
		SetName();
		break;
	case 2:
		SetAnimalColor();
		break;
	case 3:
		SetAnimalNutrition();
		break;
	case 4:
		SetAge();
		break;
	case 5:
		SetWeight();
		break;
	case 6:
		SetName();
		SetAnimalColor();
		SetAnimalNutrition();
		SetAge();
		SetWeight();
	default:
		break;
	}
}

void IgoninAnimal::SetParamsFromFile(std::ifstream& fin)
{
	fin.ignore(10000, '\n');
	getline(fin, name);
	fin >> animalColor;
	fin >> animalNutrition;
	fin >> age;
	fin >> weight;
}

void IgoninAnimal::CastAnimalToConsole()
{
	cout << format("{:<15}", "Имя: ") << name << endl; 
	cout << format("{:<15}", "Цвет: ") << animalColors[animalColor] << endl;
	cout << format("{:<15}", "Тип питания: ") << nutritionTypes[animalNutrition] << endl;
	cout << format("{:<15}", "Возраст: ") << age << endl;
	cout << format("{:<15}", "Вес: ") << weight << endl;
}

void IgoninAnimal::CastAnimalToFile(std::ofstream& fout)
{
	fout << name << endl;
	fout << animalColor << ' ';
	fout << animalNutrition << ' ';
	fout << age << ' ';
	fout << weight << endl;
}
