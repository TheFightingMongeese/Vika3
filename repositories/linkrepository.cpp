#include "linkrepository.h"
#include "utilities/utils.h"
#include "models/relation.h"
#include <cstdlib>
#include <sstream>
#include <QString>

using namespace std;

LinkRepository::LinkRepository()
{
    db = utils::getDatabaseConnection();
}

bool LinkRepository::addLink(QString scientistId, QString computerId)
{
    db.open();

    if (!db.isOpen())
    {
        return false;
    }

    QSqlQuery query(db);

    stringstream sqlQuery;
    sqlQuery << "INSERT INTO relations (scientistId, computerId) VALUES ("
             << "'" << scientistId.toStdString() << "', "
             << "'" << computerId.toStdString() << "'"
             << ")";

    if (!query.exec(QString::fromStdString(sqlQuery.str())))
    {
        return false;
    }

    //db.close();

    return true;
}

vector<Relation> LinkRepository::getAllRelations()
{
    vector<Relation> results;

    stringstream sql;
    sql << "SELECT Scientists.ID as 'ScientistID', Scientists.Name as 'ScientistName', Computers.ID as 'ComputerID', Computers.name as 'ComputerName'";
    sql << "FROM Relations ";
    sql << "    INNER JOIN Scientists ON ";
    sql << "        Relations.ScientistID = Scientists.ID ";
    sql << "    INNER JOIN Computers ON ";
    sql << "        Relations.ComputerID = Computers.ID ";

    QSqlQuery query(db);
    query.prepare(QString::fromStdString(sql.str()));
    query.exec();

    while(query.next())
    {
        int scientistID = query.value("ScientistID").toInt();
        QString name = query.value("ScientistName").toString();

        int computerID = query.value("ComputerID").toInt();
        QString computerName = query.value("ComputerName").toString();

        Scientist scientist(scientistID, name);
        Computer computer(computerID, computerName);

        results.push_back(Relation(scientist, computer));
    }
    return results;

}

/*vector<Link> LinkRepository::searchForLinks(string searchTerm)         á eftir að útfæra SQL fallið til að leita af ID eftir nafni
{
    stringstream sqlQuery;
    sqlQuery << "SELECT * FROM Scientists WHERE name LIKE '%" << searchTerm.toStdString() << "%"
           << "' UNION "
           << "SELECT * FROM Computers WHERE name LIKE '%" << searchTerm.toStdString()  << "%"
           << "' UNION "
           << "SELECT * FROM Scientists WHERE yearDied LIKE '%" << searchTerm.toStdString()  << "%'";

    return queryScientists(QString::fromStdString(sqlQuery.str()));
}*/

bool LinkRepository::removeLink(QString scientistId, QString computerId)

{
    db.open();

    if (!db.isOpen())
    {
        return false;
    }

    QSqlQuery query(db);

    stringstream sqlQuery;
    sqlQuery << "DELETE FROM relations WHERE "
             << "scientistId = '" << scientistId.toStdString() << "' AND "
             << "computerId = '" << computerId.toStdString() << "'";

    if (!query.exec(QString::fromStdString(sqlQuery.str())))
    {
        return false;
    }

    //db.close();

    return true;
}

