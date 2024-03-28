#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <vector>
#include <string>
#include "Cell.h"

class Board {
private:
    int boardSize;
    std::vector<std::vector<int>> rowsInfo;
    std::vector<std::vector<int>> colsInfo;
    std::vector<std::vector<Cell>> board;
    void initBoard();

public:
    Board();
    Board(int boardSize);
    int size() const;
    int getSingleRowInfo(int i, int j) const;
    void setSingleRowInfo(int i, int j, int val);
    int getSingleColInfo(int i, int j) const;
    void setSingleColInfo(int i, int j, int val);
    void setTile(int row, int col, char val);
    std::array<bool, 4> getPossibleValues(int row, int col) const;
    
    // func check entire row, col of a single cell to update possible value of that cell
    
    // get Best tile
    // markTile abstraction for underlying length 4 array
    void markTile(char c);
    friend std::ostream& operator<<(std::ostream& os, const Board& b);
};

#endif