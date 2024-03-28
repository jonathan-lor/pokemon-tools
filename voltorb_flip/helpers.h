#ifndef HELPERS_H
#define HELPERS_H

#include <iostream>
#include <vector>
#include <string>
#include "Board.h"

void printSolverRules();

std::vector<std::string> split(const std::string& s, char delim);
// parses file of correct format to 2d vector that matches rowInfo or colInfo vectors in Board
void writeFileToBoard(std::string& filename, Board& b);

#endif