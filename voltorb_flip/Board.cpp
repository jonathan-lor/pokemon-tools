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
    board = std::vector<std::vector<char>>(boardSize, std::vector<char>(boardSize, '?'));
    rowsInfo = std::vector<std::vector<int>>(boardSize, std::vector<int>(2, 0));
    colsInfo = std::vector<std::vector<int>>(boardSize, std::vector<int>(2, 0));
}

void Board::setTile(int row, int col, char val) {
    board[row][col] = val;
}

std::ostream& operator<<(std::ostream& os, const Board& b) {
    for(int i = 0; i < 5 * b.boardSize; i++) os << "-";
    os << std::endl;
    for(int i = 0; i < b.boardSize; i++) {
        for(int j = 0; j < b.boardSize; j++) {
            os << b.board[i][j] << "    ";
        }
        os << "| " << b.rowsInfo[i][0] << "," << b.rowsInfo[i][1] << std::endl;
        if(i < b.boardSize - 1) {
            for(int i = 0; i < 5 * b.boardSize; i++) os << " ";
            os << "|" << std::endl;
        }
    }
    for(int i = 0; i < 5 * b.boardSize; i++) os << "-";
    os << std::endl;
    for(int i = 0; i < b.boardSize; i++) {
        os << b.colsInfo[i][0] << "," << b.colsInfo[i][1] << "  ";
    }
    os << std::endl;

    return os;
}