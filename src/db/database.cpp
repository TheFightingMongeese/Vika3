#include "db/database.h"
#include "utilities/constants.h"

Database::Database()
{
}

bool Database::connect()
{
    QString dbName = QString::fromStdString(constants::DATABASE_NAME);

    if (QSqlDatabase::contains(dbName)) {
        db = QSqlDatabase::database(dbName);
    }
    else
    {
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName(dbName);
    }

    return db.open();
}

void Database::close()
{
    db.close();
}
