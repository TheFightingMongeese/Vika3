#include "utilities/computercomparator.h"


ComputerComparator::ComputerComparator(std::string column, bool sortInAscendingOrder)
{
    this->sortColumn = column;
    this->sortInAscendingOrder = sortInAscendingOrder;
}

bool ComputerComparator::operator() (const Computer& first, const Computer& second)
{
    if (sortColumn == "name")
    {
        if (sortInAscendingOrder)
        {
            return first.getName() < second.getName();
        }
        else
        {
            return second.getName() < first.getName();
        }
    }
    else if (sortColumn == "YearOfBuild")
    {
        if (sortInAscendingOrder)
        {
            return first.getYearOfBuild() < second.getYearOfBuild();
        }
        else
        {
            return second.getYearOfBuild() < first.getYearOfBuild();
        }
    }

    return false;
}

