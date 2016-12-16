#ifndef LINKREPOSITORY_H
#define LINKREPOSITORY_H

#include "models/relation.h"
#include <QtSql>
#include <vector>
#include <string>

/**
 * @brief The LinkRepository handles connections between scientists and computers in the database
 */

class LinkRepository
{
public:
    LinkRepository();

    /**
     * @brief addLink saves a link between scientist and computer to the database
     * @param scientistId The scientist id to connect to
     * @param computerId The computer id to connect to
     * @return true if it was a success, false if it was a failure
     */
    bool addLink(QString scientistId, QString computerId);

    /**
     * @brief removeLink removes a link between scientist and computer to the database
     * @param scientistId The scientist id to connect to
     * @param computerId The computer id to connect to
     * @return true if it was a success, false if it was a failure
     */
    bool removeLink(QString scientistId, QString computerId);
    std::vector<Relation> getAllRelations();
private:
    QSqlDatabase db;
};

#endif // LINKREPOSITORY_H
