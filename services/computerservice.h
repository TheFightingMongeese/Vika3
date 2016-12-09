#ifndef COMPUTERSERVICE_H
#define COMPUTERSERVICE_H
#include "repositories/computerrepository.h"




class Computerservice
{
public:
    Computerservice();


    std::vector<Computer> getAllComputers(std::string orderBy, bool orderAscending);


    std::vector<Computer> searchForScientists(std::string searchTerm);


    bool addComputer(Computer computer);
private:

    ComputerRepository ComputerRepo;
};

#endif // COMPUTERSERVICE_H
