#include "SubFunc.h"
using namespace std;

bool inString(std::string str_where, std::string str_what)
{
	bool state = false;
    if (str_what.size() == 0)
        state = true;
    else
        for (int i = 0; i < str_where.size() - str_what.size() + 1; i++)
        {
            int cnt = 0;
            for (int j = 0; j < str_what.size(); j++)
                if (tolower(static_cast<unsigned char>(str_where[i + j])) == tolower(static_cast<unsigned char>(str_what[j])))
                    cnt++;
            if (cnt == str_what.size())
            {
                state = true;
                break;
            }
        }
    return state;
}

void inputString(istream& in, string& str)
{
    in.ignore(1, '\n');
    getline(in, str);
    cout << endl;
    //cerr << str << endl;
}

float tryInputNum(float min, float max)
{
    float num;
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

int tryChoose(int min, int max)
{
    int num;
    cout << "\n\n> ";
    while ((cin >> num).fail() || (num < min) || (num > max)) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "\n> ";
    }
    cout << endl;
    //cerr << num << endl;
    return num;
}

std::vector <int> enterInterval(int elements_cnt)
{
    cout << "Выберите первый объект:";
    int f_index = tryChoose(1, elements_cnt);
    cout << "Выберите последний объект:";
    int l_index = tryChoose(1, elements_cnt);
    
    if (f_index > l_index)
    {
        int t = f_index;
        f_index = l_index;
        l_index = t;
    }

    vector<int> index_ch;
    for (int i = f_index - 1; i < l_index; i++)
        index_ch.push_back(i);
    return index_ch;
}

std::vector <int> enterPacket(int elements_cnt)
{
    cout << "Введите количество объектов для выбора:";
    int pipes_cnt = tryChoose(1, elements_cnt);

    vector<int> index_ch;
    for (int i = 0; i < pipes_cnt; i++)
    {
        cout << "Введите индекс объекта:";
        int index_sel = tryChoose(1, elements_cnt) - 1;
        bool t = false;
        for (int j = 0; j < index_ch.size(); j++)
            t = index_sel == index_ch[j] ? true || t : false || t;
        if (!t) 
            index_ch.push_back(index_sel);
    }

    return index_ch;
}

int enterElement(int elements_cnt)
{
    cout << "Введите индекс объекта:";
    int index_ch = tryChoose(1, elements_cnt) - 1;
    return index_ch;
}

std::vector <int> choosingElements(int elements_cnt)
{
    cout << "1. Выбрать объекты на интервале" << endl << "2. Выбрать несколько объектов" << endl << "3. Выбрать один объект";
    int number = tryChoose(1, 3);
    vector<int> index_ch;
    switch (number)
    {
    case 1:
        index_ch = enterInterval(elements_cnt);
        break;
    case 2:
        index_ch = enterPacket(elements_cnt);
        break;
    case 3:
        index_ch.push_back(enterElement(elements_cnt));
        break;
    default:
        break;
    }
    return index_ch;
}

std::string chooseFiles()
{
    cout << "Choose file (press Enter to exit):\n" << endl;
    for (const auto& entry : filesystem::directory_iterator(filesystem::current_path().string() + R"(\Saves)"))
        cout << entry.path().filename() << endl;
    string name;
    cout << "\n> ";
    inputString(cin, name);
    if (!name.empty())
        return filesystem::current_path().string() + R"(\Saves\)" + name;
    else
        return "";
}



