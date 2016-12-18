#include "computerrepository.h"
#include "utilities/utils.h"

using namespace std;

ComputerRepository::ComputerRepository()
{
    db = utils::getDatabaseConnection();
}

vector<Computer> ComputerRepository::queryComputers(QString sqlQuery)
{
    vector<Computer> computers;

    db.open();

    if (!db.isOpen())
    {
        return computers;
    }

    QSqlQuery query(db);

    if (!query.exec(sqlQuery))
    {
        return computers;
    }

    while (query.next())
    {
        int id = query.value("id").toUInt();
        QString name = query.value("name").toString();
        enum computerType type = utils::intToComputerType(query.value("computerType").toInt());
        int yearBuilt = query.value("yearBuilt").toInt();

        computers.push_back(Computer(id, name, type, yearBuilt));
    }

    //db.close();

    for (unsigned int i = 0; i < computers.size(); i++)
    {
        computers.at(i).setScientists(queryScientistsByComputer(computers.at(i)));
    }

    return computers;
}

vector<Computer> ComputerRepository::getAllComputers(QString orderBy, bool orderAscending)
{
    string ascending = ((orderAscending) ? "ASC" : "DESC");

    stringstream sqlQuery;
    sqlQuery << "SELECT * FROM Computers ORDER BY " << orderBy.toStdString() << " " << ascending;

    return queryComputers(QString::fromStdString(sqlQuery.str()));
}

vector<Computer> ComputerRepository::searchForComputers(QString searchTerm)
{
    stringstream sqlQuery;
    sqlQuery << "SELECT * FROM Computers WHERE name LIKE '%" << searchTerm.toStdString() << "%"
           << "' UNION "
           << "SELECT * FROM Computers WHERE computerType LIKE '%" << searchTerm.toStdString() << "%"
           << "' UNION "
           << "SELECT * FROM Computers WHERE yearBuilt LIKE '%" << searchTerm.toStdString() << "%'";

    return queryComputers(QString::fromStdString(sqlQuery.str()));
}

bool ComputerRepository::addComputer(Computer computer)
{
    db.open();

    if (!db.isOpen())
    {
        return false;
    }

    QSqlQuery query(db);

    stringstream sqlQuery;
    sqlQuery << "INSERT INTO Computers (name, computerType, yearBuilt) VALUES ("
             << "'" << computer.getName().toStdString() << "', "
             << computer.getType() << ", "
             << computer.getYearBuilt()
             << ")";

    if (!query.exec(QString::fromStdString(sqlQuery.str())))
    {
        return false;
    }

    //db.close();

    return true;
}

bool ComputerRepository::updateComputer(Computer computer)
{
    db.open();

    if (!db.isOpen())
    {
        return false;
    }

    QSqlQuery query(db);

    stringstream sqlQuery;
    sqlQuery << "UPDATE Computers SET name = '" << computer.getName().toStdString() << "', "
             << "computerType = " << computer.getType() << ", "
             << "yearBuilt = " << computer.getYearBuilt() << " "
             << "WHERE id = " << computer.getId();

    if (!query.exec(QString::fromStdString(sqlQuery.str())))
    {
        return false;
    }

    //db.close();

    return true;
}

std::vector<Scientist> ComputerRepository::queryScientistsByComputer(Computer computer)
{
    vector<Scientist> scientists;

    db.open();

    if (!db.isOpen())
    {
        return scientists;
    }

    QSqlQuery query(db);

    stringstream sqlQuery;
    sqlQuery << "SELECT s.* FROM ScientistComputerConnections scc ";
    sqlQuery << "JOIN Scientists s ";
    sqlQuery << "ON s.id = scc.scientistId ";
    sqlQuery << "WHERE scc.computerId = " << computer.getId();

    query.exec(QString::fromStdString(sqlQuery.str()));

    while (query.next())
    {
        int id = query.value("id").toUInt();
        QString name = query.value("name").toString();
        enum sexType sex = utils::intToSex(query.value("sex").toInt());
        int yearBorn = query.value("yearBorn").toInt();
        int yearDied = query.value("yearDied").toInt();

        scientists.push_back(Scientist(id, name, sex, yearBorn, yearDied));
    }

    return scientists;
}