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
		cout << "��� �� ������ ������?" << endl;
		cout << "1. ������ ��� ���������" << endl;
		cout << "2. ������ ���� ���������" << endl;
		cout << "3. ������ ��� ������� ���������" << endl;
		cout << "4. ������ ������� ���������" << endl;
		cout << "5. ������ ��� ���������" << endl;
		cout << "6. ������ ��� ���������";
		userChoice = tryInputNum(1, 6);
	}
	switch (userChoice)
	{
	case 0:
		cout << "������� ��� ���������:\n\n>";
		SetStringAttribute(name);
		cout << "�������� ���� ���������:";
		SetEnumAttribute(animalColors, animalColor);
		cout << "�������� ���� ���������:";
		SetEnumAttribute(nutritionTypes, animalNutrition);
		cout << "������� ������� ���������:";
		SetNumAttribute(age, 0, 200);
		cout << "������� ��� ���������:";
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
	cout << format("{:<15}", "���: ") << name << endl; 
	cout << format("{:<15}", "����: ") << animalColors[animalColor] << endl;
	cout << format("{:<15}", "��� �������: ") << nutritionTypes[animalNutrition] << endl;
	cout << format("{:<15}", "�������: ") << age << endl;
	cout << format("{:<15}", "���: ") << weight << endl;
}

void IgoninAnimal::SaveAnimal(std::ofstream& fout)
{
	fout << name << endl;
	fout << animalColor << ' ';
	fout << animalNutrition << ' ';
	fout << age << ' ';
	fout << weight << endl;
}
