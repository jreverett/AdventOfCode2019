#include <iostream>
#include <string>

int main() {
    static const int rangeMin = 158126, rangeMax = 624574;
    int numPasswords = 0;

    for (int i = rangeMin; i <= rangeMax; i++) {
        char previousVal = '#';
        bool isValid = true;
        bool hasDuplicate = false, descending = false, charIsRepeating = false;
        int charStreak = 0, numPairs = 0;

        for (char c : std::to_string(i)) {
            if (c == previousVal) {
                charStreak++;

                if (!charIsRepeating) {
                    charIsRepeating = true;
                    numPairs++;
                }
                else
                    numPairs = 0;
            }
            else {
                charIsRepeating = false;

                if (charStreak == 1)
                    hasDuplicate = true;
                
                charStreak = 0;
            }

            if (c < previousVal)
                descending = true;

            previousVal = c;
        }

        if (numPairs < 1)
            isValid = false;

        if (hasDuplicate)
            isValid = true;

        if (descending)
            isValid = false;

        if (isValid)
            numPasswords++;
    }
    
    std::cout << "Number of possible passwords: " << numPasswords << std::endl;
    return 0;
}