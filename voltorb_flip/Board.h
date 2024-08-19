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

    void processSafeHouse(std::vector<std::pair<int, int>>& safeCells);
    void updatePossibleValues(int row, int col, std::vector<std::pair<int, int>>& bestCells);
    bool check_v(int total_v, int v_found, int n);
    // for score first approach
    bool checkNum(int target, int total_points, int points_found, int total_v, int total_flipped);

public:
    Board();
    Board(int boardSize);
    int size() const;

    // these dont change and are read in, so only need a setter
    void setRowTotalPoints(int i, int p);
    void setColTotalPoints(int i, int p);
    void setRowTotalVoltorbs(int i, int v);
    void setColTotalVoltorbs(int i, int v);

    // set and adders for both cases depending on how we read in board
    void setRowPointsFound(int i, int p);
    void setColPointsFound(int i, int p);
    void setRowVoltorbsFound(int i, int v);
    void setColVoltorbsFound(int i, int v);
    void addRowPointsFound(int i, int p);
    void addColPointsFound(int i, int p);
    void addRowVoltorbsFound(int i, int v);
    void addColVoltorbsFound(int i, int v);

    // ADD ROW/COL ADD FLIP TILES!!!
    void addRowFlippedTiles(int i, int f);
    void addColFlippedTiles(int i, int f);

    void setTile(int row, int col, char val);
    std::vector<std::pair<int, int>> getBestCells();
    friend std::ostream& operator<<(std::ostream& os, const Board& b);
};

#endif