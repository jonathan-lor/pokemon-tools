#include <fstream>
#include "Board.h"
#include "helpers.h"

int main(int argc, char* argv[]) {
    Board b;
    std::cout << b << std::endl;
    std::string filename = "board.txt";
    // board.txt should describe a 5x5 board. if you update board to be bigger/smaller, update parseFileToVector arg
    // parse func is very particular in what format file it accepts
    writeFileToBoard(filename, b);

    std::cout << b << std::endl;
    std::array<bool, 4> arr;
    arr.fill(false);
    for(bool& v : arr) std::cout << v;
    std::cout << std::endl;
    return 0;
}