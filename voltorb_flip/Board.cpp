#include "Board.h"

Board::Board() {
    boardSize = 5;
    initBoard();
}

Board::Board(int size) {
    boardSize = size;
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
std::array<bool, 4> Board::getPossibleValues(int row, int col) const {
    return board[row][col].getPossibleValues();
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