#pragma once
#include "IgoninAnimal.h"

class IgoninReptile : public IgoninAnimal
{
    friend std::ostream& operator>> (std::ostream& stream_in, IgoninReptile& reptile);
    friend std::ostream& operator<< (std::ostream& stream_out, IgoninReptile& reptile);
private:
    bool isPoisonous;
    std::vector<std::string> setterOptions();
    static const std::pair<std::string, std::string> PoisonousState;
    double tailLength;
public:
    template<class Archive>
    void serialize(Archive& ar, const unsigned int version) {
        IgoninAnimal::serialize(ar, version);
        ar& isPoisonous;
        ar& tailLength;
    }

    void SetParamsFromConsole();
    void Print();
};


