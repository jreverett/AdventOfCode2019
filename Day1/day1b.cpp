#include <iostream>
#include <fstream>
#include <math.h>

int calcFuel(int mass)
{
    mass = floor(mass / 3) - 2;

    if (mass < 0)
        return 0;

    return mass += calcFuel(mass);
}

int main()
{
    std::ifstream inFile("input.txt");

    int a = 0, total = 0;
    while (inFile >> a)
        total += calcFuel(a);

    std::cout << "Total Fuel: " << total << std::endl;

    return 0;
}