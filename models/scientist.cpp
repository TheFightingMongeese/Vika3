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

Scientist::Scientist(QString name, enum sexType sex, int yearBorn){
    id = 0;
    this->name = name;
    this->sex = sex;
    this->yearBorn = yearBorn;
    this->yearDied = 0;
}
Scientist::Scientist(unsigned int id, QString name){
    this->id = id;
    this->name = name;
}
Scientist::Scientist(QString name, enum sexType sex, int yearBorn, int yearDied)
{
    id = 0;
    this->name = name;
    this->sex = sex;
    this->yearBorn = yearBorn;
    this->yearDied = yearDied;
}

Scientist::Scientist(unsigned int id, QString name, sexType sex, int yearBorn, int yearDied)
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

QString Scientist::getName() const
{
    return name;
}

enum sexType Scientist::getSex() const
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

void Scientist::setID(int id)
{
    this->id = id;
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

bool Scientist::contains(QString searchTerm)
{
    QString searchTermLower = utils::stringToLower(searchTerm);

    QString nameLower = utils::stringToLower(name);
    if (nameLower.contains(searchTermLower) != string::npos)
    {
        return true;
    }

    if (searchTermLower == "male" && sex == sexType::male)    {
        return true;
    }

    if (searchTermLower == "female" && sex == sexType::female)    {
        return true;
    }

    QString yearBornString = utils::intToString(yearBorn);

    if (yearBornString.contains(searchTerm) != string::npos)
    {
        return true;
    }

    if (yearDied != 0)
    {
        QString yearDiedString = utils::intToString(yearDied);

        if (yearDiedString.contains(searchTerm) != string::npos)
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
