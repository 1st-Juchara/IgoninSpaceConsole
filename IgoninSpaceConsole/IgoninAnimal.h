#pragma once
#include "SubFunc.h"


class IgoninAnimal
{
private:
    std::vector<std::string> animalColors = { "�������", "����������", "�����", "������", "�����" };
    std::vector<std::string> nutritionTypes = { "����������", "����������", "��������" };
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

