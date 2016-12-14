#include "scientist.h"
#include "utilities/utils.h"

using namespace std;

Scientist::Scientist()
{

}

Scientist::~Scientist()
{
    destroyComputers();
}

Scientist::Scientist(string name, string sex, int yearBorn)
{
    id = 0;
    this->name = name;
    this->sex = sex;
    this->yearBorn = yearBorn;
    this->yearDied = 0;
}

Scientist::Scientist(string name, std::string sex, int yearBorn, int yearDied)
{
    id = 0;
    this->name = name;
    this->sex = sex;
    this->yearBorn = yearBorn;
    this->yearDied = yearDied;
}

Scientist::Scientist(unsigned int id, std::string name, std::string sex, int yearBorn, int yearDied)
{
    this->id = id;
    this->name = name;
    this->sex = sex;
    this->yearBorn = yearBorn;
    this->yearDied = yearDied;
}

unsigned int Scientist::getId()
{
    return id;
}

std::string Scientist::getName() const
{
    return name;
}
/*
enum sexType Scientist::getSex() const
{
    return sex;
}
*/

std::string Scientist::getSex() const
{
    return sex;
}

int Scientist::getYearBorn() const
{
    return yearBorn;
}

int Scientist::getYearDied() const
{
    return yearDied;
}

std::vector<Computer*> Scientist::getComputers() const
{
    return computers;
}

void Scientist::setComputers(std::vector<Computer> newComputers)
{
    destroyComputers();

    for (unsigned int i = 0; i < newComputers.size(); i++)
    {
        Computer currentComputer = newComputers.at(i);
        this->computers.push_back(new Computer(currentComputer.getId(), currentComputer.getName(), currentComputer.getType(), currentComputer.getYearBuilt()));
    }
}

bool Scientist::contains(string searchTerm)
{
    string searchTermLower = utils::stringToLower(searchTerm);

    string nameLower = utils::stringToLower(name);
    if (nameLower.find(searchTermLower) != string::npos)
    {
        return true;
    }

    if (searchTermLower == "male" && sex == "male")
    {
        return true;
    }

    if (searchTermLower == "female" && sex == "female")
    {
        return true;
    }

    string yearBornString = utils::intToString(yearBorn);

    if (yearBornString.find(searchTerm) != string::npos)
    {
        return true;
    }

    if (yearDied != 0)
    {
        string yearDiedString = utils::intToString(yearDied);

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

void Scientist::destroyComputers()
{
    for (unsigned int i = 0; i < computers.size(); i++)
    {
        delete computers.at(i);
    }
}
