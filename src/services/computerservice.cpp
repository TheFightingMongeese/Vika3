#include "services/computerservice.h"
#include "utilities/computercomparator.h"
#include "utilities/constants.h"
#include <iostream>
#include <algorithm>

using namespace std;

ComputerService::ComputerService()
{
}

std::vector<Computer> ComputerService::getAllComputers(std::string orderBy, bool orderAscending)
{
    vector<Computer> Computers = computerRepo.getAllComputers();
    std::sort(Computers.begin(), Computers.end(), ComputerComparator(orderBy, orderAscending));

    return Computers;
}

std::vector<Computer> ComputerService::searchForComputers(std::string searchTerm)
{
    return computerRepo.searchForComputers(searchTerm);
}

enum addStatus ComputerService::addComputer(Computer computer)
{
    // Validate the input:

    if (computer.getName() == "")
    {
        return addStatus::nameMissing;
    }

    // Validation complete. Ask the data layer to store the
    // new entry:
    bool result = computerRepo.addComputer(computer);

    if (result == false)
    {
        return addStatus::generalFailure;
    }

    return addStatus::success;
}
