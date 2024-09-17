#include "IgoninForest.h"

IgoninForest::~IgoninForest()
{
	ClearForest();
}

void IgoninForest::AddAnimalsConsole()
{
	IgoninAnimal* animal = new IgoninAnimal();
	animal->SetParamsFromConsole(6);
	animals.push_back(animal);
}

void IgoninForest::ChangeAnimal()
{
	if (!IsForestEmpty()) {
		CastForestToCosole();
		int index_ch = enterElement(animals.size());
		animals[index_ch]->SetParamsFromConsole();
	}
}

void IgoninForest::CastForestToCosole(const vector<int>& indices)
{
	if (!IsForestEmpty()) {
		if (indices.empty())
			for (int i = 0; i < animals.size(); i++) {
				cout << "Животное №" << i + 1 << endl;
				animals[i]->CastAnimalToConsole();
				cout << endl;
			}
		else
			for (int i = 0; i < indices.size(); i++) {
				cout << "Животное №" << indices[i] << endl;
				animals[indices[i]]->CastAnimalToConsole();
				cout << endl;
			}
	}
	
}

void IgoninForest::CastForestToFile()
{
	if (!IsForestEmpty()) {
		string file_name = chooseFiles();
		if (!file_name.empty()) {
			ofstream fout(file_name, ios_base::out | ios_base::trunc);// out - открыте для записи, trunc - удаление содержимого
			fout << animals.size() << endl;
			for (int i = 0; i < animals.size(); i++) {
				animals[i]->CastAnimalToFile(fout);
			}
			fout.close();
		}
	}
}

void IgoninForest::AddAnimalsFile()
{
	string file_name = chooseFiles();
	if (!file_name.empty()) {
		ClearForest();
		ifstream fin(file_name);
		if (fin.is_open())
		{
			int animal_cnt;
			fin >> animal_cnt;
			for (int i = 0; i < animal_cnt; i++) {
				IgoninAnimal* animal = new IgoninAnimal;
				animal->SetParamsFromFile(fin);
				animals.push_back(animal);
			}
			fin.close();
		}
		else
			cout << "Error: can't find save file" << endl;
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

void IgoninForest::ClearForest()
{
	for (auto animal : this->animals) {
		delete animal;
	}
	this->animals.clear();
}
