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

void Board::setRowPointsFound(int i, int p) {
    rowsInfo[i].setPointsFound(p);
}

void Board::setColPointsFound(int i, int p) {
    colsInfo[i].setPointsFound(p);
}

void Board::setRowVoltorbsFound(int i, int v) {
    rowsInfo[i].setVoltorbsFound(v);
}

void Board::setColVoltorbsFound(int i, int v) {
    colsInfo[i].setVoltorbsFound(v);
}

void Board::addRowPointsFound(int i, int p) {
    rowsInfo[i].addPointsFound(p);
}

void Board::addColPointsFound(int i, int p) {
    colsInfo[i].addPointsFound(p);
}

void Board::addRowVoltorbsFound(int i, int v) {
    rowsInfo[i].addVoltorbsFound(v);
}

void Board::addColVoltorbsFound(int i, int v) {
    colsInfo[i].addVoltorbsFound(v);
}

void Board::setTile(int row, int col, char val) {
    board[row][col].setActualValue(val);
}

std::vector<std::pair<int, int>> Board::getBestCells() {
    std::cout << "calling getBestCells" << std::endl;
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
    std::vector<int> safeRowIndices; // count these to avoid adding dupes to safeCells
    for(int i = 0; i < rowsInfo.size(); i++) {
        if(rowsInfo[i].getTotalVoltorbs() == 0) {
            safeRowIndices.push_back(i);
            for(int j = 0; j < board.size(); j++) {
                if(!board[i][j].revealed()) safeCells.push_back({i, j});
            }
        }
    }

    // nearly same logic except need to handle presence of safe rows
    // lowkey might need to test this method more
    if(safeRowIndices.size() > 0) {
        int safeRowIndicesP = 0;
        for(int i = 0; i < colsInfo.size(); i++) {
            if(colsInfo[i].getTotalVoltorbs() == 0) {
                for(int j = 0; j < board.size(); j++) {
                    if(safeRowIndicesP < safeRowIndices.size() && j == safeRowIndices[safeRowIndicesP]) {
                        safeRowIndicesP++;
                    } else {
                        if(!board[j][i].revealed()) safeCells.push_back({j, i});   
                    }
                }
            }
        }
    } else {
        for(int i = 0; i < colsInfo.size(); i++) {
            if(colsInfo[i].getTotalVoltorbs() == 0) {
                for(int j = 0; j < board.size(); j++) {
                    if(!board[j][i].revealed()) safeCells.push_back({j, i});
                }
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


    std::cout << "Calling updatepossibleValues on " << row << ", " << col << std::endl;

    std::cout << "total_v_in_row: " << total_v_in_row << std::endl;
    std::cout << "total_points_in_row: " << total_points_in_row << std::endl;
    std::cout << "v_found_row: " << v_found_row << std::endl;
    std::cout << "points_found_row: " << points_found_row << std::endl;

    std::cout << std::endl;

    std::cout << "total_v_in_col: " << total_v_in_col << std::endl;
    std::cout << "total_points_in_col: " << total_points_in_col << std::endl;
    std::cout << "v_found_col: " << v_found_col << std::endl;
    std::cout << "points_found_col: " << points_found_col << std::endl;

    std::cout << std::endl;
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