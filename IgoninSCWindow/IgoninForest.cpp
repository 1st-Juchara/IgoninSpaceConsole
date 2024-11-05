#include "IgoninForest.h"



BOOST_CLASS_EXPORT_GUID(IgoninAnimal, "IgoninAnimal")
BOOST_CLASS_EXPORT_GUID(IgoninReptile, "IgoninReptile")

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
    //cout << "Что вы хотите изменить?" << endl;
    //cout << "1. Животное" << endl;
    //cout << "2. Рептилию";
    //bool userChoice = tryInputNum(1, 2) == 1 ? true : false;
    //
    //if (userChoice && !IsAnimalsEmpty())
    ChangeAnimal();
    //if (!userChoice && !IsReptilesEmpty())
    //	ChangeReptile();
}

void IgoninForest::AddAnimalConsole()
{
    shared_ptr<IgoninAnimal> animal = make_shared<IgoninAnimal>();
    animal->SetParamsFromConsole();
    animals.push_back(animal);
}

void IgoninForest::AddReptileConsole()
{
    shared_ptr<IgoninReptile> reptile = make_shared<IgoninReptile>();
    reptile->SetParamsFromConsole();
    animals.push_back(reptile);
}

void IgoninForest::ChangeAnimal()
{
    PrintAnimals();
    int index_ch = selectElement(animals.size());
    animals[index_ch]->SetParamsFromConsole();
}

//void IgoninForest::ChangeReptile()
//{
//	PrintReptiles();
//	int index_ch = selectElement(reptiles.size());
//	reptiles[index_ch]->SetParamsFromConsole();
//}

void IgoninForest::PrintToCosole()
{
    if (!IsAnimalsEmpty())
        PrintAnimals();
    //if (!IsReptilesEmpty())
    //	PrintReptiles();
}

void IgoninForest::PrintAnimals()
{
    for (int i = 0; i < animals.size(); i++) {
        cout << "Животное" << " №" << i + 1 << endl;
        cout << *animals[i];
        cout << endl;
    }
}

//void IgoninForest::PrintReptiles()
//{
//	for (int i = 0; i < reptiles.size(); i++) {
//		cout << "Рептилия" << " №" << i + 1 << endl;
//		cout << *reptiles[i];
//		cout << endl;
//	}
//}

void IgoninForest::SaveSer()
{
    string file_name = chooseFiles(true);
    if (!file_name.empty())
    {
        ofstream fout(file_name);
        if (fout)
        {
            boost::archive::text_oarchive oa(fout);

            oa << animals;

            fout.close();
        }
        //oa << reptiles.size();
        //for (auto reptile : reptiles) {
        //	oa << reptile;
        //}
    }
}

void IgoninForest::LoadSer()
{
    string file_name = chooseFiles(false);

    if (!file_name.empty())
    {
        //
        Clear();
        std::ifstream fin(file_name);

        if (fin)
        {
            try {
                boost::archive::text_iarchive ia(fin);
                ia >> animals;
            }
            catch (const exception& e)
            {
                cout << "Ошибка: файл поврежден\n\n";
                Clear();
            }
            fin.close();
        }
        // в один вектор, сериализацию
        //int reptilesCount = 0;
        //ia >> reptilesCount;

        //for (int i = 0; i < reptilesCount; i++) {
        //	try {
        //		shared_ptr<IgoninReptile> reptile = nullptr;
        //		ia >> reptile;
        //		reptiles.push_back(reptile);
        //	}
        //	catch (const exception& e)
        //	{
        //		cout << "Ошибка: файл поврежден\n\n";
        //		Clear();
        //	}
        //}
    }
}

string IgoninForest::Load(const string &fileName)
{
    if (!fileName.empty())
    {
        //
        Clear();
        std::ifstream fin(fileName);

        if (fin)
        {
            try {
                boost::archive::text_iarchive ia(fin);
                ia >> animals;
            }
            catch (const exception& e)
            {
                return "Ошибка: файл поврежден";
                Clear();
            }
            fin.close();
        }
    }
    return "Успешно загружено!";
}

vector<unordered_map<string, string>> IgoninForest::GetAnimals()
{
    vector<unordered_map<string, string>> animalsData;
    if (IsAnimalsEmpty())
        animalsData.push_back(unordered_map<string, string>{{"Ошибка", "Лес пуст..."}});
    else
    {
        for (auto animal : animals)
        {
            unordered_map<string, string> animalData = animal->getAnimalData();
            animalsData.push_back(animalData);
        }
    }
    return animalsData;
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

//bool IgoninForest::IsReptilesEmpty()
//{
//	if (reptiles.empty()) {
//		cout << "Список рептилий пуст\n\n";
//		return true;
//	}
//	else
//		return false;
//}

void IgoninForest::Clear()
{
    animals.clear();
    //reptiles.clear();
}

