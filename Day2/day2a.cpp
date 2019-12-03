#include <iostream>
#include <fstream>
#include <vector>

int main() {
    std::fstream inFile("input.txt");
    std::string val;
    std::vector<unsigned int> values;

    while (std::getline(inFile, val, ','))
        values.push_back(std::stoi(val));

    int index = 0;

    values[1] = 12;
    values[2] = 2;

    while (values[index] != 99) {
        // set positions
        int pos1 = values[index + 1];
        int pos2 = values[index + 2];
        int savePos = values[index + 3];

        // add (1) or multiply (2)
        if (values[index] == 1)
            values[savePos] = values[pos1] + values[pos2];  
        else if (values[index] == 2)
            values[savePos] = values[pos1] * values[pos2];
        else
            exit(EXIT_FAILURE);
        
        index += 4;
    }

    std::cout << "result: " << values[0] << std::endl;
}