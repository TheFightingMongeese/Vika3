#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql>

class Database
{
public:
    Database();
    bool connect();
    void close();
private:
    QSqlDatabase db;
};

#endif // DATABASE_H
