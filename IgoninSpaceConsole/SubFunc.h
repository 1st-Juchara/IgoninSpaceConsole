#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <filesystem>
//#include <functional>

void inputString(std::istream& in, std::string& str);

double tryInputNum(double min, double max);

int enterElement(int elements_cnt);

std::string chooseFiles(const bool& out = false);