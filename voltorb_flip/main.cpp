#include <fstream>
#include <unistd.h>
#include "Board.h"
#include "helpers.h"

int main(int argc, char* argv[]) {

    int opt = 0;
    std::string boardFileName = "board.txt";
    std::string solution = "board_solution.txt";

    while((opt = getopt(argc, argv, "b:s:")) != -1) {
        switch(opt) {
            case 'b':
                boardFileName = optarg;
                break;
            case 's':
                solution = optarg;
                break;
            default:
                std::cerr << "Invalid Command Line Argument\n";
        }
    }
    Board b; // actual board algo runs on
    Board s; // solution to compare
    // board.txt should describe a 5x5 board. if you update board to be bigger/smaller, update parseFileToVector arg
    // parse func is very particular in what format file it accepts
    // everything assumes a valid board input
    writeFileToBoard(boardFileName, b);
    writeFileToBoard(solution, s);
    std::cout << b << std::endl;
    std::cout << s << std::endl;

    std::vector<std::pair<int, int>> bestCells;
    bestCells = b.getBestCells();
    for(const auto& cell : bestCells) {
        std::cout << cell.first << ", " << cell.second << std::endl;
    }
    return 0;
}