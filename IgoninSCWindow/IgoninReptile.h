#ifndef IGONINREPTILE
#define IGONINREPTILE

#pragma once
#include "IgoninAnimal.h"
#include <boost/serialization/base_object.hpp>

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
        ar& boost::serialization::base_object<IgoninAnimal>(*this);
        ar& isPoisonous;
        ar& tailLength;
    }
    std::unordered_map<std::string, std::string> getAnimalData();
    void SetParamsFromConsole();
    void Print();
};

#endif // IGONINREPTILE
