#include "Cell.h"

Cell::Cell() {
    for(bool& elem : possibleValues) elem = true;
    actualValue = '?';
}

std::array<bool, 4> Cell::getPossibleValues() const {
    return possibleValues;
}

void Cell::setPossibleValues(int index, bool value) {
    possibleValues[index] = value;
}

const char Cell::getActualValue() const {
    return actualValue;
}

void Cell::setActualValue(char c) {
    actualValue = c;
}