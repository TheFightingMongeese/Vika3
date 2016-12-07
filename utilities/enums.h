#ifndef ENUMS_H
#define ENUMS_H

/**
 * @brief Specifies all possible return values from the add command.
 * Adding a scientist may fail for several reasons:
 * * The data could not be written to the file
 * * The data is invalid (i.e. validation failed)
 * * etc.
 */
enum addStatus
{
    success = 1,
    nameMissing = 2,
    yearBornMissing = 3,
    yearDiedBeforeYearBorn = 4,
    invalidInput = 5,
    generalFailure = 6
};

#endif // ENUMS_H
