#include "IgoninForest.h"

IgoninForest::~IgoninForest()
{
	Clear();
}

void IgoninForest::AddAnimalsConsole()
{
	IgoninAnimal* animal = new IgoninAnimal();
	animal->SetParamsFromConsole(0);
	animals.push_back(animal);
}

void IgoninForest::ChangeAnimal()
{
	if (!IsForestEmpty()) {
		PrintToCosole();
		int index_ch = enterElement(animals.size());
		animals[index_ch]->SetParamsFromConsole();
	}
}

void IgoninForest::PrintToCosole(const vector<int>& indices)
{
	if (!IsForestEmpty()) {
		if (indices.empty())
			for (int i = 0; i < animals.size(); i++) {
				cout << "Животное №" << i + 1 << endl;
				animals[i]->PrintAnimal();
				cout << endl;
			}
		else
			for (int i = 0; i < indices.size(); i++) {
				cout << "Животное №" << indices[i] << endl;
				animals[indices[i]]->PrintAnimal();
				cout << endl;
			}
	}
	
}

void IgoninForest::Save()
{
	if (!IsForestEmpty()) {
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

void IgoninForest::Load()
{
	string file_name = chooseFiles();
	if (!file_name.empty()) {
		ifstream fin(file_name);
		if (fin.is_open())
		{
			Clear();
			bool Error = false;
			int animal_cnt = 0;
			fin >> animal_cnt;
			Error = animal_cnt == 0 ? true : false;
			for (int i = 0; i < animal_cnt; i++) {
				IgoninAnimal* animal = new IgoninAnimal;
				if ((fin >> *animal).fail())
				{
					Error = true;
					break;
				}
				else
					animals.push_back(animal);
			}
			fin.close();
			if (Error)
				cout << "Ошибка: файл поврежден\n\n";
		}
		else
			cout << "Ошибка: файл не найден\n\n";
	}
}

bool IgoninForest::IsForestEmpty()
{
	if (animals.empty()) {
		cout << "Список животных пуст\n\n";
		return true;
	}
	else
		return false;

}

void IgoninForest::Clear()
{
	for (auto animal : this->animals) {
		delete animal;
	}
	this->animals.clear();
}
