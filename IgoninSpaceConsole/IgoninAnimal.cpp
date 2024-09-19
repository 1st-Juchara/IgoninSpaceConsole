#include "IgoninAnimal.h"

using namespace std;



void IgoninAnimal::SetEnumAttribute(const vector<std::string>& params, int& attribute)
{
	for (int i = 0; i < params.size(); i++)
		cout << endl << i + 1 << ". " << params[i];
	attribute = tryInputNum(1, params.size()) - 1;
}

void IgoninAnimal::SetStringAttribute(string& attribute)
{
	inputString(cin, attribute);
}

void IgoninAnimal::SetNumAttribute(double& attribute, double min, double max)
{
	if (min > max)
	{
		double t = min;
		min = max;
		max = min;
	}
	attribute = tryInputNum(min, max);
}

void IgoninAnimal::SetParamsFromConsole(const int& mode)
{
	int userChoice = mode;
	if (mode == -1) {
		cout << "Что вы хотите ввести?" << endl;
		cout << "1. Ввести имя животного" << endl;
		cout << "2. Ввести цвет животного" << endl;
		cout << "3. Ввести тип питания животного" << endl;
		cout << "4. Ввести возраст животного" << endl;
		cout << "5. Ввести вес животного" << endl;
		cout << "6. ВВЕСТИ ВСЕ ПАРАМЕТРЫ";
		userChoice = tryInputNum(1, 6);
	}
	switch (userChoice)
	{
	case 0:
		cout << "Введите имя животного:\n\n>";
		SetStringAttribute(name);
		cout << "Выберите цвет животного:";
		SetEnumAttribute(animalColors, animalColor);
		cout << "Выберите цвет животного:";
		SetEnumAttribute(nutritionTypes, animalNutrition);
		cout << "Введите возраст животного:";
		SetNumAttribute(age, 0, 200);
		cout << "Введите вес животного:";
		SetNumAttribute(weight, 0, 20000);
		break;
	case 1:
		SetStringAttribute(name);
		break;
	case 2:
		SetEnumAttribute(animalColors, animalColor);
		break;
	case 3:
		SetEnumAttribute(nutritionTypes, animalNutrition);
		break;
	case 4:
		SetNumAttribute(age, 0, 200);
		break;
	case 5:
		SetNumAttribute(age, 0, 20000);
		break;
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

void IgoninAnimal::PrintAnimal()
{
	cout << format("{:<15}", "Имя: ") << name << endl; 
	cout << format("{:<15}", "Цвет: ") << animalColors[animalColor] << endl;
	cout << format("{:<15}", "Тип питания: ") << nutritionTypes[animalNutrition] << endl;
	cout << format("{:<15}", "Возраст: ") << age << endl;
	cout << format("{:<15}", "Вес: ") << weight << endl;
}

void IgoninAnimal::SaveAnimal(std::ofstream& fout)
{
	fout << name << endl;
	fout << animalColor << ' ';
	fout << animalNutrition << ' ';
	fout << age << ' ';
	fout << weight << endl;
}
