#ifndef IGONINANIMAL
#define IGONINANIMAL
#pragma once
#include "SubFunc.h"
#include <Windows.h>
#include <unordered_map>
#include <map>

using namespace std;

class IgoninAnimal
{
    friend std::ifstream& operator>> (std::ifstream& fin, IgoninAnimal& animal);
    friend std::ofstream& operator<< (std::ofstream& fout, IgoninAnimal& animal);
    friend std::ostream& operator>> (std::ostream& stream_out, IgoninAnimal& animal);
    friend std::ostream& operator<< (std::ostream& stream_out, IgoninAnimal& animal);
    HANDLE consoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
protected:
    virtual std::vector<std::string> setterOptions();
    static const std::vector<std::string> animalColors;// { "красный", "коричневый", "серый", "черный", "белый" };
    static const std::vector<int> colorsCodes;// { 12, 6, 8, 48, 15 };
    static const std::vector<std::string> nutritionTypes;// { "плотоядное", "травоядное", "всеядное" };
    std::string name;
    int Color;
    int Nutrition;
    double age;
    double weight;
public:
    template<class Archive>
    void serialize(Archive& ar, const unsigned int version) {
        ar& name;
        ar& Color;
        ar& Nutrition;
        ar& age;
        ar& weight;
    }
    virtual std::unordered_map<std::string, std::string> getAnimalData();
    virtual void SetParamsFromConsole();
    virtual void Print();
};
#endif // IGONINANIMAL


