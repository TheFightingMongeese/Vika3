#include "repositories/scientistrepository.h"
#include "utilities/utils.h"
#include "utilities/constants.h"

#include <fstream>
#include <cstdlib>
#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>
#include <QDir>

using namespace std;


ScientistRepository::ScientistRepository()
{
}

std::vector<Scientist> ScientistRepository::getAllScientists()
{
    vector<Scientist> scientists;

    if (db.connect())
    {
        QSqlQuery query("SELECT Name, Gender, YearBorn, YearDied FROM scientists");

        while (query.next())
        {
            std::string name = query.value(0).toString().toStdString();
            enum genderType gender = utils::stringToGender(query.value(1).toString().toStdString());
            int yearBorn = query.value(2).toInt();
            int yearDied = query.value(3).toInt();

            if (!yearDied)
            {
                scientists.push_back(Scientist(name, gender, yearBorn));
            }
            else
            {
                scientists.push_back(Scientist(name, gender, yearBorn, yearDied));
            }
        }
    }

    db.close();

    return scientists;
}

vector<Scientist> ScientistRepository::searchForScientists(string searchTerm)
{
    vector<Scientist> allScientists = getAllScientists();
    vector<Scientist> filteredScientists;

    for (unsigned int i = 0; i < allScientists.size(); i++)
    {
        if (allScientists.at(i).contains(searchTerm))
        {
            filteredScientists.push_back(allScientists.at(i));
        }
    }

    return filteredScientists;
}

bool ScientistRepository::addScientist(Scientist scientist)
{
    if (db.connect())
    {
        string name = scientist.getName();
        enum genderType gender = scientist.getGender();
        int yearBorn = scientist.getYearBorn();
        int yearDied = scientist.getYearDied();

        QSqlQuery query;

        query.prepare("INSERT INTO scientists (name, gender, yearBorn, yearDied) VALUES (:name, :gender, :yearBorn, :yearDied)");
        query.bindValue(":name", QString::fromStdString(name));
        query.bindValue(":gender", gender);
        query.bindValue(":yearBorn", yearBorn);

        if (yearDied != constants::YEAR_DIED_DEFAULT_VALUE)
        {
            query.bindValue(":yearDied", yearDied);
        }
        return query.exec();
    }
    else
    {
        return false;
    }

    db.close();
    return true;
}
