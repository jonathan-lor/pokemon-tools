#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <vector>

class Board {
private:
    int boardSize;
    std::vector<std::vector<int>> rowsInfo;
    std::vector<std::vector<int>> colsInfo;
    std::vector<std::vector<char>> board;
    void initBoard();

public:
    Board();
    Board(int boardSize);
    void setSingleRowInfo(int i, int j, int val);
    void setSingleColInfo(int i, int j, int val);
    void setTile(int row, int col, char val);
    friend std::ostream& operator<<(std::ostream& os, const Board& b);
};

#endif