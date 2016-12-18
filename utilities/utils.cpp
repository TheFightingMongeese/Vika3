#include "utilities/utils.h"

#include <sstream>
#include <cstdlib>

namespace utils {
    std::vector<QString> split(QString line, char delimeter)
    {
        std::vector<QString> result;

        QString currentWord = "";

        for (int i = 0; i < line.length(); i++)
        {
            QChar currentChar = line[i];

            if (currentChar == delimeter)
            {
                if  (currentWord.length())
                {
                    result.push_back(currentWord);
                    currentWord = "";
                }
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

    int stringToInt(QString str)
    {
        return str.toInt();
    }

    QString stringToLower(QString str)
    {
        QString result = "";

        for (int i = 0; i < str.length(); i++)
        {
            QChar currentCharacter = str[i];

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

    QString intToString(int number)
    {
        std::stringstream stream;
        stream << number;
        return QString::fromStdString(stream.str());
    }

    enum sexType intToSex(int number)
    {
        return static_cast<enum sexType>(number);
    }

    enum computerType intToComputerType(int number)
    {
        return static_cast<enum computerType>(number);
    }

    enum sexType stringToSex(QString str)
    {
        return intToSex(stringToInt(str));
    }

    QString sexToString(sexType type)
    {
        return type == sexType::male ? "Male" : "Female";
    }

    QSqlDatabase getDatabaseConnection()
    {
        QString connectionName = "Sigga";
        QSqlDatabase db;

        if(QSqlDatabase::contains(connectionName))
        {
            db = QSqlDatabase::database(connectionName);
        }
        else
        {
            db = QSqlDatabase::addDatabase("QSQLITE", connectionName);
            db.setDatabaseName("database.sqlite");

            db.open();
        }

        return db;
    }
}
