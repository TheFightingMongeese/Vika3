#include "linkservice.h"

#include <string>

using namespace std;

LinkService::LinkService()
{

}

bool LinkService::addLink(QString scientistId, QString computerId)
{
    return linkRepo.addLink(scientistId, computerId);
}

bool LinkService::removeLink(QString scientistId, QString computerId)
{
    return linkRepo.removeLink(scientistId, computerId);
}
std::vector<Relation> LinkService::GetAllLinks()
{
    return linkRepo.getAllRelations();
}
