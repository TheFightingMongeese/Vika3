#ifndef COMPUTER_H
#define COMPUTER_H
#include <string>

class COMPUTER
{
public:
    COMPUTER(std::string name, int yearDesign);
    COMPUTER(std::string name, int yearDesign,std::string type);

    std::string getName() const;
    //enum genderType getGender() const;
    int getYearDesign() const;
    std::string getType() const;

    bool contains(std::string searchTerm);

private:
    std::string _name;
    std::string _Type;
    int _YearDesign;
    //int _yearDied;      setja bool hérna ?
};
