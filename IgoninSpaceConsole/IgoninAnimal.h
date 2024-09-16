#pragma once
#include "SubFunc.h"


class IgoninAnimal
{
private:
    std::vector<std::string> animalColors = { "красный", "коричневый", "серый", "черный", "белый" };
    std::vector<std::string> nutritionTypes = { "плотоядное", "травоядное", "всеядное" };
    std::string name;
    int animalColor;
    int animalNutrition;
    float age;
    float weight;

    void SetName();
    void SetAnimalColor();
    void SetAnimalNutrition();
    void SetAge();
    void SetWeight();

public:
    void SetParamsFromConsole(const int& mode = 0);
    void SetParamsFromFile(std::ifstream& fin);
    void CastAnimalToConsole();
    void CastAnimalToFile(std::ofstream& fout);
};

