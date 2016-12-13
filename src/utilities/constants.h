#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string>

/**
 * This file contains constants that this application uses
 */

namespace constants {
    const std::string DATABASE_NAME = "scientists.sqlite";
    const char FILE_DELIMETER = '\t';
    const int YEAR_DIED_DEFAULT_VALUE = 13337;
    const int YEAR_OF_BUILD_DEFAULT_VALUE = 51994;

    const unsigned int MENU_COMMAND_WIDTH = 5;
    const unsigned int SORT_COMMAND_WIDTH = 15;

    const std::string SORT_SCIENTIST_NAME_ASCENDING = "name-asc";
    const std::string SORT_SCIENTIST_NAME_DESCENDING = "name-desc";
    const std::string SORT_SCIENTIST_YEAR_BORN_ASCENDING = "born-asc";
    const std::string SORT_SCIENTIST_YEAR_BORN_DESCENDING = "born-desc";
    const std::string SORT_SCIENTIST_YEAR_DIED_ASCENDING = "died-asc";
    const std::string SORT_SCIENTIST_YEAR_DIED_DESCENDING = "died-desc";

    const std::string SORT_COMPUTER_NAME_ASCENDING = "name-asc";
    const std::string SORT_COMPUTER_NAME_DESCENDING = "name-desc";
    const std::string SORT_COMPUTER_YEAR_OF_BUILD_ASCENDING = "build-asc";
    const std::string SORT_COMPUTER_YEAR_OF_BUILD_DESCENDING = "build-desc";
    const std::string SORT_COMPUTER_TYPE_ASCENDING = "built-asc";
    const std::string SORT_COMPUTER_TYPE_DESCENDING = "built-desc";
}

#endif // CONSTANTS_H

