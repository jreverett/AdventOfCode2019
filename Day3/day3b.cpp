#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

using Position = std::pair<int, int>;
using Wire = std::vector<Position>;

void extendWire(Wire &wire, Position &pos, std::string &posUpdate) {
    char command = posUpdate.at(0);
    int distance = stoi(posUpdate.erase(0, 1));
    std::pair<int, int> direction;

    switch (command) {
        case 'U':
            direction = {0, 1};
            break;
        case 'D':
            direction = {0, -1};
            break;
        case 'L':
            direction = {-1, 0};
            break;
        case 'R':
            direction = {1, 0};
            break;
        default:
            exit(EXIT_FAILURE);
    }

    for (int i = distance; i != 0; i--) {
        pos = {pos.first + direction.first, pos.second + direction.second};
        wire.push_back(pos);    
    }
}

Wire createWire(std::string wireData) {
    Wire wire;
    Position pos = {0, 0};

    std::stringstream sstrLine(wireData);
    std::string posUpdate;

    // store every step the wire takes
    while (std::getline(sstrLine, posUpdate, ',')) {
        extendWire(wire, pos, posUpdate);
    }

    return wire;
}

int main() {
    std::fstream inFile("input.txt");
    std::string strWire1, strWire2;

    std::getline(inFile, strWire1);
    std::getline(inFile, strWire2);

    Wire wire1 = createWire(strWire1);
    Wire wire2 = createWire(strWire2);

    int fewestSteps = -1;

    for (int i = 0; i != (int)wire1.size(); i++) {
        for (int j = 0; j != (int)wire2.size(); j++) {
            if (wire1[i] == wire2[j] && (fewestSteps == -1 || i + j < fewestSteps))
                fewestSteps = i + j + 2; // zero-indexed -> one-indexed
        }
    }

    std::cout << "Fewest steps: " << fewestSteps << std::endl;
    return 0;
}