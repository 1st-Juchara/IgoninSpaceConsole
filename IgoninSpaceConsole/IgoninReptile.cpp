#include "IgoninReptile.h"
#include "IgoninForest.h"

using namespace std;

const std::pair<std::string, std::string> IgoninReptile::PoisonousState = { "�������", "�� �������" };

std::vector<std::string> IgoninReptile::setterOptions()
{
	auto all = IgoninAnimal::setterOptions();
	all.push_back("����������");
	all.push_back("����� ������");
	return all;
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
	cout << format("{:<15}", "����������: ") << poison << endl;
	cout << format("{:<15}", "����� ������: ") << tailLength << endl;
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
