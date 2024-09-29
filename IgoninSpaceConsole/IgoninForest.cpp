#include "IgoninForest.h"

IgoninForest::~IgoninForest()
{
	Clear();
}

void IgoninForest::AddAnimalsConsole()
{
	cout << "Что вы хотите создать?" << endl;
	cout << "1. Животное" << endl;
	cout << "2. Рептилию";
	bool userChoice = tryInputNum(1, 2) == 1 ? true : false;
	if (userChoice)
		AddAnimalConsole();
	else
		AddReptileConsole();
}

void IgoninForest::ChangeElement()
{
	cout << "Что вы хотите изменить?" << endl;
	cout << "1. Животное" << endl;
	cout << "2. Рептилию";
	bool userChoice = tryInputNum(1, 2) == 1 ? true : false;

	if (userChoice && !IsAnimalsEmpty())
		ChangeAnimal();
	if (!userChoice && !IsReptilesEmpty())
		ChangeReptile();
}

void IgoninForest::AddAnimalConsole()
{
	IgoninAnimal* animal = new IgoninAnimal();
	animal->SetParamsFromConsole();
	animals.push_back(animal);
}

void IgoninForest::AddReptileConsole()
{
	IgoninReptile* reptile = new IgoninReptile();
	reptile->SetParamsFromConsole();
	reptiles.push_back(reptile);
}

void IgoninForest::ChangeAnimal()
{
	PrintAnimals();
	int index_ch = selectElement(animals.size());
	animals[index_ch]->SetParamsFromConsole();
}

void IgoninForest::ChangeReptile()
{
	PrintReptiles();
	int index_ch = selectElement(reptiles.size());
	reptiles[index_ch]->SetParamsFromConsole();
}

void IgoninForest::PrintToCosole()
{
	if (!IsAnimalsEmpty()) 
		PrintAnimals();
	if (!IsReptilesEmpty())
		PrintReptiles();
}

void IgoninForest::PrintAnimals()
{
	for (int i = 0; i < animals.size(); i++) {
		cout << "Животное" << " №" << i + 1 << endl;
		cout << *animals[i];
		cout << endl;
	}
}

void IgoninForest::PrintReptiles()
{
	for (int i = 0; i < reptiles.size(); i++) {
		cout << "Рептилия" << " №" << i + 1 << endl;
		cout << *reptiles[i];
		cout << endl;
	}
}

void IgoninForest::Save()
{
	if (!IsAnimalsEmpty()) {
		string file_name = chooseFiles(true);
		if (!file_name.empty()) {
			ofstream fout(file_name, ios_base::out | ios_base::trunc);// out - открыте для записи, trunc - удаление содержимого
			fout << animals.size() << endl;
			for (auto animal : animals) {//!!!!!!!!!!!!!
				fout << *animal;
			}
			fout.close();
		}
	}
}

void IgoninForest::SaveSer()
{
	string file_name = chooseFiles(true);
	if (!file_name.empty())
	{
		ofstream fout(file_name);
		boost::archive::text_oarchive oa(fout);

		oa << animals.size();
		for (auto animal : animals) {
			oa << animal;
		}

		oa << reptiles.size();
		for (auto reptile : reptiles) {
			oa << reptile;
		}
	}
}

void IgoninForest::LoadSer()
{
	string file_name = chooseFiles(false);

	if (!file_name.empty())
	{
		Clear();
		std::ifstream fin(file_name);
		boost::archive::text_iarchive ia(fin);

		int animalsCount = 0;
		ia >> animalsCount;

		for (int i = 0; i < animalsCount; i++) {
			IgoninAnimal* animal = nullptr;
			ia >> animal;

			if (animal == nullptr) {
				cout << "Ошибка: файл поврежден\n\n";
				Clear();
			}
			else
				animals.push_back(animal);
		}

		int reptilesCount = 0;
		ia >> reptilesCount;

		for (int i = 0; i < reptilesCount; i++) {
			IgoninReptile* reptile = nullptr;
			ia >> reptile;

			if (reptile == nullptr) {
				cout << "Ошибка: файл поврежден\n\n";
				Clear();
			}
			else
				reptiles.push_back(reptile);
		}
	}
}

void IgoninForest::Load()
{
	string file_name = chooseFiles();
	if (!file_name.empty()) {
		ifstream fin(file_name);
		if (fin.is_open())
		{
			Clear();
			int animal_cnt = 0;
			fin >> animal_cnt;
			for (int i = 0; i < animal_cnt; i++) {
				IgoninAnimal* animal = new IgoninAnimal;
				if ((fin >> *animal).fail())
				{
					Clear();
					delete animal;
					break;
				}
				else
					animals.push_back(animal);
			}
			if (!fin)
				cout << "Ошибка: файл поврежден\n\n";
			fin.close();
		}
		else
			cout << "Ошибка: файл не найден\n\n";
	}
}

bool IgoninForest::IsAnimalsEmpty()
{
	if (animals.empty()) {
		cout << "Список животных пуст\n\n";
		return true;
	}
	else
		return false;

}

bool IgoninForest::IsReptilesEmpty()
{
	if (reptiles.empty()) {
		cout << "Список рептилий пуст\n\n";
		return true;
	}
	else
		return false;
}

void IgoninForest::Clear()
{
	for (auto animal : animals) {
		delete animal;
	}
	animals.clear();

	for (auto reptile : reptiles) {
		delete reptile;
	}
	reptiles.clear();

}
