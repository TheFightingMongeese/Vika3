#ifndef UTILS_H
#define UTILS_H

#include <cstdlib>
#include <sstream>
#include <vector>
#include <string>
#include <QtSql>

#include "models/scientist.h"
#include "models/computer.h"

/**
 * This file contains reusable utility functions used throughout the application
 */

namespace utils {
    std::vector<QString> split(QString line, char delimeter);

    int stringToInt(QString str);

    QString stringToLower(QString str);

    QString intToString(int number);

    enum sexType intToSex(int number);

    enum computerType intToComputerType(int number);

    enum sexType stringToSex(QString str);

    QString sexToString(sexType type);

    QString typeToString(computerType type);


    QSqlDatabase getDatabaseConnection();
}

#endif // UTILS_H

