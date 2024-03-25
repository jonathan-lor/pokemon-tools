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

void writeFileToBoard(std::string& filename, Board& b) {
    std::ifstream file(filename);
    std::string line;

    if(file.is_open()) {
        try {
            for(int r = 0; r < 2; r++) { // runs for 2 iterations - first sets row, second sets col
                getline(file, line); // gets rows first
                std::vector<std::vector<int>> res(b.size(), std::vector<int>(2, 0));
                std::vector<std::string> splitted = split(line, ';');
                for(size_t i = 0; i < splitted.size(); i++) {
                    splitted[i].erase(std::remove(splitted[i].begin(), splitted[i].end(), '('), splitted[i].end());
                    splitted[i].erase(std::remove(splitted[i].begin(), splitted[i].end(), ')'), splitted[i].end());
                    std::vector<std::string> vals = split(splitted[i], ','); // results in sum like [3, 2]
                    res[i][0] = stoi(vals[0]);
                    res[i][1] = stoi(vals[1]);
                }
                for(size_t i = 0; i < res.size(); i++) {
                    r == 0 ? b.setSingleRowInfo(i, 0, res[i][0]) : b.setSingleColInfo(i, 0, res[i][0]);
                    r == 0 ? b.setSingleRowInfo(i, 1, res[i][1]) : b.setSingleColInfo(i, 1, res[i][1]);
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