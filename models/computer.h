#ifndef COMPUTER_H
#define COMPUTER_H

#include <string>

enum computerType {
    mechanical,
    electronic,
    electromechanical
};

/**
 * @brief The data model for computers
 */
class Computer
{
public:
    Computer(std::string name, computerType type);
    Computer(std::string name, computerType type, int yearOfBuild);

    int getID() const;
    std::string getName() const;
    enum computerType getType() const;
    int getYearOfBuild() const;
    bool getBuilt() const;

    void setID(int id);

    bool contains(std::string searchTerm);

private:
    int _id;
    std::string _name;
    enum computerType _type;
    int _yearOfBuild;
    int _built;
};

#endif // COMPUTER_H
