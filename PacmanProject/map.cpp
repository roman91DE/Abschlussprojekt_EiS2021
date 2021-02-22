#include "map.h"
#include <iostream>

Map::Map(std::string filepath) {
    std::ifstream fileStream(filepath);
    char buffer;
    while(fileStream) {
        std::vector <char> line;
        while (true) {
            buffer = fileStream.get();
            if (buffer == '\n') {
                vec.push_back(line);
                break;
            }
            else { line.push_back(buffer); }
            }
        }
    }

Map::~Map() {}


bool Map::isFree(int xPosition, int yPosition) {
    if ((vec[yPosition][xPosition] == ' ' )
                      ||
        (vec[yPosition][xPosition] == '.')  )
         { return true;  }
    else { return false; }
}


void Map::printToStdOut() {
    for (unsigned int i=0; i < vec.size(); i++) {
        for (unsigned int j = 0; j < vec[i].size(); j++) {
            std::cout << vec[i][j];
        }
        std::cout << std::endl;
    }

}
