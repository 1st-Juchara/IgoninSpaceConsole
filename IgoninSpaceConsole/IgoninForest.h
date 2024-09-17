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
    void CastForestToCosole(const vector<int>& indices = {});
    void CastForestToFile();
    void AddAnimalsFile();
    bool IsForestEmpty();
    void ClearForest();
};

