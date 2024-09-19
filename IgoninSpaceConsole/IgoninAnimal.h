#pragma once
#include "SubFunc.h"


class IgoninAnimal
{
private:
    std::vector<std::string> setterOptions = { "0. ������ ��", "1. ������ ��� ���������", "2. ������ ���� ���������",
                                                "3. ������ ��� ������� ���������", "4. ������ ������� ���������",
                                                "5. ������ ��� ���������" };
    std::vector<std::string> animalColors = { "�������", "����������", "�����", "������", "�����" };
    std::vector<std::string> nutritionTypes = { "����������", "����������", "��������" };
    
    std::string name;
    int animalColor;
    int animalNutrition;
    double age;
    double weight;
public:
    void SetEnumAttribute(const std::vector<std::string>& params, int& attribute);
    void SetStringAttribute(std::string& attribute);
    void SetNumAttribute(double& attribute, double min, double max);
    void SetParamsFromConsole(const int& mode = -1);
    void SetParamsFromFile(std::ifstream& fin);
    void PrintAnimal();
    void SaveAnimal(std::ofstream& fout);
};

