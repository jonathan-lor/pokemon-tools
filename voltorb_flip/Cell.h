#ifndef CELL_H
#define CELL_H

#include <array>

class Cell {
private:
    // indexes & corresponding values
    // all begin at true, and switched to false if not possible
    // 0 -> voltorb
    // 1 -> 1
    // 2-> 2
    // 3 -> 3
    std::array<bool, 4> possibleValues;
    char actualValue;
    // actual value
public:
    Cell();
    std::array<bool, 4> getPossibleValues() const;
    void setPossibleValues(int index, bool value);
    void printPossibleValues();
    const char getActualValue() const;
    void setActualValue(char c);


};

#endif