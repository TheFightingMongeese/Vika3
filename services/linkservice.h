#ifndef LINKSERVICE_H
#define LINKSERVICE_H

#include "repositories/linkrepository.h"

/**
 * @brief The LinkService acts as a middle layer between the UI and Data layers
 */

class LinkService
{
public:
    LinkService();

    /**
     * @brief addLink saves a link between scientists and computers to a database
     * @param scientistId The scientist id to connect to
     * @param computerId The computer id to connect to
     * @return true if it was a success, false if it was a failure
     */
    bool addLink(QString scientistId, QString computerId);

    /**
     * @brief removeLink removes a link between scientists and computers to a database
     * @param scientistId The scientist id to connect to
     * @param computerId The computer id to connect to
     * @return true if it was a success, false if it was a failure
     */
    bool removeLink(QString scientistId, QString computerId);
    std::vector<Relation> GetAllLinks();
private:
    LinkRepository linkRepo;
};

#endif // LINKSERVICE_H
