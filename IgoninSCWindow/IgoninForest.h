#ifndef IGONINFOREST
#define IGONINFOREST

#pragma once
#include "SubFunc.h"
#include <memory>
#include "IgoninAnimal.h"
#include "IgoninReptile.h"
#include <map>


#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/serialization/export.hpp>
#include <boost/serialization/base_object.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/serialization/string.hpp>
#include <boost/serialization/version.hpp>
#include <boost/serialization/split_member.hpp>
#include <boost/serialization/shared_ptr.hpp>


using namespace std;

class IgoninForest
{
private:
    vector<shared_ptr<IgoninAnimal>> animals;
    //vector<shared_ptr<IgoninReptile>> reptiles;
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
    void SaveSer();
    void LoadSer();
    //new
    string Load(const string& fileName);
    string Save(const string& fileName);
    vector<unordered_map<string, string>> GetAnimals();
    //
    bool IsAnimalsEmpty();
    void Clear();
};

#endif // IGONINFOREST
