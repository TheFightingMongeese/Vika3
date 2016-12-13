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
        QSqlQuery query("SELECT ID, Name, Gender, YearBorn, YearDied FROM scientists");

        while (query.next())
        {
            int id = query.value(0).toInt();
            std::string name = query.value(1).toString().toStdString();
            enum genderType gender = utils::stringToGender(query.value(2).toString().toStdString());
            int yearBorn = query.value(3).toInt();
            int yearDied = query.value(4).toInt();

            if (!yearDied)
            {
                Scientist scientist(name, gender, yearBorn);
                scientist.setID(id);
                scientists.push_back(scientist);
            }
            else
            {
                Scientist scientist(name, gender, yearBorn, yearDied);
                scientist.setID(id);
                scientists.push_back(scientist);
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
    bool success = false;
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
        success = query.exec();
    }

    db.close();
    return success;
}

bool ScientistRepository::connectComputer(int scientistID, int computerID)
{
    bool success = false;
    if (db.connect())
    {
        QSqlQuery query;
        query.prepare("INSERT INTO relations (ScientistID, ComputerID) VALUES (:scientistID, :computerID)");
        query.bindValue(":scientistID", scientistID);
        query.bindValue(":computerID", computerID);
        success = query.exec();

        if (!success)
        {
            qDebug() << "\nInsert relation error: " << query.lastError();
        }
    }

    db.close();
    return success;
}

