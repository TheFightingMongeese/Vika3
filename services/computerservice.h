#ifndef COMPUTERSERVICE_H
#define COMPUTERSERVICE_H

#include "repositories/computerrepository.h"
#include "utilities/enums.h"

/**
 * @brief The ComputerService acts as a middle layer between the UI and Data layers, also handles sorting
 */
class ComputerService
{
public:
    ComputerService();

    /**
     * @brief getAllComputers fetches computers from the ComputersRepository and sorts them
     * @param orderBy Which column the computers should be sorted on
     * @param orderAscending Should the list be sorted in ascending order?
     * @return a vector containing all computers in the repository
     */
    std::vector<Computer> getAllComputers(std::string orderBy, bool orderAscending);

    /**
     * @brief searchForComputers fetches all computers from file and filters them on searchTerm
     * @param searchTerm Contains the input that the user wishes to filter on
     * @return a vector of computers filtered by searchTerm
     */
    std::vector<Computer> searchForComputers(std::string searchTerm);

    /**
     * @brief addComputers saves a computers model to a file
     * @param computers The model to save
     * @return enum value which indicates the result of the operation (see addStatus definition)
     */
    enum addStatus addComputer(Computer computer);
private:
    ComputerRepository computerRepo;
};

#endif // COMPUTERSERVICE_H
