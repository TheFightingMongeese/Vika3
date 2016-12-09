#ifndef COMPUTERREPOSITORY_H
#define COMPUTERREPOSITORY_H

#include <vector>
#include <string>
#include <QSqlDatabase>

#include "models/computer.h"


/**
 * @brief The computerRepository class handles reading and writing scientists to and from a file
 */
class ComputerRepository
{
public:
    ComputerRepository();

    /**
     * @brief getAllComputers fetches all computers from the data file
     * @return a vector containing all computers in the data file
     */
    std::vector<Computer> getAllComputers();

    /**
     * @brief searchForComputers fetches all computers from file and filters them on searchTerm
     * @param searchTerm Contains the input that the user wishes to filter on
     * @return a vector of computers filtered by searchTerm
     */
    std::vector<Computer> searchForComputers(std::string searchTerm);

    /**
     * @brief addComputer saves a computer model to a file
     * @param computer The model to save
     * @return true if it was a success, false if it was a failure
     */
    bool addComputer(Computer computer);

private:
    QSqlDatabase db;
    std::string fileName;
};

#endif // COMPUTERREPOSITORY_H
