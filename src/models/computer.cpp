#include "computer.h"

using namespace std;

Computer::Computer()
{

}

Computer::Computer(string name, enum computerType type)
{
    id = 0;
    this->name = name;
    this->type = type;
    this->yearBuilt = 0;
}

Computer::Computer(string name, enum computerType type, int yearBuilt)
{
    id = 0;
    this->name = name;
    this->type = type;
    this->yearBuilt = yearBuilt;
}

Computer::Computer(unsigned int id, std::string name, enum computerType type, int yearBuilt)
{
    this->id = id;
    this->name = name;
    this->type = type;
    this->yearBuilt = yearBuilt;
}

unsigned int Computer::getId()
{
    return id;
}

string Computer::getName()
{
    return name;
}

int Computer::getYearBuilt()
{
    return yearBuilt;
}

enum computerType Computer::getType()
{
    return type;
}

std::string Computer::getTypeAsString()
{
    if (type == computerType::electronic)
    {
        return "Electronic";
    }
    else if (type == computerType::mechanical)
    {
        return "Mechanical";
    }
    else if (type == computerType::transistor)
    {
        return "Transistor";
    }
    else
    {
        return "Other";
    }
}

bool Computer::wasBuilt()
{
    return yearBuilt != 0;
}

std::vector<Scientist> Computer::getScientists()
{
    return scientists;
}

void Computer::setScientists(std::vector<Scientist> newScientists)
{
    scientists = newScientists;
}
