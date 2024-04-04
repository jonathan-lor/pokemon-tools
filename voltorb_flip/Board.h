#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include "Cell.h"
#include "RowColInfo.h"

class Board {
private:
    int boardSize;
    // std::vector<std::vector<int>> rowsInfo;
    // std::vector<std::vector<int>> colsInfo;
    std::vector<RowColInfo> rowsInfo;
    std::vector<RowColInfo> colsInfo;
    std::vector<std::vector<Cell>> board;
    void initBoard();

public:
    Board();
    Board(int boardSize);
    int size() const;

    void setRowTotalPoints(int i, int p);
    void setColTotalPoints(int i, int p);

    void setRowTotalVoltorbs(int i, int v);
    void setColTotalVoltorbs(int i, int v);

    void setTile(int row, int col, char val);
    
    std::vector<std::pair<int, int>> bestCells();
    void processSafeHouse(std::vector<std::pair<int, int>>& safeCells);
    void updatePossibleValues(int row, int col, std::vector<std::pair<int, int>>& bestCells);
    void check_v(int total_v, int v_found, int n);
    friend std::ostream& operator<<(std::ostream& os, const Board& b);
};

#endif