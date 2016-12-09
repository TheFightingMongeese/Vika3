#ifndef COMPUTERCOMPARATOR_H
#define COMPUTERCOMPARATOR_H

#include "models/computer.h"

class computercomparator
{
public:
    computercomparator(std::string sortColumn, bool sortInAscendingOrder);

    bool operator() (const Computer& first, const Computer& second);
private:
    std::string sortColumn;
    bool sortInAscendingOrder;
};
#endif // COMPUTERCOMPARATOR_H
