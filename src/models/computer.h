#ifndef COMPUTER_H
#define COMPUTER_H

#include <QString>
#include <vector>

// Computer can just include scientist like normally
#include "scientist.h"

/**
 * @brief The data model for computers
 */

enum computerType {
    Electronic,
    Mechanical,
    Transistor,
    Other
};

class Computer
{
public:
    Computer();
    Computer(QString name, enum computerType type);
    Computer(unsigned int id, QString name);
    Computer(QString name, enum computerType type, int yearBuilt);
    Computer(unsigned int id, QString name, enum computerType type, int yearBuilt);

    unsigned int getId();
    QString getName();
    enum computerType getType();
    QString getTypeAsString();

    QString getTypeName();
    int getYearBuilt();
    bool wasBuilt();
    std::vector<Scientist> getScientists();

    void setScientists(std::vector<Scientist> newScientists);

private:
    unsigned int id;
    QString name;
    enum computerType type;
    int yearBuilt;

    std::vector<Scientist> scientists;
};

#endif // COMPUTER_H
