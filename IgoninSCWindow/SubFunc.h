#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <filesystem>

//#include <functional>

void inputString(std::istream& in, std::string& str);

double tryInputNum(double min, double max);

int selectElement(int elements_cnt);

std::vector<std::string> getFiles(std::string pathFromProject);

std::string chooseFiles(bool out = false);

void SetEnumAttribute(const std::vector<std::string>& params, int& attribute, const std::string& attributeName);

void SetStringAttribute(std::string& attribute, const std::string& attributeName);

void SetNumAttribute(double& attribute, double min, double max, const std::string& attributeName);

void SetBoolAttribute(const std::pair<std::string, std::string>& options, bool& attribute, const std::string& attributeName);

