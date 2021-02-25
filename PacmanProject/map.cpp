#include "map.h"
#include <iostream>

Map::Map(std::string filepath, unsigned int numLines) {
    std::fstream fileStream;
    fileStream.open(filepath);
    if (! fileStream.is_open()) { std::cout << "Can't open File !\n"; return; }
    char buffer;
    for (unsigned int i = 0; i < numLines; i++) {
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
        fileStream.close();
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
