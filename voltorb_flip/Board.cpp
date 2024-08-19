#include "Board.h"
#include <unordered_set>

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

void Board::addRowFlippedTiles(int i, int f) {
    rowsInfo[i].addFlippedTiles(f);
}

void Board::addColFlippedTiles(int i, int f) {
    colsInfo[i].addFlippedTiles(f);
}

void Board::setTile(int row, int col, char val) {
    board[row][col].setActualValue(val);
}

std::vector<std::pair<int, int>> Board::getBestCells() {
    std::vector<std::pair<int, int>> bestCells; // not guaranteed safe but best prob.

    // processing safe house rule
    //processSafeHouse(bestCells);
    if(bestCells.size() > 0) return bestCells;

    for(int i = 0; i < this->board.size(); i++) {
        for(int j = 0; j < this->board[0].size(); j++) {
            updatePossibleValues(i, j, bestCells);
        }
    }

    /*
    // for cell in board, update v, 1, 2, 3
    updatePossibleValues(0, 0, bestCells);

    updatePossibleValues(2, 2, bestCells);

    updatePossibleValues(4, 1, bestCells);
    */

    return bestCells;
}

void Board::processSafeHouse(std::vector<std::pair<int, int>>& safeCells) {
    // HOOD METHOD. PROBABLY REFACTOR THIS
    // iterate rowsInfo
    // std::vector<int> safeRowIndices; // count these to avoid adding dupes to safeCells
    std::unordered_set<int> safeRowIndices;
    for(int i = 0; i < rowsInfo.size(); i++) {
        if(rowsInfo[i].getTotalVoltorbs() == 0) {
            safeRowIndices.insert(i);
            for(int j = 0; j < board.size(); j++) {
                if(!board[i][j].revealed()) safeCells.push_back({i, j});
            }
        }
    }

    // nearly same logic except need to handle presence of safe rows
    // lowkey might need to test this method more
    if(!safeRowIndices.empty()) {
        // int safeRowIndicesP = 0;
        for(int i = 0; i < colsInfo.size(); i++) {
            if(colsInfo[i].getTotalVoltorbs() == 0) {
                for(int j = 0; j < board.size(); j++) {
                    if(!safeRowIndices.count(j) && !board[j][i].revealed()) safeCells.push_back({j, i});
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

    int row_tiles_flipped = rowsInfo[row].getFlippedTiles();
    int col_tiles_flipped = colsInfo[col].getFlippedTiles();

    std::cout << "Calling updatepossibleValues on " << row << ", " << col << std::endl;

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

    // std::cout << "total tiles in row/col: " << boardSize << std::endl;
    // std::cout << "row_tiles_flipped: " << row_tiles_flipped << std::endl;
    // std::cout << "col_tiles_flipped: " << col_tiles_flipped << std::endl;

    bool valid_1 = checkNum(1, total_points_in_row, points_found_row, total_v_in_row, row_tiles_flipped) && checkNum(1, total_points_in_col, points_found_col, total_v_in_col, col_tiles_flipped);
    bool valid_2 = checkNum(2, total_points_in_row, points_found_row, total_v_in_row, row_tiles_flipped) && checkNum(2, total_points_in_col, points_found_col, total_v_in_col, col_tiles_flipped);
    bool valid_3 = checkNum(3, total_points_in_row, points_found_row, total_v_in_row, row_tiles_flipped) && checkNum(3, total_points_in_col, points_found_col, total_v_in_col, col_tiles_flipped);

    bool voltorb_possible = check_v(total_v_in_row, v_found_row, this->boardSize) && check_v(total_v_in_col, v_found_col, this->boardSize);

    std::cout << "1 possible: " << valid_1 << std::endl;
    std::cout << "2 possible: " << valid_2 << std::endl;
    std::cout << "3 possible: " << valid_3 << std::endl;
    std::cout << "v possible: " << voltorb_possible << std::endl;


    std::cout << "-------------------------------------------------" << std::endl;
}

bool Board::checkNum(int target, int total_points, int points_found, int total_v, int total_flipped) {
    // still need to account for overlap if a v is 'flipped' (found by process of elimination)
    int num_indices = boardSize - total_v - total_flipped;
    int max_sum = total_points - points_found;

    // int min_possible_sum = 1 * num_indices;
    // int max_possible_sum = 3 * num_indices;

    int min_sum_with_target = target + 1 * (num_indices - 1);
    int max_sum_with_target = target + 3 * (num_indices - 1);

    return min_sum_with_target <= max_sum && max_sum <= max_sum_with_target;
}

bool Board::check_v(int total_v, int v_found, int n) {
    
    return v_found < total_v;
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