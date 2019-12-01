#include <iostream>
#include <fstream>
#include <math.h>

int main()
{
    std::ifstream inFile("input.txt");

    int a = 0, total = 0;

    while (inFile >> a)
        total += floor(a / 3) - 2;

    std::cout << "Total Fuel: " << total << std::endl;

    return 0;
}