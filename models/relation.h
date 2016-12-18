#ifndef RELATION_H
#define RELATION_H
#include "scientist.h"
#include "computer.h"

class Relation
{
public:
    Relation();
    Relation(int id, Scientist scientist, Computer computer);
    Relation(Scientist scientist, Computer computer);

    void setScientistID(int id);
    void setComputerID(int id);
    Scientist getScientist();
    Computer getComputer();

private:
    Scientist scientist;
    Computer computer;
};

#endif // RELATION_H
