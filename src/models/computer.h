#ifndef COMPUTER_H
#define COMPUTER_H

#include <string>
#include <vector>

// Computer can just include scientist like normally
#include "scientist.h"

/**
 * @brief The data model for computers
 */

enum computerType {
    electronic,
    mechatronic,
    transistor,
    other
};

class Computer
{
public:
    Computer();
    Computer(std::string name, std::string type);
    Computer(std::string name, std::string type, int yearBuilt);
    Computer(unsigned int id, std::string name, std::string type, int yearBuilt);

    unsigned int getId();
    std::string getName();
    std::string getType();

    std::string getTypeName();
    int getYearBuilt();
    bool wasBuilt();
    std::vector<Scientist> getScientists();

    void setScientists(std::vector<Scientist> newScientists);

private:
    unsigned int id;
    std::string name;
    std::string type;
    int yearBuilt;

    std::vector<Scientist> scientists;
};

#endif // COMPUTER_H
