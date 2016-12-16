#include "linkrepository.h"
#include "utilities/utils.h"

#include <cstdlib>
#include <sstream>
#include <QString>

using namespace std;

LinkRepository::LinkRepository()
{
    db = utils::getDatabaseConnection();
}

bool LinkRepository::addLink(string scientistId, string computerId)
{
    db.open();

    if (!db.isOpen())
    {
        return false;
    }

    QSqlQuery query(db);

    stringstream sqlQuery;
    sqlQuery << "INSERT INTO relations (scientistId, computerId) VALUES ("
             << "'" << scientistId << "', "
             << "'" << computerId << "'"
             << ")";

    if (!query.exec(QString::fromStdString(sqlQuery.str())))
    {
        return false;
    }

    db.close();

    return true;
}

/*vector<Link> LinkRepository::searchForLinks(string searchTerm)         á eftir að útfæra SQL fallið til að leita af ID eftir nafni
{
    stringstream sqlQuery;
    sqlQuery << "SELECT * FROM Scientists WHERE name LIKE '%" << searchTerm << "%"
           << "' UNION "
           << "SELECT * FROM Computers WHERE name LIKE '%" << searchTerm << "%"
           << "' UNION "
           << "SELECT * FROM Scientists WHERE yearDied LIKE '%" << searchTerm << "%'";

    return queryScientists(QString::fromStdString(sqlQuery.str()));
}*/

bool LinkRepository::removeLink(string scientistId, string computerId)
{
    db.open();

    if (!db.isOpen())
    {
        return false;
    }

    QSqlQuery query(db);

    stringstream sqlQuery;
    sqlQuery << "DELETE FROM relations WHERE "
             << "scientistId = '" << scientistId << "' AND "
             << "computerId = '" << computerId << "'";

    if (!query.exec(QString::fromStdString(sqlQuery.str())))
    {
        return false;
    }

    db.close();

    return true;
}

