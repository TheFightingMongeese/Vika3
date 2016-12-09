#include "models/computer.h"
#include "utilities/utils.h"
#include "utilities/constants.h"

using namespace std;


Computer::Computer(string name, enum computerType type)
{
    _name = name;
    _type = type;
    _yearOfBuild = constants::YEAR_OF_BUILD_DEFAULT_VALUE;
}

Computer::Computer(string name, enum computerType type, int yearOfBuild)
{
    _name = name;
    _type = type;
    _yearOfBuild = yearOfBuild;
}

std::string Computer::getName() const
{
    return _name;
}

enum computerType Computer::getType() const
{
    return _type;
}

int Computer::getYearOfBuild() const
{
    return _yearOfBuild;
}

bool Computer::getBuilt() const
{
    return _yearOfBuild != constants::YEAR_OF_BUILD_DEFAULT_VALUE;
}

bool Computer::contains(string searchTerm)
{
    string searchTermLower = utils::stringToLower(searchTerm);

    string nameLower = utils::stringToLower(_name);
    if (nameLower.find(searchTermLower) != string::npos)
    {
        return true;
    }

    if (searchTermLower == "electronic" && _type == computerType::electronic)
    {
        return true;
    }

    if (searchTermLower == "mechanical" && _type == computerType::mechanical)
    {
        return true;
    }

    if (_yearOfBuild != constants::YEAR_OF_BUILD_DEFAULT_VALUE)
    {
        string yearOfBuildString = utils::intToString(_yearOfBuild);

        if (yearOfBuildString.find(searchTerm) != string::npos)
        {
            return true;
        }
    }

    if (searchTermLower == "Not built" && !this->getBuilt())
    {
        return true;
    }

    return false;
}
