#include <iostream>
#include "Board.h"

int main(int argc, char* argv[]) {
    Board b;
    std::cout << b << std::endl;
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            b.setTile(i, j, 'V');
        }
    }
    std::cout << b << std::endl;
    return 0;
} 