#include "IgoninReptile.h"
#include "IgoninForest.h"

using namespace std;

const std::pair<std::string, std::string> IgoninReptile::PoisonousState = { "ядовито", "не ядовито" };

std::vector<std::string> IgoninReptile::setterOptions()
{
    auto all = IgoninAnimal::setterOptions();
    all.push_back("ядовитость");
    all.push_back("длину хвоста");
    return all;
}

std::unordered_map<std::string, std::string> IgoninReptile::getAnimalData()
{
    unordered_map<string, string> animalData = IgoninAnimal::getAnimalData();
    animalData.insert({"Ядовитость", isPoisonous ? PoisonousState.first : PoisonousState.second});
    animalData.insert({"Длина хвоста", to_string(tailLength)});
    return animalData;
}

void IgoninReptile::SetParamsFromMap(std::unordered_map<string, string> &animalData)
{
    IgoninAnimal::SetParamsFromMap(animalData);
    isPoisonous = animalData["Ядовитость"] == PoisonousState.first;
    tailLength = stoi(animalData["Длина хвоста"]);
}

void IgoninReptile::SetParamsFromConsole()
{
    IgoninAnimal::SetParamsFromConsole();
    SetBoolAttribute(PoisonousState, isPoisonous, setterOptions()[6]);
    SetNumAttribute(tailLength, 0, 100, setterOptions()[7]);
}

void IgoninReptile::Print()
{
    IgoninAnimal::Print();
    string poison = isPoisonous ? PoisonousState.first : PoisonousState.second;
    cout << "Ядовитость: " << poison << endl;
    cout << "Длина хвоста: " << tailLength << endl;
}

std::ostream& operator>>(std::ostream& stream_in, IgoninReptile& reptile)
{
    reptile.SetParamsFromConsole();
    return stream_in;
}

std::ostream& operator<<(std::ostream& stream_out, IgoninReptile& reptile)
{
    reptile.Print();
    return stream_out;
}
