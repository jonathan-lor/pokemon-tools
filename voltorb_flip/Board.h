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
    
    // markTile abstraction for underlying length 4 array
    // just shows which values are possible
    void markTile(char c);
    friend std::ostream& operator<<(std::ostream& os, const Board& b);
};

#endif