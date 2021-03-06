#ifndef SCIENTIST_H
#define SCIENTIST_H

#include <QString>
#include <vector>

/**
 * @brief The data model for scientists
 */

// Forward declaration to let Scientist know that Computer exists
class Computer;

enum sexType {
    female,
    male
};

class Scientist
{
public:
    Scientist();
    ~Scientist();
    Scientist(QString name, sexType sex, int yearBorn);
    Scientist(QString name, sexType sex, int yearBorn, int yearDied);
    Scientist(unsigned int id, QString name, sexType sex, int yearBorn, int yearDied);
    Scientist(unsigned int id, QString name);
    unsigned int getId();
    QString getName() const;
    enum sexType getSex() const;
    QString getSexAsString();
    int getYearBorn() const;
    int getYearDied() const;
    std::vector<Computer*> getComputers() const;

    void setID(int id);
    void setComputers(std::vector<Computer> computers);

    bool contains(QString searchTerm);

private:
    void destroyComputers();

    unsigned int id;
    QString name;
    sexType sex;
    int yearBorn;
    int yearDied;

    // Computer now has to be a pointer
    std::vector<Computer*> computers;
};

#endif // SCIENTIST_H
