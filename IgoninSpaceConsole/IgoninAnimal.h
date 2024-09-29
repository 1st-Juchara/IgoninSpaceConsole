#pragma once
#include "SubFunc.h"
#include <Windows.h>
#include <map>

class IgoninAnimal
{
    friend std::ifstream& operator>> (std::ifstream& fin, IgoninAnimal& animal);
    friend std::ofstream& operator<< (std::ofstream& fout, IgoninAnimal& animal);
    friend std::ostream& operator>> (std::ostream& stream_out, IgoninAnimal& animal);
    friend std::ostream& operator<< (std::ostream& stream_out, IgoninAnimal& animal);
    HANDLE consoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
protected:
    virtual std::vector<std::string> setterOptions();
    static const std::vector<std::string> animalColors;// { "�������", "����������", "�����", "������", "�����" };
    static const std::vector<int> colorsCodes;// { 12, 6, 8, 48, 15 };
    static const std::vector<std::string> nutritionTypes;// { "����������", "����������", "��������" };
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

    virtual void SetParamsFromConsole();
    virtual void Print();
};



