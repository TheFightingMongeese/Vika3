#include "services/scientistservice.h"
#include "utilities/scientistcomparator.h"
#include "utilities/constants.h"

#include <algorithm>

using namespace std;

ScientistService::ScientistService()
{

}

std::vector<Scientist> ScientistService::getAllScientists(std::string orderBy, bool orderAscending)
{
    vector<Scientist> scientists = scientistRepo.getAllScientists();

    std::sort(scientists.begin(), scientists.end(), ScientistComparator(orderBy, orderAscending));

    return scientists;
}

std::vector<Scientist> ScientistService::searchForScientists(std::string searchTerm)
{
    return scientistRepo.searchForScientists(searchTerm);
}

enum addStatus ScientistService::addScientist(Scientist scientist)
{
    // Validate the input:

    if (scientist.getName() == "")
    {
        return addStatus::nameMissing;
    }
    else if (scientist.getYearBorn() == 0)
    {
        return addStatus::yearBornMissing;
    }
    else if (scientist.getYearDied() != constants::YEAR_DIED_DEFAULT_VALUE)
    {
        if (scientist.getYearDied() < scientist.getYearBorn())
        {
            return addStatus::yearDiedBeforeYearBorn;
        }
    }

    // Validation complete. Ask the data layer to store the
    // new entry:
    bool result = scientistRepo.addScientist(scientist);

    if (result == false)
    {
        return addStatus::generalFailure;
    }

    return addStatus::success;
}
