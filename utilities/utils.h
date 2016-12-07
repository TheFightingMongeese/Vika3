#ifndef UTILS_H
#define UTILS_H

#include <cstdlib>
#include <sstream>
#include <vector>
#include <string>

#include "models/scientist.h"

/**
 * This file contains reusable utility functions used throughout the application
 */

namespace utils {    
    std::vector<std::string> splitString(std::string line, char delimeter);

    int stringToInt(std::string str);

    std::string stringToLower(std::string str);

    std::string intToString(int number);

    enum genderType intToGender(int number);

    enum genderType stringToGender(std::string str);
}

#endif // UTILS_H

