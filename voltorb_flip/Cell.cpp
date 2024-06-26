#include "Cell.h"
#include <iostream>

Cell::Cell() : possibleValues({1, 1, 1, 1}) {
    // for(bool& elem : possibleValues) elem = true;
    actualValue = '?';
}

std::array<bool, 4> Cell::getPossibleValues() const {
    return possibleValues;
}

void Cell::setPossibleValues(int index, bool value) {
    possibleValues[index] = value;
}

void Cell::printPossibleValues() {
    for(const bool& val : possibleValues) std::cout << val;
    std::cout << std::endl;
}

char Cell::getActualValue() const {
    return actualValue;
}

void Cell::setActualValue(char c) {
    actualValue = c;
}

bool Cell::revealed() {
    return actualValue == '1' || actualValue == '2' || actualValue == '3' || actualValue == 'v';
}