#pragma once
#include "SubFunc.h"
#include <Windows.h>
#include <map>

class IgoninAnimal
{
    friend std::ifstream& operator>> (std::ifstream& fin, IgoninAnimal& animal);
    friend std::ofstream& operator<< (std::ofstream& fout, IgoninAnimal& animal);
    HANDLE consoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
private:
    std::vector<std::string> setterOptions = { "0. ¬вести всЄ", "1. ¬вести им€ животного", "2. ¬вести цвет животного",
                                                "3. ¬вести тип питани€ животного", "4. ¬вести возраст животного",
                                                "5. ¬вести вес животного" };
    std::vector<std::string> animalColors = { "красный", "коричневый", "серый", "черный", "белый" };
    std::vector<int> colorsCodes = { 12, 6, 8, 48, 15 };
    std::vector<std::string> nutritionTypes = { "плото€дное", "траво€дное", "все€дное" };
    
    std::string name;
    int Color;
    int Nutrition;
    double age;
    double weight;
public:
    void SetEnumAttribute(const std::vector<std::string>& params, int& attribute);
    void SetStringAttribute(std::string& attribute);
    void SetNumAttribute(double& attribute, double min, double max);
    void SetParamsFromConsole(const int& mode = -1);
    void PrintAnimal();
};



