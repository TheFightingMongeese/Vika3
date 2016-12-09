#include "computerservice.h"
#include "utilities/computercomparator.h"
#include "utilities/constants.h"

#include <algorithm>

using namespace std;


Computerservice::Computerservice()
{

}

std::vector<Computer> ComputerService::getAllComputers(std::string orderBy, bool orderAscending)
{
    vector<Computer> computer = computerRepo.getAllComputers();

    std::sort(computer.begin(), computer.end(), ComputerComparator(orderBy, orderAscending));

    return computers;
}

std::vector<Computer> ComputerService::searchForComputers(std::string searchTerm)
{
    return computerRepo.searchForComputers(searchTerm);
}


string addStatus ComputerService::addComputer(Computer computer)
{
    // Validate the input:

    if (computer.getName() == "")
    {
        return "Missing name";
    }
    else if (computer.getType() == "")
    {
        return "Missing Type";
    }
    else if (computer.getYearDesign() == "")
    {
        return "Not built";
    }

    // Validation complete. Ask the data layer to store the
    // new entry:
    bool result = computerRepo.addComputer(computer);

    if (result == false)
    {
        return "Failed to add";
    }

    return "Success!";
}

