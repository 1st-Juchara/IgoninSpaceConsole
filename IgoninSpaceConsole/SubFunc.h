#pragma once
#include <cctype>    // std::tolower
#include <algorithm> // std::equal
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <filesystem>
#include <map>
#include <windows.h> 
//#include <functional>

bool inString(std::string str_where, std::string str_what);

void inputString(std::istream& in, std::string& str);

float tryInputNum(float min, float max);

int tryChoose(int min, int max);

std::vector <int> enterInterval(int elements_cnt);

std::vector <int> enterPacket(int elements_cnt);

int enterElement(int elements_cnt);

std::vector <int> choosingElements(int elements_cnt);

std::string chooseFiles();