#include <iostream>
#include <fstream>
#include <vector>

int calculateResult(std::vector<int> values, int noun, int verb) {
    values[1] = noun;
    values[2] = verb;
    
    int index = 0;
    
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

    return values[0];    
}

int main() {
    std::fstream inFile("input.txt");
    std::vector<int> values;
    std::string val;

    while (std::getline(inFile, val, ','))
        values.push_back(std::stoi(val));

    int answer = 0;
    // loop each noun + verb until opcode 99
    for (int noun = 0; noun < 100; noun++) {
        for (int verb = 0; verb < 100; verb++) {
            if (calculateResult(values, noun, verb) == 19690720) {
                answer = 100 * noun + verb;
                goto END;
            }
        }        
    }

    END:
    std::cout << "Day 2 (b) answer: " << answer << std::endl;
}