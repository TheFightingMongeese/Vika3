#include "relation.h"

using namespace std;

Relation::Relation()
{

}

Relation::Relation(Scientist scientist, Computer computer)
{
    this->scientist = scientist;
    this->computer = computer;
}

void Relation::setScientistID(int id)
{
    scientist.setID(id);
}

void Relation::setComputerID(int id)
{
    computer.setID(id);
}

Scientist Relation::getScientist()
{
    return scientist;
}

Computer Relation::getComputer()
{
    return computer;
}
