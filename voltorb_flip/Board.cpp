#include "Board.h"

Board::Board() {
    this->boardSize = 5;
    initBoard();
}

Board::Board(int size) {
    this->boardSize = size;
    initBoard();
}

void Board::initBoard() {
    board = std::vector<std::vector<Cell>>(boardSize, std::vector<Cell>(boardSize, Cell()));
    rowsInfo = std::vector<RowColInfo>(boardSize, RowColInfo());
    colsInfo = std::vector<RowColInfo>(boardSize, RowColInfo());
}

int Board::size() const {
    return boardSize;
}

void Board::setRowTotalPoints(int i, int p) {
    rowsInfo[i].setTotalPoints(p);
}

void Board::setColTotalPoints(int i, int p) {
    colsInfo[i].setTotalPoints(p);
}

void Board::setRowTotalVoltorbs(int i, int v) {
    rowsInfo[i].setTotalVoltorbs(v);
}

void Board::setColTotalVoltorbs(int i, int v) {
    colsInfo[i].setTotalVoltorbs(v);
}

void Board::setTile(int row, int col, char val) {
    board[row][col].setActualValue(val);
}

std::vector<std::pair<int, int>> Board::bestCells() {
    std::vector<std::pair<int, int>> safeCells; // cells here always safe to flip
    std::vector<std::pair<int, int>> bestCells; // not guaranteed safe but best prob.

    // processing safe house rule
    processSafeHouse(safeCells);
    if(safeCells.size() > 0) return safeCells;

    // for cell in board, update v, 1, 2, 3
    updatePossibleValues(0, 0, bestCells);

    updatePossibleValues(2, 2, bestCells);

    updatePossibleValues(4, 1, bestCells);


    return bestCells;
}

void Board::processSafeHouse(std::vector<std::pair<int, int>>& safeCells) {
    // iterate rowsInfo
    for(int i = 0; i < rowsInfo.size(); i++) {
        if(rowsInfo[i].getTotalVoltorbs() == 0) {
            for(int j = 0; j < board.size(); j++) {
                if(!board[i][j].revealed()) safeCells.push_back({i, j});
            }
        }
    }

    // iterate colsInfo
    for(int i = 0; i < colsInfo.size(); i++) {
        if(colsInfo[i].getTotalVoltorbs() == 0) {
            for(int j = 0; j < board.size(); j++) {
                if(!board[j][i].revealed()) safeCells.push_back({j, i});
            }
        }
    }
}

void Board::updatePossibleValues(int row, int col, std::vector<std::pair<int, int>>& bestCells) {
    // int rowLength = boardSize, colLength = boardSize;

    int total_v_in_row = rowsInfo[row].getTotalVoltorbs();
    int total_points_in_row = rowsInfo[row].getTotalPoints();
    int v_found_row = rowsInfo[row].getVoltorbsFound();
    int points_found_row = rowsInfo[row].getPointsFound();

    int total_v_in_col = colsInfo[col].getTotalVoltorbs();
    int total_points_in_col = colsInfo[col].getTotalPoints();
    int v_found_col = colsInfo[col].getVoltorbsFound();
    int points_found_col = colsInfo[col].getPointsFound();

    // test

    // std::cout << "Calling updatepossibleValues on " << row << ", " << col << std::endl;

    // std::cout << "total_v_in_row: " << total_v_in_row << std::endl;
    // std::cout << "total_points_in_row: " << total_points_in_row << std::endl;
    // std::cout << "v_found_row: " << v_found_row << std::endl;
    // std::cout << "points_found_row: " << points_found_row << std::endl;

    // std::cout << std::endl;

    // std::cout << "total_v_in_col: " << total_v_in_col << std::endl;
    // std::cout << "total_points_in_col: " << total_points_in_col << std::endl;
    // std::cout << "v_found_col: " << v_found_col << std::endl;
    // std::cout << "points_found_col: " << points_found_col << std::endl;

    // std::cout << std::endl;
}

void check_v() {

}

std::ostream& operator<<(std::ostream& os, const Board& b) {
    for(int i = 0; i < 5 * b.boardSize; i++) os << "-";
    os << std::endl;
    for(int i = 0; i < b.boardSize; i++) {
        for(int j = 0; j < b.boardSize; j++) {
            os << b.board[i][j].getActualValue() << "    ";
        }
        os << "| " << b.rowsInfo[i].getTotalPoints() << "," << b.rowsInfo[i].getTotalVoltorbs() << std::endl;
        if(i < b.boardSize - 1) {
            for(int i = 0; i < 5 * b.boardSize; i++) os << " ";
            os << "|" << std::endl;
        }
    }
    for(int i = 0; i < 5 * b.boardSize; i++) os << "-";
    os << std::endl;
    for(int i = 0; i < b.boardSize; i++) {
        os << b.colsInfo[i].getTotalPoints() << "," << b.colsInfo[i].getTotalVoltorbs() << "  ";
    }
    os << std::endl;

    return os;
}