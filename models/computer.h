#ifndef COMPUTER_H
#define COMPUTER_H

#include <string>

enum computerType {
    mechanical,
    electronic,
};

/**
 * @brief The data model for computers
 */
class Computer
{
public:
    Computer(std::string name, computerType type);
    Computer(std::string name, computerType type, int yearOfBuild);

    std::string getName() const;
    enum computerType getType() const;
    int getYearOfBuild() const;
    bool getBuilt() const;

    bool contains(std::string searchTerm);

private:
    std::string _name;
    enum computerType _type;
    int _yearOfBuild;
    int _built;
};

#endif // COMPUTER_H
