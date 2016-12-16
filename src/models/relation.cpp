#include "relation.h"

using namespace std;

Relation::Relation(Scientist scientist, Computer computer)
{
    this->scientist = scientist;
    this->computer = computer;
}

Scientist Relation::getScientist()
{
    return scientist;
}

Computer Relation::getComputer()
{
    return computer;
}

QString Relation::toString()
{
    return "bla";
}

bool Relation::contains(string str)
{
    return true;
}
