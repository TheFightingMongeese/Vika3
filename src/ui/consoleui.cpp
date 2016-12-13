#include "ui/consoleui.h"
#include "utilities/constants.h"
#include "utilities/utils.h"

#include <iostream>
#include <iomanip>

using namespace std;

ConsoleUI::ConsoleUI()
{
    lastCommand = command::menu;
    sortBy = "name";
    sortAscending = true;
}

int ConsoleUI::start()
{
    while (lastCommand != command::quit)
    {
        display();
        readInput();
    }

    return 0;
}

void ConsoleUI::display()
{
    switch (lastCommand)
    {
        case command::menu:
            displayMenu();
            break;
        case command::add:
        case command::sort:
            displayChooseModelMenu();
            break;
        case command::addComputer:
            displayAddComputerMenu();
            break;
        case command::addScientist:
            displayAddScientistMenu();
            break;
        case command::display:
            displayAllScientists();
            break;
        case command::displayAllComputers:
            displayAllComputers();
            break;
        case command::search:
            displayChooseModelMenu();
            break;
        case command::sortScientist:
            displayScientistSortMenu();
            break;
        case command::connect:
            displayConnect();
            break;
        case command::sortComputer:
            displayComputerSortMenu();
            break;
        case command::searchComputer:
            displayComputerSearchMenu();
            break;
        case command::searchScientist:
            displayScientistSearchMenu();
            break;
        default:
            displayUnknownCommandMenu();
            break;
    }
}

void ConsoleUI::readInput()
{
    if (lastCommand == command::display)
    {
        lastCommand = command::sort;
        return;
    }

    string userInput;
    getline(cin, userInput);

    cout << "\n\n";

    bool shouldTreatInputAsCommand = (lastCommand != command::search);

    // Level 1 commands
    if (userInput == "d" && shouldTreatInputAsCommand) //display
    {
        lastCommand = command::sort;
    }
    else if (userInput == "a" && shouldTreatInputAsCommand) //add
    {
        lastCommand = command::add;
    }
    else if (userInput == "s" && shouldTreatInputAsCommand) //search
    {
        lastCommand = command::search;
    }
    else if (userInput == "c" && shouldTreatInputAsCommand)
    {
        lastCommand = command::connect;
    }
    else if (userInput == "b") //back
    {
        lastCommand = command::menu;
    }
    else if (userInput == "q") //quit
    {
        lastCommand = command::quit;
    }
    // Level 2 commands
    else if (lastCommand == command::add && userInput == "computer")
    {
        lastCommand = command::addComputer;
    }
    else if (lastCommand == command::add && userInput == "scientist")
    {
        lastCommand = command::addScientist;
    }
    else if (lastCommand == command::sort && userInput == "scientist")
    {
        lastCommand = command::sortScientist;
    }
    else if (lastCommand == command::sort && userInput == "computer")
    {
        lastCommand = command::sortComputer;
    }
    else if (lastCommand == command::search && userInput == "computer")
    {
        lastCommand = command::searchComputer;

    }
    else if(lastCommand == command::search && userInput == "scientist")
    {
        lastCommand = command::searchScientist;

    }
    else
    {
        // User input
        if (lastCommand == command::addScientist)
        {
            addScientistCommandHandler(userInput);
        }
        else if (lastCommand == command::addComputer)
        {
            addComputerCommandHandler(userInput);
        }
        else if (lastCommand == command::sortScientist)
        {
            sortCommandHandler(userInput);
        }
        else if (lastCommand == command::sortComputer)
        {
            sortComputerCommandHandler(userInput);
        }
        else if (lastCommand == command::searchScientist)
        {
            searchCommandHandler(userInput);
        }
        else if (lastCommand == command::connect)
        {
            addConnectionCommandHandler(userInput);
        }
        else if (lastCommand == command::searchComputer)
        {
            searchComputerCommandHandler(userInput);
        }
        else
        {
            lastCommand = command::unknown;
        }
    }
}

void ConsoleUI::addComputerCommandHandler(string userInput)
{
    enum addStatus status = addComputer(userInput);
    if (status == addStatus::success) {
        cout << "Successfully added a computer\n\n";
        lastCommand = command::menu;
    }
    else
    {
        switch(status)
        {
        case addStatus::nameMissing:
            cout << "The name is required" << endl;
            break;
        case addStatus::computerTypeMissing:
            cout << "You must specify the type of the computer" << endl;
            break;
        case addStatus::invalidInput:
            cout << "Check your input - type in 2 or 3 values, separated by commas" << endl;
            break;
        default:
            cout << "There was an error adding the computer. Sorry for that :/" << endl;
            break;
        }
    }
}

void ConsoleUI::addScientistCommandHandler(string userInput)
{
    enum addStatus status = addScientist(userInput);
    if (status == addStatus::success)
    {
        cout << "Successfully added a scientist\n\n";
        lastCommand = command::menu;
    }
    else
    {
        switch(status)
        {
        case addStatus::nameMissing:
            cout << "The name is required" << endl;
            break;
        case addStatus::yearBornMissing:
            cout << "You must specify when the scientist was born" << endl;
            break;
        case addStatus::yearDiedBeforeYearBorn:
            cout << "The scientist cannot be born after (s)he died!" << endl;
            break;
        case addStatus::invalidInput:
            cout << "Check your input - type in 3 or 4 values, separated by commas" << endl;
            break;
        default:
            cout << "There was an error adding the scientist. Sorry for that :/" << endl;
            break;
        }
    }
}

void ConsoleUI::addConnectionCommandHandler(string userInput)
{
    if (addConnection(userInput))
    {
        cout << "Successfully added a connection\n\n";
        lastCommand = command::menu;
    }
    else
    {
        cout << "There was an error adding the connection. Sorry for that :/" << endl;
    }
}

void ConsoleUI::sortCommandHandler(string userInput)
{
    if (setSort(userInput))
    {
        lastCommand = command::display;
    }
    else
    {
        displayError("Your input did not match any of the sort commands");
    }
}

void ConsoleUI::sortComputerCommandHandler(string userInput)
{
    if (setComputerSort(userInput))
    {
        lastCommand = command::displayAllComputers;
    }
    else
    {
        displayError("Your input did not match any of the sort commands");
    }
}

void ConsoleUI::searchCommandHandler(string userInput)
{
    displayScientists(scientistService.searchForScientists(userInput));
}

void ConsoleUI::searchComputerCommandHandler(string userInput)
{
    displayComputers(computerService.searchForComputers(userInput));
}

void ConsoleUI::displayMenu()
{
    cout << "Enter a command:\n\n";
    cout << setw(constants::MENU_COMMAND_WIDTH) << std::left
         << "a:" << "Adds a scientist or a computer\n";

    cout << setw(constants::MENU_COMMAND_WIDTH) << std::left
         << "d:" << "Displays scientists or a computer\n";

    cout << setw(constants::MENU_COMMAND_WIDTH) << std::left
         << "s:" << "Search for a scientist or a computer\n";

    cout << setw(constants::MENU_COMMAND_WIDTH) << std::left
         << "c:" << "Connect computer to a scientist\n";

    cout << setw(constants::MENU_COMMAND_WIDTH) << std::left
         << "q:" << "Quits the program\n\n";

    cout << "Command: ";
}

void ConsoleUI::displayChooseModelMenu()
{
    cout << "Please choose a model:\n\n"
         << "computer\n"
         << "scientist\n\n";
    cout << "If you would like to go back to the main menu, please type: b\n";
    cout << "Command: ";
}

void ConsoleUI::displayAddComputerMenu()
{
    cout << "To add a computer, type in:\n";
    cout << "Name, type, year of build (optional)\n";
    cout << "Comma separated like in the example above.\n\n";
    cout << "If you would like to go back to the main menu, please type: b\n";
    cout << "Input: ";
}

void ConsoleUI::displayAddScientistMenu()
{
    cout << "To add a scientist, type in:\n";
    cout << "Name,gender,yearBorn,yearDied (optional)\n";
    cout << "Comma separated like in the example above.\n\n";
    cout << "If you would like to go back to the main menu, please type: b\n";
    cout << "Input: ";
}

void ConsoleUI::displayAllScientists()
{
    vector<Scientist> scientists = scientistService.getAllScientists(sortBy, sortAscending);

    displayScientists(scientists);

    cout << '\n';

    lastCommand = command::display;
}

void ConsoleUI::displayAllComputers()
{
    vector<Computer> computers = computerService.getAllComputers(sortBy, sortAscending);

    displayComputers(computers);

    cout << '\n';

    lastCommand = command::display;
}

void ConsoleUI::displayScientistSearchMenu()
{
    cout << "Search for a scientist.\n\n";

    cout << "If you would like to go back to the main menu, please type: b\n";
    cout << "Input: ";
}

void ConsoleUI::displayScientistSortMenu()
{
    cout << "How should the list be sorted:\n\n";
    cout << setw(constants::SORT_COMMAND_WIDTH) << std::left
         << constants::SORT_SCIENTIST_NAME_ASCENDING << "Sorts by name, ascending.\n";

    cout << setw(constants::SORT_COMMAND_WIDTH) << std::left
         << constants::SORT_SCIENTIST_NAME_DESCENDING << "Sorts by name, descending.\n";

    cout << setw(constants::SORT_COMMAND_WIDTH) << std::left
         << constants::SORT_SCIENTIST_YEAR_BORN_ASCENDING << "Sorts by year born, ascending.\n";

    cout << setw(constants::SORT_COMMAND_WIDTH) << std::left
         << constants::SORT_SCIENTIST_YEAR_BORN_DESCENDING << "Sorts by year born, descending.\n";

    cout << setw(constants::SORT_COMMAND_WIDTH) << std::left
         << constants::SORT_SCIENTIST_YEAR_DIED_ASCENDING << "Sorts by year died, ascending.\n";

    cout << setw(constants::SORT_COMMAND_WIDTH) << std::left
         << constants::SORT_SCIENTIST_YEAR_DIED_DESCENDING << "Sorts by year died, descending.\n\n";

    cout << "If you would like to go back to the main menu, please type: b\n";

    cout << "Command: ";
}

void ConsoleUI::displayConnect()
{
    cout << "Connect computer to a scientist.\n\n";
    cout << "Please write the ID of the computer and the ID of the scientist.\n";
    cout << "Computer ID,Scientist ID\n";
    cout << "Comma separated like in the example above.\n\n";
    cout << "If you would like to go back to the main menu, please type: back\n";
    cout << "Input: ";
}

void ConsoleUI::displayComputerSearchMenu()
{
    cout << "Search for a computer.\n\n";

    cout << "If you would like to go back to the main menu, please type: b\n";
    cout << "Input: ";
}

void ConsoleUI::displayComputerSortMenu()
{
    cout << "How should the list be sorted:\n\n";
    cout << setw(constants::SORT_COMMAND_WIDTH) << std::left
         << constants::SORT_COMPUTER_NAME_ASCENDING << "Sorts by name, ascending.\n";

    cout << setw(constants::SORT_COMMAND_WIDTH) << std::left
         << constants::SORT_COMPUTER_NAME_DESCENDING << "Sorts by name, descending.\n";

    cout << setw(constants::SORT_COMMAND_WIDTH) << std::left
         << constants::SORT_COMPUTER_YEAR_OF_BUILD_ASCENDING << "Sorts by year of build, ascending.\n";

    cout << setw(constants::SORT_COMMAND_WIDTH) << std::left
         << constants::SORT_COMPUTER_YEAR_OF_BUILD_DESCENDING << "Sorts by year of build, descending.\n";

    cout << setw(constants::SORT_COMMAND_WIDTH) << std::left
         << constants::SORT_COMPUTER_TYPE_ASCENDING << "Sorts by type, ascending.\n";

    cout << setw(constants::SORT_COMMAND_WIDTH) << std::left
         << constants::SORT_COMPUTER_TYPE_DESCENDING << "Sorts by type, descending.\n\n";

    cout << "If you would like to go back to the main menu, please type: b\n";

    cout << "Command: ";
}

void ConsoleUI::displayUnknownCommandMenu()
{
    displayError("Unknown command");
    cout << "Command: ";
}

void ConsoleUI::displayScientists(std::vector<Scientist> scientists)
{
    if (scientists.size() == 0)
    {
        cout << "No scientist found.\n";
        return;
    }

    cout << "Printing all scientists:\n";

    cout << setw(10) << std::left << "ID:"
         << setw(20) << std::left << "Name:"
         << setw(8) << std::left << "Gender:"
         << setw(12) << std::left << "Year born:"
         << setw(12) << std::left << "Year died:" << endl;

    for (unsigned int i = 0; i < scientists.size(); i++)
    {
        string scientistGender = (scientists.at(i).getGender() == genderType::male) ? "Male" : "Female";

        int yearDied = scientists.at(i).getYearDied();
        string died = (yearDied == constants::YEAR_DIED_DEFAULT_VALUE) ? "Alive" : utils::intToString(yearDied);

        cout << setw(10) << std::left << scientists.at(i).getID()
             << setw(20) << std::left << scientists.at(i).getName()
             << setw(8) << std::left << scientistGender
             << setw(12) << std::left << scientists.at(i).getYearBorn()
             << setw(12) << std::left << died << endl;
    }
}

void ConsoleUI::displayComputers(std::vector<Computer> computers)
{
    if (computers.size() == 0)
    {
        cout << "No computers found.\n";
        return;
    }

    cout << "Printing all computers:\n";

    cout << setw(10) << std::left << "ID:"
         << setw(20) << std::left << "Name:"
         << setw(20) << std::left << "Type:"
         << setw(12) << std::left << "Year of build:" << endl;

    for (unsigned int i = 0; i < computers.size(); i++)
    {
        string type;
        if(computers.at(i).getType() == computerType::electronic)
        {
            type = "Electronic";
        }
        else if(computers.at(i).getType() == computerType::mechanical)
        {
            type = "Mechanical";
        }
        else if(computers.at(i).getType() == computerType::electromechanical)
        {
            type = "Electro-Mechanical";
        }
        else
        {
            type = "Other";
        }

        int yearOfBuild = computers.at(i).getYearOfBuild();
        string built = (yearOfBuild == constants::YEAR_OF_BUILD_DEFAULT_VALUE) ? "Not built" : utils::intToString(yearOfBuild);

        cout << setw(10) << std::left << computers.at(i).getID()
             << setw(20) << std::left << computers.at(i).getName()
             << setw(20) << std::left << type
             << setw(12) << std::left << built << endl;
    }
}

enum addStatus ConsoleUI::addScientist(string data)
{
    vector<string> fields = utils::splitString(data, ',');

    // General validation of input, i.e. check if the number of parameters
    // entered by the user is within the expected range:
    if (fields.size() > 2 && fields.size() < 5)
    {
        string name = fields.at(0);

        // A very simplistic implementation of gender selection.
        // We could of course offer more options, but to keep this
        // simple, we won't.
        enum genderType gender;
        if (fields.at(1) == "male")
        {
            gender = genderType::male;
        }
        else
        {
            gender = genderType::female;
        }
        int yearBorn = utils::stringToInt(fields.at(2));

        if (fields.size() == 3)
        {
            return scientistService.addScientist(Scientist(name, gender, yearBorn));
        }
        else
        {
            int yearDied = utils::stringToInt(fields.at(3));

            return scientistService.addScientist(Scientist(name, gender, yearBorn, yearDied));
        }
    }

    return addStatus::invalidInput;
}

bool ConsoleUI::addConnection(string data)
{
    vector<string> fields = utils::splitString(data, ',');

    if (fields.size() == 2)
    {
        int computerID = utils::stringToInt(fields.at(0));
        int scientistID = utils::stringToInt(fields.at(1));
        return scientistService.connectComputer(scientistID, computerID);
    }

    return false;
}

enum addStatus ConsoleUI::addComputer(string data)
{
    vector<string> fields = utils::splitString(data, ',');

    // General validation of input, i.e. check if the number of parameters
    // entered by the user is within the expected range:
    if (fields.size() > 1 && fields.size() < 4)
    {
        string name = fields.at(0);

        computerType type;
        if (fields.at(1) == "mechanical")
        {
            type = computerType::mechanical;
        }
        else if(fields.at(1) == "electromechanical")
        {
            type = computerType::electromechanical;
        }
        else
        {
            type = computerType::electronic;
        }

        if (fields.size() == 2)
        {
            return computerService.addComputer(Computer(name, type));
        }
        else
        {
            int yearOfBuild = utils::stringToInt(fields.at(2));
            return computerService.addComputer(Computer(name, type, yearOfBuild));
        }
    }

    return addStatus::invalidInput;
}

bool ConsoleUI::setSort(string sortCommand)
{
    if (sortCommand == constants::SORT_SCIENTIST_NAME_ASCENDING)
    {
        sortBy = "name";
        sortAscending = true;
    }
    else if (sortCommand == constants::SORT_SCIENTIST_NAME_DESCENDING)
    {
        sortBy = "name";
        sortAscending = false;
    }
    else if (sortCommand == constants::SORT_SCIENTIST_YEAR_BORN_ASCENDING)
    {
        sortBy = "yearBorn";
        sortAscending = true;
    }
    else if (sortCommand == constants::SORT_SCIENTIST_YEAR_BORN_DESCENDING)
    {
        sortBy = "yearBorn";
        sortAscending = false;
    }
    else if (sortCommand == constants::SORT_SCIENTIST_YEAR_DIED_ASCENDING)
    {
        sortBy = "yearDied";
        sortAscending = true;
    }
    else if (sortCommand == constants::SORT_SCIENTIST_YEAR_DIED_DESCENDING)
    {
        sortBy = "yearDied";
        sortAscending = false;
    }
    else
    {
        return false;
    }

    return true;
}
bool ConsoleUI::setComputerSort(string sortCommand)
{
    if (sortCommand == constants::SORT_COMPUTER_NAME_ASCENDING)
    {
        sortBy = "name";
        sortAscending = true;
    }
    else if (sortCommand == constants::SORT_COMPUTER_NAME_DESCENDING)
    {
        sortBy = "name";
        sortAscending = false;
    }
    else if (sortCommand == constants::SORT_COMPUTER_YEAR_OF_BUILD_ASCENDING)
    {
        sortBy = "yearofBuild";
        sortAscending = true;
    }
    else if (sortCommand == constants::SORT_COMPUTER_YEAR_OF_BUILD_DESCENDING)
    {
        sortBy = "yearofBuild";
        sortAscending = false;
    }
    else if (sortCommand == constants::SORT_COMPUTER_TYPE_ASCENDING)
    {
        sortBy = "type";
        sortAscending = true;
    }
    else if (sortCommand == constants::SORT_COMPUTER_TYPE_DESCENDING)
    {
        sortBy = "type";
        sortAscending = false;
    }
    else
    {
        return false;
    }

    return true;
}

void ConsoleUI::displayError(string error)
{
    cout << "There was an error: " << error << "\n";
    cout << "Please try again or type 'b' to go back.\n\n";
}
