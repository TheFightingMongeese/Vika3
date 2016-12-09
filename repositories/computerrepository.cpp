#include "repositories/computerrepository.h"
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


ComputerRepository::ComputerRepository()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbName = QString::fromStdString(constants::DATABASE_NAME);
    db.setDatabaseName(dbName);
}

std::vector<Computer> ComputerRepository::getAllComputers()
{
    vector<Computer> computers;

    if (db.open())
    {
        QSqlQuery query("SELECT Name, Type, YearOfBuild, Built FROM computers", db);

        while (query.next())
        {
            std::string name = query.value(0).toString().toStdString();
            enum computerType type = utils::stringToType(query.value(1).toString().toStdString());
            int yearOfBuild = query.value(2).toInt();

            if (!yearOfBuild)
            {
                computers.push_back(Computer(name, type));
            }
            else
            {
                computers.push_back(Computer(name, type, yearOfBuild));
            }
        }
    }

    db.close();

    return computers;
}

vector<Computer> ComputerRepository::searchForComputers(string searchTerm)
{
    vector<Computer> allComputers = getAllComputers();
    vector<Computer> filteredComputers;

    for (unsigned int i = 0; i < allComputers.size(); i++)
    {
        if (allComputers.at(i).contains(searchTerm))
        {
            filteredComputers.push_back(allComputers.at(i));
        }
    }

    return filteredComputers;
}

bool ComputerRepository::addComputer(Computer computer)
{
    if (db.open())
    {
        string name = computer.getName();
        enum computerType type = computer.getType();
        int yearOfBuild = computer.getYearOfBuild();

        QSqlQuery query;

        query.prepare("INSERT INTO computers (Name, Type, YearOfBuild, Built) VALUES (:name, :type, :YearOfBuild, :Built)");
        query.bindValue(":name", QString::fromStdString(name));
        query.bindValue(":type", type);

        if (yearOfBuild != constants::YEAR_OF_BUILD_DEFAULT_VALUE)
        {
            query.bindValue(":YearOfBuild", yearOfBuild);
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
