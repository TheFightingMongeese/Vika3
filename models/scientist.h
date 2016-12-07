#ifndef SCIENTIST_H
#define SCIENTIST_H

#include <string>

enum genderType {
    female,
    male
};

/**
 * @brief The data model for scientists
 */
class Scientist
{
public:
    Scientist(std::string name, genderType sex, int yearBorn);
    Scientist(std::string name, genderType sex, int yearBorn, int yearDied);

    std::string getName() const;
    enum genderType getGender() const;
    int getYearBorn() const;
    int getYearDied() const;

    bool contains(std::string searchTerm);

private:
    std::string _name;
    enum genderType _gender;
    int _yearBorn;
    int _yearDied;
};

#endif // SCIENTIST_H
