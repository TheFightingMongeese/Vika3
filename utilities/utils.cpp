#include "utilities/utils.h"

#include <sstream>
#include <cstdlib>

namespace utils {
    std::vector<std::string> splitString(std::string line, char delimeter) 
    {
        std::vector<std::string> result;

        std::string currentWord = "";

        for (unsigned int i = 0; i < line.length(); i++) 
        {
            char currentChar = line[i];

            if (currentChar == delimeter) 
            {
                //if  (currentWord.length()) {
                result.push_back(currentWord);
                currentWord = "";
                //}
            } 
            else 
            {
                if (currentChar != '\n') 
                {
                    currentWord += currentChar;
                }
            }
        }

        if (currentWord.length()) 
        {
            result.push_back(currentWord);
        }

        return result;
    }

    int stringToInt(std::string str) 
    {
        return atoi(str.c_str());
    }

    std::string stringToLower(std::string str) 
    {
        std::string result = "";

        for (unsigned int i = 0; i < str.length(); i++)
        {
            char currentCharacter = str[i];

            // http://www.asciitable.com/
            if (currentCharacter <= 90 && currentCharacter >= 65)
            {
                result += currentCharacter + 32;
            }
            else
            {
                result += currentCharacter;
            }
        }

        return result;
    }

    std::string intToString(int number) 
    {
        std::stringstream stream;
        stream << number;
        return stream.str();
    }

    enum genderType intToGender(int number)
    {
        return static_cast<enum genderType>(number);
    }

    enum genderType stringToGender(std::string str)
    {
        return str=="Male" ? genderType::male : genderType::female;
    }

    enum computerType intToType(int number)
    {
        return static_cast<enum computerType>(number);
    }

    enum computerType stringToType(std::string str)
    {
        if(str=="Mechanical")
            return computerType::mechanical;
        else if(str=="Electronic")
            return computerType::electronic;
        else if(str=="Electro-Mechanical")
            return computerType::electromechanical;

    }
}
