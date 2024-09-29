#pragma once
#include "SubFunc.h"
#include "IgoninAnimal.h"
#include "IgoninReptile.h"

using namespace std;

class IgoninForest
{
private:
    vector<IgoninAnimal*> animals;
    vector<IgoninReptile*> reptiles;
    void AddAnimalConsole();
    void AddReptileConsole();
public:
    ~IgoninForest();
    void AddAnimalsConsole();
    void ChangeElement();
    void ChangeAnimal();
    void ChangeReptile();
    void PrintToCosole();
    void PrintAnimals();
    void PrintReptiles();
    void Save();
    void SaveSer();
    void LoadSer();
    void Load();
    bool IsAnimalsEmpty();
    bool IsReptilesEmpty();
    void Clear();
};

