#include <sstream>
#include <fstream>
#include <algorithm>
#include "helpers.h"

std::vector<std::string> split(const std::string& s, char delim) {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream stream(s);
    while(getline(stream, token, delim)) {
        tokens.push_back(token);
    }
    return tokens;
}

// naive parser from file to board
void writeFileToBoard(std::string& filename, Board& b) {
    std::ifstream file(filename);
    std::string line;

    if(file.is_open()) {
        try {
            // read the first line corresponding to length of row/col (n)
            int n;
            getline(file, line);
            n = stoi(line);
            // ADD POINTS FOUND V FOUND
            // read second and third lines corresponding to contents of row, col respectively
            for(int r = 0; r < 2; r++) { // runs for 2 iterations - first sets row, second sets col
                getline(file, line); // gets rows first
                std::vector<std::vector<int>> res(b.size(), std::vector<int>(2, 0));
                std::vector<std::string> splitted = split(line, ';');
                for(size_t i = 0; i < splitted.size(); i++) {
                    splitted[i].erase(std::remove(splitted[i].begin(), splitted[i].end(), '('), splitted[i].end());
                    splitted[i].erase(std::remove(splitted[i].begin(), splitted[i].end(), ')'), splitted[i].end());
                    std::vector<std::string> vals = split(splitted[i], ','); // results in something like [3, 2]
                    res[i][0] = stoi(vals[0]);
                    res[i][1] = stoi(vals[1]);
                }
                for(size_t i = 0; i < res.size(); i++) {
                    // set total points from headers
                    r == 0 ? b.setRowTotalPoints(i, res[i][0]) : b.setColTotalPoints(i, res[i][0]);
                    r == 0 ? b.setRowTotalVoltorbs(i, res[i][1]) : b.setColTotalVoltorbs(i, res[i][1]);
                }
            }
            // reading and parsing the actual board
            // (also includes counting and setting found points from board values)
            for(int i = 0; i < n; i++) {
                getline(file, line);
                std::vector<std::string> rowVals = split(line, ',');
                for(int j = 0; j < n; j++) {
                    // TODO: add int conversion here for simpler calcs
                    b.setTile(i, j, rowVals[j][0]);
                    // checking if tile is 'flipped'
                    if(rowVals[j][0] != '_') {
                        b.addRowFlippedTiles(i, 1);
                        b.addColFlippedTiles(j, 1);
                    }
                    // counting points and voltorbs
                    if(isdigit(rowVals[j][0])) {
                        b.addRowPointsFound(i, (int)(rowVals[j][0] - 48));
                        b.addColPointsFound(j, (int)(rowVals[j][0] - 48));
                    }
                }
            }
        } catch (...) {
            std::cerr << "Error reading from " << filename << std::endl;
        }
        file.close();
    } else {
        std::cerr << "Error opening " << filename << std::endl;
    }
}