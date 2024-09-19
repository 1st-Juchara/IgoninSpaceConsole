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

int enterElement(int elements_cnt)
{
    cout << "Введите индекс объекта:";
    int index_ch = tryInputNum(1, elements_cnt) - 1;
    return index_ch;
}

std::string chooseFiles(const bool& out)
{// is_absolute, vector<string> files, check typr (string, int)?
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
        return name;
    }
    else
        return R"(Saves\)" + files[selectedFileIndex - 1];
}



