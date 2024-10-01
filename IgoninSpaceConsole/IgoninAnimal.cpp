#include "IgoninAnimal.h"
#include "IgoninForest.h"
using namespace std;

std::vector<std::string> IgoninAnimal::setterOptions()
{
	return { "��", "���", "��� �������", "�������", "���", "����" };
}
const std::vector<std::string> IgoninAnimal::animalColors = { "�������", "����������", "�����", "������", "�����", "�������", "������" };
const std::vector<int> IgoninAnimal::colorsCodes = { 12, 6, 8, 240, 15, 10, 14 };
const std::vector<std::string> IgoninAnimal::nutritionTypes = { "����������", "����������", "��������" };


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
	cout << format("{:<15}", "���: ") << name << endl; 
	cout << format("{:<15}", "��� �������: ") << nutritionTypes[Nutrition] << endl;
	cout << format("{:<15}", "�������: ") << age << endl;
	cout << format("{:<15}", "���: ") << weight << endl;

	cout << format("{:<15}", "����: ");
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