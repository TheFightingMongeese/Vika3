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

    db.close();

    return true;
}

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

    db.close();

    return true;
}

