#include "IgoninAnimal.h"

using namespace std;

void IgoninAnimal::SetName()
{
	cout << "������� ��� ���������:" << "\n\n> ";
	inputString(cin, name);
}

void IgoninAnimal::SetAnimalColor()
{
	cout << "�������� ���� ���������:";
	for (int i = 0; i < animalColors.size(); i++) {
		cout << endl << i + 1 << ". " << animalColors[i];
	}
	animalColor = tryChoose(1, animalColors.size()) - 1;
}

void IgoninAnimal::SetAnimalNutrition()
{
	cout << "�������� ��� ������� ���������:";
	for (int i = 0; i < nutritionTypes.size(); i++) {
		cout << endl << i + 1 << ". " << nutritionTypes[i];
	}
	animalNutrition = tryChoose(1, nutritionTypes.size()) - 1;
}

void IgoninAnimal::SetAge()
{
	cout << "������� ������� ���������:";
	age = tryInputNum(0, 100);
}

void IgoninAnimal::SetWeight()
{
	cout << "������� ��� ��������� (� ��):";
	weight = tryInputNum(0.001, 200000);
}

void IgoninAnimal::SetParamsFromConsole(const int& mode)
{
	int userChoice = mode;
	if (mode == 0) {
		cout << "��� �� ������ ������?" << endl;
		cout << "1. ������ ��� ���������" << endl;
		cout << "2. ������ ���� ���������" << endl;
		cout << "3. ������ ��� ������� ���������" << endl;
		cout << "4. ������ ������� ���������" << endl;
		cout << "5. ������ ��� ���������" << endl;
		cout << "6. ������ ��� ���������";
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
	cout << format("{:<15}", "���: ") << name << endl; 
	cout << format("{:<15}", "����: ") << animalColors[animalColor] << endl;
	cout << format("{:<15}", "��� �������: ") << nutritionTypes[animalNutrition] << endl;
	cout << format("{:<15}", "�������: ") << age << endl;
	cout << format("{:<15}", "���: ") << weight << endl;
}

void IgoninAnimal::CastAnimalToFile(std::ofstream& fout)
{
	fout << name << endl;
	fout << animalColor << ' ';
	fout << animalNutrition << ' ';
	fout << age << ' ';
	fout << weight << endl;
}
