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
}

std::vector<Computer> ComputerRepository::getAllComputers()
{
    vector<Computer> computers;

    if (db.connect())
    {
        QSqlQuery query("SELECT ID, Name, ComputerType, YearOfBuild FROM computers");

        while (query.next())
        {
            int id = query.value(0).toInt();
            std::string name = query.value(1).toString().toStdString();
            enum computerType type = utils::stringToType(query.value(2).toString().toStdString());
            int yearOfBuild = query.value(3).toInt();

            if (!yearOfBuild)
            {
                Computer computer(name, type);
                computer.setID(id);
                computers.push_back(computer);
            }
            else
            {
                Computer computer(name, type, yearOfBuild);
                computer.setID(id);
                computers.push_back(computer);
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
    bool success = true;
    if (db.connect())
    {
        string name = computer.getName();
        enum computerType type = computer.getType();
        int yearOfBuild = computer.getYearOfBuild();

        QSqlQuery query;

        query.prepare("INSERT INTO computers (Name, ComputerType, YearOfBuild) VALUES (:name, :type, :YearOfBuild)");
        query.bindValue(":name", QString::fromStdString(name));
        query.bindValue(":type", type);

        if (yearOfBuild != constants::YEAR_OF_BUILD_DEFAULT_VALUE)
        {
            query.bindValue(":YearOfBuild", yearOfBuild);
        }

        success = query.exec();

        if (!success)
        {
            qDebug() << "\nInsert computer error: " << query.lastError();
        }
    }

    db.close();
    return success;
}
