#ifndef COMPUTERREPOSITORY_H
#define COMPUTERREPOSITORY_H

#include <vector>
#include <string>

#include "db/database.h"
#include "models/computer.h"



class ComputerRepository
{
public:
    ComputerRepository();

    std::vector<Computer> getAllComputers();


    std::vector<Computer> searchForComputers(std::string searchTerm);

    bool addComputer(Computer computer);

private:
    Database db;
};

#endif // COMPUTERREPOSITORY_H
