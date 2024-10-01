#include "IgoninReptile.h"
#include "IgoninForest.h"

using namespace std;

const std::pair<std::string, std::string> IgoninReptile::PoisonousState = { "€довито", "не €довито" };

std::vector<std::string> IgoninReptile::setterOptions()
{
	auto all = IgoninAnimal::setterOptions();
	all.push_back("€довитость");
	all.push_back("длину хвоста");
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
	cout << format("{:<15}", "ядовитость: ") << poison << endl;
	cout << format("{:<15}", "ƒлина хвоста: ") << tailLength << endl;
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
