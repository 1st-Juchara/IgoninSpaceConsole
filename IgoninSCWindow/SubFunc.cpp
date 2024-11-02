#include "SubFunc.h"
using namespace std;

void inputString(istream& in, string& str)
{
    in >> ws;
    getline(in, str);
    cout << endl;
    //cerr << str << endl;
}

double tryInputNum(double min, double max)// <T> min max
{
    double num;
    cout << "\n\n> ";
    while ((cin >> num).fail() || (num < min) || (num > max)) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "\n\n> ";
    }
    cout << endl;
    //cerr << num << endl;
    return num;
}

int selectElement(int elements_cnt)
{
    cout << "Введите индекс:";
    int index_ch = tryInputNum(1, elements_cnt) - 1;
    return index_ch;
}

vector<string> getFiles(string pathFromProject) // список файлов
{
    vector<string> fileNames;
    ;
    for (const auto& entry : filesystem::directory_iterator(filesystem::current_path().string() + R"(\)" + pathFromProject)) {
        fileNames.push_back(entry.path().filename().string());
    }
    return fileNames;
}

std::string chooseFiles(bool out)
{
    string name;
    cout << "Выберите файл:\n" << endl;
    vector<string> files;
    int i = 0;
    for (const auto& entry : filesystem::directory_iterator(filesystem::current_path().string() + R"(\Saves)")) {
        files.push_back(entry.path().filename().string());
        cout << i + 1 << ". " << files[i] << endl;
        i++;
    }
    if (files.empty() && !out) {
        cout << "Файлов не обнаруженно" << endl;
        return "";
    }
    if (out)
        cout << "0. Создать новый файл / Сохранить в другом месте";
    else
        cout << "0. Загрузить из стороннего файла";
    int selectedFileIndex = tryInputNum(0, files.size());
    if (selectedFileIndex == 0)
    {
        cout << "Введите имя файла\n\n>";
        inputString(cin, name);
        if (filesystem::path(name).is_absolute())
            return name;
        else
            return R"(Saves\)" + name;
    }
    else
        return R"(Saves\)" + files[selectedFileIndex - 1];
}

void SetEnumAttribute(const std::vector<std::string>& params, int& attribute, const string& attributeName)
{
    cout << "Выберите " << attributeName << ":" << endl;
    for (int i = 0; i < params.size(); i++)
        cout << endl << i + 1 << ". " << params[i];
    attribute = tryInputNum(1, params.size()) - 1;
}

void SetStringAttribute(std::string& attribute, const string& attributeName)
{
    cout << "Введите " << attributeName << ":";
    cout << "\n\n> ";
    inputString(cin, attribute);
}

void SetNumAttribute(double& attribute, double min, double max, const string& attributeName)
{
    cout << "Введите " << attributeName << ":";
    if (min > max)
    {
        cout << "Ошибка: минимальное число больше максимального";
        return;
    }
    attribute = tryInputNum(min, max);
}

void SetBoolAttribute(const std::pair<std::string, std::string>& options, bool& attribute, const string& attributeName)
{
    cout << "Выберите " << attributeName << ":" << endl;
    cout << "1. " << options.first << endl;
    cout << "2. " << options.second;
    attribute = tryInputNum(1, 2) == 1;
}



