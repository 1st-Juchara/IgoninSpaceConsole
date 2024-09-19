#pragma once
#include "SubFunc.h"
#include "IgoninAnimal.h"

using namespace std;

class IgoninForest
{
private:
    vector<IgoninAnimal*> animals;
public:
    ~IgoninForest();
    void AddAnimalsConsole();
    void ChangeAnimal();
    void PrintToCosole(const vector<int>& indices = {});
    void Save();
    void Load();
    bool IsForestEmpty();
    void Clear();
};

