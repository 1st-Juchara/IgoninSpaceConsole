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
    std::vector<std::string> setterOptions = { "0. ������ ��", "1. ������ ��� ���������", "2. ������ ���� ���������",
                                                "3. ������ ��� ������� ���������", "4. ������ ������� ���������",
                                                "5. ������ ��� ���������" };
    std::vector<std::string> animalColors = { "�������", "����������", "�����", "������", "�����" };
    std::vector<int> colorsCodes = { 12, 6, 8, 48, 15 };
    std::vector<std::string> nutritionTypes = { "����������", "����������", "��������" };
    
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



