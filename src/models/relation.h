#ifndef RELATION_H
#define RELATION_H
#include "scientist.h"
#include "computer.h"

class Relation
{
public:
    Relation(int id, Scientist scientist, Computer computer);
    Relation(Scientist scientist, Computer computer);

    Scientist getScientist();
    Computer getComputer();

    QString toString();
    bool contains(std::string str);

private:
    Scientist scientist;
    Computer computer;
};

#endif // RELATION_H
