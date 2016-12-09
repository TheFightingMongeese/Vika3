#include "models/scientist.h"
#include "utilities/utils.h"
#include "utilities/constants.h"

using namespace std;

Scientist::Scientist(string name, enum genderType gender, int yearBorn)
{
    _name = name;
    _gender = gender;
    _yearBorn = yearBorn;
    _yearDied = constants::YEAR_DIED_DEFAULT_VALUE;
}

Scientist::Scientist(string name, enum genderType gender, int yearBorn, int yearDied)
{
    _name = name;
    _gender = gender;
    _yearBorn = yearBorn;
    _yearDied = yearDied;
}

void Scientist::setID(int id)
{
    _id = id;
}

int Scientist::getID() const
{
    return _id;
}

std::string Scientist::getName() const
{
    return _name;
}

enum genderType Scientist::getGender() const
{
    return _gender;
}

int Scientist::getYearBorn() const
{
    return _yearBorn;
}

int Scientist::getYearDied() const
{
    return _yearDied;
}

bool Scientist::contains(string searchTerm)
{
    string searchTermLower = utils::stringToLower(searchTerm);

    string nameLower = utils::stringToLower(_name);
    if (nameLower.find(searchTermLower) != string::npos)
    {
        return true;
    }

    if (searchTermLower == "male" && _gender == genderType::male)
    {
        return true;
    }

    if (searchTermLower == "female" && _gender == genderType::female)
    {
        return true;
    }

    string yearBornString = utils::intToString(_yearBorn);

    if (yearBornString.find(searchTerm) != string::npos)
    {
        return true;
    }

    if (_yearDied != constants::YEAR_DIED_DEFAULT_VALUE)
    {
        string yearDiedString = utils::intToString(_yearDied);

        if (yearDiedString.find(searchTerm) != string::npos)
        {
            return true;
        }
    }
    else
    {
        if (searchTermLower == "alive")
        {
            return true;
        }
    }

    return false;
}
