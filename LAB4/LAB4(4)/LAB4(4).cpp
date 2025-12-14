// LAB4(4).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>

int main()
{
    const int idLastTwo = 3; // "03" -> numeric value 3
    const int start = 1;
    const int end = 12;

    std::cout << "Multiplication table for student ID last two digits: 03\n\n";

    for (int i = start; i <= end; ++i)
    {
        // print each value with two digits (leading zero for 03 and single-digit multipliers/results)
        std::cout << std::setfill('0') << std::setw(2) << idLastTwo
                  << " x " << std::setw(2) << i
                  << " = " << std::setw(2) << (idLastTwo * i)
                  << std::setfill(' ') << '\n';
    }

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
