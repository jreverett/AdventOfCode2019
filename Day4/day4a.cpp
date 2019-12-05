#include <iostream>
#include <string>

int main() {
    static const int rangeMin = 158126, rangeMax = 624574;
    int numPasswords = 0;

    for (int i = rangeMin; i <= rangeMax; i++) {
        char previousVal = '#';
        bool hasDuplicate = false;
        bool descending = false;        

        for (char c : std::to_string(i)) {
            if (c == previousVal)
                hasDuplicate = true;
            if (c < previousVal)
                descending = true;

            previousVal = c;
        }

        if (hasDuplicate && !descending) {
            numPasswords++;
        }
    }
    
    std::cout << "Number of possible passwords: " << numPasswords << std::endl;
    return 0;
}